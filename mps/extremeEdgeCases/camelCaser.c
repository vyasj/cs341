#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char **camel_caser(const char *input) {
    if(!input) {
        return NULL;
    }

    // malloc enough memory to make  a copy of the input string
    // this is necessary because we need to edit the pointer
    char *head = malloc(sizeof(char) * (strlen(input) + 1));
    head = strcpy(head, input);

    // initialize two pointers that will move along the length
    // of the copied string, a couter for the number of characters
    // found, and a counter for the number of sentences found
    char *ptr = head;
    char *start = head;
    int chars = 0;
    int sentences = 0;

    // count the number of sentences in the input string
    while (*ptr != '\0') {
        if (ispunct(*ptr)) {
            sentences++;
        }
        ptr++;
    }

    // malloc enough memory for the number of sentences in the
    // input string, since the return variable will be an array
    // of camelCased sentences, and initialize a counter for
    // which sentence the algorithm is currently building
    ptr = head;
    char **ret = malloc(sizeof(char*) * (sentences + 1));
    char **retHead = ret;

    while (*ptr != '\0') {
        // if the current letter is punctuation, return to the
        // beginning of the sentence and begin to camelCase it
        if (ispunct(*ptr)) {
            char *end = ptr;
            ptr = start;
            while (ptr != end) {
                // only count the letters in the string to malloc
                if (isalpha(*ptr)) {
                    chars++;
                }
                ptr++;
            }
            // malloc enough memory for the characters counted and
            // initialize counter variables for the index of the
            // sentence to add the character and whether or not
            // it is a new word, so it should be capitalized
            char *sentence = malloc(sizeof(char) + (chars + 1));
            int currIdx = 0;
            ptr = start;
            int newWord = 0;
            while (ptr != end) {
                // if the current character is a space, then the
                // next character is the start of a new word,
                // otherwise the first letter should be capitalized
                if (isspace(*ptr)) {
                    if (ispunct(*(ptr-1))) {
                        newWord = 0;
                    } else {
                        newWord = 1;
                    }
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
            // add endline character to the current sentence and
            // add the sentence to the array to be returned
            sentence[currIdx] = '\0';
            *ret = sentence;
            ret++;
            start = ptr;
        }
        ptr++;
    }
    *ret = NULL;

    // free the copy of the string made initially
    free(head);

    return retHead;
}

void destroy(char **input) {
    char **head = input;
    while (*head) {
        free(*head);
        head++;
    }
    free(*head);
    free(input);
}

int main(int argc, char **argv) {
    char *input = "The Heisenbug is an incredible creature. Facenovel servers get their power from its indeterminism. Code smell can be ignored with INCREDIBLE use of air freshener. God objects are the new religion.";
    char **result = camel_caser(input);

    char ** resultHead = result;
    while (*resultHead) {
        printf("%s\n", *resultHead);
        resultHead++;
    }

    destroy(result);

    return 0;
}
