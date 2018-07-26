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
    cout <<" memory not alloted " <<endl;
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

int getCount(struct node *head){
  int i=0;
  while(head!=NULL){
    i++;
    head = head->next;
  }
  return i;
}

void getNode(struct node *head,int k){
  int tot,x;
  tot = getCount(head);
  x = tot - k;
  while(k--){
    if(head->next==NULL){
      cout <<"-1" <<endl;
      return;
    }
    head  = head->next;
  }
  cout <<head->data <<" " <<endl;
}

int main(){
    int n,k,dt;
    struct node *head=NULL, *tail=NULL;
//   head = (struct node*)malloc(sizeof(struct node));
    cin >>n;
    for(int i=0;i<n;i++){
      cin >>dt;
      append(&head,&tail,dt);
    }
    cin >>k;
    getNode(head,k);
    return 0;
}
