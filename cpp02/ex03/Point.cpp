/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stetrel <stetrel@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 02:35:14 by stetrel           #+#    #+#             */
/*   Updated: 2025/04/22 11:51:20 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::~Point(){}

Point::Point(): _x(0), _y(0){}

Point::Point(const Point &point): _x(point._x), _y(point._y){}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y){}

const Fixed	Point::getX( void ){
	return (this->_x);
}

const Fixed	Point::getY( void ){
	return (this->_y);
}

Point& Point::operator=( Point const & ){
	return (*this);
}

