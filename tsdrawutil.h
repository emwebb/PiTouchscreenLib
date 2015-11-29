#ifndef TS_DRAW_UTIL_HEADER
#define TS_DRAW_UTIL_HEADER

#include "tsscreen.h"


void ts_clearFrameBuffer(struct frame_buffer* fb);
void ts_16FillFrameBuffer(struct frame_buffer* fb, short colour);
void ts_16SetPixel(struct frame_buffer* fb, int x, int y, short colour);


#endif