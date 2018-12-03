#include <stdio.h>
#include <stdlib.h>

int main( void ) {
	int total = 0, change, i, j;
	FILE* f = fopen( "input", "r" );
	int* history = malloc ( 1024 * sizeof ( int ) ), history_count = 0, history_max = 1024;
	int* flist = malloc ( 2048 * sizeof ( int ) ), flist_count = 0, flist_max = 2048;

	printf( "Locking on to frequency pattern\n" );
	
	while ( fscanf( f, "%i", &change ) > 0 ) {
		flist[flist_count++] = change;
		if ( flist_count >= flist_max ) {
			flist_max += 1024;
			flist = realloc( flist, flist_max * sizeof ( int ) );
		}
		printf( "." );
	}
	printf( "\nOK\n\n" );

	printf( "Beginning chronal calibration sequence, please wait\n" );

	history[history_count++] = total;
	while ( 1 ) {
		printf( "." );
		fflush( stdout );
		for ( i = 0; i < flist_count; i++ ) {
			total += flist[i];

			history[history_count++] = total;
			if ( history_count >= history_max ) {
				history_max += 1024;
				history = realloc( history, history_max * sizeof ( int ) );
			} 

			for ( j = 0; j < history_count - 1; j++ ) {
				if ( history[j] == total ) {
					printf( "\nCALIBRATION COMPLETE\nFinal frequency: %i\n", total );
					return 0;
				}
			}
		}
	} 

	return 1;
}