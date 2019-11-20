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

int main(int argc, char *argv[]){

  if(argc == 5){
      string operation = argv[1];
      string image1 = argv[2];
      string image2 = argv[3];
      string outputImage = argv[4];

      Image firstImage(image1);
      firstImage.outputImage = outputImage;

      if(operation == "-a"){
          Image secondImage(image2);
          firstImage.load();
          secondImage.load();
          firstImage + secondImage;

      }else if(operation == "-s"){
          Image secondImage(image2);
          firstImage.load();
          secondImage.load();
          firstImage - secondImage;

      }else if(operation == "-l"){
          Image secondImage(image2);
          firstImage.load();
          secondImage.load();
          firstImage/secondImage;

      }else if(operation == "-t"){
          string thresh = argv[3];
          int threshold = atoi(thresh.c_str());
          firstImage.load();
          firstImage*threshold;

      }

  }else if(argc == 4){
        string operation = argv[1];
        string image1 = argv[2];
        string outputImage = argv[3];
        Image object(image1);
        object.outputImage = outputImage;
        object.load();

        if(operation == "-i"){
            !object;
        }

  }else{
      cout << "Too few or too many arguments entered."<<endl;
  }
  return 0;
}
