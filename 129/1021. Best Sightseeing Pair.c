int max(int a, int b)
{
    if(a > b) return a;
    else      return b;
}

int maxScoreSightseeingPair(int* A, int ASize) {
    int maxScore = INT_MIN;
    int cur = INT_MIN;
    for(int i = 0; i < ASize; i++){
        maxScore = max(maxScore, cur + A[i]);
        cur = max(cur, A[i]) - 1;
    }
    return maxScore;
}
