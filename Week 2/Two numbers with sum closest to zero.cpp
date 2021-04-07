int closestToZero(int arr[], int n)
{
	sort (arr, arr + n); // sorting the array
	int i = 0, j = n - 1;
	int sum = arr[i] + arr[j]; // initializing sum
	int diff = abs (sum); // initializing the result

	while (i < j)
	{
	    // if we have zero sum, there's no result better. Hence, we return
		if (arr[i] + arr[j] == 0) 
			return 0;
			
		// if we get a better result, we update the difference
		if (abs (arr[i] + arr[j]) < abs (diff))
		{
			diff = (arr[i] + arr[j]);
			sum = arr[i] + arr[j];
		}
		else if(abs (arr[i] + arr[j]) == abs (diff))
        {
            sum=max(sum,arr[i]+arr[j]);
        }
        
        // if the current sum is greater than zero, we search for a smaller sum
		if (arr[i] + arr[j] > 0)
			j--;
		// else, we search for a larger sum
		else
			i++;
	}
	return sum;
}
