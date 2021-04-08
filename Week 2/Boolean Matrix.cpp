void booleanMatrix(vector<vector<int> > &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    int row[r], col[c];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(matrix[i][j]){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(row[i] || col[j]){
                matrix[i][j] = 1;
            }
        }
    }
}
// Space Optimised.
void booleanMatrix(vector<vector<int> > &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    bool row = false, col = false;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
        	if(i == 0 && matrix[i][j]){
        		row = true;
			}
			if(j == 0 && matrix[i][j]){
				col = true;
			}
            if(matrix[i][j]){
            	matrix[0][j] = 1;
            	matrix[i][0] = 1;
            }
        }
    }
    for(int i = 1; i < r; i++){
    	for(int j = 1; j < c; j++){
    		if(matrix[0][j] || matrix[i][0]){
    			matrix[i][j] = 1;
			}
		}
	}
	if(row){
		for(int j = 0; j < c; j++){
			matrix[0][j] = 1;
		}
	}
	if(col){
		for(int i = 0; i < r; i++){
			matrix[i][0] = 1;
		}
	}
}
