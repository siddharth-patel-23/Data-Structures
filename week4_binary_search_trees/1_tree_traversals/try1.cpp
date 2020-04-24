#include <bits/stdc++.h>
using namespace std;

struct st
{
    int k, l, r;
};

struct Node
{
    int key;
    Node* left, *right;
    Node(int key)
    {
        this->key=key;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(vector<st> v, int i)
{
    if (i==-1) return NULL;
    Node* root=new Node(v[i].k);
    root->left=buildTree(v, v[i].l);
    root->right=buildTree(v, v[i].r);
    return root;
}

void inorder(Node* root)
{
    Node* tmp=root;
    if (root==NULL) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
    root=tmp;
}

void preorder(Node* root)
{
    Node* tmp=root;
    if (root==NULL) return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
    root=tmp;
}

void postorder(Node* root)
{
    Node* tmp=root;
    if (root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
    root=tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i;
	cin>>n;
	vector<st> v(n); 
	for (i=0;i<n;i++)
	{
	    cin>>v[i].k>>v[i].l>>v[i].r;
	}
	Node* root=buildTree(v, 0);
	inorder(root);
	cout<<"\n";
	preorder(root);
	cout<<"\n";
	postorder(root);
// 	Node *root=new Node(v[0].k);
// 	if (v[0].l!=-1)
// 	root->left=v[v[0].l].k;
// 	if (v[0].r!=-1)
// 	root->right=v[v[0].r].k;
	
	return 0;
}
