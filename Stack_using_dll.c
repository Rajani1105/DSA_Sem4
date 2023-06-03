//reading random numbers from a file and performing stack operations using linked lists
#include <stdio.h>
#include <stdlib.h>
FILE *input,*stack,*poped,*pushed,*op;
int data;
struct Node
{
    int dat;
    struct Node *next,*prev;
};
typedef struct Node *node;
node top=NULL,newnode,temp;
void push()
{
    newnode=malloc(sizeof(struct Node));
    newnode->next=NULL;
    newnode->prev=NULL;
    fscanf(input,"%d",&data);
    stack=fopen("stack.txt","a");
    fprintf(stack,"%d\n",data);
    fprintf(pushed,"%d\n",data);
    fprintf(op,"push\n");
    fclose(stack);
    newnode->dat=data;
    if(top==NULL)
        top=newnode;
    else
    {
        top->next=newnode;
        newnode->prev=top;
        top=top->next;
    }
}

void pop()
{
    if(top==NULL)
    {
        printf("\nStack underflow:");
        return;
    }
    stack=fopen("stack.txt","w");
    fprintf(poped,"%d\n",top->dat);
    temp=top;
    top=top->prev;
    free(temp);
    top->next=NULL;
    fprintf(op,"pop\n");
    temp=top;
    while(temp->prev!=NULL)
        temp=temp->prev;
    while(temp!=NULL)
    {
        fprintf(stack,"%d\n",temp->dat);
        temp=temp->next;
    }
    fclose(stack);
}

void flushfile()
{
    poped=fopen("poped.txt","w");
    pushed=fopen("pushed.txt","w");
    op=fopen("op.txt","w");
    fclose(pushed);
    stack=fopen("stack.txt","w");
    fclose(stack);
    fclose(poped);
    fclose(op);
}
void random()
{
    for(int i=0;i<100;i++)
    {
        fprintf(input,"%d\n",rand()%1000);            //generate random numbers in input file
    }
}
void display()
{
    temp=top;
    while(temp->prev!=NULL)
        temp=temp->prev;
    printf("\n\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->dat);
        temp=temp->next;
    }

}
int main()
{
    int choice;
    input=fopen("input.txt","w");
    flushfile();                        //clear previous log files
    poped=fopen("poped.txt","a");
    pushed=fopen("pushed.txt","a");
    op=fopen("op.txt","a");

    if(input==NULL||poped==NULL||pushed==NULL||op==NULL)
    {
        printf("\n\nFile not opened!");
        goto finish;
    }
    random();
    fclose(input);

    input=fopen("input.txt","r");
    while(1){
    printf("\nEnter choice:\n 1-push\n 2-pop\n 3-display\n 4-end:\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:push();break;
        case 2:pop();break;
        case 3:display();break;
        case 4:goto finish;break;
        default:printf("Invalid choice");
    }
    }
    finish:
    printf("\nfinished");
    fclose(input);
    fclose(stack);
    fclose(pushed);
    fclose(poped);
    fclose(op);
    return 0;
}
