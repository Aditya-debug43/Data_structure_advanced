int possibleStringCount(char* word) {
    int left=0;
    int right=1;
    int wordlen=strlen(word);
    int freq=1;
    int possible=1;
    while(right<wordlen)
    {
        if(word[left]==word[right]){
            freq++;
            right++;
        }
        else
        {
            if(freq>1)
            possible+=freq-1;
            freq=1;
            left=(right++);
        }
    }
    if(freq>1)
    possible+=freq-1;
    return possible;
}
