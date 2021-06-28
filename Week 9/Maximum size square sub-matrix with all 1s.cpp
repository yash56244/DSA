using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, m;
	    cin>>n>>m;
	    int arr[n][m];
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            cin>>arr[i][j];
	        }
	    }
	    int dp[n][m];
	    for(int j = 0; j < m; j++){
	        dp[n-1][j] = arr[n-1][j];
	    }
	    for(int i = 0; i < n; i++){
	        dp[i][m-1] = arr[i][m-1];
	    }
	    for(int i = n - 2; i >= 0; i--){
	        for(int j = m - 2; j >= 0; j--){
	            if(arr[i][j] == 0){
	                dp[i][j] = 0;
	            }else{
	                dp[i][j] = 1 + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
	            }
	        }
	    }
	    int res = INT_MIN;
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            res = max(res, dp[i][j]);
	        }
	    }
	    cout<<res<<endl;
	}
	return 0;
}
