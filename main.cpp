#include <iostream>
#include <string>
#include "Singleton.hpp"
using namespace std;

class Item : private Singleton<Item>{
public:
  static Item *GetItem (){ return GetInstance(); }
  string Get_Name (void){ return name_; }
  void Set_Name (string name){ name_ = name; }

private:
  using Singleton::Singleton;
  string name_;
};

int main(){
  Singleton_class *sc1 = Singleton_class::GetInstance();
  Singleton_class *sc2 = Singleton_class::GetInstance();

  sc1->Set_Num(10);
  cout << sc1->Get_Num() << endl;
  sc2->Set_Num(20);
  cout << sc1->Get_Num() << endl;

  Item *single1 = Item::GetItem();
  Item *single2 = Item::GetItem();

  single1->Set_Name("Iron sword");
  cout << single1->Get_Name() << endl;
  single2->Set_Name("Iron shield");
  cout << single1->Get_Name() << endl;

  return 0;
}
