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

void print(struct node *head){
  while(head!=NULL){
      cout <<head->data <<" ";
      head = head->next;
  }
  cout <<endl;
}

int getDetectLoop(struct node *head){
  struct node *temp,*first,*second;
  first = head;
  second = head;
  while(second->next!=NULL){
    first = first->next;
    if(second->next->next==NULL){
        second = second->next;
    }
    else{
        second = second->next->next;
    }
    if(&first->data == &second->data){
      return 2;
    }
  }
  return 0;
}

int main(){
    int n,x,s,dt;
    struct node *head=NULL, *tail=NULL,*temp;
//   head = (struct node*)malloc(sizeof(struct node));
    cin >>n;
    for(int i=0;i<n;i++){
      cin >>dt;
      append(&head,&tail,dt);
    }
    cin >>x;
    temp = head;
    if(x>0){
      while(x--){
        temp = temp->next;
      }
      tail->next = temp;
    }
    cout <<" loop detected " <<endl;
    s = getDetectLoop(head);
    if(s>0){
      cout <<"True" <<endl;
    }
    else{
      cout <<"False" <<endl;
    }
    return 0;
}
