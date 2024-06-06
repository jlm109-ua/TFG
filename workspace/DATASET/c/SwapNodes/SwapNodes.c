#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int n) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void InOrder(struct node *root) {
    if (!root)
        return;
    InOrder(root->left);
    InOrder(root->right);
}

void swapSubtreesOfLevel(struct node *root, int k) {
    if (!root)
        return;
    struct node *queue[1001];
    int rear = -1;
    int front = -1;
    queue[++rear] = root;
    queue[++rear] = NULL;
    int level = 1;
    while (front != rear) {
        struct node *tmp = queue[++front];
        if (tmp == NULL) {
            if (rear != front)
                queue[++rear] = NULL;
            level++;
        } else {
            if (level == k) {
                struct node *sw = tmp->left;
                tmp->left = tmp->right;
                tmp->right = sw;
            }
            if (tmp->left)
                queue[++rear] = tmp->left;
            if (tmp->right)
                queue[++rear] = tmp->right;
        }
    }
}

void runMain() {
    int N = 3;
    struct node *root = NULL;
    struct node *queue[1001];
    int rear = -1;
    int front = -1;
    int level = 1;
    if (N > 0) {
        root = createNode(1);
        queue[++rear] = root;
        queue[++rear] = NULL;
    }
    while ((N > 0) && (front != rear)) {
        struct node *tmp = queue[++front];
        if (tmp == NULL) {
            if (rear != front)
                queue[++rear] = NULL;
            level++;
        } else {
            int a = 2, b = 3;
            if (a != -1) {
                tmp->left = createNode(a);
                queue[++rear] = tmp->left;
            }
            if (b != -1) {
                tmp->right = createNode(b);
                queue[++rear] = tmp->right;
            }
            N--;
        }
    }
    int T = 2;
    while (T > 0) {
        int k = 1;
        int itr = 2;
        int lvl = k;
        while (lvl <= level) {
            swapSubtreesOfLevel(root, lvl);
            lvl = itr * k;
            itr++;
        }
        InOrder(root);
        T--;
    }
}

int main() {
    runMain();
    return 0;
}
