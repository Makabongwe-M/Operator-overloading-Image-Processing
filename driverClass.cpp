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

  /*string operation = argv[1];
  string Image1 = argv[2];
  string Image2 = argv[3];
  string OutputImage = argv[4];*/

  //cout << argc << endl;

  //cout << operation << " "<<Image1 << " "<< Image2 << " "<< OutputImage<<endl;

  if(argc == 5){
      string operation = argv[1];
      string Image1 = argv[2];
      string Image2 = argv[3];
      string OutputImage = argv[4];

      Image firstImage(Image1);
      firstImage.OutputImage = OutputImage;

      if(operation == "-a"){
          Image secondImage(Image2);
          firstImage.load();
          secondImage.load();
          firstImage + secondImage;
        //cout << "add" <<endl;
      }else if(operation == "-s"){
          Image secondImage(Image2);
          firstImage.load();
          secondImage.load();
          firstImage - secondImage;

      }else if(operation == "-l"){
          Image secondImage(Image2);
          firstImage.load();
          secondImage.load();
          firstImage/secondImage;

      }else if(operation == "-t"){
          string thresh = argv[3];
          int threshold = atoi(thresh.c_str());
          firstImage.load();
          firstImage*threshold;
          cout << threshold <<endl;
      }

  }else if(argc == 4){
        string operation = argv[1];
        string Image1 = argv[2];
        string OutputImage = argv[3];
        Image object(Image1);
        object.OutputImage = OutputImage;
        object.load();

        if(operation == "-i"){
            !object;
        }

  }else{
      cout << "Too few or too many arguments entered."<<endl;
  }
  return 0;
}
