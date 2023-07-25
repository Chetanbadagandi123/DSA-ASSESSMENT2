#include <stdio.h>
#include <stdlib.h>
#include<time.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTraversal(Node* root,FILE *fileinorder)
{
    if (root != NULL)
    {
        inorderTraversal(root->left,fileinorder);
        printf("%d ", root->data);
        fprintf(fileinorder,"%d ",root->data);
        inorderTraversal(root->right,fileinorder);
    }
}

void preorderTraversal(Node* root,FILE *filepreorder)
{
    if (root != NULL) {
        printf("%d ", root->data);
        fprintf(filepreorder,"%d ",root->data);
        preorderTraversal(root->left,filepreorder);
        preorderTraversal(root->right,filepreorder);
    }
}

void postorderTraversal(Node* root,FILE *filepostorder)
{
    if (root != NULL) {
        postorderTraversal(root->right,filepostorder);
        printf("%d ", root->data);
        fprintf(filepostorder,"%d ",root->data);
        postorderTraversal(root->left,filepostorder);
    }
}

Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    Node* root = NULL;
    FILE* file = fopen("numbers.txt", "w");
    FILE* filepostorder = fopen("numberspostorder.txt", "w");
    FILE* filepreorder = fopen("numberspreorder.txt", "w");
    FILE* fileinorder = fopen("numbersinorder.txt", "w");

    srand(time(0));
    int lower=1,upper=100,count=10;
    int arr[count];

    printf("The random nos are\n");
    for(int j=0;j<count;j++)
    {
        arr[j]=(rand()%(upper-lower+1))+lower;
        fprintf(file,"%d ",arr[j]);
        printf("%d ",arr[j]);
    }

    for (int i = 0; i < count; i++)
    {
        root = insert(root, arr[i]);
    }

    printf("\nInorder traversal of the tree: ");
    inorderTraversal(root,fileinorder);

    printf("\nPreorder traversal of the tree: ");
    preorderTraversal(root,filepreorder);

    printf("\npostorder traversal of the tree: ");
    postorderTraversal(root,filepostorder);
    int key;
    printf("\nEnter the key to delete a node :");
    scanf("%d",&key);
    deleteNode(root,key);
    fprintf(fileinorder,"\n");
    printf("\nThe modified Inorder traversal of tree: ");
    inorderTraversal(root,fileinorder);
    fclose(file);
    fclose(filepreorder);
    fclose(filepostorder);
    fclose(fileinorder);

    return 0;
}
