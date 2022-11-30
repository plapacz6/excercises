#include <iostream>
#include <vector>
using namespace std;

/* ----------------------------------- */
template <typename T>
struct magazynek_t {
  std::vector<T> dane;
  magazynek_t() = default;
  //magazynek_t(magazynek_t &) = delete;

  template <typename TTT>
  magazynek_t(magazynek_t<TTT> & o_){
    cout << "kopiujacy z tego samgo szablonu ale moze byc inny T" << endl;
    for(auto d: o_.dane) {
      dane.push_back(d);  //mozliwa konwersja
    }
    //dane = o_.dane;//gdy inne typy T i TTT to nie dziala 
    //                 (bo konwerja w = )
  }
  magazynek_t(magazynek_t & o_){
    cout << "kopujacy z identycznego typu" << endl;
    dane = o_.dane;    
  }

// 
//  magazynek_t(magazynek_t<double> & o_) {
//    cout << "kopioujacy z magazynek_t<double>" << endl;
//    dane = o_.dane;
//    
//    /*
//    dane.clear();
//    for(auto d : o_.dane)
//      dane.push_back(d);
//    */
//  }
//

  //konstr. "konwertujacy"
  template <typename WW>
  magazynek_t(const WW& data);

  template <typename Z>
  magazynek_t(initializer_list<Z>);

  template <typename ZZ>
  void przyjmij(ZZ a){
    T roboczy = a;
    cout << "przyjmuje: " << a << " --> " << roboczy << std::endl;
  }

  T& get_data(){
    return dane;
  }
  T daj_wektor() const {
    return dane;
  }

  void drukuj(){
    for( auto d : dane )
      cout << d << " ";
    cout << endl;
  }
  
};
/* ----------------------------------- */
template <typename T>
template <typename WW>
magazynek_t<T>::magazynek_t(const WW& data){
  cout << "k.konwertujacy: \n";
  for(auto d : data.daj_wektor()) 
    dane.push_back(d);
  drukuj();
}
/* ----------------------------------- */
template <typename T>
template <typename Z>
magazynek_t<T>::magazynek_t(initializer_list<Z> il){  
  cout << "inicjalizers list:" << endl;
  for(auto d: il) {
    //przyjmij(d);
    dane.push_back(d);
  }
}
/* ----------------------------------- */



/* ----------------------------------- */
int main(){
  /*
  wszyskie inicjalizoatory na liscie inicjalizoatorow musza byc 
  tego samgo typu, bo inaczej dedukcja typu sie nie udaje
  czyli np.   9.  zamiast 9
  */
  //magazynek_t<char> m1 = {3.14, 434.445432, 1.234235, 9};
  magazynek_t<char> m1 = {3.14, 434.445432, 1.234235, 9.};


  //magazynek_t<char> m1 =  {98,99,100,34,45,99};
  m1.drukuj();
  //magazynek_t<double> m2 = {.234, 1.344, 99999.99};
  magazynek_t<double> m2 = {98, 99, 100};
  m2.drukuj();
  magazynek_t<int> m3 = {3.14, 4544.444, 9999.999, 9.};
  m3.drukuj();
  magazynek_t<char> m4({3.14, 434.445432, 1.234235, 9.});
  m4.drukuj();
  magazynek_t<char> m5(m2);
  m5.drukuj();
  magazynek_t<char> m6(m5);
  m6.drukuj();
  return 0;
}
