#include<iostream>
using namespace std;
class tree{
	public:
	tree *left;
	tree *right;
	int data;
	tree(){
		left=NULL;
		right=NULL;
		data=0;
	}
	tree(int v){
		left=NULL;
		right=NULL;
		data=v;
	}
};
class AVL{
	public:
		tree *root;
	 AVL(){
	 	root=NULL;
	 }
	 bool isempty(){
	 	if(root==NULL){
	 		return 1;
		}
		else{
		 	return 0;
		 }
	 }
	 int height(tree *root){
	 	if(root==NULL)
	 	 return -1;
	 	else{
	 	 	int lh=height(root->left);
	 	 	int rh=height(root->right);
	 	 	
	 	 	if(lh>rh){
	 	 		return(lh+1);
			}
			else{
				return(rh+1);
			}
		}
	 }
	 int getbalance(tree *node){
	 	if(node==NULL){
	 		return -1;
		 }
		 return (height(node->left)-height(node->right));
	 }
	tree * insert(tree *root,int val){
			if(root==NULL){
				return new tree(val);
			}
			if(val < root->data){
				root->left = insert(root->left,val);
				
			}
			else if(val > root->data){
				root->right = insert(root->right,val);
			}
			return root;
			int h=height(root);
			h = 1 + max(height(root->left),
                        height(root->right));

		int balance = getbalance(root);
		// Left Left Case
		if (balance > 1 && val < root->left->data)
		    return rightrotate(root);
		
		// Right Right Case
		if (balance < -1 && val > root->right->data)
		    return leftrotate(root);
		
		// Left Right Case
		if (balance > 1 && val > root->left->data)
		{
		    root->left = leftrotate(root->left);
		    return rightrotate(root);
		}
		
		// Right Left Case
		if (balance < -1 && val < root->right->data)
		{
		    root->right = rightrotate(root->right);
		    return leftrotate(root);
		}

		return root;
	}
	 tree *leftrotate(tree *x){
	 	tree *n1=x->right;
	 	tree *n2=n1->left;
	 	
	 	//rotation
	 	n1->left=x;
	 	x->right=n2;
	 	
	 	int h=height(x);
		 h = max(height(x->left),   
                    height(x->right)) + 1;
    	h=height(n1) ;
		h= max(height(n1->left),
                    height(n1->right)) + 1;
 
   			 return n1;
	 }
	 tree *rightrotate(tree *y){
	 	tree *n1=y->left;
	 	tree *n2=n1->right;
	 	
	 	//rotation
	 	n1->right=y;
	 	y->left=n2;
	 	
	 	int h=height(y);
		 h = max(height(y->left),
                    height(y->right)) + 1;
    	h=height(n1);
		h = max(height(n1->left),
                    height(n1->right)) + 1;
    	return n1;
	 }
	 void inorder(tree *root){
			if(root==NULL){
				return;
			}
			inorder(root->left);
			cout<<root->data<<" "<<height(root)<<endl;
		    inorder(root->right);
			return;
	}
	void preorder(tree *root){
			if(root==NULL){
				return;
			}
			cout<<root->data<<" "<<height(root)<<endl;
			preorder(root->left);
			preorder(root->right);
			return;
	}
};
int main(){
	tree *root=NULL;
	AVL obj;
	root=obj.insert(root,55);
	obj.insert(root,66);
	obj.insert(root,77);
	obj.insert(root,11);
	obj.insert(root,33);
	obj.insert(root,22);
	obj.insert(root,35);
	obj.insert(root,25);
	obj.insert(root,44);
	obj.insert(root,88);
	obj.insert(root,99);
	cout<<"Inorder\n";
	obj.inorder(root);
	cout<<"Preorder\n";
	obj.preorder(root);
}
