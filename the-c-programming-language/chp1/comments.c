#include <stdio.h>

enum {
    NORMAL,
    IN_BLOCK_COMMENT,
    IN_LINE_COMMENT,
    IN_STRING,
    IN_CHAR
};

/* This program should ignore all 
   types of comments such as multi
   lined and single line, whilst 
   ensuring that chars and string 
   are not touched */
int main(void) {
    int curr, prev = 0;
    int state = NORMAL;

    while ((curr = getchar()) != EOF) {
        switch(state) {

        // For the normal case
        case NORMAL:
            if (prev == '/' && curr == '*') {
                state = IN_BLOCK_COMMENT;
                prev = 0;
            }
            else if (prev == '/' && curr == '/') {
                state = IN_LINE_COMMENT;
                prev =0;
            }
            else if (curr == '"') {
                putchar(curr);
                state = IN_STRING;
            }
            else if (curr == '\'') {
                putchar(curr);
                state = IN_CHAR;
            }
            else {
                if (prev)
                    putchar(prev);
                if (curr == '/')
                    prev = curr;
                else {
                    putchar(curr);
                    prev = 0;
                }
            }
            break;

        /* For the inline case */
        case IN_LINE_COMMENT: 
            if (curr == '\n') {
                putchar(curr);
                state = NORMAL;
            }
            break;
        /* For the // in a block case */
        case IN_BLOCK_COMMENT: 
            if (prev == '*' && curr == '/') {
                state = NORMAL;
                curr = 0;
            }
            prev = curr;
            break;

        /* For the // in a string 
           case */
        case IN_STRING: 
            putchar(curr);
            if (curr == '"' && prev != '\\')
                state = NORMAL;
            prev = curr;
            break;
        
        case IN_CHAR: // for chars 
            putchar(curr);
            if (curr == '\'' && prev != '\\') 
                state = NORMAL;
            prev = curr;
            break;
        }
    }
    return 0;
}
