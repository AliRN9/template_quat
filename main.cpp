#include <iostream>
#include <vector>
#include "quat.hpp"
#include "poly.hpp"

using namespace std;

int main() {
    std::vector<Quat<double> > vq{{1., 2., 3., 4.},
                                  {5,  6,  7,  8}};
    Poly<Quat<double> > p3(vq);
//    cout << p3 << endl;

    std::vector<Quat<double> > vq1{{2., 4., 6., 8},
                                   {10., 12., 14., 16.}};
    Poly<Quat<double> > p4(vq1);
    cout << "first: " << p3 << endl;
    cout << "second: " << p4 << endl;
    cout << " + " << endl;
    cout << (p3 + p4) << endl;
    cout << (p3 - p4) << endl;
    cout << (p3 * p4) << endl;
}