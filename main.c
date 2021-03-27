#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Item{
int key;
char * info;
}*Item;

const int SZ = 10;

struct Table{
int n;
struct Item first[SZ];
}Table;

int getInt(int *a)
{
int n;
do{
    n = scanf("%d", a, sizeof(int));
    if (n < 0)
        return 0;
    if (n == 0){
        printf("%s\n", "Error! Repeat input");
        scanf("%*c", 0);
    }
    } while (n == 0);
return 1;
}

char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}


// DIALOG

const char *MSGS[] = {"0. Quit", "1. Add", "2. Find", "3. Delete", "4. Show"};
const char *errmsgs[] = {"Ok", "Duplicate key", "Table overflow"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]);


int dialog(const char *msgs[], int n) {
    char *errmsg = "";
    int choice;
    do {
        puts(errmsg);
        errmsg = "You are wrong. Repeate, please!";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
    }
    puts("Make your choice: ");
    choice = getchar() - '0';
    while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}
// DIALOG END

int D_Add(struct Table *ptab)
{
int k, rc, n;
char *info = NULL;
printf("Enter key: -->");
    n = getInt(&k);
    if(n == 0)
        return 0;
    printf("Enter info:\n");
    info = get_str();
    if (info == NULL)
        free(info);
    printf("%s: %d\n", errmsgs[rc], k);
return 1;
}



int main()
{
struct Table table;
int c = 0;
    do {
    c = dialog(MSGS, MSGS_SIZE);
    switch(c) {
    case 0:
        break;
    case 1:
        printf("\n***\nAdd\n***\n");
            D_Add(&table);
        break;
    case 2:
        printf("***\nOption 2\n***\n");
        break;
    case 3:
        printf("***\nOption 3\n***\n");
        break;
    case 4:
        printf("***\nOption 4\n***\n");
        break;
    }
    } while (c != 0);
return 0;
}






