// BinaryGap

int solution(int N) {
    int last = -1;
    int size = sizeof(N) * 8;
    int result = 0;
    for (int i=0; i<size; ++i) {
        if ((1 << i) & N) {
            if (last == -1) {
                last = i;
            } else {
                result = std::max(result, i - last - 1);
                last = i;
            }
        }
    }
    return result;
}
