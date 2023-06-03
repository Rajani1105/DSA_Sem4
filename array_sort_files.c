//Reading random numbers from a file into an array,sorting them and writing them into another file
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fptr,*fptr1;
  int arr1[1000],arr[1000];

void rand_no(int n)
 {
     fptr=fopen("random.txt","w");
  for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
        fprintf(fptr,"%d ",arr[i]);
    }

    fclose(fptr);
 }

 void read_frm_file(int m)
 {


    for(int i=0;i<m;i++)
    {
        fscanf(fptr,"%d",&arr1[i]);
    }

 }
 void sort(int m)
 {
  for(int i=0;i<m;i++)
    {
        for(int j=0;j<m-1-i;j++)
        {
            if(arr1[j]>arr1[j+1])
            {
                int temp=0;
                temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            }
        }
    }
 }

 void disp_write(int m)
 {
     fptr1=fopen("sorted.txt","w");
     for(int i=0;i<m;i++)
    {
        printf("%d ",arr1[i]);
        fprintf(fptr1,"%d ",arr1[i]);
    }
    fclose(fptr1);
 }


int main()
{

    int n;
    printf("\nEnter number of random numbers to be generated: ");
    scanf("%d",&n);
    int arr[n];

    rand_no(n);
    fptr=fopen("random.txt","r");
    int m;
    read_frm_file(m);
    time_t t1,t2,t;
    printf("\nEnter number of elements to be sorted: ");
    scanf("%d",&m);
    t1=time(NULL);
    sort(m);
    disp_write(m);
    t2=time(NULL);
    t=t2-t1;
    printf("\n\nTime %d",t);
      fclose(fptr);
      return 0;
}


