vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) 
{
    int sri = 0, sci = 0;
    vector<int> ans;
    while(sri < r && sci < c){
        for(int i = sci; i < c; i++){
            ans.push_back(arr[sri][i]);
        }
        sri++;
        for(int i = sri; i < r; i++){
            ans.push_back(arr[i][c - 1]);
        }
        c--;
        if(sri < r){
            for(int i = c - 1; i >= sci; i--){
                ans.push_back(arr[r - 1][i]);
            }
            r--;
        }
        if(sci < c){
            for(int i = r - 1; i>= sri; i--){
                ans.push_back(arr[i][sci]);
            }
            sci++;
        }
    }
    return ans;
}
