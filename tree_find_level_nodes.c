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

int height(Node* node)
{
    if (node == NULL)
    return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        return (lheight + 1);
        else
        return (rheight + 1);
    }
}

void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
    return;
    if (level == 0)
    printf("%d     ", root->data);
    else if (level > 0)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(Node* root)
{
    int h = height(root);
    for (int i = 0; i < h; i++)
    {
        printf("level %d : ",i);
        printCurrentLevel(root, i);
        printf("\n");
    }
}

void printTree(Node* root, int level) {
    if (root == NULL)
        return;

    printTree(root->right, level + 1);
    printf("\n");
    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d", root->data);
    printTree(root->left, level + 1);
}



int main()
{
    Node* root = NULL;
    FILE* file = fopen("numbers.txt", "w");
    FILE* filepostorder = fopen("numberspostorder.txt", "w");
    FILE* filepreorder = fopen("numberspreorder.txt", "w");
    FILE* fileinorder = fopen("numbersinorder.txt", "w");

    srand(time(0));
    int space=0;
    int lower=1,upper=100,count=10;
    int arr[count];

    printf("The random nos are\n");
    for(int j=0;j<count;j++)
    {
        arr[j]=(rand()%(upper-lower+1))+lower;
        fprintf(file,"%d ",arr[j]);
        printf("%d ",arr[j]);
    }
    fclose(file);

    int num;
    FILE* file1 = fopen("numbers.txt", "r");
    //for (int i = 0; i < count; i++)
    while((fscanf(file1,"%d",&num))!=EOF)
    {
        root = insert(root, num);
    }

    printf("\nInorder traversal of the tree: ");
    inorderTraversal(root,fileinorder);

    printf("\nPreorder traversal of the tree: ");
    preorderTraversal(root,filepreorder);

    printf("\npostorder traversal of the tree: ");
    postorderTraversal(root,filepostorder);

    printf("\n\n");
    printLevelOrder(root);


printTree(root,0);


    fclose(file1);
    fclose(filepreorder);
    fclose(filepostorder);
    fclose(fileinorder);

    return 0;
}
