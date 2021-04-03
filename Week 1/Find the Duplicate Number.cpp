#include<bits/stdc++.h>

using namespace std;

int findDuplicate(int nums[]) {
    	int slow = nums[0];
        int fast = nums[0];
        do {
          slow = nums[slow];
          fast = nums[nums[fast]];
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast) {
          slow = nums[slow];
          fast = nums[fast];
        }
        return fast;
}

int main(){
	int arr[] = {3,1,3,4,2};
	cout<<findDuplicate(arr);
	return 0;
}
