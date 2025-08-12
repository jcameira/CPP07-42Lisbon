#ifndef ITER_HPP
# define ITER_HPP

# include <string>

template< typename T >

void	iter( T *array, int arr_len, void ( *func )( T & ) ) {
	if ( array == NULL || func == NULL )
		return ;
	for ( int i = 0; i < arr_len; i++ )
		func( array[i] );
}

#endif