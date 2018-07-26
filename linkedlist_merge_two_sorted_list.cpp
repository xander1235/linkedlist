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

void print(struct node *head){
  while(head!=NULL){
      cout <<head->data <<" ";
      head = head->next;
  }
  cout <<endl;
}

void getMerge(struct node **head1,struct node **head2){
  struct node *temp=NULL,*head=NULL;
  int i=0;
  //check the base conditions first
  if(*head1==NULL){
    *head1 = *head2;
    return;
  }
  if(*head2==NULL){
    *head1 = *head1;
    return;
  }
  while((*head1)!=NULL || (*head2)!=NULL){
    if(*head1 == NULL){
      temp->next = *head2;
      *head2 = (*head2)->next;
      temp = temp->next;
    }
    else if(*head2 == NULL){
      temp->next = *head1;
      *head1 = (*head1)->next;
      temp = temp->next;
    }
    else if((*head1)->data >= (*head2)->data){
      if(i==0){
        head = *head2;
        temp = head;
        *head2 = (*head2)->next;
        i++;
      }
      else{
        temp->next = *head2;
        temp = temp->next;
        *head2 = (*head2)->next;
      }
    }
    else{
      if(i==0){
        head = *head1;
        temp = head;
        *head1 = (*head1)->next;
        i++;
      }
      else{
        temp->next = *head1;
        temp = temp->next;
        *head1 = (*head1)->next;
      }
    }
  }
*head1 = head;
}

int main(){
    int n,m,dt;
    struct node *head1=NULL, *tail1=NULL , *head2=NULL, *tail2=NULL;
//   head = (struct node*)malloc(sizeof(struct node));
    cin >>n >>m;
    for(int i=0;i<n;i++){
      cin >>dt;
      append(&head1,&tail1,dt);
    }
    for(int i=0;i<m;i++){
      cin >>dt;
      append(&head2,&tail2,dt);
    }
    cout <<"linked list after merging" <<endl;
    getMerge(&head1,&head2);
    print(head1);
    return 0;
}
