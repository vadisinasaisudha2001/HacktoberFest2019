#include<stdio.h>
void quick_sort(int number[25],int first,int last){
int i, j, pivot, temp;
if(first<last){
pivot=first;
i=first;
j=last;
while(i<j){
while(number[i]<=number[pivot]&&i<last)
i++;
while(number[j]>number[pivot])
j--;
if(i<j){
temp=number[i];
number[i]=number[j];
number[j]=temp;
}
}
temp=number[pivot];
number[pivot]=number[j];
number[j]=temp;
quick_sort(number,first,j-1);
quick_sort(number,j+1,last);
}
}
int main(){
int i, count, number[25];
printf("Enter the size of an array: ");
scanf("%d",&count);
printf("Enter %d elements: ", count);
for(i=0;i<count;i++)
scanf("%d",&number[i]);
quick_sort(number,0,count-1);
printf("The Sorted Order is: ");
for(i=0;i<count;i++)
printf(" %d",number[i]);
return 0;
}
