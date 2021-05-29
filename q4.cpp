vector<int> candyStore(int N, int K, vector<int> candies) {
    vector<int> min_max_res;
    if (N < 1 || N > 1000000 || K < 1000000) {
        return min_max_res;
    }
    min_max_res.push_back(0);
    min_max_res.push_back(0);

    int max_index = N;
    for (int i = 0; i < max_index; ++i) {
        min_max_res[0] += candies[i];
        max_index -= K;
    }
    int min_index = 0;
    for (int i = N - 1; i >= min_index; --i) {
        min_max_res[1] += candies[i];
        min_index += K;

    }
    return min_max_res;
}
