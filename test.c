/*
 * main.c
 * 
 * Copyright 2015 Ethan Webb <ethanwebb@Ethans-MacBook-Pro.local>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


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

