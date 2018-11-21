#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std; 
struct Node {
    int data; 
    Node* right; 
    Node* left; 
};

Node* create(int data){
    Node* temp = new Node();
    temp->data = data; 
    temp->right = NULL; 
    temp->left = NULL; 
}
void insert(Node* &root, int data){
    if (root == NULL) root = create(data);
    else if (root->data < data) insert(root->right, data);
    else insert(root->left, data);     
}
void display(Node* &root){
    if(root != NULL){
        cout << root->data << " ";
        display(root->left);
        display(root->right);
    }
}
void breadthFirstTraversal(Node* &root){
    vector<Node*> queue; 
    Node* current;
    queue.push_back(root);
    while(!queue.empty()){
        current = queue.front();
        queue.erase(queue.begin());
        cout << current->data << " ";
        if(current->left != NULL) queue.push_back(current->left);
        if(current->right != NULL) queue.push_back(current->right);           
    }
}
void dfs(Node* &root){
    if(root != NULL){
        cout << root->data << " ";
        if(root->left != NULL) dfs (root->left);
        else dfs(root->right);

    } 
}

int main(){
    Node* root= NULL;
    int n;
    for(int i =  0; i <10; ++i){
        n = rand() % 100;
        cout << n << " "; 
        insert(root, n);
    }
    cout << endl;
    display(root);
    cout << endl;
    breadthFirstTraversal(root); 
    cout << endl;
    dfs(root);
    dfs(root->right);
    
   /*
    cout << "  " << 1 << endl;
    cout << " / \\" << endl;
    cout << "/   \\ " << endl;
    */
}