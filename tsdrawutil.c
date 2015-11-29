#include "tsdrawutil.h"

void ts_clearFrameBuffer(struct frame_buffer* fb) {
    memset(fb->buffer,0,fb->buffer_size);
}

void ts_16FillFrameBuffer(struct frame_buffer* fb, short colour) {
    int n;
    for ( n = 0; n < fb->width*fb->height; n++){
        ((short*)fb->buffer)[n] = colour;
    }
}

void ts_16SetPixel(struct frame_buffer* fb, int x, int y, short colour){
    ((short*)fb->buffer)[x+y*fb->width] = colour;
}