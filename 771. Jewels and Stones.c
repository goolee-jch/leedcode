int numJewelsInStones(char* J, char* S) {
    int hash[128] = {0};
    int ret = 0;
    for (int i=0;i<strlen(J);i++)
    {
        hash[J[i]]++;
    }
    for (int i=0;i<strlen(S);i++)
    {
        if(hash[S[i]])
        {
            ret++;
        }
    }
    return ret;
}