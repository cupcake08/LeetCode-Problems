//problem link -> https://leetcode.com/problems/minimum-space-wasted-from-packaging/
//idea -> https://leetcode.com/problems/minimum-space-wasted-from-packaging/discuss/1253948/Python-3-Binary-Search-%2B-pre-sum-explanation-with-picture.
int minWastedSpace(vector<int>& packs, vector<vector<int>>& suppliers) {
    sort(begin(packs), end(packs));
    long sum_packs = accumulate(begin(packs), end(packs), 0l), res = LONG_MAX;
    for (auto &boxes : suppliers ) {
        sort(begin(boxes), end(boxes));
        if (boxes.back() >= packs.back()) {
            long prev = 0, cur = 0, total = 0;
            for (auto b : boxes) {
                cur = upper_bound(begin(packs) + prev, end(packs), b) - begin(packs);
                total += b * (cur - prev);
                prev = cur;
            }
            res = min(res, total - sum_packs);
        }
    }
    return res == LONG_MAX ? -1 : res % 1000000007;
}
