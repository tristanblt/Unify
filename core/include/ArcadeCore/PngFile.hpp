/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PngFile
*/

#ifndef PNGFILE_HPP_
#define PNGFILE_HPP_

#include <string>
#include <stdexcept>
#include <png.h>

class PngFile {
    public:
        PngFile(const std::string &path);
        ~PngFile();

        png_bytep *getPixels() const;
        int getHeight() const;
        int getWidth() const;

    protected:
    private:
        int _width;
        int _height;
        png_byte _colorType;
        png_byte _bitDepth;
        png_bytep *_pixels;
        FILE *_fp;
        png_structp _png;
        png_infop _info;

};

#endif /* !PNGFILE_HPP_ */
