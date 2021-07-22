#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
81 / 81 test cases passed, but took too long.

Instead of doing a recursion approach with dp,
think simpler and preprocess. (thought about this first but didn't do this because of time complexity)

Next time: try different methods instead of trying to fully optimize one.
*/

class Solution {
private:
    static const int maxN = 2000;
    string str;
    int n;
    
    // 0 not set, 1 no, 2 yes - memoize isPalindrome and canSplit
    int isp[maxN][maxN]; 
    int cnp[maxN][maxN][3]; // 0 is 1, 1 is 2, 2 is 3
    
public:
    // O((start+end)/2)
    bool isPalindrome(int start, int end){
        if(isp[start][end] != 0){
            return isp[start][end] == 2;
        }
        
        for(int i = start; i < (start + end + 1)/2; i++){
            if(str[i] != str[end-(i-start)]){
                isp[start][end] = 1;
                return false;
            }    
        }
        
        isp[start][end] = 2;
        return true;
    }
    
    bool checkPartitioning(string s) {
        str = s;
        n = s.size();
        
        // cout << "checking: " << s << '\n';
        return canSplit(0, n-1, 3);   
    }
    
    // can split inclusive bounds - string into p palindromes
    bool canSplit(int start, int end, int p){
        if(cnp[start][end][p-1] != 0){
            return cnp[start][end][p-1] == 2;
        }
        
        if(p <= 1) {
            return isPalindrome(start, end);
        }
        
        // find all palindromes - O(n^2 / 2)
        for(int j = start; j <= end; j++){
            if(isPalindrome(start, j)){
                if(canSplit(j+1, n-1, p-1)){
                    cnp[start][end][p-1] = 2;
                    return true;
                }
            }
        }
        
        cnp[start][end][p-1] = 1;
        return false;
    }
};