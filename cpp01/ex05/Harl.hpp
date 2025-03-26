#pragma once

#include <iostream>

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	call_level(int i);
	public:
		Harl( void );
		~Harl( void );
		void	complain( std::string level );
};
