bool queryString(char* S, int N) {
  bool *seen = calloc(N, sizeof(bool));
  int X = 0;
    
  for (int i = 0; i < strlen(S) && X < N; ++i) {
    if (S[i] == '0') continue;
    for (int j = i, num = 0; num <= N && j < strlen(S); ++j) {
      num = (num << 1) + S[j] - '0';
      if (num > 0 && num <= N && !seen[num - 1]) {
        ++X;
        seen[num - 1] = true;
      }
    }
  }
  return X == N;
}
//寫得差不多...我寫的比較醜@@
