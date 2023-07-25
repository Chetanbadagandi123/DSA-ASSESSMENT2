#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *link;
}*NODE;

NODE create_node();
NODE insert_end(NODE head,int num);
NODE delete_end(NODE head);
NODE delete_front(NODE head);
void display(NODE head);

int main()
{
    int ch,n,num,i;
    int upper,lower;
    scanf("%d %d %d",&upper,&lower,&n);
    NODE head=NULL;
    while(1)
    {
        printf("SINGLY LINKED LIST MENU \n");
        printf("1:insert end 2:delete end 3:delete front 4:display 5:exit \n");
        printf("ENTER YOUR CHOICE \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: for(i=0;i<n;i++)
                    {
                      num = (rand() %(upper - lower + 1)) + lower;
                      head=insert_end(head,num);
                    }
                   break;
            case 2:head=delete_end(head);
                   break;
            case 3:head=delete_front(head);
                   break;
            case 4:display(head);
                   break;
            case 5:exit(0);
                    break;
            default:printf("INVALID CHOICE \n");
                    break;
        }
    }
    return 0;
}

NODE create_node(int num)
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node ));
    if(newnode==NULL)
    {
        printf("MEMORY NOT ALLOCATED \n");
        exit(0);
    }
    newnode->data=num;
    newnode->link=NULL;
    return newnode;
}
NODE insert_end(NODE head,int num)
{
    NODE cur,newnode;
    newnode=create_node(num);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        cur=head;
        while(cur->link!=NULL)
        {
            cur=cur->link;
        }
        cur->link=newnode;
    }
    return head;
}

NODE delete_end(NODE head)
{
    NODE prev,cur;
    if(head==NULL)
    {
        printf("EMPTY NODE \n");
    }
    else if(head->link==NULL)
    {
        printf("DELETED DATA IS %d \n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        prev=NULL;
        cur=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=NULL;
        printf("DELETED DATA IS %d \n",cur->data);
        free(cur);
    }
    return head;
}
NODE delete_front(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("EMPTY NODE \n");
    }
    else if(head->link==NULL)
    {
        printf("DELETED DATA IS %d \n",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head;
        head=head->link;
        cur->link=NULL;
        printf("DELETED DATA IS %d \n",cur->data);
        free(cur);
    }
    return head;
}

void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("SINGLY LINKED LIST IS EMPTY \n");

    }
    else
    {
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
    }
}
