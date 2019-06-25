#include <cstring>

#include "gifenc.h"

int main( int argc, char* argv[ ] )
{
	uint8_t palette[] = {
        0x00, 0x00, 0x00,   /* entry 0: black */
        0xFF, 0xFF, 0xFF,   /* entry 1: white */
    };
    int depth = 1;          /* palette has 1 << 2 (i.e. 4) entries */

	ge_GIF* gif = ge_new_gif( "test.gif", 4, 4, palette, depth, 0 );

	uint8_t frame1[ ] = { 0, 1, 1, 0 };
	uint8_t frame2[ ] = { 1, 0, 0, 1 };

	memcpy( gif->frame, frame1, 4 );
	ge_add_frame( gif, 100 );
	memcpy( gif->frame, frame2, 4 );
	ge_add_frame( gif, 100 );
	ge_close_gif( gif );

	return 0;
}