#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "std.h" 

int main(int argc, char** argv)
{
	char operation[9];
	if(in_param(argc, argv, operation))
	{
		TODO_LIST todo_list = list_init( argc, argv );
		todo_list.load_list( todo_list_to_load_iface( &todo_list ));
		if(!strcmp(operation, "add"))
		{
			todo_list.add_task( 
			todo_list_to_add_iface( &todo_list ));
		}
		else if(!strcmp(operation, "show"))
		{
			todo_list.show_task( 
			todo_list_to_show_iface( &todo_list ));
		}

		else if(!strcmp(operation, "rm"))
		{
			todo_list.rm_task( 
			todo_list_to_rm_iface( &todo_list ));
		}
		todo_list.save_list(todo_list_to_save_iface( &todo_list ));

	}
	return 0;
}
	
