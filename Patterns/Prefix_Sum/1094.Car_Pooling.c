bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity) {
    int size=trips[0][2];
    for(int i=1;i<tripsSize;i++){
        if(size<trips[i][2])
        size=trips[i][2];
    }
    size+=1;
    int* arr=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    arr[i]=0;
    for(int i=0;i<tripsSize;i++){
        int a=trips[i][0],l=trips[i][1],r=trips[i][2];
        arr[l]+=a;
        if(r<size)
        arr[r]-=a;
    }
    for(int i=1;i<size;i++)
    arr[i]+=arr[i-1];

    for(int i=0;i<size;i++){
        if(arr[i]>capacity)
        return false;
    }
 return true;   
}
