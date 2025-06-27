void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void moveZeroes(int* nums, int numsSize) {
    if (numsSize==1)
    return;
    int zero=0;
    int nonzero=0;
      do{
         while(zero<numsSize && nums[zero]!=0)
        zero++;
        while(nonzero<numsSize && nums[nonzero]==0)
        nonzero++;
        printf("%d\t%d\n",zero,nonzero);

        if(zero<nonzero && zero<numsSize && nonzero<numsSize){
        swap(nums+zero,nums+nonzero);
        zero++;
        nonzero++;
        }
        else
        {
        if(zero>nonzero)
        nonzero=zero+1;
        }
        
    }while(nonzero<numsSize && zero<numsSize);
    
}
