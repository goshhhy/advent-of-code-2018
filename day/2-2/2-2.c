#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void ) {
	FILE* f = fopen( "input", "r" );
	char boxList[251][64];

	printf( "Loading box IDs\n" );

	for ( int i = 0; fscanf( f, "%s", boxList[i] ) > 0; i++ ) {
		printf( "." );
	}
	printf( "\nOK\n\n" );

	printf( "Searching for matching box IDs\n" );

	for ( int i = 0; i < 251; i++ ) {
		printf( "." );
		char* firstBox = boxList[i];
		for ( int j = i; j < 251; j++ ) {
			char* secondBox = boxList[j];
			int shared = 0;
			for ( int n = 0; n < strlen( firstBox ); n++ ) {
				if ( firstBox[n] == secondBox[n] )
					shared++;
			}

			if ( shared == strlen( firstBox ) - 1 ) {
				printf( "\n\nFOUND: " );
				for ( int n = 0; n < strlen( firstBox ); n++ ) {
					if ( firstBox[n] == secondBox[n] )
						printf( "%c", firstBox[n] );
				}
				printf( "\n" );
				return 0;
			} 

		}

	}

	return 1;
}