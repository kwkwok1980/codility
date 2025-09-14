vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    int N = P.size();
    std::vector<int> result_list(N, 0);
    std::unordered_map<char, int> impact_factor_map{{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
    for (int i=0; i<N; ++i) {
        int start = P[i];
        int end = Q[i];
        int result = 10;
        for (int j=start; j<=end; ++j){
            char c = S[j];
            int impact_factor = impact_factor_map[c];            
            if (impact_factor == 1) {
                result = 1;
                break;
            } else {
                result = std::min(result, impact_factor);
            }
        }
        result_list[i] = result;
    }
    return result_list;
}
