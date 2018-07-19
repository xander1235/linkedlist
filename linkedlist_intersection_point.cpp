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

int getIntersection(struct node *head1, struct node *head2){
  int n1=0,n2=0;
  struct node *temp1, *temp2;
  temp1 = head1;
  temp2 = head2;
  while(temp1!=NULL || temp2!=NULL){
    if(temp1!=NULL){
      n1++;
      temp1 = temp1->next;
    }
    if(temp2!=NULL){
      n2++;
      temp2 = temp2->next;
    }
  }
  if(n1>n2){
    n2 = n1 - n2;
    while(n2>0){
      head1 = head1->next;
      //cout <<head1->data <<endl;
      n2--;
    }
  }
  if(n2>n1){
    n1 = n2 - n1;
    while(n1>0){
      head2 = head2->next;
      n1--;
    }
  }
  while(head1!=NULL){
    //search with data address to detect the loop
    if(&head1->data == &head2->data){
      return head1->data;
    }
    head1 = head1->next;
    head2 = head2->next;
  }
}

int main(){
    int n,m,l,k,dt;
    struct node *head1=NULL, *tail1=NULL,*head2=NULL, *tail2=NULL,*head3=NULL, *tail3=NULL;
//   head = (struct node*)malloc(sizeof(struct node));
    cin >>n >>m >>l;
    for(int i=0;i<n;i++){
      cin >>dt;
      append(&head1,&tail1,dt);
    }
    for(int i=0;i<m;i++){
      cin >>dt;
      append(&head2,&tail2,dt);
    }
    for(int i=0;i<l;i++){
      cin >>dt;
      append(&head3,&tail3,dt);
    }
    if(tail1!=NULL){
      tail1->next = head3;
    }
    if(tail2!=NULL){
      tail2->next = head3;
    }
    cout <<" loop removed " <<endl;
    k = getIntersection(head1,head2);
    if(k==0){
      k=-1;
    }
    cout <<k <<endl;
    return 0;
}
