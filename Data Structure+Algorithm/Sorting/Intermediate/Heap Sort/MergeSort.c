#include<stdio.h>

void merge(int Array[20],int start,int _break,int end){
    int LeftArraySize = _break - start + 1;
    int RightArraySize = end - _break;
    int Left[LeftArraySize + 1];
    int Right[RightArraySize + 1];
    for(int i=0;i < LeftArraySize;i++){
        Left[i]=Array[start + i];
    }
    for(int i=0;i < RightArraySize;i++){
        Right[i]=Array[_break+i+1];
    }
    Left[LeftArraySize] = 999999999;
    Right[RightArraySize] = 999999999;
    int i = 0,j = 0;
    for(int k = start;k <= end;k++){
        if(Left[i]<=Right[j]){
            Array[k] = Left[i];
            i++;
        }else{
            Array[k] = Right[j];
            j++;
        }
    }
}

void mergesort(int Array[20],int start,int end){
    if(start<end){
        int _break = start + (end - start) / 2;
        mergesort(Array, start, _break);
        mergesort(Array,_break+1,end);
        merge(Array,start, _break, end);
    }
}

int main(){
    int Array[20];
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    printf("Enter array elements:\n");
    for(int i = 0;i < size;i++){
        printf("Array[%d]:",i);
        scanf("%d",&Array[i]);
    }

    mergesort(Array, 0, size - 1);

    for(int i = 0;i < size;i++){
        printf("%d ",Array[i]);
    }
    printf("\n");
    return 0;
}
