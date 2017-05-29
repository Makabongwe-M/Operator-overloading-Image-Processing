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
typedef unsigned char uchar;

Image::Image(){
  //default constructor
}

void Image::load(string filename){

  string line;
  string dimensions;
  ifstream myfile(filename);
  std::vector<string> v;
  int count = 0;
  if (myfile.is_open()){
     while (myfile.good()){
       getline (myfile,line);
       if(count > 3){
         v.push_back(line);
         count ++;
       }else{
         if(count == 2){
           dimensions = line;
         }
         count ++;
       }

     }
  }

  std::istringstream iss(dimensions);
  std::vector<std::string> results((std::istream_iterator<std::string>(iss)),std::istream_iterator<std::string>());
  height = stoi(results[0]);
  width = stoi(results[1]);
  numberofPixels = height*width;
  cout << height<< " "<< width<< " "<< numberofPixels <<endl;

  //cout << dimensions;
  int cou = 0;
  int j = 0;
  data.reset(new unsigned char[numberofPixels]);
  for(int i = 0; i< v.size(); i++){
    string str = v[i];
    for(char& c : str) {
      data[j] = c;
      j++;
      cou++;
    }
  }
  cout<< cou <<endl;
  //std::string s = "scott>=tiger";


  // token is "scott"
}

void Image::writeImage(std::unique_ptr<unsigned char[]> &array){
    unsigned char *dat= new unsigned char[height*width*sizeof(uchar)];

    for(int i = 0; i<numberofPixels;i++){
      dat[i] = array[i];
    }

    ofstream outfile ("output.pgm");
    if (!outfile.is_open()){
       cout << "Can't open output file"  << "output.pgm" << endl;
       exit(1);
    }

    outfile << "P5\n" << "512" << " " << "512" << " 255\n";
    outfile.write((char *)dat, height*width*sizeof(uchar));
    outfile.close();
    delete[] dat;

  }
