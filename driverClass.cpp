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



int main(){
  Image object;
  object.load("Lenna_standard.pgm");
  Image::iterator begin = object.begin();
  Image::iterator end = object.end();

  while (begin != end) {
    cout << object.data
  }

  return 0;
}
