#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

node* root=NULL;

bool search(node* root,int key){
	if(root!=NULL){
		if(root->data==key)
			return true;
		if(root->data>key)
			return search(root->left,key);
		if(root->data<key)
			return search(root->right,key);
	}
	return false;
}

node* insertnode(node* root,int d){
	node* temp=new node();
	temp->data=d;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL||root->data==d)
		return temp;
	else if(d<root->data)
		root->left=insertnode(root->left,d);
	else if(d>root->data)
		root->right=insertnode(root->right,d);
}

void inordertraversal(node* root){
	if(root==NULL)
		return;
	inordertraversal(root->left);
	cout<<root->data<<"  ";
	inordertraversal(root->right);
}

void preordertraversal(node* root){
	if(root==NULL)
		return;
	cout<<root->data<<"  ";
	preordertraversal(root->left);
	preordertraversal(root->right);
}

void postordertraversal(node* root){
	if(root==NULL)
		return;
	postordertraversal(root->left);
	postordertraversal(root->right);
	cout<<root->data<<"  ";
}

void levelordertraversal(node* root){
	queue<node*> q;
	if(root!=NULL){
		q.push(root);
		while(!q.empty()){
			cout<<q.front()->data<<" ";
			if(q.front()->left!=NULL)
				q.push(q.front()->left);
			if(q.front()->right!=NULL)
				q.push(q.front()->right);
			q.pop();
		}
	}
	cout<<endl;
}

int height(node* root){
	if(root==NULL)
		return -1;
	return max(height(root->left),height(root->right))+1;
}

int countofleaf(node* root){
	if(root==NULL)
		return 0;
	if(root->left==NULL&&root->right==NULL){
		return 1;
	}
		return countofleaf(root->left)+countofleaf(root->right);
}

int countofnonleaf(node* root){
	if(root==NULL||(root->left==NULL&&root->right==NULL))
		return 0;
	return 1+countofnonleaf(root->left)+countofnonleaf(root->right);
}

void mirror(node* root){
	if(root==NULL)
		return;
	node* temp=root->left;
	root->left=root->right;
	root->right=temp;
	mirror(root->left);
	mirror(root->right);
}

int main(){
	cout<<"Enter first node in bst"<<endl;
	int f;
	cin>>f;
	root=insertnode(root,f);
	
	bool flag=true;
	int d;
	int ch;
	while(flag){
		
		cout<<"Enter choise:"<<endl;

		cout<< "1.insert \n"
			"2.preorder \n"
			"3.inorder \n"
			"4.postorder \n"
			"5.level order \n"
			"6.search \n"
			"7.height \n"
			"8.count leaf \n"
			"9.count non leaf \n"
			"10.mirror \n"
			"11.quit \n"<<endl;
		
		
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter data: ";
				cin>>d;
				insertnode(root,d);
				break;
			case 2:
				preordertraversal(root);
				cout<<endl;
				break;
			case 3:
				inordertraversal(root);
				cout<<endl;
				break;
			case 4:
				postordertraversal(root);
				cout<<endl;
				break;
			case 5:
				levelordertraversal(root);
				break;
			case 6:
				cout<<"Enter key to search for"<<endl;
				cin>>d;
				if(search(root,d))
					cout<<"Found"<<endl;
				else cout<<"Not found"<<endl;
				break;
				case 7:
				cout<<"Height is: "<<height(root)<<endl;
				break;
			case 8:
				cout<<"Leaf count is: "<<countofleaf(root)<<endl;
				break;
			case 9:
				cout<<"Non leaf count is: "<<countofnonleaf(root)<<endl;
				break;
			case 10:
				cout<<"After mirroring inorder traversal: "<<endl;
				mirror(root);
				inordertraversal(root);
				cout<<endl;
				break;
			case 11:
				flag=false;
				break;
			default:
				cout<<"Invalid input"<<endl;
				return 0;
		}
	}


	return 0;
}
