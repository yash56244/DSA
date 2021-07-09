// O(nlogn) using DnC
class Solution {
public:
    int maxArea;
    int findMin(vector<int>& heights, int l, int h){
        int Min = INT_MAX, idx = -1;
        for(int i = l; i <= h; i++){
            if(heights[i] < Min){
                Min = heights[i];
                idx = i;
            }
        }
        return idx;
    }
    void rec(vector<int>& heights, int l, int h){
        if(l == h){
            maxArea =  max(maxArea, heights[l]);
        }else{
            int minIndex = findMin(heights, l, h);
            maxArea = max(maxArea, heights[minIndex] * (h - l + 1));
            if(minIndex != l)
                rec(heights, l, minIndex - 1);
            if(minIndex != h)
                rec(heights, minIndex + 1, h);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        maxArea = 0;
        rec(heights, 0, heights.size() - 1);
        return maxArea;
    }
};
// O(n) using stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0, n = heights.size();
        for(int i = 0; i < n; i++){
            while(!s.empty() && heights[s.top()] > heights[i]){
                int t = s.top();
                s.pop();
                maxArea = max(maxArea, heights[t] * (s.empty() ? i : i - s.top() - 1));
                cout<<heights[t]<<" "<<(s.empty() ? i : i - s.top() - 1)<<endl;
            }
            s.push(i);
        }
        while(!s.empty()){
            int t = s.top();
            s.pop();
            maxArea = max(maxArea, heights[t] * (s.empty() ? n : n - s.top() - 1));
            cout<<heights[t]<<" "<<(s.empty() ? n : n - s.top() - 1)<<endl;
        }
        return maxArea;
    }
};
