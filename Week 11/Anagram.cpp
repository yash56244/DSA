bool isAnagram(string a, string b){
    
    // Your code here
    const int count=256;
    int arr[count]={0};
    bool flag=1;
    if(a.length()!=b.length())
    {
        return false;
    }
    else
    {
        for(int i=0;i<a.length();i++)
        {
            arr[a[i]]++;
            arr[b[i]]--;
        }
        for(int j=0;j<count;j++)
        {
            if(arr[j]!=0)
             return false;
        }
    }
    return true;
}
