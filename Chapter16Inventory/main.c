#include <stdio.h>
#include "readline.h"
#define NAME_LEN 25
#define MAX_PARTS 100
// request for member ‘number’ in something not a structure or union, something is outdated and you need to set -std=C89
struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;

}; int inventory[MAX_PARTS];

int num_parts = 0;
int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
int main() {
    char code;
    for (;;) {
        printf("enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n');
        switch (code) {
            case 'i' : insert(); break;
            case 's': search();break;
            case 'u': update();break;
            case 'p': print();break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");

    }

//    printf("Hello, World!\n");
    return 0;
}

int find_part(int number) {
    int i;
    for (i=0; i< num_parts; i++)
        if (inventory[i].number == number)
            return i;
    return -1;
}

void insert(void) {
    int part_number;
    if (num_parts == MAX_PARTS) {
        printf("Database is full: can't add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", &part_number);
    if (find_part(part_number) == 0) {
        printf("Part already exists.\n");
        return;
    }
    inventory[num_parts].number = part_number;

}

