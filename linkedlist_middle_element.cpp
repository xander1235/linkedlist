#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node *next;
};

void append(struct node **head, struct node **tail, int dt){
  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  if(!newnode){
    cout <<"memory not alloted" <<endl;
    return;
  }
  newnode->data = dt;
  newnode->next = NULL;
  if(*head==NULL){
    //cout << dt <<endl;
    *head = newnode;
  }
  else{
		if(*tail != NULL)
    	(*tail)->next = newnode;
  }
  *tail = newnode;
}

void getMiddle(struct node *head){
  struct node *first = head,*second = head;
  if(!head){
    cout <<" empty linked list " <<endl;
    return;
  }

  while(second->next!=NULL){
    first = first->next;
    if(second->next->next==NULL){
        second = second->next;
    }
    else{
        second = second->next->next;
    }
  }
  cout <<" middle element in the linked list " <<endl;
  cout <<first->data <<endl;
}

int main(){
    int n,dt;
    struct node *head=NULL, *tail=NULL;
//   head = (struct node*)malloc(sizeof(struct node));
    cin >>n;
    for(int i=0;i<n;i++){
      cin >>dt;
      append(&head,&tail,dt);
    }
    getMiddle(head);
    return 0;
}
