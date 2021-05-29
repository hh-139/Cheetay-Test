int *spirallyTraverse(int R, int C, int **matrix) {
    if (R < 1 || C < 1) {
        return NULL;
    }
    int remainingTraverses = R * C;
    int cur_direction = 0; //0: Left, 1:Down, 2:Right, 3:Up

    int *result = new int[R * C];

    int looped = -1; // increase depth in spiral

    int ri = 0, ci = -1; //current indexes
    while (remainingTraverses > 0) {
        if (cur_direction == 0) {
            ++looped;
            ++ci;
            for (int i = 0; i < C - looped; ++i, ++ci) {
                result[(R * C) - remainingTraverses] = matrix[ri][ci];
                --remainingTraverses;
            }
            --ci;
            ++looped;
        }
        if (cur_direction == 1) {
            ++ri;
            for (int i = 0; i < R - looped; ++i, ++ri) {
                result[(R * C) - remainingTraverses] = matrix[ri][ci];
                --remainingTraverses;
            }
            --ri;
        }
        if (cur_direction == 2) {
            --ci;
            for (int i = 0; i < C - looped; ++i, --ci) {
                result[(R * C) - remainingTraverses] = matrix[ri][ci];
                --remainingTraverses;
            }
            ++ci;
        }
        if (cur_direction == 3) {
            --ri;
            for (int i = 0; i < R - looped - 1; ++i, --ri) { // for last pass in current depth subtract -1
                result[(R * C) - remainingTraverses] = matrix[ri][ci];
                --remainingTraverses;
            }
            ++ri;
        }
        cur_direction = (cur_direction + 1) % 4; // next direction calculation
    }

    return result;
}
