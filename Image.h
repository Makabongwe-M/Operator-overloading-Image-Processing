#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include <tr1/unordered_map>
#include <queue>
#include <bits/stdc++.h>
using namespace std::tr1;
using namespace std;

class Image{

  public:
      Image();
      void load(string filename);
      void save(string filename);
      std::unique_ptr<unsigned char[]> data;



      class iterator{
          friend Image;
          private:
              unsigned char *ptr;
              // construct only via Image class (begin/end)
              iterator(u_char *p) : ptr(p) {}

          public://copy construct is public
              iterator( const iterator & rhs) : ptr(rhs.ptr) {}

              iterator& operator++(){     //prefix
                ptr++;
                return *this;
              }

              iterator operator++(int){   //postfix
                iterator temp = *this;
                ++*this;
                return temp;
              }

      };

      // define begin()/end() to get iterator to start and
      // "one-past" end.
      iterator begin(void){
         return iterator(data.get());
      }

      iterator end(void){
          return iterator(data.get()+(width*height));
      }


  private:
    int width, height;



};
#endif
