#pragma once
#include<iostream>
#include <utility>
#include <vector>
#include <complex>
#include <vector>

template <typename T>
class Poly
{
public:
	std::vector<T> coef = {};
	Poly() = default;
	explicit Poly(std::vector<T> coef1) : coef(std::move(coef1)) {};
	Poly<T> operator + (const Poly<T>& p);
	Poly<T> operator - (const Poly<T>& p);
	Poly<T> operator * (const Poly<T>& p);
	//Poly<T> der();
	//Poly<T> integral();
};
template <typename T>
std::ostream& operator<<(std::ostream&, Poly<T> p);





template <typename T>
Poly<T> Poly<T>::operator + (const Poly<T>& p)
{
	std::vector<T> new_coef(std::max(coef.size(), p.coef.size()));
	Poly<T> res(new_coef);
	for (int i = 0; i < (std::max(coef.size(), p.coef.size())); ++i)
	{
		//std::cout << i << std::endl;
		double p1 = coef.size() > i ? coef[i] : 0;
		double p2 = p.coef.size() > i ? p.coef[i] : 0;
		new_coef[i] = p1 + p2;
		res.coef[i] = new_coef[i];
	}
	//std::cout << res.coef.size() << std::endl;
	return res;
}


template <typename T>
Poly<T> Poly<T>::operator - (const Poly<T>& p)
{
	std::vector<T>new_coef(std::max(coef.size(), p.coef.size()));
	Poly<T> res(new_coef);
	for (int i = 0; i < (std::max(coef.size(), p.coef.size())); ++i)
	{
		double p1 = coef.size() > i ? coef[i] : 0;
		double p2 = p.coef.size() > i ? p.coef[i] : 0;
		new_coef[i] = p1 - p2;
		res.coef[i] = new_coef[i];
	}
	return res;
}

template <typename T>
Poly<T> Poly<T>::operator * (const Poly<T>& p)
{

	std::vector<T>new_coef(coef.size() + p.coef.size() - 1);
	Poly res(new_coef);
	for (int i = 0; i < (coef.size() + p.coef.size() - 1); ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			new_coef[i + j] += coef[i] * p.coef[j];
			res.coef[i] = new_coef[i + j];
		}

	}
	return res;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Poly<T> p) {
	for (int i = 0; i < p.coef.size(); ++i) {
		os << p.coef[i] << " ";
	}
	return os;
}

