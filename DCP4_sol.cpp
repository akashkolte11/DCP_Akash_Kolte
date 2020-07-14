#include <bits/stdc++.h>
using namespace std;

#define MARKER -1

struct node{
    int key;
    struct node *left, *right;
};

node* newNode(int key){
    node* temp = new node();
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

void serialize(node* root, FILE *fp){
    if(root==NULL){
        fprintf(fp, "%d ", MARKER); 
        return;
    }
    fprintf(fp, "%d ", root->key); 
    serialize(root->left, fp); 
    serialize(root->right, fp);
}

void deSerialize(node* &root, FILE *fp){
    int val; 
    if ( !fscanf(fp, "%d ", &val) || val == MARKER) 
       return;
       
    root = newNode(val); 
    deSerialize(root->left, fp); 
    deSerialize(root->right, fp);
}

void inorder(node *root){
    if(root){
        inorder(root->left);
        cout << root->key;
        inorder(root->right);
    }
}

int main(){
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    
    FILE *fp = fopen("tree.txt", "w");
    if(fp==NULL){
        puts("Could not open the file");
        return 0;
    }
    serialize(root, fp);
    fclose(fp);
    
    node* root1 = NULL;
    fp = fopen("tree.txt", "r");
    deSerialize(root1, fp);
    
    cout<< "Inorder traversal of tree constructed from file: \n";
    inorder(root1);
    return 0;
}