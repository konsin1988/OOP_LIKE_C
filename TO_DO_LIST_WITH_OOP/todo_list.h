#pragma once

#include <stddef.h>
#include <stdlib.h>
#include "operations_iface.h"


struct tegTODO_STRUCT
{
	char task[50];
	char date[15];
};
typedef struct tegTODO_STRUCT TODO;

typedef struct TODO_LIST* todo_list_ptr;
struct TODO_LIST
{
	load_list_func_ptr load_list;
	save_list_func_ptr save_list;
	add_task_func_ptr add_task;
	show_task_func_ptr show_task;
	rm_task_func_ptr rm_task;

	TODO* todo_list_arr;
	int add_pos;
	int rm_pos;
	int argc;
	char** argv;
};
typedef struct TODO_LIST TODO_LIST;

// ***constructor***
TODO_LIST list_init(int argc, char** argv);

// ***manual type casting***
load_iface_ptr todo_list_to_load_iface( todo_list_ptr );
save_iface_ptr todo_list_to_save_iface( todo_list_ptr );
add_iface_ptr todo_list_to_add_iface( todo_list_ptr );
show_iface_ptr todo_list_to_show_iface( todo_list_ptr );
rm_iface_ptr todo_list_to_rm_iface( todo_list_ptr );

todo_list_ptr load_iface_to_todo_list( load_iface_ptr ptr );
todo_list_ptr save_iface_to_todo_list( save_iface_ptr ptr );
todo_list_ptr add_iface_to_todo_list( add_iface_ptr ptr );
todo_list_ptr show_iface_to_todo_list( show_iface_ptr ptr );
todo_list_ptr rm_iface_to_todo_list( rm_iface_ptr ptr );
