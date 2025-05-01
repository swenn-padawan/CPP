#include "Exception.hpp"

GradeException::GradeException(const std::string &msg): _message(msg){}

GradeException::~GradeException() throw(){};

const char* GradeException::what() const throw() {
	return (_message.c_str());
}
