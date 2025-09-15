
int solution(std::vector<int>& values) {
    std::vector<int> results1{};
    std::vector<int> results2{};
    std::vector<int> results3{};
    std::vector<int> results4{};
    
    int pos_count = 0;
    int neg_count = 0;
    int result = std::numeric_limits<int>::min();

    for (int value : values) {
        if (value >= 0) {
            ++pos_count;
            if (results1.size() < 3) {
                auto it = std::lower_bound(results1.begin(), results1.end(), value, std::greater<int>{});
                results1.insert(it, value);
            } else {
                if (value > results1.back()) {
                    results1.pop_back();
                    auto it = std::lower_bound(results1.begin(), results1.end(), value, std::greater<int>{});
                    results1.insert(it, value);
                }
            }

            if (results2.size() < 3) {
                auto it = std::lower_bound(results2.begin(), results2.end(), value, std::less<int>{});
                results2.insert(it, value);
            } else {
                if (value < results2.back()) {
                    results2.pop_back();
                    auto it = std::lower_bound(results2.begin(), results2.end(), value, std::greater<int>{});
                    results2.insert(it, value);
                }
            }
            
            
        } else {
            ++ neg_count;
            if (results3.size() < 3) {
                auto it = std::lower_bound(results3.begin(), results3.end(), value, std::less<int>{});
                results3.insert(it, value);
            } else {
                if (value < results3.back()) {
                    results3.pop_back();
                    auto it = std::lower_bound(results3.begin(), results3.end(), value, std::less<int>{});
                    results3.insert(it, value);
                }
            }

            if (results4.size() < 3) {
                auto it = std::lower_bound(results4.begin(), results4.end(), value, std::greater<int>{});
                results4.insert(it, value);
            } else {
                if (value > results4.back()) {
                    results4.pop_back();
                    auto it = std::lower_bound(results4.begin(), results4.end(), value, std::greater<int>{});
                    results4.insert(it, value);
                }
            }
        }
    }
    
    if (pos_count >= 1) {
        if (neg_count >= 2) {
            result = std::max(result, results1[0] * results3[0] * results3[1]);    
        }
    }

    if (pos_count >= 2) {
        if (neg_count >= 1) {
            result = std::max(result, results2[0] * results2[1] * results4[0]);
        }
    }

    if (pos_count >= 3) {
        result = std::max(result, results1[0] * results1[1] * results1[2]);
    }
    
    if (neg_count >= 1) {
        if (pos_count >= 2) {
            result = std::max(result, results4[0] * results2[0] * results2[1]);
        }
    }

    if (neg_count >= 2) {
        if (pos_count >= 1) {
            result = std::max(result, results3[0] * results3[1] * results1[0]);
        }
    }

    if (neg_count >= 3) {
        result = std::max(result, results4[0] * results4[1] * results4[2]);
    }
    return result;
}
