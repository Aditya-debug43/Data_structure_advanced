int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int *arr=(int*)malloc(sizeof(int)*(startTimeSize+1));
    int index=0;
    for(int i=0;i<startTimeSize+1;i++)
    {
        if(i==0){
            arr[index++]=startTime[i];
        }
        else if(i<startTimeSize)
        {
            arr[index++]=startTime[i]-endTime[i-1];
        }
        else{
            arr[index++]=eventTime-endTime[i-1];
        }

    }
    int left=0;
    int right=k;
    int max=0;
    int sum=0;
    for(int i=0;i<=k;i++)
    sum+=arr[i];
    max=sum;
    while(right<(startTimeSize)){
        sum-=arr[left++];
        sum+=arr[++right];
        if(sum>max)
        max=sum;
    }
  return max;  
}
