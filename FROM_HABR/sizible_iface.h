#pragma once

typedef struct sizible_iface* sizible_iface_ptr;
typedef unsigned int (*get_size_func_ptr)( sizible_iface_ptr);

struct sizible_iface
{
	get_size_func_ptr get_size;
};

typedef struct sizible_iface sizible_iface;
