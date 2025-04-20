//
// Created by elms on 4/17/25.
//

#ifndef IMAGE_DEMO_H
#define IMAGE_DEMO_H
#include <string>
#include <cstdint>

/*
 * generate pixels values for a demonstration image
 *
 * array size must be width * height * 3
 */
void demo_image(uint8_t [], size_t height, size_t width);

/*
 * write an image array to a file in BMP format
 *
 * Assumes RGB data
 * array size must be width * height * 3
 */
bool write_image(const uint8_t data[],
    uint32_t height, uint32_t width,
    const std::string &path);

#endif //IMAGE_DEMO_H
