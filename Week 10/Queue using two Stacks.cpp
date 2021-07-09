void StackQueue :: push(int x)
{
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
    if(s1.empty()){
        return -1;
    }
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    int t = s2.top();
    s2.pop();
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    return t;
}
