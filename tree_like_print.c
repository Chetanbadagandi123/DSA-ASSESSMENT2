#include <malloc.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define COUNT 5

struct Node
{
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node* node= (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
        return newNode(data);

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

void inorderTraversal(struct Node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void print2DUtil(struct Node* root, int space)
{
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	//printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);

	// Process left child
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct Node* root)
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
}

int main()
{
    struct Node* root = NULL;

    srand(time(0));
    int lower=1,upper=100,count=10;
    int arr[count];

    printf("The random nos are\n");
    for(int j=0;j<count;j++)
    {
        arr[j]=(rand()%(upper-lower+1))+lower;
        printf("%d ",arr[j]);
    }

    for (int i = 0; i < count; i++)
    {
        root = insert(root, arr[i]);
    }

    printf("\nInorder traversal of the tree: ");
    inorderTraversal(root);
    printf("\n\n\n");
    print2D(root);

    return 0;
}
