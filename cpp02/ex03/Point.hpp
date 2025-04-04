#include <iostream>
#include "Fixed.hpp"

class Point{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const Point &point);
		Point(float x, float y);
		~Point();

		Fixed& operator = (const Fixed& fixed);

		const Fixed getX( void );
		const Fixed getY( void );
		void		setX( const Fixed x );
		void		setY( const Fixed y );
};

// pour la fonction regarder la video sur la rasterisation
bool bsp( Point const a, Point const b, Point const c, Point const point);
