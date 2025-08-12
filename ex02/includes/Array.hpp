#ifndef ARRAY_HPP
# define ARRAY_HPP

# define MAX_VAL 1024

template< typename T>

class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(): _size( 0 ) {
			std::cout << "Default Constructor called: created empty Array of size 0" << std::endl;
			this->_array = new T[this->_size];
		}

		Array( unsigned int size ): _size( size ) {
			std::cout << "Constructor for an Array of size " << size << " called" << std::endl;
			this->_array = new T[this->_size];
		}

		Array( const Array &copy ): _size( copy.size() ) {
			std::cout << "Copy Constuctor called" << std::endl;
			this->_array = NULL;
			*this = copy;
		}

		~Array() {
			if ( this->_array != NULL )
				delete [] this->_array;
		}

		Array &operator=( const Array &obj ) {
			if ( this->_array != NULL )
				delete [] this->_array;
			if ( obj.size() != 0 ) {
				this->_size = obj.size();
				this->_array = new T[this->_size];
				for ( unsigned int i = 0; i < this->size(); i++ )
					this->_array[i] = obj._array[i];
			}
			return ( *this );
		}

		T &operator[]( unsigned int index ) {
			if (index >= this->_size || this->_array == NULL ) {
				std::cout << "index: " << index << std::endl;
				throw Array<T>::InvalidIndexException();
			}
			return ( this->_array[index] );
		}

		class	InvalidIndexException : public std::exception {
		    public:
			    virtual const char	*what() const throw();
		};

		unsigned int size() const {
			return ( this->_size );
		}

};

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw() {
	return ( "Error: Invalid index" );
}

#endif