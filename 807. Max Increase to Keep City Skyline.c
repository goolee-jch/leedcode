int maxIncreaseKeepingSkyline(int** grid, int gridRowSize, int *gridColSizes) {
    if(grid==NULL)
        return 0;
    int *botton = malloc(*gridColSizes*sizeof(int));
    int *right = malloc(gridRowSize*sizeof(int));
    for(int i=0;i<gridRowSize;i++)
        right[i] = 0;
    for(int i=0;i<*gridColSizes;i++)
        botton[i] = 0;
    for(int i=0;i<gridRowSize;i++)
    {
        for(int j=0;j<*gridColSizes;j++)
        {
            if(grid[i][j]>right[i])
                right[i] = grid[i][j];
            if(grid[i][j]>botton[j])
                botton[j] = grid[i][j];
        }
    }
    int ret = 0;
    for(int i=0;i<gridRowSize;i++)
    {
        for(int j=0;j<*gridColSizes;j++)
        {
            if(right[i]>botton[j])
                ret+=botton[j]-grid[i][j];
            else
                ret+=right[i]-grid[i][j];
        }
    }
    return ret;
}