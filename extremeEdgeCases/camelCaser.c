#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **camel_caser(const char *input) {
    if(!input) {
        return NULL;
    }

    char *head = malloc(sizeof(char) * (strlen(input) + 1));
    head = strcpy(head, input);

    char *ptr = head;
    char *start = head;
    int chars = 0;
    int sentences = 0;

    while (*ptr != '\0') {
        if (ispunct(*ptr)) {
            sentences++;
        }
        ptr++;
    }

    ptr = head;
    char **ret = malloc(sizeof(char*) * (sentences + 1));
    int numSentence = 0;

    while (*ptr != '\0') {
        if (ispunct(*ptr)) {
            char *end = ptr;
            ptr = start;
            while (ptr != end) {
                if (isalpha(*ptr)) {
                    chars++;
                }
                ptr++;
            }
            char *sentence = malloc(sizeof(char) + (chars + 1));
            int currIdx = 0;
            ptr = start;
            int newWord = 0;
            while (ptr != end) {
                if (isspace(*ptr)) {
                    newWord = 1;
                } else if (isalpha(*ptr)) {
                    if (newWord) {
                        sentence[currIdx] = toupper(*ptr);
                    } else {
                        sentence[currIdx] = tolower(*ptr);
                    }
                    currIdx++;
                    newWord = 0;
                }
                ptr++;
            }
            sentence[currIdx] = '\0';
            ret[numSentence] = sentence;
            printf("%s\n", ret[numSentence]);
            start = ptr;
        }
        numSentence++;
        ptr++;
    }
    ret[numSentence+1] = NULL;

    free(head);

    return ret;
}

int main(int argc, char **argv) {
    char *input = "The Heisenbug is an incredible creature. Facenovel servers get their power from its indeterminism. Code smell can be ignored with INCREDIBLE use of air freshener. God objects are the new religion.";
    char **result = camel_caser(input);
    // printf("%s\n", result[0]);

    /*
    int s = 0;
    while (strcmp(result[s], "\0") == 0) {
        printf("%s\n", result[s]);
        s++;
    }
    */

    return 0;
}
