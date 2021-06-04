void convertTree(Node* root){
	if(!root || (!root->left && !root->right)){
		return;
	}
	convertTree(root->left);
	convertTree(root->right);
	int left = 0, right = 0;
	if(root->left){
		left = root->left->data;
	}
	if(root->right){
		right = root->right->data;
	}
	int diff = left + right - root->data;
	if(diff > 0){
		root->data += diff;
	}else if(diff < 0){
		increment(root, -diff);
	}
}
void increment(Node* root, int diff){
	if(root->left){
		root->left->data += diff;
		increment(root->left, diff);
	}else if(root->right){
		root->right->data += diff;
		increment(root->right, diff);
	}
}
