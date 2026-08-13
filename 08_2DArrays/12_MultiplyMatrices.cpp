#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    vector<vector<int>> multiplyMatrices(vector<vector<int>> &a, vector<vector<int>> &b) {
        int n = a.size();
        vector<vector<int>> res(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // res[i][j] = summation(k-> 0 to n-1) a[i][k]*b[k][j];
                for(int k=0;k<n;k++){
                    res[i][j] += a[i][k]*b[k][j];
                }
            }
        }
        return res;
    }
};