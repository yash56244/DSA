string complement(string &s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '0'){
			s[i] = '1';
		}else{
			s[i] = '0';
		}
	}
	return s;
}
string getLevel(int level){
	if(level == 0){
		return "0";
	}
	string upperLevel = getLevel(level - 1);
	return upperLevel + complement(upperLevel);
}
