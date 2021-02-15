#include "std.h"

static point_ptr base_iface_to_point( base_iface_ptr ptr );

//implementation of the virtual method of the base_iface interface
static const char* point_get_name( base_iface_ptr ptr )
{
	static const char* null_point_ptr = "Null point";
	static const char* some_point_ptr = "Some point";

	point_ptr casted_ptr = base_iface_to_point( ptr );

	const char* result = null_point_ptr;
	if( casted_ptr->x || casted_ptr->y )
	{
		result = some_point_ptr;
	}
	return result;
}

static point_ptr sizible_iface_to_point(sizible_iface_ptr ptr );

//implementation of the virtual method 
//of the sizible_iface interface
static unsigned int point_get_size( sizible_iface_ptr ptr)
{
	point_ptr casted_ptr = sizible_iface_to_point( ptr );

	unsigned int size = (unsigned int)(sizeof(casted_ptr->x ) + 
		sizeof(casted_ptr->y));
	return size;
}

//implementation of common method point_t structure
static void point_print_coordinates( point_ptr ptr)
{
	printf("x = %u, y = %u\n", ptr->x, ptr->y);
}

//constructor point_t
//initialize all function pointers with private function
point_t point_init(int x, int y)
{
	point_t point;

	point.get_name = point_get_name;
	point.get_size = point_get_size;
	point.print_coordinates = point_print_coordinates;

	point.x = x;
	point.y = y;

	return point;
}

//this enum required for type casting
enum
{
	num_get_name_offset = 0,
	num_get_size_offset = sizeof( get_name_func_ptr),
};

//type casting implementation
static point_ptr base_iface_to_point( base_iface_ptr ptr )
{
	return (point_ptr)( (char*)ptr - num_get_name_offset );
}

base_iface_ptr point_to_base_iface( point_ptr ptr )
{
	return (base_iface_ptr)( (char*)ptr + num_get_name_offset);
}

static point_ptr sizible_iface_to_point( sizible_iface_ptr ptr )
{
	return (point_ptr)( (char*)ptr - num_get_size_offset );
}

sizible_iface_ptr point_to_sizible_iface( point_ptr ptr )
{
	return (sizible_iface_ptr)( (char*)ptr + 
			num_get_size_offset );
}
