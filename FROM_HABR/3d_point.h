#pragma once

typedef struct d3_point_t* d3_point_ptr;
typedef void (*d3_point_print_coordinates_func)( d3_point_ptr );

struct d3_point_t	//inherites base_iface and sizible_iface
{
	//common methods
	d3_point_print_coordinates_func print_coordinates;

	//virtual methods
	get_name_func_ptr get_name;
	get_size_func_ptr get_size;

	//coordinates
	int x;
	int y;
	int z;
};

typedef struct d3_point_t d3_point_t;

//constructor
d3_point_t d3_point_init( int x, int y, int z );

//manual type casting from d3_point_ptr to base_iface_ptr
base_iface_ptr d3_point_to_base_iface( d3_point_ptr ptr );

//manual type casting from d3_point_ptr to sizible_iface_ptr
sizible_iface_ptr d3_point_to_sizible_iface( d3_point_ptr ptr );


