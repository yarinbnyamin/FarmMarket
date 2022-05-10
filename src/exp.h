/*
 * exp.h
 *
 *  Created on: Jan 12, 2022
 *      Author: ise
 */

#ifndef EXP_H_
#define EXP_H_
#include <exception>


class CowException : public exception{
public:
	virtual const char* what() const throw(){
		return "Insert valid number of cow farms\n";
	}
};

class SheepException : public exception{
public:
	virtual const char* what() const throw(){
		return "Insert valid number of sheep farms\n";
	}
};

class ChickenException : public exception{
public:
	virtual const char* what() const throw(){
		return "Insert valid number of chicken farms\n";
	}
};


#endif /* EXP_H_ */
