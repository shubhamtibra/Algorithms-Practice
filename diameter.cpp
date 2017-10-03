/* Diameter of a binary tree using Divide and Conquer in linear asymptotic running time */

#include <iostream>
#include <algorithm> 

using namespace std;

/* a pair to represent the diameter and the height of a binary tree
 diameter being the first one */
typedef pair<int, int> myPair;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
	int data;
	struct node* left, *right;
};

/* function to create a new node of tree and returns pointer */
struct node* newNode(int data);

/* Function to get the diameter and height of a binary tree */
myPair heightDiameter(struct node * tree)
{
    // base case i.e. when the tree is empty
    if (tree == NULL) return make_pair(0, 0);
    
    myPair leftTree = heightDiameter(tree->left);
    myPair rightTree = heightDiameter(tree->right);
    
    int height = max(leftTree.second, rightTree.second) + 1;
    int diameter = max(max(leftTree.first, rightTree.first), leftTree.second + rightTree.second + 1);
    
    return make_pair(diameter, height);
} 

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}

/* Driver program to test above functions*/
int main()
{

/* Constructed binary tree is 
			1
		/ \
		2	 3
	/ \
	4	 5
*/
struct node *root = newNode(1);
root->left	 = newNode(2);
root->right	 = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
myPair ans = heightDiameter(root);
cout<<"Diameter and height of the given binary tree is "<<ans.first << " and "<< ans.second << endl;

return 0;
}
