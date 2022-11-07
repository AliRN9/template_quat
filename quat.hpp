#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <complex>
#include <vector>

using namespace std;

template<typename T>
class Quat
{
public:
	T s=0;
	T x=0;
	T y=0;
	T z=0;
	Quat() = default;
	 
	Quat(T scalaris , T i, T j , T k ) 
	{
		s = scalaris;
		x = i;
		y = j;
		z = k;
	}

	Quat<T> operator + (const Quat<T>& q);
	Quat<T> operator - (const Quat<T>& q);
	Quat<T> operator * (const Quat<T>& q);
	bool operator == (const Quat<T>& qt);
	bool operator != (const Quat<T>& q);
	Quat<T> operator += (const Quat<T>& q);
	Quat<T> operator * (int n);
	Quat<T> operator = (int n);

};


template <typename T>
Quat<T> Quat<T>::operator +(const Quat<T>& q)
{
	Quat<T> res(s - q.s, x - q.x, y - q.y, z - q.z);
	return res;
}


template <typename T>
Quat<T> Quat<T> :: operator -(const Quat<T>& q)
{
	Quat<T> res(s - q.s, x - q.x, y - q.y, z - q.z);
	return res;
}


template <typename T>
Quat<T>  Quat<T> :: operator * (const Quat<T>& q)
{
	Quat<T>	res(
		s * q.s - x * q.x - y * q.y - z * q.z,
		s * q.x + x * q.s + y * q.z - z * q.y,
		s * q.y - x * q.z + y * q.s + z * q.x,
		s * q.z + x * q.y - y * q.x + z * q.s
		);
	return res;

}

template<typename T>
bool Quat<T>::operator == (const Quat<T>& q)
{
	bool res = ((s == q.s) && (x == q.x) && (y == q.y) && (z == q.z));
	return res;
}

template<typename T>
bool Quat<T>::operator != (const Quat<T>& q)
{
	bool res = ((s != q.s) || (x != q.x) || (y != q.y) || (z != q.z));
	return res;
}


template<typename T>
Quat<T> Quat<T>::operator += (const Quat<T>& q) 
{
	Quat<T>	res = (s = s + q.s, x = x + q.x, y = y + q.y, z = z + q.z);
	return res;
}

template<typename T>
Quat<T> Quat<T>::operator * (int n)
{
	Quat<T> res(s * n, x * n, y * n, z * n);
	return res;
}

template<typename T>
Quat<T> Quat<T>::operator = (int n)
{
    this->s=n;
    this->x=n;
    this->y=n;
    this->z=n;

    return *this;
}

template<typename T>
ostream& operator<<(ostream& os, Quat<T>& q)
{
	os << "(" << q.s << ", [" << q.x << ", " << q.y << ", " << q.z << "])";
	return os;
}