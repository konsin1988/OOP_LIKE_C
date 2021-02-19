#pragma once

// ***load_list interface***
typedef struct load_iface* load_iface_ptr;
typedef const char* (*load_list_func_ptr)( load_iface_ptr );

struct load_iface
{
	load_list_func_ptr load_list;
};

typedef struct load_iface load_iface;

// ***save_list interface***

typedef struct save_iface* save_iface_ptr;
typedef const char* (*save_list_func_ptr)( save_iface_ptr );

struct save_iface
{
	save_list_func_ptr save_list;
};

typedef struct save_iface save_iface;

// ***add_task interface***

typedef struct add_iface* add_iface_ptr;
typedef const char* (*add_task_func_ptr)( add_iface_ptr );

struct add_iface
{
	add_task_func_ptr add_task;
};

typedef struct add_iface add_iface;
 
// ***show_task interface***

typedef struct show_iface* show_iface_ptr;
typedef const char* (*show_task_func_ptr)( show_iface_ptr );

struct show_iface
{
	show_task_func_ptr show_task;
};

typedef struct show_iface show_iface;


// ***rm_task interface***

typedef struct rm_iface* rm_iface_ptr;
typedef const char* (*rm_task_func_ptr)( rm_iface_ptr );

struct rm_iface
{
	rm_task_func_ptr rm_task;
};

typedef struct rm_iface rm_iface;

