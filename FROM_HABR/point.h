#pragma once

typedef struct point_t* point_ptr;
typedef void (*point_print_coordinates_func)( point_ptr );

struct point_t  //inherits base_iface and sizible_iface
{
	//virual methods
	get_name_func_ptr get_name;
	get_size_func_ptr get_size;

	//other methods
	point_print_coordinates_func print_coordinates;

	//coordinates
	int x;
	int y;
};

typedef struct point_t point_t;

//constructor
point_t point_init( int x, int y );

//manual type casting from point_ptr to base_iface_ptr
base_iface_ptr point_to_base_iface( point_ptr ptr);

//manual type casting from point_ptr to sizible_iface_ptr
sizible_iface_ptr point_to_sizible_iface( point_ptr ptr);
