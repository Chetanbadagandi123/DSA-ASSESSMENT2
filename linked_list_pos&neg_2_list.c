#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};
typedef struct Node *NODE;

void insertNode(NODE *head, int num)
{
    NODE newNode = malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->link = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->link = *head;
        *head = newNode;
    }
}

void display(NODE head)
{
    NODE temp = head;
    while (temp != NULL)
    {
        printf("%d->(%d)  ", temp->data,&temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void separateLists(NODE head, NODE *posList, NODE *negList)
{
    NODE temp = head;
    FILE* posfile = fopen("posfile.txt", "w");
    FILE* negfile = fopen("negfile.txt", "w");
    while (temp != NULL)
    {
        if(temp->data >= 0)
        {
            insertNode(posList, temp->data);
            fprintf(posfile,"%d->(%d)  ",temp->data,&temp->data);
        }
        else
        {
            insertNode(negList, temp->data);
            fprintf(negfile,"%d->(%d)  ",temp->data,&temp->data);
        }
        temp = temp->link;
    }
    fclose(posfile);
    fclose(negfile);
}

int main()
{
    FILE* file = fopen("numbers.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    NODE head = NULL;
    NODE posList = NULL;
    NODE negList = NULL;
    for(int i=0;i<n;i++)
    {
        num=(rand()%(upper-lower+1)-lower;
        fscanf(file,"%d",num);
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF)
    {
        insertNode(&head, num);
    }
    fclose(file);

    separateLists(head, &posList, &negList);

    printf("Positive numbers: ");
    display(posList);

    printf("Negative numbers: ");
    display(negList);
    return 0;
}
