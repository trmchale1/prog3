#include <iostream>
#include <fstream>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data) {
	struct node* head = new node;
	head->data = data;
	head->left = NULL;
	head->right = NULL;
	return(head);
}

struct node* insert(struct node* node, int data) {
	if(node == NULL){
		return (newNode(data));
	} else {
		if(data < node->data) node->left = insert(node->left,data);
		else if (data > node->data) node->right = insert(node->right,data);
		else {}
		return(node);
	}	
}

void printTree(struct node* node){
	if(node == NULL) return;
	printTree(node->left);
	cout << "Printing inorder "  << node->data << endl;
	printTree(node->right);
}

void printChildren(struct node* node){
        int i = 0;
	if(node == NULL) return;
        printChildren(node->left);
        if(node->left == NULL && node->right == NULL){
		i = 0;	
	} else if ((node->left != NULL && node->right == NULL) || (node->right != NULL && node->left == NULL))  {
	i = 1;
	}
	else {
		i = 2;
	}
	
	cout << "The node: " << node->data << " number of children: " << i  <<endl;
        printChildren(node->right);
}

void preTraversal(struct node* node){
if(node == NULL) return;

        cout << "Pretraversal: " << node->data << endl;
        preTraversal(node->left);
        preTraversal(node->right);
}

void postTraversal(struct node* node){
if(node == NULL) return;
        postTraversal(node->left);
        postTraversal(node->right);
        cout << "Post-traversal " << node->data << endl;
}

int size(struct node* node){
	if(node == NULL) return 0;
        return size(node->left) + 1 + size(node->right);
}

struct node* FindMin(struct node* root){
  while(root->left != NULL) root = root->left;
  return root;
}

struct node* Delete(struct node *root, int data){
  if(root == NULL) return root;
  else if(data < root->data) root->left = Delete(root->left,data);
  else if(data > root->data) root->right = Delete(root->right, data);
  else {
    // Case 1: No Child
    if(root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
    // Case 2: one child
    } else if(root->left == NULL){
      struct node *temp = root;
      root = root->right;
      delete temp;
    } else if(root->right == NULL){
      struct node *temp = root;
      root = root->left;
      delete temp;
    } else{
      struct node *temp = FindMin(root->right);
      root->data = temp->data;
      root->right = Delete(root->right, temp->data);
    }
  }
  return root;
}

int main() {
	struct node *head = new node;
	head = NULL;

// Everything below this line is the real program

	ifstream data1;
	data1.open("data1.txt");
	int temp = 0;
	data1 >> temp;
	while(temp != -999) {	
		head = insert(head,temp);
		data1 >> temp;
	}
		
		printTree(head);
		preTraversal(head);
		postTraversal(head);
		int o  = size(head);
		cout << "Size is: "<< o << endl;
		printChildren(head);
		cout << "Making changes ..." << endl;
	char n;
	data1 >> n;	
	while(!data1.fail()){
		if(n == 'i'){
			data1 >> temp;
			head = insert(head,temp);
		} else if (n == 'd') {
			data1 >> temp;
			head = Delete(head,temp);
		}
		data1 >> n;
	}
		printTree(head);
                preTraversal(head);
               postTraversal(head);
                int p = size(head);
		cout << "Size is " << p << endl;
                printChildren(head);
		delete head;

		cout << "First program done." << endl;

	struct node *head2 = new node;
        head2 = NULL;
	ifstream data2;
        data2.open("data2.txt");
        int temp2 = 0;
        data2 >> temp2;
        while(temp2 != -999) {
                head2 = insert(head2,temp2);
                data2 >> temp2;
        }
                printTree(head2);
                preTraversal(head2);
                postTraversal(head2);
                int o2  = size(head2);
                cout << "Size is: "<< o2 << endl;
                printChildren(head2);
        	cout << "Making changes ..." << endl;

	char n2;
        data2 >> n2;
        while(!data2.fail()){
                if(n2 == 'i'){
                        data2 >> temp2;
                        head2 = insert(head2,temp2);
                } else if (n2 == 'd') {
                        data2 >> temp2;
                        head2 = Delete(head2,temp2);
                }
                data2 >> n2;
        }
                printTree(head2);
                preTraversal(head2);
                postTraversal(head2);
                o2 = size(head2);
		cout << "Size is: " << o2 << endl;
                printChildren(head2);
                delete head2;

		cout << "Second Program done" << endl;

	struct node *head3 = new node;
        head3 = NULL;
        ifstream data3;
        data3.open("data3.txt");
        int temp3 = 0;
        data3 >> temp3;
        while(temp3 != -999) {
                head3 = insert(head3,temp3);
                data3 >> temp3;
        }
                printTree(head3);
                preTraversal(head3);
                postTraversal(head3);
                int o3  = size(head3);
                cout << "Size is: " << o3 << endl;
                printChildren(head3);
        
	cout << "Making changes ..." << endl;
	
	char n3;
        data3 >> n3;
	cout << n3 << endl;
        while(!data3.fail()){
                if(n3 == 'i'){

                        data3 >> temp3;
                        head3 = insert(head3,temp3); 

		} else if (n3 == 'd') {
                        data3 >> temp3;
                        head3 = Delete(head3,temp3);
                }
                data3 >> n3;
        }
                printTree(head3);
                preTraversal(head3);
                postTraversal(head3);
                o3 = size(head3);
		cout << "Size is: " << o3 << endl;
                printChildren(head3);
                delete head3;

                cout << "Third Program done" << endl;

	struct node *head4 = new node;
        head4 = NULL;
        ifstream data4;
        data4.open("data4.txt");
        int temp4 = 0;
        data4 >> temp4;
        while(temp4 != -999) {
                head4 = insert(head4,temp4);
                data4 >> temp4;
        }
                printTree(head4);
                preTraversal(head4);
                postTraversal(head4);
                int o4  = size(head4);
                cout << "Size is: " << o4 << endl;
                printChildren(head4);
        
	cout << "Making changes ..." << endl;

	char n4;
        data2 >> n4;
        while(!data4.fail()){
                if(n4 == 'i'){
                        data4 >> temp4;
                        cout << temp4 << endl;
			head4 = insert(head4,temp4);
                } else if (n4 == 'd') {
                        data4 >> temp4;
                        head4 = Delete(head4,temp4);
                }
                data4 >> n4;
        }
                printTree(head4);
                preTraversal(head4);
                postTraversal(head4);
                o4 = size(head4);
		cout << "Size is: " << o4 << endl;
                printChildren(head4);
                delete head4;

                cout << "Fourth Program done" << endl;

struct node *head5 = new node;
        head5 = NULL;
        ifstream data5;
        data5.open("data5.txt");
        int temp5 = 0;
        data5 >> temp5;
        while(temp5 != -999) {
                head5 = insert(head5,temp5);
                data5 >> temp5;
        }
                printTree(head5);
                preTraversal(head5);
                postTraversal(head5);
                int o5  = size(head5);
                cout << "Size is: " << o5 << endl;
                printChildren(head5);
        
	cout << "Making changes ..." << endl; 
	
	char n5;
        data5 >> n5;
        while(!data5.fail()){
                if(n5 == 'i'){
                        data5 >> temp5;
                        cout << temp5 << endl;
			head5 = insert(head5,temp5);
                } else if (n2 == 'd') {
                        data5 >> temp5;
                        head5 = Delete(head5,temp5);
                }
                data5 >> n5;
        }
                printTree(head5);
                preTraversal(head5);
                postTraversal(head5);
                o5 = size(head5);
		cout << "Size is: " << o5 << endl; 
                printChildren(head5);
                delete head5;

                cout << "Fifth program done" << endl;

	struct node *head6 = new node;
        head6 = NULL;
        ifstream data6;
        data6.open("data6.txt");
        int temp6 = 0;
        data6 >> temp6;
        while(temp6 != -999) {
                head6 = insert(head6,temp6);
                data6 >> temp6;
        }
                printTree(head6);
                preTraversal(head6);
                postTraversal(head6);
                int o6  = size(head6);
                cout << "Size is: " << o6 << endl;
                printChildren(head6);
        
	cout << "Making changes ..." << endl;

	char n6;
        data2 >> n6;
        while(!data6.fail()){
                if(n6 == 'i'){
                        data6 >> temp6;
                        head6 = insert(head6,temp6);
                } else if (n6 == 'd') {
                        data6 >> temp6;
                        head6 = Delete(head6,temp6);
                }
                data6 >> n6;
        }
                printTree(head6);
                preTraversal(head6);
                postTraversal(head6);
                o6 = size(head6);
                cout << "Size is: " << o6 << endl;
		printChildren(head6);
                delete head6;

                cout << "Sixth Program done" << endl;

	struct node *head7 = new node;
        head7 = NULL;
        ifstream data7;
        data7.open("data7.txt");
        int temp7 = 0;
        data7 >> temp7;
        while(temp7 != -999) {
                head7 = insert(head7,temp7);
                data7 >> temp7;
        }
                printTree(head7);
                preTraversal(head7);
                postTraversal(head7);
                int o7 = size(head7);
                cout << "Size is: " << o7 << endl;
                printChildren(head7);
        
	cout << "Making changes ..." << endl;

	char n7;
        data7 >> n7;
        while(!data7.fail()){
                if(n7 == 'i'){
                        data7 >> temp7;
                        head7 = insert(head7,temp7);
                } else if (n7 == 'd') {
                        data7 >> temp7;
                        head7 = Delete(head7,temp7);
                }
                data7 >> n7;
        }
                printTree(head7);
                preTraversal(head7);
                postTraversal(head7);
                o7  = size(head7);
                cout << "Size is: " << o7 << endl;
		printChildren(head7);
                delete head7;

                cout << "Seventh Program done" << endl;


}
