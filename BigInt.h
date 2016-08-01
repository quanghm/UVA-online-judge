/*
 * BigInt.h
 *
 *  Created on: May 9, 2015
 *      Author: quang
 */

#ifndef BIGINT_H_
#define BIGINT_H_

template <class T>
class BigInt{
	T value;
public:
	BigInt(T v):value(v){};
	T divide(int d);
	BigInt add(BigInt t){
		T s;
		BigInt sum;

		return sum:
	};
	T substract(BigInt t);
};

template <class T>
T BigInt<T>::divide(int d){
	// d<10;
	int r;
}

#endif /* BIGINT_H_ */
