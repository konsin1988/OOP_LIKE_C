#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "todo_list.h"

void str_split(int argc, char** argv, char* task, char* date)
{
	sscanf(argv[2], "%s", task);
	for(size_t i=3; i<argc-1; ++i)
	{
		if(strlen(task)+1+strlen(argv[i]) > 50)
			break;
		strcat(task, " ");
		strcat(task, argv[i]);
	}
	sscanf(argv[argc-1], "%s", date);
}

// ***load_list***

void load_list_func( load_iface_ptr ptr )
{
	FILE *F;
	if((F = fopen("todo_list.dat", "rt")) == NULL)
	{
		fprintf(stderr, "Unable to open 'todo_list.dat'\n");
		return;
	}
	todo_list_ptr casted_ptr = load_iface_to_todo_list( ptr ); 
	fscanf(F, "%zu\n", &(*casted_ptr).add_pos);
	for(size_t i=0; i<(*casted_ptr).add_pos; ++i)
	{
		fscanf(F, "%[^\n]%*c", (*casted_ptr).todo_list_arr[i].task);
		fscanf(F, "%s\n", (*casted_ptr).todo_list_arr[i].date);
	}

	fclose(F);
}

// *** save_list ***

void save_list_func( save_iface_ptr ptr )
{
	FILE *F;
	if((F = fopen("todo_list.dat", "wt")) == NULL)
	{
		fprintf(stderr, "Unable to open 'todo_list.dat'\n");
		return;
	}
	todo_list_ptr casted_ptr = save_iface_to_todo_list( ptr ); 
	fprintf(F, "%zu\n", (*casted_ptr).add_pos-(*casted_ptr).rm_pos);
	for(size_t i=(*casted_ptr).rm_pos; i<(*casted_ptr).add_pos; ++i)
	{
		fprintf(F, "%s\n", (*casted_ptr).todo_list_arr[i].task);
		fprintf(F, "%s\n", (*casted_ptr).todo_list_arr[i].date);
	}
	fclose(F);
}

// *** add_task ***

void add_task_func( add_iface_ptr ptr )
{
	todo_list_ptr casted_ptr = add_iface_to_todo_list( ptr ); 
	if(((*casted_ptr).add_pos) > 99)
	{
		printf("Stack overflow. Stop\n");
		return;
	}
	char task[50];
	char date[15];
	str_split((*casted_ptr).argc, (*casted_ptr).argv, task, date);
	sscanf(task, "%49[^\n]%*c", (*casted_ptr).todo_list_arr[(*casted_ptr).add_pos].task);
	sscanf(date, "%14s", (*casted_ptr).todo_list_arr[(*casted_ptr).add_pos].date);
	(*casted_ptr).add_pos++;
}

// *** show_task ***

void show_task_func( show_iface_ptr ptr )
{
	todo_list_ptr casted_ptr = show_iface_to_todo_list( ptr ); 
	if((*casted_ptr).add_pos == 0)
	{
		printf("There is nothing to show. All tasks done!!!\n");
		return;
	}
	printf("First in line task: \t");
	printf("%s\t", (*casted_ptr).todo_list_arr[0].task);
	printf("%s\n", (*casted_ptr).todo_list_arr[0].date);
}

// *** rm_task ***

void rm_task_func( rm_iface_ptr ptr)
{
	todo_list_ptr casted_ptr = rm_iface_to_todo_list( ptr ); 
	if((*casted_ptr).add_pos == 0)
	{
		printf("There is nothing to remove. All tasks done!!!\n");
		return;
	}
	printf("Task \"%s\" done! Congratulations!!!\n", (*casted_ptr).todo_list_arr[0].task);
	++(*casted_ptr).rm_pos;
}

// *** constructor TODO_LIST ***

TODO_LIST list_init( int argc, char** argv )
{
	TODO_LIST todo_list;
	TODO todo_list_arr[100];

	todo_list.load_list = (load_list_func_ptr)load_list_func;
	todo_list.save_list = (save_list_func_ptr)save_list_func;
	todo_list.add_task = (add_task_func_ptr)add_task_func;
	todo_list.show_task = (show_task_func_ptr)show_task_func;
	todo_list.rm_task = (rm_task_func_ptr)rm_task_func;

	todo_list.todo_list_arr = todo_list_arr;
	todo_list.add_pos = 0;
	todo_list.rm_pos = 0;
	todo_list.argc = argc;
	todo_list.argv = argv;

	return todo_list;
}
