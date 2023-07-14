/**********************************************************************
 *@file task6_2.c
 *@brief this program create linked list and display number of nodes present and their values 
 *@parameter structure pointer
 *@return structure pointer
 *@ note structure node consist of one data  and two structure pointer which has the memory address of left and right nodes
 
 *@Author Praveen P
 *@Created date 25/06/23
 *@version 1
 *@bug
 *@last modified data 25/06/23
 ***********************************************************************/

#include<stdio.h>
#include<stdlib.h>
struct tree_node
{
int data;
struct tree_node* left;
struct tree_node* right;
};
/**********************************************************************************
 *@ brief gives number of nodes present
 *@ parameter structure pointer
 *@ return integer
 *@ note give base address of structure as parameter
 *******************************************************************************************/
int count_nodes(struct tree_node*);
/**********************************************************************************
 *@ brief prints all data in the linked list
 *@ parameter structure pointer
 *@ return void
 *@ note give base address of structure as parameter
 *******************************************************************************************/
void print(struct tree_node *);

int main()
{
	struct tree_node* root=(struct tree_node*)malloc(sizeof(struct tree_node));
	root->data=10;
	root->left=(struct tree_node*)malloc(sizeof(struct tree_node));
	root->right=(struct tree_node*)malloc(sizeof(struct tree_node));
	root->left->data=20;
	root->right->data = 30;
	root->left->left=(struct tree_node*)malloc(sizeof(struct tree_node));
	root->left->right=(struct tree_node*)malloc(sizeof(struct tree_node));
	root->left->left->data=40;
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	root->left->right->data=50;
	root->left->right->left=NULL;
	root->left->right->right=NULL;
	root->right->left=(struct tree_node*)malloc(sizeof(struct tree_node));
	root->right->right=(struct tree_node*)malloc(sizeof(struct tree_node));
	root->right->left->data=60;
	root->right->left->left=NULL;
	root->right->left->right=NULL;
	root->right->right->data=70;
	root->right->right->left=NULL;
	root->right->right->right=NULL;
	printf("%d\n",count_nodes(root));
	print(root);
	return 0;
}

int count_nodes(struct tree_node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	return(1+count_nodes(root->left)+count_nodes(root->left));
}
void print(struct tree_node *root)
{
	struct tree_node* Print=(struct tree_node*)malloc(sizeof(struct tree_node));
	if(Print!=NULL)
		{
			Print=root;
			printf("%d",Print->data);
			Print=Print->left;
			printf("%d",Print->data);
			Print=Print->right;
			printf("%d",Print->data);
		}
}

