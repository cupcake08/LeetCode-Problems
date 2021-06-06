//problem link -> https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
//Discuss -> https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/discuss/1253874/C%2B%2B-Solution-sliding-window.-O(N)
/*
Idea
For the 1st operation, we can simply do s += s to append the whole string to the end.
then we make two different string with the same length by 01 and 10 alternative. for example: s = 11100
s = 1110011100
s1= 1010101010
s2= 0101010101
finally, use sliding window（size n）to compare s to both s1 and s2.
why we can double s to fullfil the first operation, let's look at the same example s = 11100:`
double s: 1110011100
size n window: |11100|11100 ==> 1|11001|1100 ==> 11|10011|100 and so on, when we move one step of the sliding window, it is the same to append 1 more element from beginning.
*/
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;
        string s1, s2;
        
        for(int i = 0; i < s.size(); i++) {
            s1 += i & 1 ? '0' : '1';
            s2 += i & 1 ? '1' : '0';
        }
        int ans1 = 0, ans2 = 0, ans = INT_MAX;
        for(int i = 0; i < s.size(); i++) {
            if(s1[i] != s[i]) ++ans1;
            if(s2[i] != s[i]) ++ans2;
            if(i >= n) { //the most left element is outside of sliding window, we need to subtract the ans if we did `flip` before.
                if(s1[i - n] != s[i - n]) --ans1;
                if(s2[i - n] != s[i - n]) --ans2;
            }
            if(i >= n - 1)
                ans = min({ans1, ans2, ans});
        }
        return ans;
    }
};
