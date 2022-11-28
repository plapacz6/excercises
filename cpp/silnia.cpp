#include <iostream>
using namespace std;

//recursive
int silnia_r(int x){
  if(x < 2) return 1;
  else return x * silnia_r(x - 1);
}

//iterative
int silnia_i(int x){
  double silnia = 1;
  if(x < 2) return silnia;  
  for(int i = x; i > 1; i--){
    silnia *= i;
  }
  return silnia;
}

#include <iostream>
#include <type_traits>

template <unsigned n>
struct factorial : std::integral_constant<int, n * factorial<n-1>::value> {};

template <>
struct factorial<0> : std::integral_constant<int, 1> {};

unsigned silnia_t2[6];
// silnia_t2[0] = factorial<0>::value; //przypisanie (tylko w funkcji)
// silnia_t2[1] = factorial<1>::value;
// silnia_t2[2] = factorial<2>::value;
// silnia_t2[3] = factorial<3>::value;
// silnia_t2[4] = factorial<4>::value;
// silnia_t2[5] = factorial<5>::value;

unsigned silnia_t[6] = {  //inicjalizacja
  factorial<0>::value,
  factorial<1>::value,
  factorial<2>::value,
  factorial<3>::value,
  factorial<4>::value,
  factorial<5>::value,
};

int main(){
  
  silnia_t2[0] = factorial<0>::value;
  silnia_t2[1] = factorial<1>::value;
  silnia_t2[2] = factorial<2>::value;
  silnia_t2[3] = factorial<3>::value;
  silnia_t2[4] = factorial<4>::value;
  silnia_t2[5] = factorial<5>::value;  

  for(int x = 5; x > -1; x--){
    cout << "silnia(" << x << ")" << endl;
    cout << silnia_r(x) << endl;
    cout << silnia_i(x) << endl;
    cout << silnia_t[x] << endl;
    cout << silnia_t2[x] << endl;
  }
  return 0;
}