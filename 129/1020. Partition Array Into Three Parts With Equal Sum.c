bool canThreePartsEqualSum(int* A, int ASize) {
    if (ASize < 3)return false;
    
    int totalSum = 0;
    for (int k = 0;k < ASize;k++) {
        totalSum += A[k];
    }
    if (totalSum % 3 != 0)return false;
    
    int currentSum = 0;
    int partCount = 0;
    for (int i = 0;i < ASize;i ++) {
        currentSum += A[i];
        if (currentSum == totalSum / 3) {
            currentSum = 0;
            partCount ++;
            
            if (partCount == 3)return true;
        }
    }
    return false;
}
