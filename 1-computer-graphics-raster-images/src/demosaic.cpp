#include "demosaic.h"

// red: 0, green: 1, blue: 2
int get_color(int i, int j){
    if (i % 2 == 1 && j % 2 == 0) {
        return 0;
    }
    if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
        return 1;
    }
    if (i % 2 == 0 && j % 2 == 1) {
        return 2;
    }
    return -1;
}


std::vector<unsigned char> count_color(int ori_x, int ori_y, const std::vector<unsigned char> & bayer, int height, int width) {
    int red_count = 0, green_count = 0, blue_count = 0;
    double red_sum = 0, green_sum = 0, blue_sum = 0;
    std::vector<unsigned char> rgb;
    rgb.resize(3);
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            int x = ori_x + i;
            int y = ori_y + j;
            if (x >= 0 && x < height && y >= 0 && y < width){
                if (get_color(x, y) == 0){ // red
                    red_sum += bayer[width * x + y];
                    red_count++;
                }
                if (get_color(x, y) == 1) { // green
                    green_sum += bayer[width * x + y];
                    green_count++;
                }
                if (get_color(x, y) == 2) { // blue
                    blue_sum += bayer[width * x + y];
                    blue_count++;
                }
            }
        }
    }
    rgb[0] = (unsigned char)(red_sum / red_count);
    rgb[1] = (unsigned char)(green_sum / green_count);
    rgb[2] = (unsigned char)(blue_sum / blue_count);
    return rgb;
}


void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    int tmp = 0;
    for (int i = 0; i < height; i++){
        for (int j= 0; j < width; j++){
            std::vector<unsigned char> demos_rgb;
            demos_rgb.resize(3);
            demos_rgb = count_color(i, j, bayer, height, width);
            if (get_color(i, j) == 0){
                rgb[tmp++] = bayer[i * width + j];
                rgb[tmp++] = (unsigned char)demos_rgb[1];
                rgb[tmp++] = (unsigned char)demos_rgb[2];
            }
            if (get_color(i, j) == 1){
                rgb[tmp++] = (unsigned char)demos_rgb[0];
                rgb[tmp++] = bayer[i * width + j];
                rgb[tmp++] = (unsigned char)demos_rgb[2];
            }
            if (get_color(i, j) == 2){
                rgb[tmp++] = (unsigned char)demos_rgb[0];
                rgb[tmp++] = (unsigned char)demos_rgb[1];
                rgb[tmp++] = bayer[i * width + j];
            }
        }
    }
  ////////////////////////////////////////////////////////////////////////////
}
