//Reading random numbers from file and performing stack operations using arrays and writing stack data to file
#include<stdio.h>
#include<stdlib.h>
int stack[100],ch,n,top,x,i,num;
void push(void);
void pop(void);
void display(void);
FILE *fstack,*fpush,*fpop,*fip;


int main()
{
  fpush=fopen("push.txt","w");
   fpop=fopen("pop.txt","w");
    top=-1;
    printf("\n Enter the size of STACK[MAX=1000]:");
    scanf("%d",&n);
    printf("Enter the number of random numbers to be generated\n");
    scanf("%d",&num);
    random_n(num);
    fip=fopen("input.txt","r");
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\nEnter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;

            case 4:printf("\n\t EXIT POINT ");

                fclose(fpush);
                fclose(fpop);
                fclose(fip);
                fstack=fopen("stack.txt","w");
                if(top>=0)
               {
                for(i=top;i>=0;i--)
                fprintf(fstack," %d",stack[i]);

                }
                else
                  {
                    fprintf(fstack,"-");
                  }
                fclose(fstack);
                break;



           default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }

        }
    }
    while(ch!=4);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("\n\tSTACK is over flow");

    }
    else
    {
        fscanf(fip,"%d",&x);
        top++;
        stack[top]=x;
        fprintf(fstack,"%d ",x);
        fprintf(fpush,"%d ",x);
   }
}
void pop()
{
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        fprintf(fpop,"%d ",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n The elements in STACK \n");
        for(i=top;i>=0;i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }

}
void random_n(int num)
{   int a;
    fip=fopen("input.txt","w");
    for (i=0;i<num;i++)
    {
      a=rand()%1000;
      fprintf(fip,"%d ",a);
    }
    fclose(fip);
}
