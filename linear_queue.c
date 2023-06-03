//Reading random numbers from a file, performing linear queue operations using linked lists and writing queue data to file
#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE node;


FILE *fip,*enq,*deq,*queue,*logg;
 node *head=NULL ,*tail=NULL;


void Enqueue()
{
     node *newnode=malloc(sizeof(struct NODE));
     if(newnode==NULL)
     {
         printf("node is not created\n");
         return;
     }

     int val;

     fscanf(fip,"%d ",&val);


    newnode->data=val;
    newnode->next=NULL;

    if(head==NULL && tail==NULL)
        head=tail= newnode;
    else
    {

        tail->next=newnode;
        tail=newnode;
    }
 fprintf(enq,"%d ",val);
 queue=fopen("queue.txt","a");
 fprintf(queue,"%d ",val);
 fclose(queue);
 logg=fopen("logg.txt","a");
 fprintf(logg,"enqueue\n");
}

void Dequeue()
{
    node *temp;

    if(head==NULL)
         {
             printf("Queue is Empty. Unable to perform dequeue\n");
             return;
         }


        temp=head;
       head=head->next;
        if(head== NULL)
            tail= NULL;


       fprintf(deq,"%d ",temp->data);
       free(temp);

    queue=fopen("queue.txt","w");
    temp=head;
    while(temp!=NULL)
    {
        fprintf(queue,"%d ",temp->data);
        temp=temp->next;
    }
    fclose(queue);
    fprintf(logg,"dequeue\n");



}

void display()
{
     node *temp=head;

    while(temp)
    {
        printf("%d->",temp->data);

        temp = temp->next;
    }
    printf("NULL\n");
}
void random_n(int num)
{   int a;
    fip=fopen("input1.txt","w");
    for (int i=0;i<num;i++)
    {
      a=rand()%1000;
      fprintf(fip,"%d ",a);
    }
    fclose(fip);
}

int main()
{
    queue=fopen("queue.txt","w");
    fclose(queue);
    logg=fopen("logg.txt","w");
    fclose(logg);
    int ch,n;
    printf("enter the number of random numbers to be generated\n");
    scanf("%d",&n);
    random_n(n);
    fip=fopen("input1.txt","r");
    enq=fopen("enqueue.txt","w");
    deq=fopen("dequeue.txt","w");
    while(1)
    {
        printf("enter 1-Enqueue\n 2-dequeue\n 3-display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:Enqueue();
                  break;
            case 2:Dequeue();
                  break;
            case 3:display();
                  break;
            case 4:goto finish;
                   break;
             default :printf("invalid choice\n");
        }
    }



   finish: fclose(fip);
           fclose(enq);
            fclose(deq);
            fclose(logg);

    return 0;

}
