int equilibriumPoint(long long A[], int n) {
	int total = accumulate(A, A + n, 0);
	int right = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (right == total - (A[i] + right)) {
		    return i + 1;
		}
		right += A[i];
	}
	return -1;
}
