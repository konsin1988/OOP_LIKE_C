#pragma once

typedef struct base_iface* base_iface_ptr;
typedef const char* (*get_name_func_ptr)( base_iface_ptr );

struct base_iface
{
	get_name_func_ptr get_name;
};

typedef struct base_iface base_iface;

