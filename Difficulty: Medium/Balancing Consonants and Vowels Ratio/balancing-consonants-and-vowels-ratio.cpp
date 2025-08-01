class Solution {
  public:
   bool isVowel(char &ch){
      return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
  }
    int countBalanced(vector<string>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        int preSum=0;
        for(string &str:arr){
        int vowel=0,consonants=0;
            for(char &ch:str){
                if(isVowel(ch))vowel++;
                else consonants++;
            }
            preSum+=vowel-consonants;
            if(mp.find(preSum)!=mp.end())count+=mp[preSum];
            mp[preSum]++;
        }
        return count;
    }
};