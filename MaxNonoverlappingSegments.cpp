int solution(vector<int>&A, vector<int>& B) {
    int N = A.size();
    int count = 0;
    int cursor = 0;
    for (int i=0; i<N; ++i) {
        if (i == 0) {
            ++count;
            cursor = B[i];
        } else {
            if (A[i] > cursor) {
                ++count;
                cursor = B[i];
            }
        }
    }
    return count;
}
