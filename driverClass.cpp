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
  /*Image object;
  object.load("Lenna_standard.pgm");
  !object;*/

  Image object2;
  object2.load("shrek_rectangular.pgm");
  //!object2;
  object2*100;
  //object2/object;
  //object2;

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



  return 0;
}

/*std::istringstream iss(dimensions);
std::vector<std::string> results((std::istream_iterator<std::string>(iss)),std::istream_iterator<std::string>());
height = stoi(results[0]);
width = stoi(results[1]);
numberofPixels = height*width;*/
