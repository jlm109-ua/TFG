#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int HasCycle(struct Node* head)
{
    if (head == NULL) 
        return 0;
    
    struct Node *slow, *fast;
    slow = head;
    fast = head;
    
    while (fast && slow) {
        fast = fast->next;
        
        if (fast == NULL) { // No loop
            return 0;
        }
        
        if (fast == slow) { // Loop found
            return 1;
        }
        
        fast = fast->next;
        
        if (fast == slow) {
            return 1;
        }
        
        if (fast == NULL)
            return 0;
        
        slow = slow->next;
    }
   
    return 0;
}

void runMain(){
     struct Node *A, *B, *C, *D, *E, *F;
    A = (struct Node*) malloc(sizeof(struct Node)); 
    B = (struct Node*) malloc(sizeof(struct Node)); 
    C = (struct Node*) malloc(sizeof(struct Node)); 
    D = (struct Node*) malloc(sizeof(struct Node)); 
    E = (struct Node*) malloc(sizeof(struct Node)); 
    F = (struct Node*) malloc(sizeof(struct Node));

    // case 2:
    A->next = B; 
    B->next = C;
    C->next = A;

    // case 3:  
    A->next = B; 
    B->next = C; 
    C->next = D; 
    D->next = E; 
    E->next = F; 
    F->next = E;

    // case 4:
    A->next = B; 
    B->next = C; 
    C->next = D; 
    D->next = E; 
    E->next = F; 
    F->next = NULL;

    // case 5:
    A->next = B; 
    B->next = C; 
    C->next = D; 
    D->next = E; 
    E->next = F; 
    F->next = A;

    free(A);
    free(B);
    free(C);
    free(D);
    free(E);
    free(F);

}

int main()
{
    runMain();
    return 0;
}
