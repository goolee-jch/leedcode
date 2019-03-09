int isSub(char *s, char *t)
{
    int lens = strlen(s);
    int lent = strlen(t);
    int i, j;
    
    for (i = 0, j = 0; i < lent; i++) {
        while (j < lens && s[j] != t[i])
            j++;
        if (j == lens)
            return 0;
        j++;
    }
    return 1;
}
char* findLongestWord(char* s, char** d, int dSize) {
    int i, max = 0, len = 0;
    char *p = NULL;
    
    for (i = 0; i < dSize; i++) {
        if (isSub(s, d[i]) == 1) {
            len = strlen(d[i]);
            if (len > max || (len == max && strcmp(d[i], p) < 0)) {
                max = len;
                p = d[i];
            }
        }
    }
    return p == NULL? "": p;
}