#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
    else
        printf("Element already exists in BST.\n");
    return root;
}
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->key == key)
        return 1;
    else if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct Node* deleteLeaf(struct Node* root, int key, int *deleted) {
    if (root == NULL)
        return NULL;

    if (key < root->key)
        root->left = deleteLeaf(root->left, key, deleted);
    else if (key > root->key)
        root->right = deleteLeaf(root->right, key, deleted);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            *deleted = 1;
            return NULL;
        } else {
            *deleted = 0; 
        }
    }
    return root;
}
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
int main() {
    struct Node* root = NULL;
    int choice, key, found, deleted;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Search an element\n");
        printf("2. Insert an element\n");
        printf("3. Delete a leaf element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &key);
                found = search(root, key);
                if (found)
                    printf("Element found in BST.\n");
                else
                    printf("Element not found.\n");
                break;

            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &key);
                deleted = 0;
                root = deleteLeaf(root, key, &deleted);
                if (deleted)
                    printf("Leaf node %d deleted successfully.\n", key);
                else
                    printf("Element %d is not a leaf node or not found.\n", key);
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}
