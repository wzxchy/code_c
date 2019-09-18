#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<int> nl;
    vector<int> nr;
    int n;
    void backtrack(string& s,int d,string str,int n1,int n2)
    {
        if(d==s.length())
        {
            if(n1==n2 && n1==n)
            {
                ans.push_back(str);
                return ;
            }
        }
        if(s[d]=='(')
        {
            if(n1<n) backtrack(s,d+1,str+s[d],n1+1,n2);
            if(nl[d+1]+n1>=n) backtrack(s,d+1,str,n1,n2);
        }
        else if(s[d]==')')
        {
            if(n2<n1) backtrack(s,d+1,str+s[d],n1,n2+1);
            if(nr[d+1]+n2>=n) backtrack(s,d+1,str,n1,n2);
        }
        else
        {
            backtrack(s,d+1,str+s[d],n1,n2);
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        int len=s.length();
        int cnt=0;
        n=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')
            {
                cnt++;
            }
            else if(s[i]==')')
            {
                if(cnt>0)
                {
                    n++;
                    cnt--;
                }
            }
        }
        cout<<n<<endl;
        nl.resize(len+1);
        nr.resize(len+1);
        nl[len]=0;
        nr[len]=0;
        for(int i=len-1;i>=0;i--)
        {
            nl[i]=nl[i+1];
            nr[i]=nr[i+1];
            if(s[i]=='(')   nl[i]++;
            if(s[i]==')')   nr[i]++;
        }
        string str;
        backtrack(s,0,str,0,0);
        if(ans.size()==0) return ans;
        sort(ans.begin(),ans.end());
        vector<string> ans1;
        ans1.push_back(ans[0]);
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i]!=ans[i-1]) ans1.push_back(ans[i]);
        }
        for(int i=0;i<ans1.size();i++)
        {
            cout<<ans1[i]<<endl;
        }
        return ans1;
    }
};
int main()
{
   Solution s;
   s.removeInvalidParentheses(")(");

    return 0;
}
/*

*/
