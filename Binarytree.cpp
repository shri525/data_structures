#include <iostream>
#include <queue>
using namespace std;


struct node {
    int data;
    node* left;
    node* right;
};


void inorder(node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(node* root) {
    if(root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    node* root = NULL;
    int choice, value, n;
    char x;

    do {
        cout << "\n--- BINARY TREE ---\n";
        cout << "1. Create Tree\n";
        cout << "2. Insert Node\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Display (Inorder)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: 
            {
                cout << "Enter number of nodes: ";
                cin >> n;

                for(int i = 0; i < n; i++) {
                    cout << "Enter value: ";
                    cin >> value;

                    node* newNode = new node;
                    newNode->data = value;
                    newNode->left = newNode->right = NULL;

                    if(root == NULL) {
                        root = newNode;
                    } else {
                        queue<node*> q;
                        q.push(root);

                        while(!q.empty()) {
                            node* temp = q.front();
                            q.pop();

                            if(temp->left == NULL) {
                                temp->left = newNode;
                                break;
                            } else {
                                q.push(temp->left);
                            }

                            if(temp->right == NULL) {
                                temp->right = newNode;
                                break;
                            } else {
                                q.push(temp->right);
                            }
                        }
                    }
                }
                cout << "Tree Created\n";
                break;
            }

            case 2: 
            {
                cout << "Enter value: ";
                cin >> value;

                node* newNode = new node;
                newNode->data = value;
                newNode->left = newNode->right = NULL;

                if(root == NULL) {
                    root = newNode;
                } else {
                    queue<node*> q;
                    q.push(root);

                    while(!q.empty()) {
                        node* temp = q.front();
                        q.pop();

                        if(temp->left == NULL) {
                            temp->left = newNode;
                            break;
                        } else {
                            q.push(temp->left);
                        }

                        if(temp->right == NULL) {
                            temp->right = newNode;
                            break;
                        } else {
                            q.push(temp->right);
                        }
                    }
                }

                cout << "Node Inserted\n";
                break;
            }

            case 3:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Display (Inorder): ";
                inorder(root);
                cout << endl;
                break;

           
        }

        cout << "Do you want to continue (y/n): ";
        cin >> x;

    } while(x == 'y' || x == 'Y');

    return 0;
}
