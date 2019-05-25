#include "convert-image.h"
#include <jpeglib.h>


uint8_t *create_texture_jpeg_data(
    const char *buffer,
    size_t length,
    enum gs_color_format *format,
    uint32_t *cx_out, uint32_t *cy_out,
    uint8_t *output_buffer) {

    uint8_t *data;

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_mem_src(&cinfo, buffer, length);

    if (jpeg_read_header(&cinfo, TRUE) != 1) {
        blog(LOG_ERROR, "libjpeg: Invalid JPEG data");
        jpeg_destroy_decompress(&cinfo);
        return NULL;
    }

    // start decompressor
    cinfo.out_color_space = JCS_EXT_BGRA;
    jpeg_start_decompress(&cinfo);

    // save width and height components
    *cx_out = (uint32_t)cinfo.output_width;
    *cy_out = (uint32_t)cinfo.output_height;
    if (cinfo.output_components != 4) {
        blog(LOG_ERROR, "libjpeg: Invalid component count");
        jpeg_abort_decompress(&cinfo);
        jpeg_destroy_decompress(&cinfo);
        return NULL;
    }
    *format = GS_BGRA;

    // alloc output buffer
    if (output_buffer) {
        data = output_buffer;
    } else {
        data = bmalloc(cinfo.output_width * cinfo.output_height * cinfo.output_components);
    }

    // decode
    while (cinfo.output_scanline < cinfo.output_height) {
		unsigned char *buffer_array[1];
		buffer_array[0] = data + (cinfo.output_scanline) * cinfo.output_width * cinfo.output_components;

		jpeg_read_scanlines(&cinfo, buffer_array, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    return data;
}