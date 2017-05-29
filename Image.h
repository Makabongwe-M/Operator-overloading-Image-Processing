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
      void writeImage(std::unique_ptr<unsigned char[]> &array);
      //std::unique_ptr<unsigned char[]> getData();


      class iterator{
          friend Image;
          //friend std::ostream& operator<< (std::ostream &out, const iterator &dt);
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
                iterator temp (*this);
                ++*this;
                return temp;
              }

              bool operator == (iterator &b) const{
                return (ptr== b.ptr);
              }

              bool operator!=(const iterator &other) const {
                return !(ptr == other.ptr);
              }

              unsigned char operator *() const{
                 return *ptr;
              }


      };

      // define begin()/end() to get iterator to start and
      // "one-past" end.
      iterator begin(void){
         return iterator(data.get());
      }

      iterator end(void){
          return iterator(data.get()+(numberofPixels));
      }

      std::unique_ptr<unsigned char[]> operator+(Image& other){
          //iterator temp;
          //cout << "here";
          std::unique_ptr<unsigned char[]> tempData(new unsigned char[numberofPixels]);

          Image::iterator beg  = this->begin(), end = this->end();
          Image::iterator beg2  = other.begin(), end2 = other.end();
          int count = 0;
          while(beg != end){
            //cout << (int)(*(beg));
            int diff = (int)(*(beg)) + (int)(*(beg2));
            //cout << diff<<" ";
            char result = (char)(diff);
            //cout << result <<" ";
            tempData[count] = result;
            //cout << tempData[count];
            beg++;
            beg2++;
            count++;
          }
          //temp = *(this->ptr) + *(other->ptr);
          //cout << sizeof(tempData)<<" test  ";
          writeImage(tempData);
          return tempData;
      }

      std::unique_ptr<unsigned char[]> operator-(Image& other){
          //iterator temp;
          std::unique_ptr<unsigned char[]> tempData(new unsigned char[numberofPixels]);

          Image::iterator beg  = this->begin(), end = this->end();
          Image::iterator beg2  = other.begin(), end2 = other.end();
          int count = 0;
          while(beg !=end){
            int diff = (int)(*(beg)) - (int)(*(beg2));
            //cout << diff<<" ";
            char result = (char)(diff);
            //cout << result <<" ";
            tempData[count] = result;
            //cout << tempData[count];
            beg++;
            beg2++;
            count++;
          }
          //temp = *(this->ptr) + *(other->ptr);
          writeImage(tempData);
          return tempData;
      }

      std::unique_ptr<unsigned char[]> operator!(){
          //iterator temp;
          std::unique_ptr<unsigned char[]> tempData(new unsigned char[numberofPixels]);

          Image::iterator beg  = this->begin(), end = this->end();
          int count = 0;
          while(beg!= end){
            int invert = 255 - (int)(*(beg));
            char result = (char)(invert);
            tempData[count] = result;
            beg++;
            count++;
          }
          //temp = *(this->ptr) + *(other->ptr);
          writeImage(tempData);
          return tempData;
      }


      std::unique_ptr<unsigned char[]> operator/(Image& other){
          //iterator temp;
          std::unique_ptr<unsigned char[]> tempData(new unsigned char[numberofPixels]);

          Image::iterator beg  = this->begin(), end = this->end();
          Image::iterator beg2  = other.begin(), end2 = other.end();
          int count = 0;

          while(count < numberofPixels){
            char result;
            if((int)(*(beg2)) == 0){
              result = (char)*beg2;
            }else{
              result = (char)*beg;
            }
            //cout << diff<<" ";
            //char result = (char)(diff);
            //cout << result <<" ";
            tempData[count] = result;
            //cout << tempData[count];
            beg++;
            beg2++;
            count++;
          }
          //temp = *(this->ptr) + *(other->ptr);
          writeImage(tempData);
          return tempData;
      }

      std::unique_ptr<unsigned char[]> operator*(){
          //iterator temp;
          std::unique_ptr<unsigned char[]> tempData(new unsigned char[numberofPixels]);

          Image::iterator beg  = this->begin(), end = this->end();
          int count = 0;
          while(beg!= end){
            int pixel = (int)(*(beg));

            if(pixel > 150){
              pixel = 255;
            }else{
              pixel = 0;
            }

            char result = (char)(pixel);
            tempData[count] = pixel;
            beg++;
            count++;
          }
          //temp = *(this->ptr) + *(other->ptr);
          writeImage(tempData);
          return tempData;
      }

      /*friend ostream &operator<<(ostream &output, const Image &D){
         output <<*(iterator::D.ptr);
         return output;
      }*/

  private:
    int width, height,numberofPixels;
    std::unique_ptr<unsigned char[]> data;



};
#endif
