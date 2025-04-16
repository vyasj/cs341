#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char* name;
    int age;
    struct Person* friends[10];
};

typedef struct Person person_t;

person_t* create(char* name, int age) {
    person_t* p = malloc(sizeof(person_t));
    p->name = name;
    p->age = age;

    return p;
}

void destroy(person_t* p) {
    memset(p, 0, sizeof(*p));
    free(p);
}

int main() {
    person_t* p1 = create("Agent Smith", 128);
    person_t* p2 = create("Sonny Moore", 256);
    p1->friends[0] = p2;
    p2->friends[0] = p1;

    printf("sizeof(p1) = %zu\n", sizeof(*p1));
    printf("list of p1's friends:\n");
    int i = 0;
    while (p1->friends[i]) {
        printf("p1's friend: %s\n", p1->friends[0]->name);
        i++;
    }
    destroy(p1);
    printf("is p2 still around?\n");
    if (p2->age == 256) {
        printf("yes!\n");
    } else {
        printf("no :(\n");
    }
    destroy(p2);
    return 0;
}
