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

	fseek( input, 0, SEEK_SET );

	while ( fscanf( input, "%i %i %i %i %i", &claim, &x, &y, &w, &h ) > 0 ) {
		int disputed = 0;
		printf( "verifying claim %i (loc %i,%i sz %ix%i)\n", claim, x, y, w, h );
		for ( int i = x; i < x + w; i++ ) {
			for ( int j = y; j < y + h; j++ ) {
				if ( fabric[i][j] > 1 ) {
					disputed = 1;
				}
			}
		}
		if ( disputed == 0 ) {
			printf( "CLAIM %i IS UNDISPUTED\n", claim );
			return 0;
		}
	}

	printf( "%i total disputed claims\n", disputed );

	return 0;
}