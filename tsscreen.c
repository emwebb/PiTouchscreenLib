#include <linux/fb.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h> 
#include <string.h>
#include "tsscreen.h" 

struct frame_buffer* ts_getFramebufferFromDevice(char *device) {
	
	struct frame_buffer* fb = malloc(sizeof(struct frame_buffer));
	
	int framebuffer_device;
	int line_size, buffer_size;
	struct fb_var_screeninfo var_info;
	
	framebuffer_device = open (device, O_RDWR);
	
	ioctl (framebuffer_device, FBIOGET_VSCREENINFO, &var_info);
	
	line_size = var_info.xres * var_info.bits_per_pixel / 8;
	buffer_size = line_size * var_info.yres;
	
	var_info.xoffset = 0;
	var_info.yoffset = 0;
	
	ioctl (framebuffer_device, FBIOPAN_DISPLAY, &var_info) == -1;
	
	fb->buffer = (char *) mmap (0, buffer_size, PROT_READ | PROT_WRITE, MAP_SHARED, framebuffer_device, 0);
	
	fb->width = var_info.xres;
	fb->height = var_info.yres;
	fb->bytes_per_pixel = var_info.bits_per_pixel / 8;
	fb->error = 0;
	fb->type = FRAMEBUFFER_TYPE_DEVICE;
	fb->buffer_size = buffer_size;
	return fb;
}

struct frame_buffer* ts_createFrameBufferBuffer(int width , int height , int bytes_per_pixel) {
    struct frame_buffer* fb = malloc(sizeof(struct frame_buffer));
    fb->width = width;
    fb->height = height;
    fb->bytes_per_pixel = bytes_per_pixel;
    fb->type = FRAMEBUFFER_TYPE_BUFFER;
    fb->buffer_size = width * height * bytes_per_pixel;
    fb->buffer = malloc(width * height * bytes_per_pixel * sizeof(char));
    fb->error = 0;
    return fb;
}

void ts_copyFrameBuffer(struct frame_buffer* from, struct frame_buffer* to){
    if(from->height == to->height && from->width == to->width && from->bytes_per_pixel == to->bytes_per_pixel) {
        memcpy(to->buffer,from->buffer,to->buffer_size);
    }
}



