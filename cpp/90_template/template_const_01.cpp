#include <iostream>
using namespace std;

//--------- HELPING DECLARATIONS -------------
template <typename, int SHIP_SIZE>
class ufo_t;

template<typename TT, int SHIP_SIZE>
void print_size(ufo_t<TT,SHIP_SIZE>&);

//--------- CLASS DEFINITION  -----------------
template <typename T, int SHIP_SIZE>
class ufo_t
{
    int ship_size;
    static int last_created_nr;
    static ufo_t *p_last_created;
    static int number_of_ships;        
  public:      
    ufo_t* prev;    
    ufo_t(int s_s);    
    ~ufo_t();
    static void print_number_of_ships();
    
    friend 
    void print_size<>(ufo_t<T,SHIP_SIZE>&);
};

//----------  METHODS -----------------------
template <typename T, int SHIP_SIZE>
ufo_t<T,SHIP_SIZE>::ufo_t(int s_s) : ship_size(s_s){
  number_of_ships++;
  if(number_of_ships == 0)
    prev = nullptr;
  else
    prev = p_last_created;  
  p_last_created = this;
}
template <typename T, int SHIP_SIZE>
ufo_t<T,SHIP_SIZE>::~ufo_t(){
  number_of_ships--;
  p_last_created = this->prev;
}

//-----------  STATIC MEMBERS ----------------
template <typename T, int SHIP_SIZE>
int ufo_t<T,SHIP_SIZE>::last_created_nr = 0;

template <typename T, int SHIP_SIZE>
ufo_t<T,SHIP_SIZE>* ufo_t<T,SHIP_SIZE>::p_last_created = nullptr;

template <typename T, int SHIP_SIZE>
int ufo_t<T,SHIP_SIZE>::number_of_ships = 0;

template <typename T, int SHIP_SIZE>
void ufo_t<T,SHIP_SIZE>::print_number_of_ships(){
  cout << "STATIC: current number_of_ships:" << number_of_ships << endl;
}

// ------------  FRIEND --------------------
template<typename TT, int SHIP_SIZE>
void print_size(ufo_t<TT, SHIP_SIZE>& x){
  cout << "size of ship: " << x.ship_size << endl;
}

//

int main(){  
  ufo_t<int, 4> *ufo_last;
  ufo_t<int, 4> *ufo_tmp;
  for(int i = 5; i < 10; i++){
    for(int j = 0; j < 10; j++){
      ufo_last = new ufo_t<int, 4>(j);
    }
  }
  while(ufo_last->prev){
    ufo_last->print_number_of_ships();
    print_size(*(ufo_last));
    ufo_tmp = ufo_last;
    ufo_last = ufo_last->prev;
    delete(ufo_tmp);    
  }


  return 0;
}