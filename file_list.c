#include "inverted_search.h"

 void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;

    while(argv[i]  != NULL)
    {
	empty = isFileEmpty(argv[i]);
	if(empty == FILE_NOTAVAILABLE)
	{
	    printf("FIle : %s is not available \n" , argv[i]);
	    printf("Hence we are not adding that file\n");
	    i++;
	    continue;
	}
	else if(empty == FILE_EMPTY)
	{
	    printf("FIle : %s is not having any contents in it\n" , argv[i]);
	    printf("Hence we are not adding that file\n");
	    i++;
	    continue;
	}
	else
	{
	    int ret_val = to_create_list_of_files(f_head , argv[i]);

	    if(ret_val == SUCCESS)
	    {
		printf("Successfull : inserting the file : %s into file linked list\n ", argv[i]);
	    }
	    else if(ret_val == REPEATATION)
	    {
		printf("THis file  : %s is repeated , Hence do not add into file linked list\n" , argv[i]);
	    }
	    else
	    {
		printf("Failure\n");
	    }
	    i++;
	}
    }
}
//fun() is used to check file is vailable or not 

// check for contents

int isFileEmpty(char *filename)
{

    FILE *fptr = fopen(filename , "r");

    if(fptr == NULL)
    {
	if(errno == ENOENT)
	{
	    return FILE_NOTAVAILABLE;
	}
    }

    fseek(fptr , 0 , SEEK_END);
    if(ftell(fptr) == 0)
    {
	return FILE_EMPTY;
    }
}
 

int to_create_list_of_files(Flist **f_head, char *name)
{
    //...................TODO..............
    //check for duplicate file names
    
    Flist *temp = NULL,*check = *f_head;;
    while(check)
    {
	    temp = check;
	    if(!strcmp(check->file_name,name))
		    return REPEATATION;
	    check = check->link;
    }
    //create a file linked list
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
	    return FAILURE;
    new->link = NULL; 
    strcpy(new->file_name,name);
    if(temp == NULL)
	    *f_head = new;
    else
	    temp->link = new;
    return SUCCESS;
}














