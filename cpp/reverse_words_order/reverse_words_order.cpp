#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

char* reverse_word_order_v1(char *strz){
  char *sp_ptr; 
  char tmp;
  char* tmp_dest;
  size_t strz_len;

  //checking if the data is correct:
  if(strz == nullptr) return nullptr;
  strz_len = strlen(strz);  
  if(strz_len == 0) return nullptr;
  sp_ptr = strchr(strz, ' ');
  if(sp_ptr == nullptr || sp_ptr == strz || sp_ptr == strz + strz_len - 1) 
    return nullptr;   
  tmp_dest = strz;

  //swap:  
  char *itL;
  for(itL = sp_ptr; itL > tmp_dest; itL--){   //space ->
    *(itL) = *(itL - 1);  
  }
  for(char* itR = sp_ptr + 1; *(itR) ; itR++){  //R<-
    tmp = *(itR);
    for(itL = itR; itL > tmp_dest + 1; itL--){  //L->
      *(itL) = *(itL - 1); 
    }
    *(tmp_dest) = tmp;
    tmp_dest++;
  }
  *(itL) = ' ';                                //space <-
  return strz;
}


//TODO:
char* reverse_word_order_v2(char *strz){
  return nullptr;
}



//*************  TESTS *******************




namespace plapacz6_test_namespace {
struct test_t {
  const char* in;
  const char* out;
  bool correct;
  test_t(const char* in_, const char* out_, bool c_)
    : in(in_), out(out_), correct(c_) {}    
};
typedef vector<test_t> vtest_t;
void addt(vtest_t& vt, const char* in_, const char* out_, bool c_){
  vt.emplace_back(test_t(in_,out_,c_));
}
}//namespace


int main(int argc, char** argv){

using plapacz6_test_namespace::test_t;
using plapacz6_test_namespace::addt;
using plapacz6_test_namespace::vtest_t;

  cout << "preparing tests" << endl;
  vtest_t vt;

  addt(vt,"napis1 nap2","nap2 napis1",1);
  addt(vt,"imie nazwisko","nazwisko imie",1);
  addt(vt,"zamiana slow","slow zamiana",1);
  addt(vt,"dlugieslowo a","a dlugieslowo",1);
  addt(vt,"b dlugieslowo","dlugieslowo b",1);
  addt(vt," slowo",nullptr,1);
  addt(vt,"slowo ",nullptr,1);
  addt(vt,"",nullptr,1);
  addt(vt,nullptr,nullptr,1);

  int pass = 0;
  int fail = 0;
  char* odp;

/*
  char *ptr0= nullptr;
  const char *ptr1 = const_cast<const char*>(ptr0);
  char *ptr2 = const_cast<char*>(ptr1);
  strcmp(ptr0,ptr1);
  cout << ptr0;
  strlen(ptr0);
  //string str0 = string(ptr0,strlen(ptr0));  //<<naruszenie ochr.pam
*/
  cout << "start testing" << endl;
  #define pstrz_MAX_LENGTH (1000)
  char bstrz[pstrz_MAX_LENGTH];
  char *pstrz = bstrz;
  for(vtest_t::iterator it = vt.begin(); it != vt.end(); it++){
    memset(pstrz,0,pstrz_MAX_LENGTH);
    cout << ".";
    if( it->in != nullptr) {
      strncpy(pstrz,it->in,pstrz_MAX_LENGTH - 1);
      cout << "_";
      pstrz[pstrz_MAX_LENGTH - 1] = '\0';
    }
    else {     
      pstrz = nullptr;
      cout << "_";
    }
    cout << "v";
    odp = reverse_word_order_v1(pstrz);
    cout << "^";
    cout << "\t[" 
      << ((it->in!=nullptr)?it->in:"nullptr") 
      << "]" <<  " \t-> [" 
      << ((odp!=nullptr)?odp:"nullptr") 
      << "]\t";        
    if((strcmp(
      (odp!=nullptr)?odp:"nullptr"
      , 
      (it->out!=nullptr)?it->out:"nullptr"
    ) == 0)  == it->correct){ 
      cout << "(+)";
      pass++;
    }
    else{
      cout << "(-)";
      fail++;
    }
    cout << endl;
  }
  cout << endl;
  cout << "stop testing" << endl;
  cout << "pass: " << pass << " fail: " << fail << endl;

  return EXIT_SUCCESS;
}
