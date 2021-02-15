#include "std.h"

static d3_point_ptr base_iface_to_d3_point( base_iface_ptr ptr );

// implementation of the virtual method of base_iface interface
static const char* d3_point_get_name( base_iface_ptr ptr )
{
	static const char* null_point_ptr = "Null 3d point";
	static const char* some_point_ptr = "Some 3d point";

	d3_point_ptr casted_ptr = base_iface_to_d3_point( ptr );

	const char* result = null_point_ptr;
	if( casted_ptr->x || casted_ptr->y || casted_ptr->z )
	{
		result = some_point_ptr;
	}
	return result;
}

static d3_point_ptr sizible_iface_to_d3_point( sizible_iface_ptr ptr );

// implementation of the virtual method of sizible_iface interface
static unsigned int d3_point_get_size( sizible_iface_ptr ptr )
{
	d3_point_ptr casted_ptr = sizible_iface_to_d3_point( ptr );

	unsigned int size = ( unsigned int )( sizeof(casted_ptr->x ) + 
	sizeof( casted_ptr->y) + sizeof( casted_ptr->z ));
	return size;
}

//implementation of the common method of d3_point_t structure
static void d3_point_print_coordinates( d3_point_ptr ptr )
{
	printf("x = %u, y = %u, z = %u\n", ptr->x, ptr->y, ptr->z);
}

// d3_point_t constructor
// initialize all function pointers with private functions
d3_point_t d3_point_init( int x, int y, int z )
{
	d3_point_t point;

	point.get_name = d3_point_get_name;
	point.get_size = d3_point_get_size;
	point.print_coordinates = d3_point_print_coordinates;

	point.x = x;
	point.y = y;
	point.z = z;

	return point;
}

// this enum is required for type casting
enum 
{
	num_get_name_offset = sizeof( d3_point_print_coordinates_func ),
	num_get_size_offset = num_get_name_offset + 
		sizeof( get_name_func_ptr ),
};

// type casting implementation
static d3_point_ptr base_iface_to_d3_point( base_iface_ptr ptr )
{
	return (d3_point_ptr)( (char*)ptr - num_get_name_offset );
}

base_iface_ptr d3_point_to_base_iface( d3_point_ptr ptr )
{
	return (base_iface_ptr)( (char*)ptr + num_get_name_offset );
}

static d3_point_ptr sizible_iface_to_d3_point( sizible_iface_ptr ptr)
{
	return (d3_point_ptr)( (char*)ptr - num_get_size_offset );
}

sizible_iface_ptr d3_point_to_sizible_iface( d3_point_ptr ptr )
{
	return (sizible_iface_ptr)( (char*)ptr + num_get_size_offset );
}

