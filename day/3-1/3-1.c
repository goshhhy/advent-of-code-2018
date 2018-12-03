#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void ) {
	FILE* input = fopen( "input", "r" );
	char string[256];
	int fabric[1024][1024];
	int claim, x, y, w, h;
	int disputed = 0;

	for ( int i = 0; i < 1024; i++ ) {
		for ( int j = 0; j < 1024; j++ ) {
			fabric[i][j] = 0;
		}
	}

	while ( fscanf( input, "%i %i %i %i %i", &claim, &x, &y, &w, &h ) > 0 ) {
		printf( "processing claim %i (loc %i,%i sz %ix%i)\n", claim, x, y, w, h );
		for ( int i = x; i < x + w; i++ ) {
			for ( int j = y; j < y + h; j++ ) {
				fabric[i][j]++;
			}
		}
	}

	for ( int i = 0; i < 1024; i++ ) {
		for ( int j = 0; j < 1024; j++ ) {
			if ( fabric[i][j] > 1 ) {
				printf( "square at %i,%i is in %i claims\n", i, j, fabric[i][j] );
				disputed++;
			}
		}
	}

	printf( "%i total disputed claims\n", disputed );

	return 0;
}