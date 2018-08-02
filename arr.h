#ifndef ARR_H
#define ARR_H

#include<initializer_list>
#include<vector>
#include<assert.h>










template<typename T> void copyover ( T* read_from, T* write_to, unsigned int write_sz )
{	for( int i = 0; i < write_sz; ++i )
	{	write_to[i] = read_from[i];
	}
}



template<typename T> class arr{
	public:
		arr()
		{	_size = 0;
			_data = nullptr;
		}
	
		arr( std::initializer_list<T> ls )
		{	_size = ls.size();
			_data = new T[ _size ];
			std::copy(ls.begin(),ls.end(), _data );
		}
	
		arr<T>( const arr<T> &other )
		{	_data = new T[other._size];
			_size = other._size;
			copyover( other._data, _data, _size );
		}
	
		arr<T>( T* n_data, unsigned int n_size )
		{	_data = n_data;
			_size = n_size;
		}
		
		arr<T>( unsigned int n_sz )
		{	_size = n_sz;
			_data = new T[_size];
		}
		
		T& operator[]( unsigned int ix )
		{	if( ix > _size ) resize( ix + 1);
			return _data[ix];
		}

		arr<T> operator+( arr<T> other )
		{	arr newarr(_size + other._size);
			copyover( _data, newarr._data, _size);
			copyover( other._data, newarr._data + _size, other._size);
			return newarr;
		}
		
		arr<T> operator()( unsigned int begin, unsigned int end )
		{	if( end < begin )
			{	arr ret = this->operator()(0,end) + (this->operator()(begin,this->_size - 1));
				return ret;
			}
			else return slice( begin, end );
		}
		
		~arr()
		{	delete[] _data;
		}
		
		unsigned int size()
		{	return _size;
		}
		
		void mutate( void(*fp)(T object))
		{	for( int i = 0; i < _size; ++i )
			{	fp(_data[i]);
			}
		}
		
		arr map( T (*fp) (T datum))
		{	arr ret(_size);
			for( int i = 0; i < ret._size; ++i )
			{	ret._data[i] =  fp(_data[i]);
			}
			return ret;
		}
		
		T acc( T (*fp) (T a, T b))
		{	T tally = _data[0];
			if( _size == 1 ) return tally;
			
			for( int i = 0; i < _size; ++i )
			{	tally = fp( tally, _data[i] );
			}
			return tally;
		}
		
		
	private:
		arr slice( unsigned int begin, unsigned int end )
		{	arr newarr(end - begin + 1);
			copyover( _data + begin, newarr._data, end - begin + 1);
			return newarr;
		}
	
		void resize( unsigned int n_sz )
		{	_size = n_sz;
			T* n_data = new T[ _size ];
			copyover( _data, n_data, _size );
			delete _data;
			_data = n_data;
		}
		
		T* _data;
		unsigned int _size;
};



#endif