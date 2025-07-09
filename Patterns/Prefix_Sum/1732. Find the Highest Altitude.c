int largestAltitude(int* gain, int gainSize) {
    int sum=gain[0];
    int max=gain[0];
    for(int i=1;i<gainSize;i++)
    {
      sum+=gain[i];
      if(sum>max)
      max=sum;
    }
    if (max<0)
    max=0;
    return max;
}
