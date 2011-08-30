#ifndef _SINGLETON_
#define _SINGLETON_

#include <iostream>

template <typename T>
class Singleton
{
protected:
  Singleton () { }
  ~Singleton () { std::cout << "destroying singleton." << std::endl; }

public:
  static T *getInstance()
  {
      if(!_singleton)
        _singleton = new T;

    return (static_cast<T*> (_singleton));
  }

  static void kill()
  {
      if(!_singleton)
          return;

        delete _singleton;
        _singleton = NULL;
  }

private:
  static T *_singleton;
};

template <typename T>
T *Singleton<T>::_singleton = NULL;

#endif
