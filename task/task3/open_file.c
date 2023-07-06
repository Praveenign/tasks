/**********************************************************************
 *@file open_file.c
 *@brief this program gets the file name from the user and open the file
 *@parameter string
 *@return integer
 *@note give the file name with correct extension
 *
 *@Author Praveen P
 *@Created date 22/06/23
 *@version 1
 *@bug
 *@last modified data 22/06/23
 ***********************************************************************/

#include<stdio.h>
#include<string.h>

FILE *file;  // file pointer 
int data;    // data is a integer type used to get the return value of the open_file function
char file_name[20];  //variable for getting filename
/* 
 * @brief get the file name in  string give back the integer value as feeback
 * @parameter string
 * @return integer
 * ******************************************************************************/
int open_file(char*);

int main()
{
	printf("Enter the filename with extention \n");
	scanf("%s",file_name);
	data=open_file(file_name);
	if(data==1)
	{
		printf("file opened successfully");
	}
	else
	{			
		perror("Error");
	}
       return(0);
}
int open_file(char*file_name)
{
	file=fopen(file_name,"r");
	if(file!=NULL)
	{
		perror("Error");
		return(1);
	}	
	else
	{
		perror("E");
		return(0);
	}
}
