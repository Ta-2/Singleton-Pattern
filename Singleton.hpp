#ifndef SINGLE_HPP
#define SINGLE_HPP

#include <stdio.h>
#include <iostream>
class Singleton_class{
public:
  static Singleton_class *GetInstance(){
    if(singleton_ == NULL) singleton_ = new Singleton_class;
    return singleton_;
  }
  void Set_Num( int num ){ num_ = num; }
  int Get_Num( void ){ return num_; }

private:
  Singleton_class (){}
  Singleton_class (const Singleton_class& r){}
  Singleton_class &operator=(const Singleton_class& r);
  static Singleton_class *singleton_;
  int num_ = 0;
};
Singleton_class *Singleton_class::singleton_ = NULL;

template <class user>
class Singleton {
protected:
  static user *GetInstance(){
    if(singleton_ == NULL) singleton_ = new user;
    return singleton_;
  }

  Singleton (){};
  Singleton (const Singleton& r){}
  Singleton &operator=(const Singleton& r);
  static user *singleton_;
};

template<class user>
user *Singleton <user>::singleton_ = NULL;

#endif
