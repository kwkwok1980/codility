#include <unordered_map>
#include <limits>
#include <algorithm>
#include <stack>
#include <string>
#include <ostream>

int solution(std::string& S) {
    std::stack<char> stack{};
    for (char c : S) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            if (stack.top() == '(') {
                stack.pop();
            } else {
                return 0;
            }
        }
    }
    if (stack.empty()) {
        return 1;
    } else {
        return 0;
    }
}
