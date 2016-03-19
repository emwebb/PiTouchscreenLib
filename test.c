#include <stdio.h>
#include "tsscreen.h"
#include "tsdrawutil.h"

int main(int argc, char **argv)
{
	struct frame_buffer* touchscreen_fb = ts_getFramebufferFromDevice("/dev/fb1");
    short colour = 0;
    struct frame_buffer* buffer_fb = ts_createFrameBufferBuffer(touchscreen_fb->width, touchscreen_fb->height, touchscreen_fb->bytes_per_pixel);
    while ( 1 ) {
        //ts_clearFrameBuffer(touchscreen_fb);
        ts_16FillFrameBuffer(buffer_fb,colour);
        ts_copyFrameBuffer(buffer_fb,touchscreen_fb);
        colour++;
    }

	return 0;
}
