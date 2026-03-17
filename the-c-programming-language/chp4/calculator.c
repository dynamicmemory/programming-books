#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100 
#define NUMBER '0'
#define MAXVAL 100 
#define BUFSIZE 100 

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char *);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0) 
                push(pop() / op2);
            else 
                printf("Error: Zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default: 
            printf("Error: Unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

int getop(char *s) {
    int i, c;
    static int prev = EOF;
    if (prev != EOF) {
        c = prev;
        prev = EOF;
    }
    else c = getchar();
    while (c == ' ' || c == '\t') c = getchar();
    s[0] = c;
    s[1] = '\0';
    if (!isdigit(c) && c != '.') return c;
    if (isdigit(c)) while (isdigit(c = getchar())) s[++i] = c;
    if (c == '.') {
        s[i++] = c;
        while (isdigit(c = getchar())) s[++i] = c;
    }
    s[i+1]='\0';
    prev = c;
    return NUMBER;
}

void push(double f) {
    if (sp < MAXVAL) 
        val[sp++] = f;
    else 
        printf("Error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0) 
        return val[--sp];
    else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

int getch(void) { return (bufp >= 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else 
        buf[bufp++] = c;
}
