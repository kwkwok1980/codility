struct Node {
    int A_ = 0;
    int C_ = 0;
    int G_ = 0;
    int T_ = 0;
};

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    std::vector<Node> node_list{};
    Node node{};
    for (char c : S) {
        if (c == 'A') ++node.A_;
        else if (c == 'C') ++node.C_;
        else if (c == 'G') ++node.G_;
        else if (c == 'T') ++node.T_;
        node_list.emplace_back(node);
    }

    int N = P.size();
    std::vector<int> result_list(N, 0);
    for (int i=0; i<N; ++i) {
        int start = P[i];
        int end = Q[i];
        if (start == 0) {
            node = node_list[end];
        } else {
            Node& node_start = node_list[start-1];
            Node& node_end = node_list[end];
            node.A_ = node_end.A_ - node_start.A_;
            node.C_ = node_end.C_ - node_start.C_;
            node.G_ = node_end.G_ - node_start.G_;
            node.T_ = node_end.T_ - node_start.T_;
        }
        if (node.A_ > 0) result_list[i] = 1;
        else if (node.C_ > 0) result_list[i] = 2;
        else if (node.G_ > 0) result_list[i] = 3;
        else if (node.T_ > 0) result_list[i] = 4;
    }
    return result_list;
}
