#include <unordered_map>
#include <limits>
#include <algorithm>
#include <stack>
#include <string>
#include <ostream>

int solution(std::string& S) {
    std::stack<char> stack{};
    for (char c : S) {
        if (c == '{' || c == '[' || c == '(') {
            stack.push(c);
        } else if (c == '}') {
            if (stack.top() == '{') {
                stack.pop();
            } else {
                return 0;
            }
        } else if (c == ']') {
            if (stack.top() == '[') {
                stack.pop();
            } else {
                return 0;
            }
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







play_arrow

play_arrow

play_arrow

check
06:24:21

06:29:58

Away from Codility tab
