int solution(int X, int Y, int D) {
    int Z = Y - X;
    int result = Z / D + ( Z % D > 0 ? 1 : 0);
    return result;
}
