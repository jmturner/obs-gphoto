#ifndef convert_image_h__included
#define convert_image_h__included

#include <stdint.h>
#include <stdlib.h>
#include <graphics/graphics.h>

uint8_t *create_texture_jpeg_data(
        const char *buffer,
        size_t length,
		enum gs_color_format *format,
		uint32_t *cx_out, uint32_t *cy_out,
        uint8_t *output_buffer);

#endif /* convert_image_h__included */