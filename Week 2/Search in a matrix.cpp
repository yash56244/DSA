int matSearch (vector <vector <int>> &mat, int n, int m, int x)
	{
	    int small = mat[0][0], large = mat[n-1][m-1];
	    if(x < small || x > large){
	        return 0;
	    }
	    int i = 0, j = m - 1;
	    while(i < n && j >= 0){
	        if(mat[i][j] == x){
	            return 1;
	        }
	        if(mat[i][j] > x){
	            j--;
	        }else{
	            i++;
	        }
	    }
	    return 0;
	}
