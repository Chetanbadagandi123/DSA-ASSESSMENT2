#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;

NODE create_node()
{
    NODE newnode;
    newnode=(NODE)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->link=NULL;
    return newnode;
}

NODE insert_end(NODE head)
{
    NODE newnode,cur;
    newnode=create_node();
    if(head==NULL)
        head=newnode;
    else
    {
        cur=head;
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=newnode;
    }
    return head;
}



void display(NODE head)
{
    NODE cur;
    if(head==NULL)
        printf("The list is empty\n");
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            printf("%d->",cur->data);
            cur=cur->link;
        }
    }
}

int count_nodes(NODE head)
{
    NODE cur;
    int count=0;
    if(head==NULL)
    {
        return count;
    }
    else if(head->link==NULL)
        count=1;
    else
    {
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->link;
        }
    }
    printf("total nodes :%d",count);
    return count;
}

void sorting(NODE head)
{
    NODE t,s;
    int temp;
    t=head;
    while(t!=NULL)
    {
        s=t->link;
        while(s!=NULL)
        {
            if(t->data>s->data)
            {
                temp=t->data;
                t->data=s->data;
                s->data=temp;
            }
            s=s->link;
        }
        t=t->link;
    }
    display(head);
}

void find_max(NODE head)
{
    NODE cur;
    int max=0,low=9999;
        cur=head;
        while(cur!=NULL)
        {
            if(cur->data>max)
                max=cur->data;
            if(cur->data<low)
                low=cur->data;
            cur=cur->link;
        }
        printf("max=%d\n low=%d",max,low);
}

int main()
{
    NODE head=NULL;
    int ch,count;
    while(1)
    {
        printf("\n1:insert end 2:display 3:find max 8:exit\n") ;
        printf("enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insert_end(head);
            break;
            case 2:head=insert_front(head);
            break;
            case 3:head=delete_end(head);
            break;
            case 4:head=delete_front(head);
            break;
            case 5:display(head);
            break;
            case 6:head=insert_position(head);
            break;
            case 7:head=delete_position(head);
            break;
            case 8:exit(0);
            break;
            case 9:head=search_delete(head);
            break;
            case 11:find_max(head);
            break;
            case 12:sorting(head);
            break;
            default:printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}

