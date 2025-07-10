char* shiftingLetters(char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
    int v=strlen(s);
    int* arr=(int*)malloc(sizeof(int)*v);
    for(int i=0;i<v;i++)
    arr[i]=0;
    for(int i=0;i<shiftsSize;i++){
        if(shifts[i][2]==0){
            int l=shifts[i][0],r=shifts[i][1]+1;
            arr[l]-=1;
            if(r<v)
            arr[r]+=1;
        }
        else
        {
            int l=shifts[i][0],r=shifts[i][1]+1;
            arr[l]+=1;
            if(r<v)
            arr[r]-=1;

        }
    }
    for(int i=1;i<v;i++)
    arr[i]+=arr[i-1];
    for(int i=0;i<v;i++){
        int ascii=((int)s[i]+arr[i]-'a')%26;
        if(ascii<0)
        ascii+=26;
        s[i]=(char)((ascii)+(int)'a');
    }
    return s;
    
}
