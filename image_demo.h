//
// Created by elms on 4/17/25.
//

#ifndef IMAGE_DEMO_H
#define IMAGE_DEMO_H
#include <string>
#include <cstdint>

void demo_image(uint8_t [][3], size_t height, size_t width);

bool write_image(const uint8_t data[][3],
    uint32_t height, uint32_t width,
    const std::string &path);

#endif //IMAGE_DEMO_H
