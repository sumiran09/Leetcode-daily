/*
Maximize the Confusion of an Exam
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. 
He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
You are given a string answerKey, where answerKey[i] is the original answer to the ith question. 
In addition, you are given an integer k, the maximum number of times you may perform the following operation:
Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

Example 1:
Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.
*/
//approach: sliding window 
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        unordered_map<char,int> mpp;// to store count of T and F in the current window 
        int left=0;
        int max_size=k;
        for(int i=0;i<k;i++){
            mpp[answerKey[i]]++;   
        }
        for(int right=k;right<answerKey.length();right++){
            mpp[answerKey[right]]++;
            while(min(mpp['T'],mpp['F'])>k){
                mpp[answerKey[left]]--;
                left++;
            }
            max_size=max(max_size,right-left+1);
        }
        return max_size;
    }
};
