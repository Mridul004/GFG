/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode=new Node(data);
        
        Node* curr=head;
        if(head->data>data){
            while(curr->next!=head) curr=curr->next;
            curr->next=newNode;
            newNode->next=head;
            return newNode;
        }
        else{
            while(curr->next!=head&&curr->next->data<data) curr=curr->next;
            newNode->next=curr->next;
            curr->next=newNode;
            return head;
        }
    }
};