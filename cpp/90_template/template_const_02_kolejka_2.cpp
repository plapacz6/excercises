#include <iostream>
using namespace std;

template <typename T>
class kolejka;

template <typename T>
int pobierz_dlugosc_kolejki(kolejka<T>& k){
  return kolejka<T>::dlugosc_kolejki;
}
template <typename T>
class kolejka{

  struct el_kolejki {
    T& el;
    el_kolejki* next;
    el_kolejki(T& el_) : el(el_), next(nullptr) {};
  };

  static int dlugosc_kolejki;
  el_kolejki* first;
  el_kolejki* last;

 public:
  kolejka();
  ~kolejka();

  void push_back(T&);
  T& pop_front();

  friend
  int pobierz_dlugosc_kolejki<>(kolejka<T>& k);
};


template <typename T>
int kolejka<T>::dlugosc_kolejki = 0;

template <typename T>
kolejka<T>::kolejka(){
  first = nullptr;
  last = nullptr;
  dlugosc_kolejki = 0;
  cout << "kolejka utworzona" << endl;
}

template <typename T>
kolejka<T>::~kolejka(){
  el_kolejki* tmp;             //elementy w kolejnie nie zostaly zniszczone 
  while(first != nullptr){        //uzytkownik kolejki powinienie sie zatroszcyzc
    tmp = first->next;            //bo on je tworzy i niszczy
    delete first;                 //wiec trzeba uwazac zeby nie stracic z nimi kontaktu
    first = tmp;                  //poza kolejka, kolejka tylko je ustawia w kolejnosci do przetworzenia jakiegos
  }
  cout << "kolejka zniszczona" << endl;
}

template <typename T>
void kolejka<T>::push_back(T& x){
  
  if(first == nullptr) {
    last = new el_kolejki(x);
    first = last;
  }
  else {
    last->next = new el_kolejki(x);
    last = last->next;
  }
  dlugosc_kolejki++;
}

template <typename T>
T& kolejka<T>::pop_front(){
  T* px = &first->el;
  el_kolejki* tmp = first->next;
  delete first;
  first = tmp;
  dlugosc_kolejki--;
  return *px;
}

int main(){

  string tbl[] = {"to", "jest", "jakies", "zdanie", ".kropka"};
  kolejka<string> k2;
  for(int i = 0; i < 5; i++){
    k2.push_back(tbl[i]);
    cout << "dlugosc kolejki k2: " << pobierz_dlugosc_kolejki(k2) << endl;    
  }
  for(int i = 0; i < 5; i++){
    cout << k2.pop_front() << " ";    
  }
  cout << endl;
  cout << "dlugosc kolejki k2: " << pobierz_dlugosc_kolejki(k2) << endl;    


  kolejka<int> k1;
  for(int i = 0; i < 10; i++){
    k1.push_back( *(new int(i)));
    cout << "dlugosc kolejki k1: " << pobierz_dlugosc_kolejki(k1) << endl;
  }
  for(int i = 0; i < 10; i++){
    int *px;    
    px = &k1.pop_front();
    cout << "pop_front z k1: " << *(px) << endl;
    cout << "dlugosc kolejki k1: " << pobierz_dlugosc_kolejki(k1) << endl;
    delete px;
  }  
  return 0;
}


