// Question Link - https://leetcode.com/problems/minimum-window-substring/
// Problem tag - Hash Table String Sliding Window
// The approach I have used is sliding window
// Expand the window until all the characters of the pattern are matching then 
// shrink it from the beginning until all the uncessary characters are exluded from the present window.
// calculate minimum for each valid window.

class Solution {
public:
    string minWindow(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        int mp1[256]={0};
        for(int i=0;i<m;i++)
        {
            mp1[t[i]]++;
        }
        int mp2[256]={0};
        int j=0;
        int s1=-1;
        int cnt=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mp2[s[i]]++;
            if(mp1[s[i]]!=0 && mp2[s[i]]<=mp1[s[i]])
            {
                cnt++;
            }
            if(cnt==m)
            {
                while(mp2[s[j]]>mp1[s[j]] or mp1[s[j]]==0)
                {
                    if(mp2[s[j]]>mp1[s[j]])
                    {
                        mp2[s[j]]-=1;
                    }
                    j++;
                }
                int len=i-j+1;
                if(len<mini)
                {
                    mini=i-j+1;
                    s1=j;
                }
            }
        }
        if(s1==-1)
        {
            return "";
        }
        return s.substr(s1,mini);
    }
};