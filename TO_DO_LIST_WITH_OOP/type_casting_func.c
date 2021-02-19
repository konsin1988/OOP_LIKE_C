#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "todo_list.h"

// *** enum for type casting

enum
{
	num_load_list_offset = 0,
	num_save_list_offset = sizeof( load_list_func_ptr ),
	num_add_task_offset = sizeof( load_list_func_ptr ) + sizeof( save_list_func_ptr ),
	num_show_task_offset = sizeof( load_list_func_ptr ) + sizeof( save_list_func_ptr ) + sizeof( add_task_func_ptr ),
	num_rm_task_offset = sizeof( load_list_func_ptr ) + sizeof( save_list_func_ptr ) + sizeof( add_task_func_ptr ) + sizeof( show_task_func_ptr ),
};

// *** type casting ***

todo_list_ptr load_iface_to_todo_list( load_iface_ptr ptr )
{
	return (todo_list_ptr)( (char*)ptr - num_load_list_offset );
}

load_iface_ptr todo_list_to_load_iface( todo_list_ptr ptr )
{
	return (load_iface_ptr)( (char*)ptr + num_load_list_offset );
}

todo_list_ptr save_iface_to_todo_list( save_iface_ptr ptr )
{
	return (todo_list_ptr)( (char*)ptr - num_save_list_offset );
}

save_iface_ptr todo_list_to_save_iface( todo_list_ptr ptr )
{
	return (save_iface_ptr)( (char*)ptr + num_save_list_offset );
}

todo_list_ptr add_iface_to_todo_list( add_iface_ptr ptr )
{
	return (todo_list_ptr)( (char*)ptr - num_add_task_offset );
}

add_iface_ptr todo_list_to_add_iface( todo_list_ptr ptr )
{
	return (add_iface_ptr)( (char*)ptr + num_add_task_offset );
}

todo_list_ptr show_iface_to_todo_list( show_iface_ptr ptr )
{
	return (todo_list_ptr)( (char*)ptr - num_show_task_offset );
}

show_iface_ptr todo_list_to_show_iface( todo_list_ptr ptr )
{
	return (show_iface_ptr)( (char*)ptr + num_show_task_offset );
}

todo_list_ptr rm_iface_to_todo_list( rm_iface_ptr ptr )
{
	return (todo_list_ptr)( (char*)ptr - num_rm_task_offset );
}

rm_iface_ptr todo_list_to_rm_iface( todo_list_ptr ptr )
{
	return (rm_iface_ptr)( (char*)ptr + num_rm_task_offset );
}

