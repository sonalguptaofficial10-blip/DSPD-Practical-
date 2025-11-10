#include <stdio.h>
#include <string.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top == MAX - 1)
        printf("\nStack Overflow! Cannot push %d\n", x);
    else
    {
        top++;
        stack[top] = x;
        printf("%d pushed into stack.\n", x);
    }
}

void pop()
{
    if(top == -1)
        printf("\nStack Underflow! Nothing to pop.\n");
    else
    {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;
    if(top == -1)
        printf("\nStack is empty.\n");
    else
    {
        printf("\nStack elements are:\n");
        for(i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

void checkPalindrome()
{
    char str[50];
    char rev[50];
    int i, len;

    printf("\nEnter a string to check palindrome: ");
    scanf("%s", str);

    len = strlen(str);
    top = -1; // reset stack

    // push all chars into stack
    for(i = 0; i < len; i++)
    {
        if(top == MAX - 1)
        {
            printf("Stack Overflow during palindrome check!\n");
            return;
        }
        stack[++top] = str[i];
    }

    // pop chars and form reverse
    for(i = 0; i < len; i++)
        rev[i] = stack[top--];
    rev[len] = '\0';

    if(strcmp(str, rev) == 0)
        printf("String is Palindrome.\n");
    else
        printf("String is not Palindrome.\n");
}

int main()
{
    int choice, val;

    do
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 5);

    return 0;
}
