/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PngFile
*/

#include "core/include/ArcadeCore/PngFile.hpp"

PngFile::PngFile(const std::string &path) :
_pixels(NULL)
{
    _fp = fopen(path.c_str(), "rb");
    _png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if(!_png)
        throw std::invalid_argument("CAN'T OPEN PNG FILE"); //todo
    _info = png_create_info_struct(_png);
    if(!_info)
        throw std::invalid_argument("CAN'T OPEN PNG FILE"); //todo
    if(setjmp(png_jmpbuf(_png)))
        throw std::invalid_argument("CAN'T OPEN PNG FILE"); //todo
    png_init_io(_png, _fp);
    png_read_info(_png, _info);
    _width = png_get_image_width(_png, _info);
    _height = png_get_image_height(_png, _info);
    _colorType = png_get_color_type(_png, _info);
    _bitDepth = png_get_bit_depth(_png, _info);
    if(_bitDepth == 16)
        png_set_strip_16(_png);
    if(_colorType == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(_png);
    if(_colorType == PNG_COLOR_TYPE_GRAY && _bitDepth < 8)
        png_set_expand_gray_1_2_4_to_8(_png);
    if(png_get_valid(_png, _info, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(_png);
    if(_colorType == PNG_COLOR_TYPE_RGB || _colorType == PNG_COLOR_TYPE_GRAY || _colorType == PNG_COLOR_TYPE_PALETTE)
        png_set_filler(_png, 0xFF, PNG_FILLER_AFTER);
    if(_colorType == PNG_COLOR_TYPE_GRAY || _colorType == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(_png);
    png_read_update_info(_png, _info);
    if (_pixels)
        throw std::invalid_argument("CAN'T OPEN PNG FILE"); //todo
    _pixels = (png_bytep*)malloc(sizeof(png_bytep) * _height);
    for(int y = 0; y < _height; y++)
        _pixels[y] = (png_byte*)malloc(png_get_rowbytes(_png, _info));
    png_read_image(_png, _pixels);
    fclose(_fp);
    png_destroy_read_struct(&_png, &_info, NULL);
}

png_bytep *PngFile::getPixels() const
{
    return (_pixels);
}

int PngFile::getWidth() const
{
    return (_width);
}

int PngFile::getHeight() const
{
    return (_height);
}

PngFile::~PngFile()
{
}
