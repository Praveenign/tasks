/**********************************************************************
 *@file task8_3.c
 *@brief this program creates a binary tree using array of integer elements and traverse in preorder,postorder , inorder and horizontal format. This program also create search binary tree using the array of integers and it helps to insert,search,delete,find maximum vakue ,find minimum value of elements.
 *@parameter structure pointer,integer 
 *@return structure pointer
 *
 *@Author Praveen P
 *@Created date 27/06/23
 *@version 1
 *@bug
 *@last modified data 29/06/23
 ***********************************************************************/

#include<stdio.h>
#include<stdlib.h>
/*******************************
 * struct tree is a main node 
 * structure pointer left and write indicates their child node
 * ***********************/
struct tree
{
int data;
struct tree *left;
struct tree *right;
};
/**************************************************************
 *@ brief this function is used to create the nodes
 *@parameter integer
 *@ return address
 **********************************************************/

struct tree* create(int data)
{
struct tree *new=(struct tree*)malloc(sizeof(struct tree));
new->data=data;
new->left=NULL;
new->right=NULL;
return new;
}
/***********************************************************************
 *@brief this function create a binary tree 
 *@ parameter integer array,starting index as integer,integer (number of elements)
 *@ return structure address
 *@ note elements are arranged according to the array index,first element is stored in root node  then left and right , in this function need to search all elements in node to pick up a particular element 
 ***********************************************************************/
struct tree *bintree(int arr[],int index,int size)
{
struct tree *root=NULL;

if(index<size)
{
//printf("add=%p\n",root); // for checking purposes
//printf("left=%p\n",root->left);
//printf("right=%p\n",root->right);
root=create(arr[index]);
root->left=bintree(arr,2*index+1,size);  // 2*index+1 => multiply  values  of left nodes
root->right=bintree(arr,2*index+2,size); //2*index+2 => multiply values of right node
}

return root;
}
/*********************************************************************************************
 * @ brief this function helps to print the tree in preorder
 *@ parameter node address
 *@ return void
 *@ note in preorder root node first prints its element then left nodes finally right nodes
 *@ this function is implemented using recursion 
 *****************************************************************************************/
void preorder(struct tree *root)
{
if(root!=NULL)
{
printf("%d",root->data);
  preorder(root->left);
  preorder(root->right);
  }
  return;
}
/*********************************************************************************************
   *@ brief this function helps to print the tree in postorder
   *@ parameter node address
   *@ return void
   *@ note in postorder left nodes first prints its element then right nodes finally root  node
   *@ this function is implemented using recursion 
   *****************************************************************************************/  
void postorder(struct tree *root)
 {
  if(root!=NULL)
  {

   postorder(root->left);
    postorder(root->right);
	printf("%d",root->data);
    }
    return;
  }
/*********************************************************************************************
   * @ brief this function helps to print the tree in inorder
   *@ parameter node address
   *@ return void
   *@ note in inorder left node first prints its element then root node finally right nodes
   *@ this function is implemented using recursion 
   *****************************************************************************************/  

void print(struct tree *root)
{
if(root!=NULL)
{
print(root->left);
printf("%d",root->data);
print(root->right);
}
return;
} 
/*********************************************************************************************
   * @ brief this function helps to insert the node in binary search tree
   *@ parameter node address and integer element
   *@ return struct address
   *@ note inserted elements has been placed at the position by comparing with the current node elements in whole tree
   *@ this function is implemented using recursion 
   *****************************************************************************************/  

struct tree *insertnode(struct tree* root,int data)
{
if(root==NULL)
{
  return(create( data));
}
if(root->data>data)
{
root->left=insertnode(root->left,data);
}
else if(root->data<data)
{
root->right=insertnode(root->right,data);
}
return root;
}

/*********************************************************************************************
   * @ brief this function helps to search elements in the binary search tree
   *@ parameter root  address and element(integer)
   *@ return element node address
   *@ search function is implemented by comparing the element value with the node elements
   *@ this function is implemented using recursion 
   *****************************************************************************************/  
struct tree* search(struct tree * root ,int data)
{
if(root==NULL||root->data==data)
{
return root;
}
if(root->data>data)
{
return(search(root->left,data));
}
else if(root->data<data)
{
return(search(root->right,data));
}
return root;
}

/***********************************************************************
   *@brief this function create a binary search tree                   
   *@ parameter integer array,integer (number of elements)
   *@ return structure address
   *@ note small values are assigned in left side child node and larger values are assigned in right side child node , which helps for easy searching of elements in a tree.
   ***********************************************************************/



struct tree * bin_search_tree(int array[],int size)
  {
  struct tree * root=NULL;
 for(int i=0;i<size;i++)
  {
  root=insertnode(root,array[i]);
  }
  return root;
  }

/*****************************************************************************************
 *@brief this function is used to find the maximum value in the binary search tree
 *@parameter structure address
 *@return integer
 ******************************************************************************************/
int findmax(struct tree *root)
{
if(root==NULL)
{
return -1;
}
while(root->right!=NULL)
{
root=root->right;

}
return root->data;
}
/*****************************************************************************************
  *@brief this function is used to find the minimum value in the binary search tree
  *@parameter structure address
  *@return integer
  ******************************************************************************************/ 
int findmin(struct tree * root)
{
if(root==NULL)
{
return -1;
}
while(root->left!=NULL)
{
root=root->left;
}
return root->data;
}
int main()
{
int array[]={10,20,30,40,50,60,70};
int size = 7;
struct tree *root=(struct tree*)malloc(sizeof(struct tree));
root=bintree(array,0,size);   //general binary tree
printf("INORDER TRAVERSE\n");
print(root);
printf("\nPREORDER TRAVERSE\n");
preorder(root);
printf("\nPOSTORDER\n");
postorder(root);

struct tree *bin_root=bin_search_tree(array,7);//binary search tree
printf("\nBINARY SEARCH TREE ELEMENTS\n");  
print(bin_root);
printf("\nsearch=%p\n",search(bin_root,70));
printf("min=%d\n",findmin(bin_root));
printf("max=%d\n",findmax(bin_root));

}


