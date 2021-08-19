#include <bits/stdc++.h>

class Node {
    public:
    int data;
    Node* next;
};

Node* getNewNode() {
    Node* node = new Node();
    return node;
}

class LinkedList {
    private:
    Node* root;

    public:
    LinkedList() {
    root = NULL;
    }

    void insert(int value, int pos) {
        Node* temp = getNewNode();
        Node* temp1 = getNewNode();   
             
        if(root == NULL && pos > 1) 
        {
            std::cout<<"List is empty, please enter position 1 \n";
            std::cout<<"\n";

        } else if(pos == 1){

            temp->data = value;
            temp->next = root;
            root = temp;

        } else {
            
            temp = root;
            for(int i=0; i<pos-2; i++){
                
                if(pos-2-i > 1 && temp->next->next == NULL){
                    std::cout<<"invalid position \n";
                    std::cout<<"\n";                    
                    return;
                }
                
                temp = temp->next;
            
            }
            
            temp1->data = value;
            temp1->next = temp->next;
            temp->next = temp1;

        }
    }

    void deletenode(int pos) {
        
        Node* temp = getNewNode();
        temp = root;
        
        if(root == NULL) {
            
            std::cout<<"ERROR: LIST IS EMPTY, PLEASE ADD SOME NODES FIRST \n";
            return;

        } else if(pos == 1) {
            
            root = temp->next;
            delete temp;

        } else {

            for(int i =0; i<pos-2; i++) {
                
                if(pos - i - 2 > 1 && temp->next->next == NULL) {
                    std::cout<<"invalid position \n";
                    return;
                }

                temp = temp->next;
            }
            Node* temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;

        }
    }

    void print() {
        Node* temp = getNewNode(); 
        temp = root;
        if(root == NULL) {
            std::cout<<"list is empty \n";
            std::cout<<"\n";
            return;
        }
        while(temp != NULL){
            std::cout<<temp->data<<"\n";
            temp = temp->next;
        }
        std::cout<<"\n";
    }


};

int main() {

    LinkedList list;
    list.insert(1,2);
    list.print();
    list.insert(1,1);
    list.print();    
    list.insert(2,2);
    list.print();
    list.insert(3,3);
    list.print();  

    return 0;

}