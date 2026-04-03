/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int binaryGuess(int l, int r) {
        int m = (r - l)/2 + l;
        int g = guess(m);
        if(g == 0) return m;
        if(g < 1) return binaryGuess(l, m-1);
        else return binaryGuess(m+1, r);
    }
    int guessNumber(int n) {
        return binaryGuess(1, n);
    }
};