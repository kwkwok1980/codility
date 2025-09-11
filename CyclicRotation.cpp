vector<int> solution(vector<int>& values, int K) {
    int N = values.size();
    K = K % N;
    std::vector<int> temp{};
    temp.reserve(N);
    for (int i=N-K; i<N; ++i) {
        temp.push_back(values[i]);
    }
    for (int i=0; i<N-K; ++i) {
        temp.push_back(values[i]);
    }
    return temp;
}
