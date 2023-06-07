/* Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.*/
 /* example : Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)    */

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        while(a>0 or b>0 or c>0){
            //to calculate right-most bits
            int bit_a= a&1;
            int bit_b= b&1;
            int bit_c= c&1;
            if(bit_c==0){
                flips=flips+(bit_a + bit_b);
            }
            else{
                if(bit_a==0 and bit_b==0){
                    flips+=1;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;

        }
        return flips;
    }
};
