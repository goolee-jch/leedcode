char* reorganizeString(char* s) {
    int slen = strlen(s);
    if(s == NULL || slen < 2) return s;
    int *bucket = calloc(26, sizeof(int));
    
    for(int i = 0; i < slen; i++){
        bucket[s[i] - 'a']++;
    }
    int max = 0;
    for(int i = 0 ; i < 26; i++){
        if(bucket[i] > bucket[max]) max = i;
    }
    
    if(bucket[max] >(slen + 1)/2) return "";
    
    char *ans = (char*)malloc(sizeof(char) * (slen + 1));
    int start = 0;
    for(int i = 0; i < slen; i = i + 2){//
        if(bucket[max] > 0){
            ans[i] = (char)('a' + max);
            bucket[max]--;
        }else{
            while(bucket[start] == 0){
                start++;
            }
            ans[i] = (char)('a' + start);
            bucket[start]--;
        }
    }
    for(int i = 1; i < slen; i = i + 2){
        while(bucket[start] == 0){
            start++;
        }
        ans[i] = (char)('a' + start);
        bucket[start]--;
    }
    ans[slen] = '\0';
    return ans;
}