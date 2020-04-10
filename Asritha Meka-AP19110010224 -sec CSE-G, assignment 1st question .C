/*1.writing a C program to Reverse a String using a STACK*/

#include <stdio.h>
#include <string.h>

#define MAX 50 

int n=-1;
int item;

char stack_string[MAX];

/*function to push the character*/
void pushChar(char item);

/*function to pop the character*/
char popChar(void);

/*function to check wheather the stack is empty or not*/
int isEmpty(void);

/*function to check wheather stack is full or not*/
int isFull(void);
 
int main()
{
    char str[MAX];
    
    int i;
    
    printf("Input a string: ");
    scanf("%[^\n]s",str); 
    
    for(i=0;i<strlen(str);i++)
        pushChar(str[i]);
        
    for(i=0;i<strlen(str);i++)
        str[i]=popChar();

    printf("Reversed String is: %s\n",str);
    
    return 0;
}
 
void pushChar(char item)
{
    if(isFull())
    {
        printf("\nStack is FULL !!!\n");
        return;
    }
    
    n=n+1;
    stack_string[n]=item;
}
 
/*function definition of popChar*/
 char popChar()
{
    if(isEmpty())
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }

    /*pop item and decrease the n*/
    item = stack_string[n];
    n=n-1;
    return item;
}
int isEmpty()
{
    if(n==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(n==MAX-1)
        return 1;
    else
        return 0;
}

