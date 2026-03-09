#include<iostream>
using namespace std;
#define n 5
int queue[n];
int front=-1;
int rear=-1;
void insertion(int value){
if(rear==n-1){
cout<<"Queue Overflow! Cannot add elements!!"<<value<<endl;
} else {
if(front==-1) 
front=0;
rear++;
queue[rear]=value;
cout<<"Inserted: "<<value<<endl;
}
}
void deletion(){
if(front==-1 || front>rear) {
cout<<"Queue Underflow! Nothing to delete."<<endl;
} else {
cout<<"Deleted: "<<queue[front]<<endl;
front++;
}
}
void display() {
if(front==-1 || front>rear) {
cout<<"Queue is empty."<<endl;
} else {
cout<<"Queue elements: ";
for(int i=front;i<=rear; i++) {
cout <<queue[i]<<" ";
}
cout<<endl;
}
}
int main() {
int choice, val;    
do {
cout<<"\n--- Queue Menu ---\n";
cout<<"1. Insert"<<endl;
cout<<"2. Delete"<<endl;
cout<<"3. Display"<<endl;
cout<<"4. Exit"<<endl;
cout<<"Enter choice: ";
cin>>choice;
switch(choice) {
case 1:
cout<<"Enter value: ";
cin>>val;
insertion(val);
break;
case 2:
deletion();
break;
case 3:
display();
break;
case 4:
cout<<"Exiting..."<<endl;
break;
default:
cout<<"Invalid choice!"<<endl;
}
} while(choice != 4);
return 0;
}
