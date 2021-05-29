vector<int> activitySelection(vector<int> start, vector<int> end, int N) {
    vector<int> result; //store chosen jobs
    if (N < 1 || N > 2102) {
        result;
    }
    
    int previouslySelected = 0; //last selected job in start it is always first job
    result.push_back(0);
    for (int i = 1; i < N; ++i) {
        if (end[previouslySelected] <= start[i]) {
            result.push_back(i);
            previouslySelected = i;
        }
    }
    return result;
}
