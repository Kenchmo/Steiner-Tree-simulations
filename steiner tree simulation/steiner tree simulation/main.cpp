//
//  main.cpp
//  steiner tree simulation
//
//  Created by Lufan Zhou on 2/20/17.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "png.hpp"

using namespace std;

int main() {
    // insert code here...
    ifstream in_stream;
    string line;
    string temp;

    in_stream.open("input.txt");
    ofstream myfile;
    myfile.open ("example.txt");
    while(!in_stream.eof()){
        in_stream >> line;
        
        
        
        myfile << line << endl;
        
        
    }
    in_stream.close();
    
    myfile.close();
    
    
    
    PNG input("in.png");
    size_t width = input.width();		//define the width and height
    size_t height = input.height();
    PNG output(width, height);			//construct an empty output image
    
    //RGBAPixel *in, *out;
    
    for (size_t i = 0; i < width; ++i){
        for (size_t j = 0; j < height; ++j){  //flipping by 180 degrees require that both
            
            output(i, j)->red = input(width - i - 1, height - j - 1)->red; // the x and y
            output(i, j)->green = input(width - i - 1, height - j - 1)->green; // flipped
            output(i, j)->blue = input(width - i - 1, height - j - 1)->blue;
            output(i, j)->alpha = input(width - i - 1, height - j - 1)->alpha;
            //in = input(width - i - 1, height - j - 1);
            //out = output(i, j);
            //*out = *in;
        }
    }
    output.writeToFile("out.png");
    
    return 0;
    return 0;
}
