#include <stdio.h>

void main( void ) {
	int total = 0, change;
	FILE* f = fopen( "input", "r" );

	printf( "Testing chronal frequency tracking...\n" );

	while ( fscanf( f, "%i", &change ) > 0 )
		total += change;

	printf( "Done. Result: %i\n", total );
}