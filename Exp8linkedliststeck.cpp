#include <iostream>
#include <stack>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

int main() {
    node *head = NULL, *temp, *newNode;
    stack<int> st;
    int choice, value, n;
    char x;

    do {
        cout << "1. Create List\n";
        cout << "2. Display List\n";
        cout << "3. Reverse using Stack\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: 
            {
                cout << "Enter number of elements: ";
                cin >> n;

                for(int i = 0; i < n; i++) {
                    newNode = new node;
                    cout << "Enter value: ";
                    cin >> value;

                    newNode->data = value;
                    newNode->prev = NULL;
                    newNode->next = NULL;

                    if(head == NULL) {
                        head = newNode;
                    } else {
                        temp = head;
                        while(temp->next != NULL)
                            temp = temp->next;

                        temp->next = newNode;
                        newNode->prev = temp;
                    }
                }
                cout << "List Created\n";
                break;
            }

            case 2:
            {
                if(head == NULL) {
                    cout << "List is Empty\n";
                } else {
                    temp = head;
                    cout << "List:\n";
                    while(temp != NULL) {
                        cout << temp->data << " ";
                        temp = temp->next;
                    }
                    cout << endl;
                }
                break;
            }

            case 3: 
            {
                if(head == NULL) {
                    cout << "List is Empty\n";
                } else {
                    temp = head;

                    while(temp != NULL) {
                        st.push(temp->data);
                        temp = temp->next;
                    }

                    temp = head;
                    while(temp != NULL) {
                        temp->data = st.top();
                        st.pop();
                        temp = temp->next;
                    }

                    cout << "List Reversed using Stack\n";
                }
                break;
          
        }

        cout << "Do you want to continue (y/n): ";
        cin >> x;

    } while(x == 'y' || x == 'Y');

    return 0;
    }
