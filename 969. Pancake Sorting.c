/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void revertstring(int* A, int ASize,int k)
{
    if(k>ASize)
        return 1;
    for(int i=0;i<k/2;i++)
    {
        A[i]^=A[k-1-i];
        A[k-1-i]^=A[i];
        A[i]^=A[k-1-i];
    }
}
int* pancakeSort(int* A, int ASize, int* returnSize) {
    int *ret = malloc(2*ASize*sizeof(int));
    if(A==NULL)
        return NULL;
    int max = -1;
    int maxidx = -1; 
    * returnSize = 0;
    for(int SearchSize = ASize;SearchSize>0;SearchSize--)
    {
        max = A[0];
        maxidx = 0;
        for(int i=1;i<SearchSize;i++)
        {
            if(A[i]>max)
            {
                max = A[i];
                maxidx = i;
            }
        }
        if(maxidx==SearchSize-1)
            continue;
        if(maxidx==0)
        {
            ret[* returnSize]=SearchSize;
        }
        else
        {
            ret[* returnSize]=maxidx+1;
            (* returnSize)++;
            revertstring(A,ASize,maxidx+1);
            ret[* returnSize]=SearchSize;
        }
        revertstring(A,ASize,SearchSize);
        (* returnSize)++;
    }
    return ret;
}
