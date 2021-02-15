#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include "std.h"

void print_name( base_iface_ptr ptr )
{
	printf("name = \"%s\"\n", ptr->get_name( ptr ) );
}

void print_size( sizible_iface_ptr ptr)
{
	printf("size = %u\n", ptr->get_size( ptr ) );
}

int main(int argc, char** argv)
{
	// constructing several points
	point_t null_point = point_init( 0, 0 );
	point_t some_point = point_init( 1, 5 );

	d3_point_t d3_null_point = d3_point_init( 0, 0, 0 );
	d3_point_t d3_some_point = d3_point_init( 0, 1, 0 );

	// display the point name throuth the interface
	print_name( point_to_base_iface( &null_point ) );
	
	// display the point size throuth the interface
	print_size( point_to_sizible_iface( &null_point ) );

	// print point coordinates
	null_point.print_coordinates( &null_point );

	printf("\n");

	//repeat for all points
	
	print_name( point_to_base_iface( &some_point ) );
	print_size( point_to_sizible_iface( &some_point ) );
	some_point.print_coordinates( &some_point );

	printf("\n");
	
	print_name( d3_point_to_base_iface( &d3_null_point ) );
	print_size( d3_point_to_sizible_iface( &d3_null_point ) );
	d3_null_point.print_coordinates( &d3_null_point );

	printf("\n");
	
	print_name( d3_point_to_base_iface( &d3_some_point ) );
	print_size( d3_point_to_sizible_iface( &d3_some_point ) );
	d3_some_point.print_coordinates( &d3_some_point );

	printf("\n");

	return 0;
}
	
