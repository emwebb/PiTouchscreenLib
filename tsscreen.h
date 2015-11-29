#ifndef TS_SCRREN_HEADER
#define TS_SCRREN_HEADER

#define FRAMEBUFFER_TYPE_DEVICE 0;
#define FRAMEBUFFER_TYPE_BUFFER 1;

struct frame_buffer {
	int width;
	int height;
	int bytes_per_pixel;
	char* buffer;
	int error;
	int type;
	int buffer_size;
};

struct frame_buffer* ts_getFramebufferFromDevice(char *device);
struct frame_buffer* ts_createFrameBufferBuffer(int width , int height , int bytes_per_pixel);
void ts_copyFrameBuffer(struct frame_buffer* from, struct frame_buffer* to);
#endif
