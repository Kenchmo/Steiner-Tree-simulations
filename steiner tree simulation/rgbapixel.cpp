#include "rgbapixel.h"

/**
 *	Constructs a default RGBAPixel.
 *	A default pixel is completely opaque (non-transparent)
 *	and white. Opaque implies that the alpha component of
 *	the pixel is 255. Lower values are transparent.
 **/
RGBAPixel::RGBAPixel(){
    
    red = 255;
    green = 255;
    blue = 255;
    alpha = 255;
    
}

/**
 *	Constructs an opaque RGBAPixel with the given red, green, blue color values.
 *	The alpha component of the pixel constructed should be 255.
 *	Parameters
 *	red	Red component for the new pixel.
 *	green	Green component for the new pixel.
 *	blue	Blue component for the new pixel.
 **/
RGBAPixel::RGBAPixel(uint8_t red, uint8_t green, uint8_t blue){
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = 255;
}
