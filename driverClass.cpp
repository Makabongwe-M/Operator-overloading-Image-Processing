#include "Image.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <queue>
#include <bits/stdc++.h>
#include <typeinfo>
#include <iomanip>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;
using std::cout;
using std::setw;

typedef unsigned char uchar;

int main(){
  Image object;
  object.load("shrek_rectangular.pgm");
  //object;

  //Image object2;
  //object2.load("Lenna_standard.pgm");

  //object+object2;

  //Image object3;
  //object3.load("shrek_rectangular.pgm");
  //object3;
  //object.Do(object, object2);
  /*std::unique_ptr<unsigned char[]> data;
  std::unique_ptr<unsigned char[]> data2;

  data2 = object/object2;
  data = object + object2;

  cout << sizeof(data);*/
  //for(int i; i<262144;i++){
  //  cout << data[i];
  //}

  //unsigned char c = ++object;
  //std::unique_ptr<unsigned char[]> data(new unsigned char[262144]);
  //cout <<Image::begin<<endl;

  //Image::iterator end = object.end();
  //std::unique_ptr<unsigned char[]> data;
  //unsigned char *data= new unsigned char[512*512*sizeof(uchar)];
  /*string line;
  ifstream myfile("Lenna_standard.pgm");
  std::vector<string> v;
  int count = 0;
  if (myfile.is_open()){
     while (myfile.good()){
       getline (myfile,line);
       if(count >= 4){
         v.push_back(line);
         count ++;
       }else{
         //cout << line << endl;
         count ++;
       }

     }
  }
  data.reset(new unsigned char[262144]);
  for(int i = 0; i< v.size(); i++){
    string str = v[i];
    int j = 0;
    for(char& c : str) {
      data[j] = c;
      j++;
    }
  }*/

  /*unsigned char *dat= new unsigned char[512*512*sizeof(uchar)];

  for(int i = 0; i<262144;i++){
    dat[i] = data2[i];
  }

  // output file streams
  ofstream fout ("masked.pgm");

  if (!fout.is_open())
  {
     cout << "Can't open output file"  << "masked.pgm" << endl;
     exit(1);
  }

  // write the header
  fout << "P5\n" << "512" << " " << "512" << " 255\n";

  // write the data
  fout.write((char *)dat, 512*512*sizeof(uchar));

  // close the stream
  fout.close();

  // free memory
  delete[] dat;*/


  return 0;
}
