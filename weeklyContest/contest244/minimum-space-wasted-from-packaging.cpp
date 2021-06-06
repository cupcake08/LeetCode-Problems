//problem link -> https://leetcode.com/problems/minimum-space-wasted-from-packaging/
//idea -> https://leetcode.com/problems/minimum-space-wasted-from-packaging/discuss/1253948/Python-3-Binary-Search-%2B-pre-sum-explanation-with-picture.
/*
Idea:
Sort packages A,
Sort boxes[i],
for each box in box[i] from small to big,
find out how many packages in A it can covers,
using binary search.

Assume we alreay cover i packages,
now we find that we can cover j packages,
the space we are using (j - i) * box size.
We accumulate the space size.

No need for prefix sum at all,
this takes extra unnecessay space.
The final result is total space - box size sum,
we just need to calculate the box size sum once,
and that's enough.


Complexity
Time O(sort(A) + sort(B) + BlogA)
Space O(sort)
*/
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
