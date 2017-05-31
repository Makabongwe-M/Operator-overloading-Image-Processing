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

}

Image::Image(string file){
  filename  = file;
}

//copy constructor
Image::Image(const Image& other): height(other.height), width(other.width),numberofPixels(other.numberofPixels),
header(other.header){
    this->data = unique_ptr<unsigned char[]>(new unsigned char[numberofPixels]);
    Image::iterator Begin  = this-> begin(), End = this->end();
    Image::iterator otherBegin(other.data.get());

    while(Begin !=  End){
      *Begin = *otherBegin;
      Begin++;
      otherBegin++;
    }
}
//move constructor
Image::Image(Image&& other): height(0), width(0), numberofPixels(0),header(""), data(nullptr){

    this->height = other.height;
    this->width = other.width;
    this->header = other.header;
    this->numberofPixels = other.numberofPixels;
    this->data = move(other.data);
}

Image::~Image(){

  //delete data;
}

/*Load the current image into the data array*/
void Image::load(){

    ifstream inputfile(filename, ios::in | ios::binary);
    string line;
    getline(inputfile, line);
    inputfile >> ws;

    header = header + line + "\n";
    getline(inputfile,line);
    header = header + line + "\n";

    while(line[0] == '#'){
      getline(inputfile, line);
      inputfile >> ws;
      header = header +line + "\n";
    }

  string::size_type size_t;
  int pos = line.find(" ");
  height = stoi(line.substr(0, pos), &size_t);
  width = stoi(line.substr(pos+1), &size_t);
  numberofPixels = height * width;

  getline(inputfile, line);
  inputfile >> ws;
  header = header +line + "\n";

  unsigned char *tempDataBlock;
  tempDataBlock = new unsigned char [height*width];
  inputfile.read((char*)tempDataBlock, height*width);
  data = unique_ptr<unsigned char[]>(tempDataBlock);

  inputfile.close();

}

/*save the output of some operation into a given file*/
void Image::save(std::unique_ptr<unsigned char[]> &array, string outputfile){

    unsigned char *tempData= new unsigned char[height*width*sizeof(uchar)];
    for(int i = 0; i<numberofPixels;i++){
      tempData[i] = array[i];
    }
    ofstream outfile (outputfile.c_str());
    if (!outfile.is_open()){
       cout << "Can't open output file" << endl;
       exit(1);
    }
    outfile << header<< "\n";
    outfile.write((char *)tempData, height*width*sizeof(uchar));
    outfile.close();
    delete[] tempData;

  }
