// Read random numbers from a file and sort them using linked list and calculate the time taken

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NODE
{
    int data;
    struct NODE *link;
};

typedef struct NODE *node;

node head=NULL;
node tail=NULL;
node newnode=NULL,curr;
int n;

void random(FILE *fptr)                    //generate random numbers
{
    printf("\nEnter the number of random numbers to be generated: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        fprintf(fptr,"%d ",rand()%1000);
    }
}

node insert(int a)                                      //Function to insert new node at the end
{
    node newnode=(node)malloc(sizeof(struct NODE));
    if(newnode==NULL)
    {
        printf("\nNode not created");
        exit(0);
    }
    newnode->data=a;
    newnode->link=NULL;
    return newnode;
}



void read(FILE *fptr)                 //function to read from file and store in linked list
{
    int a;
    for(int i=0;i<n;i++)
    {
        fscanf(fptr,"%d",&a);
        if(i==0)//first node
        {
            head=insert(a);
            tail=head;
        }
        else
        {
            newnode=insert(a);
            tail->link=newnode;
            tail=tail->link;
        }
    }
}


void display()
{
    if(head==NULL)
    {
        printf("\nEmpty..");
        return ;
    }
    node temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void sort()                                          // function to sort linked list using bubble sort
{
    node cur=head,temp1=head;
    int temp;
    do
    {
        do
        {
            temp1=temp1->link;
            if((cur->data)>(temp1->data))
            {
                temp=temp1->data;
                temp1->data=cur->data;        // swap data
                cur->data=temp;
            }

        }while(temp1->link!=NULL);
        cur=cur->link;
        temp1=cur;
    }while(cur->link!=NULL);
}

int main()
{
    FILE *fptr,*fptr2;
    time_t t1,t2,t;
    fptr=fopen("box.txt","w");               //write mode
    random(fptr);                            //generate random numbers and store in file
    fclose(fptr);
    fptr=fopen("box.txt","r");              //read mode
    read(fptr);                            //read from file and store in linked list
    fclose(fptr);
    t1=time(NULL);
    sort();
    t2=time(NULL);
    //display();
    t=t2-t1;                                //total time taken to sort
    printf("\nTime Taken: %ld",t);
    fptr2=fopen("box2.txt","w");
    curr=head;
    do
    {
        fprintf(fptr,"%d ",curr->data);      //to write the sorted numbers back to file
        curr=curr->link;
    }while(curr->link!=NULL);
    fclose(fptr2);
    return 0;
}

