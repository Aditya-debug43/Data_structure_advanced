int max(int a ,int b){
    if(a>b)
    return a;
    else
    return b;
}
int maxArea(int* height, int heightSize) {
    int maxarea=0;
    int left=0;
    int *nums=height;
    int right=heightSize-1;
    while(left<right){
        int x_dis=right-left;
        int height;
        if(nums[left]<nums[right]){
            height=nums[left];
            left++;
            while(left<right && nums[left]<height)
            left++;

        }
        else
        {
            height=nums[right];
            right--;
            while(left<right && nums[right]<height)
            right--;
        }
        maxarea=max(maxarea,x_dis*height);

    }
    return maxarea;
    
}
