#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>
#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cmath>
#include <sstream>

int solution(std::vector<int>& A) {
    int N = A.size();
    std::vector<int> odd_values(N, -1);
    std::vector<int> even_values(N, -1);
    int odd_count = 0;
    int even_count = 0;
    for (int i=0; i<N; ++i) {
        int a = A[i];
        if (a % 2 == 0) {
            ++even_count;
            even_values[i] = a;
        } else {
            ++odd_count;
            odd_values[i] = a;
        }
    }
    if (odd_count == N || odd_count == 0) {
        return N/2;
    }
    int odd_seperator = -1;
    for (int i=0; i<N; ++i) {
        if (odd_values[i] == -1) {
            odd_seperator = i;
            break;
        }
    }

    int even_seperator = -1;
    for (int i=0; i<N; ++i) {
        if (even_values[i] == -1) {
            even_seperator = i;
            break;
        }
    }

    int result = 0;

    std::vector<int> temp_values{};
    for (int i=odd_seperator; i<N; ++i){
        temp_values.push_back(odd_values[i]);
    }
    for (int i=0; i<odd_seperator; ++i){
        temp_values.push_back(odd_values[i]);
    }
    for (int i=0; i<N; ++i) {
        if (temp_values[i] != -1) {
            if (i+1<N) {
                if (temp_values[i+1] != -1) {
                    ++result;
                    ++i;
                }
            }
        }
    }

    temp_values.clear();
    for (int i=even_seperator; i<N; ++i){
        temp_values.push_back(even_values[i]);
    }
    for (int i=0; i<even_seperator; ++i){
        temp_values.push_back(even_values[i]);
    }
    for (int i=0; i<N; ++i) {
        if (temp_values[i] != -1) {
            if (i+1<N) {
                if (temp_values[i+1] != -1) {
                    ++result;
                    ++i;
                }
            }
        }
    }

    return result;
}

int main() {
    
    {
        std::vector<int> values{5, 7, 9, 6, 3};
        std::cout << solution(values) << std::endl;
    }

    {
        std::vector<int> values{1, 1, 1, 1, 1, 1};
        std::cout << solution(values) << std::endl;
    }

    {
        std::vector<int> values{1, 1, 1, 0, 1};
        std::cout << solution(values) << std::endl;
    }


}

