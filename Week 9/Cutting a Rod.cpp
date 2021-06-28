int cutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   for (int i = 1; i<=n; i++)
   {
       val[i] = INT_MIN;
       for (int j = 0; j < i; j++)
			val[i] = max(val[i], price[j] + val[i-j-1]);
   }
 
   return val[n];
}
