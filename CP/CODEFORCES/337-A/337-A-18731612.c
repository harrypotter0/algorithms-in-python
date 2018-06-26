#include<stdio.h>


void bubbleSort(int numbers[], int array_size)
{ 
  int i, j, temp; 

  for (i = (array_size - 1); i >= 0; i--) 
  {
    for (j = 1; j <= i; j++)
    {
      if (numbers[j-1] > numbers[j])
      {
        temp = numbers[j-1];
        numbers[j-1] = numbers[j];
        numbers[j] = temp;
      }
    }
  }
}

int main()
{
    int a,b,x;
    scanf("%d %d",&a,&b);
    int ar[b];
    for(x=0;x<b;x++)
    {
        scanf("%d",&ar[x]);
    };

     bubbleSort(ar,b);
     
    int min=ar[a-1]-ar[0];
    for(x=0;x<b-a+1;x++)
    {
       if ((ar[a-1+x]-ar[x])<min) min=(ar[a-1+x]-ar[x]);
    };
    
    printf("%d",min);
    
  
    return 0;
}