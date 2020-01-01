#ifndef _1D_SimpsonRule_hpp
#define _1D_SimpsonRule_hpp

#include<functional>

namespace _1D {

/** @class 
  * @brief A class that implements Simposon's rule.
  * @author C.D. Clark III
  */
template<typename T>
class SimpsonRule
{
  public:
    SimpsonRule() = default;

    // This version will integrate a callable between two points
    template<typename F>
    T operator()( F f, T a, T b, size_t N ) const;

  protected:
};


template<typename T>
template<typename F>
T SimpsonRule<T>::operator()( F f, T a, T b, size_t N ) const
{
  T sum = 0;
  T dx = static_cast<T>(b-a)/N; // size of each interval
  T x;
  for(x = a; x < b; x += dx)
  {
    sum += f(x) + 4*f(x + dx/2) + f(x + dx);
  }
  // note that 2*h = dx
  sum *= dx/6;
  return sum;
}

}


#endif // include protector
