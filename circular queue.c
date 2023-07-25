#include<stdio.h>
#include<stdlib.h>
#define size 100

struct queue
{
    int data[size];
    int front,rear;
};

int isfull(struct queue *qptr)
{
    if((qptr->rear+1)%size==qptr->front)//if rear is behind front then it is full
        return 1;
    else
        return 0;
}

int isempty(struct queue *qptr)
{
     if (qptr->front==-1 && qptr->rear==-1)
        return 1;
        else
            return 0;
}

void enqueue(struct queue *qptr,int num)
{
    if(qptr->front==-1 && qptr->rear==-1)
    {
        qptr->rear=qptr->front=0;
        qptr->data[qptr->rear]=num;
    }
    else if(isfull(qptr)){
        printf("queue overflow");
    }
    else
    {
        qptr->rear=(qptr->rear+1)%size;
        qptr->data[qptr->rear]=num;
    }
}
int dequeue(struct queue *qptr)
{
    int num=-1;
    if(isempty(qptr))
    {
        printf("Queue underflow\n");

    }
    else if (qptr->front==qptr->rear)
    {
        num=qptr->data[qptr->front];
        qptr->front=qptr->rear=-1;
    }
    else
    {
        num=qptr->data[qptr->front];
        qptr->front=(qptr->front+1)%size;
    }
    return num;
}
void display(struct queue *qptr)
{
    int i;
    if(isempty(qptr))
        printf("Queue Empty\n");
    else if(qptr->front<qptr->rear)
    {
        for(i=qptr->front+1;i<=qptr->rear;i++)
        {
            printf("%d\n",qptr->data[i]);
        }
    }
    else
    {
        for(i=qptr->front+1;i<size;i++)
        {
            printf("%d\n",qptr->data[i]);
        }
        for(i=0;i<=qptr->rear;i++)
        {
            printf("%d\n",qptr->data[i]);
        }
    }
}


/*void display(struct queue *qptr)
{
int i=qptr->front;
if (isempty(qptr))
    printf("queue is empty");

else{
    while(i!=qptr->rear)
    {
    printf("%d",qptr->data[i]);
    i=(i+1)/size;
}
printf("%d",qptr->data[i]);
}
}
*/
int main()
{
    struct queue q,*qptr;
    qptr=&q;
    qptr->rear=-1;
    qptr->front=-1;
    int ch,num;
    while(1)
    {
        printf("\n\Queue menu\n");
        printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                   {
                       printf("enter number\n");
                       scanf("%d",&num);
                       enqueue(qptr,num);
                   }
                   break;
            case 2:num=dequeue(qptr);
                   {
                        if(num==-1)
                        {
                             printf(" Queue UNDERFLOW\n");
                        }
                        else
                        {
                             printf("DEQUEUED NUMBER IS %d\n",num);
                        }
                   }
                   break;
            case 3:display(qptr);
                   break;
            case 4:exit(0);
                   break;
            default:printf("Invalid choice\n");
                    break;
        }
    }
    return 0;
}
