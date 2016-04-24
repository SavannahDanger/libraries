/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers - it's recommended to leave them included */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Shared libraries */
#include <lib/ce/graphc.h>
#include "gfx/tiles_gfx.h"

/* Tilemap defines */
#define TILE_WIDTH  16
#define TILE_HEIGHT 16

#define TILEMAP_WIDTH  40
#define TILEMAP_HEIGHT 25

#define TILEMAP_DRAW_WIDTH  20
#define TILEMAP_DRAW_HEIGHT 14

#define Y_OFFSET 16
#define X_OFFSET 0

uint8_t *tilemap_tiles[] = {
    bg_grass0, // 0
    bg_grass1, // 1
    bg_grass2, // 2
    bg_grass3, // 3
    bg_bottomleftin_tree, // 4
    bg_bottomleft_path, // 5
    bg_bottomrightin_tree, // 6
    bg_bottomright_path, // 7
    bg_bottom_path, // 8
    bg_grassbush, // 9
    bg_leftbottomin_tree, // A
    bg_leftbottomout_tree, // B
    bg_leftmiddlegroup_tree, // C
    bg_leftmiddle_tree, // D
    bg_lefttop_path, // E
    bg_left_path, // F
    bg_middle_path, // 10
    bg_rightbottomin_tree, // 11
    bg_rightbottomout_tree, // 12
    bg_rightmiddlegroup_tree, // 13
    bg_rightmiddle_tree, // 14
    bg_righttop_path, // 15
    bg_right_path, // 16
    bg_top_path, // 17
    bg_blcorner_path, // 18
    bg_brcorner_path, // 19
    bg_tlcorner_path, // 1A
    bg_trcorner_path, // 1B
    fg_bush0, // 1C
    fg_bush1, // 1D
    fg_rock0, // 1E
    fg_rock1, // 1F
    fg_rock2, // 20
    fg_sign, // 21
    fg_topleftout_tree, // 22
    fg_toprightout_tree // 23
};

uint8_t tilemap_map[] = {
	0x0E, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x15,
	0x16, 0x1A, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1B, 0x1A, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1B, 0x0F,
	0x16, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x15, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x07, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x02, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x09, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x00, 0x0E, 0x17, 0x15, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x09, 0x00, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x00, 0x16, 0x10, 0x0F, 0x09, 0x09, 0x09, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x09, 0x00, 0x09, 0x09, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x00, 0x05, 0x08, 0x07, 0x09, 0x09, 0x09, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x09, 0x00, 0x09, 0x09, 0x09, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x00, 0x02, 0x00, 0x01, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x09, 0x09, 0x01, 0x09, 0x09, 0x09, 0x09, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x09, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x09, 0x00, 0x09, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x16, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09, 0x16, 0x0F, 0x09, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x09, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x09, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x09, 0x09, 0x09, 0x09, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x0F, 0x09, 0x09, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09, 0x16, 0x0F, 0x09, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16, 0x0F,
	0x16, 0x18, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x19, 0x18, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x17, 0x19, 0x0F,
	0x05, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x07,
};

/* Put all your code here */
void main(void) {
    /* Create some local variables */
    uint8_t key;
    gc_tilemap_t tilemap;
    unsigned x_offset = 0, y_offset = 0;

    /* Initialize the tilemap structure */
    tilemap.map = tilemap_map;
    tilemap.tiles = tilemap_tiles;
    tilemap.type_width = gc_tile_16_pixel;
    tilemap.type_height = gc_tile_16_pixel;
    tilemap.tile_height = TILE_HEIGHT;
    tilemap.tile_width = TILE_WIDTH;
    tilemap.draw_height = TILEMAP_DRAW_HEIGHT;
    tilemap.draw_width = TILEMAP_DRAW_WIDTH;
    tilemap.height = TILEMAP_HEIGHT;
    tilemap.width = TILEMAP_WIDTH;
    tilemap.y_loc = Y_OFFSET;
    tilemap.x_loc = X_OFFSET;

    /* Initialize the graphics */
    gc_InitGraph();

    /* Set the palette to the current group */
    gc_SetPalette(tiles_gfx_pal, sizeof(tiles_gfx_pal));
    gc_SetTransparentColor(tiles_gfx_transpcolor_index);
    
    /* Draw to buffer to avoid tearing */
    gc_DrawBuffer();
    
    /* Set monospace font with width of 8 */
    gc_SetFontMonospace(8);
    
    /* Wait for the enter key to quit */
    while((key = os_GetCSC()) != 9) {
	
	/* Draw tilemap and coords */
        gc_ClipDrawBGTilemap(&tilemap, x_offset, y_offset);
        gc_PrintStringXY("x offset - ",40,4);
        gc_PrintUnsignedInt(x_offset,4);
        gc_PrintString(" y offset - ");
        gc_PrintUnsignedInt(y_offset,4);
	
	/* Do something based on the keypress */
        switch(key) {
            case 1:
                if (y_offset < (TILEMAP_HEIGHT*TILE_HEIGHT) - (TILEMAP_DRAW_HEIGHT*TILE_HEIGHT))
                    y_offset += TILE_HEIGHT;
                break;
            case 2:
                if (x_offset)
                    x_offset -= TILE_WIDTH;
                break;
            case 3:
                if (x_offset < (TILEMAP_WIDTH*TILE_WIDTH) - (TILEMAP_DRAW_WIDTH*TILE_WIDTH))
                    x_offset += TILE_WIDTH;
                break;
            case 4:
                if (y_offset)
                    y_offset -= TILE_HEIGHT;
                break;
            default:
                break;
        }
        gc_SwapDraw();
    }
    
    /* Close the graphics and return to the OS */
    gc_CloseGraph();
    pgrm_CleanUp();
}
