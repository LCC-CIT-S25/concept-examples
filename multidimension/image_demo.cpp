//
// Example to generate BMP
//

#include "image_demo.h"
#include <string>
#include <cstdint>
#include <fstream>

using namespace std;

const uint8_t RGB_SIZE = 3;

void demo_image(uint8_t data[], size_t height, size_t width) {
    const uint8_t RED_SHADE = 0x66;

    for (int i=0; i < height; i++) {
        for (int j=0; j < width; j++) {
            const size_t pixel_offset = (i * width + j) * RGB_SIZE;
            data[pixel_offset + 0] = RED_SHADE;  //red
            data[pixel_offset + 1] = ((j>>8) & 1) ? (j % 256) : ((255 - (j % 256))); //green
            data[pixel_offset + 2] = (i<256) ? i : 255; //blue
        }
    }
}


bool write_image(const uint8_t data[],
    uint32_t height, uint32_t width,
    const std::string &path)
{
    bool valid = true;

    ofstream f(path, ios_base::binary | ios_base::out);

    uint32_t len = width * height * 3;
    f << "BM";
    uint32_t t =  (len + 40 + 14);
    f.write(reinterpret_cast<const char*>(&t), sizeof(t));
    const uint8_t bmp_header[] =
        {
        0x00, 0x00,
        0x00, 0x00,
        0x36, 0x00, 0x00, 0x00,
        };
    f.write(reinterpret_cast<const char*>(bmp_header), sizeof(bmp_header));

    const char DIB_size[] = {0x28, 0x00, 0x00, 0x00}; // size of dib header total
    f.write(DIB_size, sizeof(DIB_size));
    f.write(reinterpret_cast<const char*>(&width), sizeof(width));
    f.write(reinterpret_cast<const char*>(&height), sizeof(height));
    const char color_info[] = {
        0x01, 0x00, // 1 plane
         24,  0x00,   // 24 bits per pixel
        0x00, 0x00, 0x00, 0x00, // BI_RGB
        0x00, 0x00, 0x18, 0x00, // size (dummy to 0)
        0x13, 0x0b, 0x00, 0x00, // pixels per meter resolution
        0x13, 0x0b, 0x00, 0x00, // pixels per meter resolution
        0x00, 0x00, 0x00, 0x00, // Auto color-palette
        0x00, 0x00, 0x00, 0x00, // all color important
        };
    f.write(color_info, sizeof(color_info));

    // Write out image data
    for (size_t i=0; i < width * height; i++) {
        // Write out in reverse Blue, Green ,Red
        f << data[i * RGB_SIZE + 2]
          << data[i * RGB_SIZE + 1]
          << data[i * RGB_SIZE + 0];
    }

    return valid;
}