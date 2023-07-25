#include<stdio.h>
#include<stdlib.h>

struct node
{
    int page_no;
    char topic[20];
    struct node *link;
};
typedef struct node *snode;

snode create_node(int num)
{
    snode newnode;
    newnode=(snode)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("MEMORY NOT ALLOCATED \n");
        exit(0);
    }
    //printf("ENTER THE PAGE NO\n");
    //scanf("%d",&newnode->page_no);
    newnode->page_no=num;
    printf("ENTER THE TOPIC FOR THE PAGE NO %d \n",num);
    scanf("%s",newnode->topic);
    newnode->link=newnode;
    return newnode;
}

snode insert_end(snode tail,int num)
{
    snode newnode;
    newnode=create_node(num);
    if(tail==NULL)
    {
        tail=newnode;
    }
    else
    {
        newnode->link=tail->link;
        tail->link=newnode;
        tail=newnode;
    }
    return tail;
}

void display(snode tail)
{
    snode cur;
    if(tail==NULL)
    {
        printf("CSLL IS EMPTY \n");
    }
    else
    {
        cur=tail->link;
        while(cur!=tail)
        {
            printf("page no = %d\t",cur->page_no);
            printf("topic = %s",cur->topic);
            printf("\n");
            cur=cur->link;
        }
            printf("page no = %d\t",cur->page_no);
            printf("topic = %s",cur->topic);
    }
}

void display_one_by_one(snode tail,int key)
{
    snode cur;
    cur=tail->link;
    if(tail==NULL)
    {
        printf("THE PPT IS EMPTY \n");
        exit(0);
    }
    while(cur!=tail)
    {
        if(cur->page_no==key)
        {
            break;
        }
        cur=cur->link;

    }
        printf("The page is:%d\t",key);
        printf("The topic is :%s",cur->topic);
}


int count_pages(snode tail)
{
    snode cur;
    int count=0;
    if(tail==NULL)
    {
        return count;
    }
    else
    {
        cur=tail->link;
        do
        {
            cur=cur->link;
            count=count+1;
        }
        while(cur!=tail->link);
        return count;
    }
}

void search(snode tail)
{
    snode cur;
    int key,status=0;
    printf("ENTER THE PAGE NUMBER TO KNOW THE TOPIC \n");
    scanf("%d",&key);
    cur=tail->link;
    if(tail==NULL)
    {
        printf("CSLL IS EMPTY \n");
        exit(0);
    }
    while(cur!=tail)
    {
        if(cur->page_no==key)
        {
            status=1;
            break;
        }
        cur=cur->link;

    }
    if(cur->page_no==key)
    {
        status=1;
    }
    if(status==1)
    {
        printf("The page %d is found \n",key);
        printf("The topic is :%s",cur->topic);
    }
    else
    {
        printf("THE PAGE NO NOT FOUND \n");
    }
}

int main()
{
    snode tail=NULL;
    int ch,key=1,k=1;
    int count;
    while(1)
    {
        printf("\n\nTHE PPT MENU IS \n");
        printf("1.insert page at end  2.display the ppt  3.count pages\n");
        printf("4.search page and display topic 5.Display one bye one 6.exit \n\n");
        printf("ENTER YOUR CHOICE \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:tail=insert_end(tail,k);
                    k++;
                   break;
            case 2:display(tail);
                   break;
            case 3:count=count_pages(tail);
                    printf("The total no of slides:%d",count);
                   break;
            case 4:search(tail);
                   break;
            case 5:count=count_pages(tail);
                    if(key==count+1)
                        key=1;
                display_one_by_one(tail,key);
                key++;
                break;
            case 6:exit(0);
               break;
            default:printf("INVALID CHOICE \n");
                    break;
        }
    }
    return 0;
}
