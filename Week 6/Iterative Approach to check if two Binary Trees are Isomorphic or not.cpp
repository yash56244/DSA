bool isIsomorphic(Node* root1, Node* root2){
	if(root1 == NULL && root2 == NULL){
		return true;
	}
	if(root1 == NULL || root2 == NULL){
		return false;
	}
	queue<Node*>q1, q2;
	q1.push(root1);
	q2.push(root2);
	vector<int> v;
	unordered_map<int, int> mp;
	while(!q1.empty() && !q2.empty()){
		if(q1.size() != q2.size()){
			return false;
		}
		int size = q1.size();
		v.clear();
		mp.clear();
		while(size--){
			Node* temp1 = q1.front();
            Node* temp2 = q2.front();
            q1.pop();
            q2.pop();
            mp[temp1->data]++;
            v.push_back(temp2->data);
            if (temp1->left)
                q1.push(temp1->left);
 
            if (temp1->right)
                q1.push(temp1->right);
 
            if (temp2->left)
                q2.push(temp2->left);
 
            if (temp2->right)
                q2.push(temp2->right);
		}
		for(auto e : v){
			if (mp.find(e) == mp.end())
                return false;
 
            else {
                mp[i]--;
                if (mp[e] < 0)
                    return false;
                else if (mp[e] == 0)
                    mp.erase(e);
            }
		}
		if(mp.size() != 0){
			return false;
		}
	}
	return true;
}
