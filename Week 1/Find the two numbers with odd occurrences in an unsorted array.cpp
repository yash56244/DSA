#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    vector<int> twoOddNum(int nums[], int n)  
    {
        int xr = 0;
        for(int i = 0; i < n; i++){
            xr ^= nums[i];
        }
        vector<int> ans(2);
        int rt = xr & ~(xr - 1);
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] & rt){
                a ^= nums[i];
            }else{
                b ^= nums[i];
            }
        }
        ans[1] = min(a, b);
        ans[0] = max(a, b);
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int Arr[N];
        for(int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<int>ans=ob.twoOddNum(Arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
