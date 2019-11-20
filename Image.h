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
      Image(string filename);
      Image(const Image& other);
      ~Image();
      Image(Image&& other);
      void load();
      void save(std::unique_ptr<unsigned char[]> &array, string outputfile);
      string header, filename, outputImage;

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

              unsigned char& operator *() const{
                 return *ptr;
              }
      };

      /*begin method points to the first char in the data array*/
      iterator begin(void){
         return iterator(data.get());
      }
      /*end method points to the last char in the data array*/
      iterator end(void){
          return iterator(data.get()+(numberofPixels));
      }

      /*Add two Images. The size must be the same to get a result*/
      std::unique_ptr<unsigned char[]> operator+(Image& other){

          if(this->numberofPixels != other.numberofPixels){
            cout << "Images are not the same size, cannot operate."<<endl;
            return nullptr;
          }else{

          std::unique_ptr<unsigned char[]> tempData(new unsigned char[numberofPixels]);
          Image::iterator beg  = this->begin(), end = this->end();
          Image::iterator beg2  = other.begin(), end2 = other.end();
          int count = 0;
          while(beg != end){
            int sum = (int)(*(beg)) + (int)(*(beg2));
            if(sum < 0){
              sum = 0;
            }else if( sum > 255){
              sum = 255;
            }
            char result = (char)(sum);
            tempData[count] = result;
            beg++;
            beg2++;
            count++;
          }
          //save the result the given file
          save(tempData, outputImage);
          return tempData;
        }
      }
        /*subtract two Images. The size must be the same to get a result*/
      std::unique_ptr<unsigned char[]> operator-(Image& other){

          if(this->numberofPixels != other.numberofPixels){
            cout << "Images are not the same size, cannot operate."<<endl;
            return nullptr;
          }else{

          std::unique_ptr<unsigned char[]> tempData(new unsigned char[numberofPixels]);
          Image::iterator beg  = this->begin(), end = this->end();
          Image::iterator beg2  = other.begin(), end2 = other.end();
          int count = 0;
          while(beg !=end){
            int diff = (int)(*(beg)) - (int)(*(beg2));
            if(diff < 0){
              diff = 0;
            }else if( diff > 255){
              diff = 255;
            }
            char result = (char)(diff);
            tempData[count] = result;
            beg++;
            beg2++;
            count++;
          }
          //save the result the given file
          save(tempData, outputImage);
          return tempData;
        }
    }
      /*Invert the Image*/
      std::unique_ptr<unsigned char[]> operator!(){

            std::unique_ptr<unsigned char[]> tempData(new unsigned char[numberofPixels]);
            Image::iterator beg  = this->begin(), end = this->end();
            int count = 0;
            while(beg!= end){
              int invert = 255 - (int)(*(beg));

              if(invert < 0){
                invert = 0;
              }else if( invert > 255){
                invert = 255;
              }
              char result = (char)(invert);
              tempData[count] = result;
              beg++;
              count++;
            }
            //save the result the given file
            save(tempData, outputImage);
            return tempData;
      }

      /*Mask an image with another image. The size must be the same to get a result*/
      std::unique_ptr<unsigned char[]> operator/(Image& other){

          if(this->numberofPixels != other.numberofPixels){
            cout << "Images are not the same size, cannot operate."<<endl;
            return nullptr;
          }else{
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
                tempData[count] = result;
                beg++;
                beg2++;
                count++;
              }
              //save the result the given file
              save(tempData, outputImage);
              return tempData;
        }
      }
      /*Generate the image above the given threshold*/
      std::unique_ptr<unsigned char[]> operator*(int threshold){

          std::unique_ptr<unsigned char[]> tempData(new unsigned char[numberofPixels]);
          Image::iterator beg  = this->begin(), end = this->end();
          int count = 0;
          while(beg!= end){
            int pixel = (int)(*(beg));
            if(pixel >threshold){
              pixel = 255;
            }else{
              pixel = 0;
            }
            char result = (char)(pixel);
            tempData[count] = pixel;
            beg++;
            count++;
          }
          //save the result the given file
          save(tempData, outputImage);
          return tempData;
      }
  private:
    int width, height,numberofPixels;
    std::unique_ptr<unsigned char[]> data;
};
#endif
