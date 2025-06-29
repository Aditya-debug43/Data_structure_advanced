void swap(int* a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int* a,int l,int h,int* arr)
{
     int pivot=a[l];
     int i=l,j=h;
        while(i<j){
            while(i<=h && a[i]<=pivot)
            i++;
            while(a[j]>pivot)
            j--;
            if(i<j){
            swap(&a[i],&a[j]);
            swap(arr+i,arr+j);
            }
        }
        swap(&a[l],&a[j]);
        swap(arr+l,arr+j);
        return j;
}
void quicksort(int* a,int l,int h,int*arr)
{
    int j;
    if(l<h){
        j=partition(a,l,h,arr);
        quicksort(a,l,j-1,arr);
        quicksort(a,j+1,h,arr);
    }
}
int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    int*arr=(int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++)
    arr[i]=i;
    quicksort(nums,0,numsSize-1,arr);
    quicksort(arr,numsSize-k,numsSize-1,nums);
    int*final=(int*)malloc(sizeof(int)*k);
    int index=0;
    for(int i=numsSize-k;i<numsSize;i++)
    final[index++]=nums[i];
    *returnSize=k;
    return final;
    
}
