#include "Image.h"
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

Image::Image(){
  //default constructor
}

void Image::load(string filename){

  string line;
  ifstream myfile(filename);
  std::vector<string> v;
  int count = 0;
  if (myfile.is_open()){
     while (myfile.good()){
       getline (myfile,line);
       if(count >= 4){
         v.push_back(line);
         count ++;
       }else{
         cout << line << endl;
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
    //cout <<"\n";
  }
/*
  for(int i = 0; i < 262144;i++){
    cout<< (int)data[i]<<" ";
  }*/

}
