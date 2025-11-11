class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        int m=s1.size(),n=s2.size();
        int t[m+1][n+1];
        memset(t,0,sizeof(t));
        for(int i =1 ; i < m+1; i++){
            for(int j =1; j < n+1; j++){
                if(s1[i-1] == s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        return (m+n)-t[m][n];
    }
};