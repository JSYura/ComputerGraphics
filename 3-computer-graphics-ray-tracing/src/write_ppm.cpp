#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code from computer-graphics-raster-images
//  return false;
    assert(
            (num_channels == 3 || num_channels ==1 ) &&
            ".ppm only supports RGB or grayscale images");

    std::ofstream res;
    res.open(filename);

    if (!res.is_open()){
        return false;
    };
    if (num_channels == 3){
        res << "P3\n";
    }else if (num_channels == 1){
        res << "P2\n";
    }else{
        return false;
    }

    res << width << " " << height << "\n255\n";

    for (unsigned char i : data) {
        res << (double)i << " ";
    }

    res.close();
    return true;
  ////////////////////////////////////////////////////////////////////////////
}
