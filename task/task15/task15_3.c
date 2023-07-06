/**********************************************************************
 *@file task15_3.c
 *@brief this program just executes the function from shared libraries
 *@parameter integer
 *@return double
 *@note this program is just for understanding of shared libraries.
 *
 *@Author Praveen P
 *@Created date 5/07/23
 *@version 1
 *@bug
 *@last modified data 6/07/23
 ***********************************************************************/

/****************************************************
*
*commands used for shared library gcc program name -o output -lm flag
to check the shared library using command ldd output

Advantage 
 *Reduced excutable size
 *dynamic updates
 *easy version management
Disadvantage
 *Dependency on library availability
 *Runtime linking overhead
 *Potential compatability issues
 
 ***********************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
	printf("square=%lf\n",sqrt(4));
	printf("cosine=%lf\n",cos(4));
	printf("sine=%lf\n",sin(4));
	printf("power=%lf\n",pow(4,6));
}
