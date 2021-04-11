// Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. 
// The rightmost element is always a leader. 
// Function to find the leaders in an array of size n
vector<int> leaders(int arr[], int n){
    vector<int> vect;
    int max_from_right =  arr[n-1];
    vect.push_back(arr[n - 1]);
    for (int i = n-2; i >= 0; i--) 
    {
        if (max_from_right <= arr[i]) 
        {            
            max_from_right = arr[i]; 
            vect.push_back(arr[i]);
        } 
    }     
    reverse(vect.begin(), vect.end());
    return vect;
}
