bool match(char a, char b){
    if(a == '{' && b == '}'){
        return true;
    }
    if(a == '(' && b == ')'){
        return true;
    }
    if(a == '[' && b == ']'){
        return true;
    }
    return false;
}
bool ispar(string x)
{
    stack<char> s;
    for(int i = 0; i < x.length(); i++){
        if(!s.empty()){
            if(match(s.top(), x[i])){
                s.pop();
                continue;
            }
        }
        s.push(x[i]);
    }
    return s.empty();
}
