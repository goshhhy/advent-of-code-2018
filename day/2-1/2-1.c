#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void ) {
	FILE* input = fopen( "input", "r" );
	char string[256];
	int counts[16];

	memset( counts, 26, sizeof( int ) );

	for ( int i = 0; i < 26; i++ ) {
		counts[i] = 0;
	}

	while ( fscanf( input, "%s", string ) > 0 ) {
		int localCounts[26], i, len;
		
		for ( i = 0; i < 26; i++ ) {
			localCounts[i] = 0;
		}
		printf( "\n" );

		printf( "first string is '%s'\n", string );
		len = strlen( string );

		for ( i = 0; i < len; i++ ) {
			printf( " string[i] is %c\n", string[i] );
			localCounts[ (string[i] - 'a') ]++;
		}

		printf( "letter counts: " );
		for ( i = 0; i < 26; i++ ) {
			printf( "%i ", localCounts[i] ); 
		}
		printf( "\n" );

		for ( i = 2; i < 16; i++ ) {
			for ( int j = 0; j < 26; j++ ) {
				if ( localCounts[j] == i ) {
					counts[i]++;
					printf( "string had a letter that repeated %i times\n", i );
					break;
				}
			}
		}

		printf( "counts: ");
		for ( i = 0; i < 16; i++ ) {
			printf( "%i ", counts[i] ); 
		}
		printf( "\n" );
	} 

	int final = 0;
	for ( int i = 0; i < 16; i++ ) {
		if ( counts[i] != 0 ) {
			if ( final == 0 ) {
				final = counts[i];
			} else {
				final = final * counts[i];
			}
		}
	}

	printf( "final: %i\n", final );

	return 0;
}