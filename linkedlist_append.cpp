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
    cout <<"memory not alloted " <<endl;
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

int getCounnt(struct node *head){
  int i=0;
  while(head!=NULL){
      i++;
      head = head->next;
  }
  return i;
}

void print(struct node *head){
  while(head!=NULL){
      cout <<head->data <<" ";
      head = head->next;
  }
  cout <<endl;
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
    cout <<" linked list " <<endl;
    print(head);
    return 0;
}
