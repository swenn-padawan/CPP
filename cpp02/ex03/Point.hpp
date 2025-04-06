#include <iostream>
#include "Fixed.hpp"

class Point{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const Point &point);
		Point(const Fixed x, const Fixed y);
		~Point();

		Point& operator=( Point const & );

		const Fixed getX( void );
		const Fixed getY( void );
		void		setX( const Fixed x );
		void		setY( const Fixed y );
};
// pour la fonction regarder la video sur la rasterisation
