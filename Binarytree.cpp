#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root) {
    if (root != NULL) {
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
        cout << "1. Create\n";
        cout << "2. Inorder\n";
        cout << "3. Preorder\n";
        cout << "4. Postorder\n";
        cout << "5. Display (Inorder)\n";
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
                        node* temp = root;
                        node* parent;

                        while(temp != NULL) {
                            parent = temp;
                            if(value < temp->data)
                                temp = temp->left;
                            else
                                temp = temp->right;
                        }

                        if(value < parent->data)
                            parent->left = newNode;
                        else
                            parent->right = newNode;
                    }
                }
                cout << "BST Created\n";
                break;
            }

            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 3: // Preorder
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 4: // Postorder
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 5: // Display (same as inorder)
                cout << "Display (Sorted Order): ";
                inorder(root);
                cout << endl;
                break;
        }        

        cout << "Do you want to continue (y/n): ";
        cin >> x;

    } while(x == 'y' || x == 'Y');

    return 0;
}
