#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void enqueue(char x)
{
    if(rear == MAX - 1)
        printf("\nQueue Overflow! Cannot insert %c\n", x);
    else
    {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = x;
        printf("%c inserted into queue.\n", x);
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
        printf("\nQueue Underflow! Nothing to delete.\n");
    else
    {
        printf("%c deleted from queue.\n", queue[front]);
        front++;
        if(front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    int i;
    if(front == -1)
        printf("\nQueue is empty.\n");
    else
    {
        printf("\nQueue elements are: ");
        for(i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
}

int main()
{
    int choice;
    char ch;

    do
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &ch);
                enqueue(ch);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 4);

    return 0;
}
