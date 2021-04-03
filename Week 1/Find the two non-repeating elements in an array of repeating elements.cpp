#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size();
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
        ans[0] = min(a, b);
        ans[1] = max(a, b);
        return ans;
    }
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
