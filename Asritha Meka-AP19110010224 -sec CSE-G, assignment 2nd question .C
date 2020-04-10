/*2.write a c program for infix to postfix conversion using stack*/

#include<stdio.h>
char stack[30];
int n = -1;
void push(char x)
{
    stack[++n] = x;
}
 
char pop()
{
    if(n == -1)
        return -1;
    else
        return stack[n--];
}
 
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
 
main()
{
    char exp[20];
    char *e, x;
    printf("Enter a expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[n]) >= priority(*e))
                printf("%c",pop());
            push(*e);
        }
        e++;
    }
    while(n!= -1)
    {
        printf("%c",pop());
    }
}
