/*******************************************************************************
 * Size: 10 px
 * Bpp: 1
 * Opts: --bpp 1 --size 10 --font C:/Users/Szoot/SquareLine/assets/monofonto rg.otf -o C:/Users/Szoot/SquareLine/assets\ui_font_Font1.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FONT1
#define UI_FONT_FONT1 1
#endif

#if UI_FONT_FONT1

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xf2,

    /* U+0022 "\"" */
    0xb4,

    /* U+0023 "#" */
    0x31, 0x9e, 0xaf, 0x32, 0x80,

    /* U+0024 "$" */
    0x4f, 0x98, 0x61, 0x9f, 0x40,

    /* U+0025 "%" */
    0xce, 0xb9, 0xf5, 0xae, 0x60,

    /* U+0026 "&" */
    0x6a, 0x64, 0xba, 0xd0,

    /* U+0027 "'" */
    0xc0,

    /* U+0028 "(" */
    0x5a, 0xaa, 0x50,

    /* U+0029 ")" */
    0xa5, 0x55, 0xa0,

    /* U+002A "*" */
    0x25, 0x5c, 0xa5, 0x0,

    /* U+002B "+" */
    0x27, 0xc8, 0x40,

    /* U+002C "," */
    0x60,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x8, 0x44, 0x22, 0x11, 0x8, 0x44, 0x0,

    /* U+0030 "0" */
    0xf9, 0x99, 0x99, 0xf0,

    /* U+0031 "1" */
    0x75, 0x54,

    /* U+0032 "2" */
    0x69, 0x13, 0x26, 0xf0,

    /* U+0033 "3" */
    0xe9, 0x12, 0x19, 0xe0,

    /* U+0034 "4" */
    0x11, 0x94, 0xaf, 0x88, 0x40,

    /* U+0035 "5" */
    0xf8, 0xe9, 0x19, 0xe0,

    /* U+0036 "6" */
    0x26, 0x4f, 0x99, 0x60,

    /* U+0037 "7" */
    0xf3, 0x22, 0x64, 0x40,

    /* U+0038 "8" */
    0x69, 0x96, 0x99, 0x60,

    /* U+0039 "9" */
    0x69, 0x9f, 0x26, 0x40,

    /* U+003A ":" */
    0x90,

    /* U+003B ";" */
    0x98,

    /* U+003C "<" */
    0x1b, 0x20, 0xc1, 0x80,

    /* U+003D "=" */
    0xf8, 0x3e,

    /* U+003E ">" */
    0x83, 0x6, 0xe8, 0x0,

    /* U+003F "?" */
    0x69, 0x16, 0x40, 0x40,

    /* U+0040 "@" */
    0x74, 0x6f, 0x5a, 0xde, 0xf,

    /* U+0041 "A" */
    0x23, 0x9c, 0xa5, 0x3b, 0x60,

    /* U+0042 "B" */
    0xf9, 0x9e, 0x99, 0xf0,

    /* U+0043 "C" */
    0x69, 0x88, 0x89, 0x60,

    /* U+0044 "D" */
    0xe9, 0x99, 0x99, 0xf0,

    /* U+0045 "E" */
    0xf2, 0x79, 0x38,

    /* U+0046 "F" */
    0xf8, 0x8f, 0x88, 0x80,

    /* U+0047 "G" */
    0x79, 0x8b, 0x99, 0x70,

    /* U+0048 "H" */
    0x99, 0x9f, 0x99, 0x90,

    /* U+0049 "I" */
    0xe9, 0x24, 0xb8,

    /* U+004A "J" */
    0x31, 0x11, 0x11, 0xe0,

    /* U+004B "K" */
    0xba, 0xec, 0xea, 0xb0,

    /* U+004C "L" */
    0x88, 0x88, 0x88, 0xf0,

    /* U+004D "M" */
    0x9f, 0xff, 0xd9, 0x90,

    /* U+004E "N" */
    0xdd, 0xdf, 0xbb, 0x90,

    /* U+004F "O" */
    0x69, 0x99, 0x99, 0x60,

    /* U+0050 "P" */
    0xe9, 0x9e, 0x88, 0x80,

    /* U+0051 "Q" */
    0x69, 0x99, 0x99, 0x73,

    /* U+0052 "R" */
    0xe9, 0x9f, 0xeb, 0x90,

    /* U+0053 "S" */
    0x79, 0x86, 0x19, 0xe0,

    /* U+0054 "T" */
    0xf2, 0x22, 0x22, 0x20,

    /* U+0055 "U" */
    0x99, 0x99, 0x99, 0x60,

    /* U+0056 "V" */
    0xda, 0x94, 0xa5, 0x38, 0x80,

    /* U+0057 "W" */
    0x8f, 0x7f, 0xf5, 0x29, 0x40,

    /* U+0058 "X" */
    0xda, 0x9c, 0x47, 0x2b, 0x60,

    /* U+0059 "Y" */
    0xda, 0x9c, 0x42, 0x10, 0x80,

    /* U+005A "Z" */
    0xf2, 0x26, 0x4c, 0xf0,

    /* U+005B "[" */
    0xea, 0xaa, 0xb0,

    /* U+005C "\\" */
    0x84, 0x10, 0x82, 0x10, 0x82, 0x10, 0x40,

    /* U+005D "]" */
    0xd5, 0x55, 0x70,

    /* U+005E "^" */
    0x22, 0x94,

    /* U+005F "_" */
    0xf8,

    /* U+0060 "`" */
    0x48,

    /* U+0061 "a" */
    0x71, 0xf9, 0xf0,

    /* U+0062 "b" */
    0x88, 0xe9, 0x99, 0xe0,

    /* U+0063 "c" */
    0x78, 0x88, 0x70,

    /* U+0064 "d" */
    0x11, 0x79, 0x99, 0x70,

    /* U+0065 "e" */
    0x69, 0xf8, 0x70,

    /* U+0066 "f" */
    0x74, 0xe4, 0x44, 0x40,

    /* U+0067 "g" */
    0x79, 0x99, 0x79, 0xe0,

    /* U+0068 "h" */
    0x88, 0xf9, 0x99, 0x90,

    /* U+0069 "i" */
    0x43, 0x24, 0xb8,

    /* U+006A "j" */
    0x21, 0x92, 0x49, 0xe0,

    /* U+006B "k" */
    0x88, 0xae, 0xca, 0xb0,

    /* U+006C "l" */
    0xd5, 0x54,

    /* U+006D "m" */
    0xfb, 0xbb, 0xb0,

    /* U+006E "n" */
    0xf9, 0x99, 0x90,

    /* U+006F "o" */
    0x69, 0x99, 0x60,

    /* U+0070 "p" */
    0xe9, 0x99, 0xe8, 0x80,

    /* U+0071 "q" */
    0x79, 0x99, 0x71, 0x10,

    /* U+0072 "r" */
    0xe8, 0x88, 0x80,

    /* U+0073 "s" */
    0xe8, 0x6a, 0xe0,

    /* U+0074 "t" */
    0x5d, 0x24, 0xc0,

    /* U+0075 "u" */
    0x99, 0x99, 0x60,

    /* U+0076 "v" */
    0xda, 0x94, 0xe2, 0x0,

    /* U+0077 "w" */
    0xaf, 0xdc, 0xa5, 0x0,

    /* U+0078 "x" */
    0x52, 0x88, 0xa5, 0x0,

    /* U+0079 "y" */
    0xda, 0x94, 0xe2, 0x10, 0x80,

    /* U+007A "z" */
    0xf2, 0x64, 0xf0,

    /* U+007B "{" */
    0x69, 0x25, 0x12, 0x4c,

    /* U+007C "|" */
    0xff, 0x80,

    /* U+007D "}" */
    0xc9, 0x24, 0x52, 0x58,

    /* U+007E "~" */
    0xed, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 80, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 80, .box_w = 1, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 80, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 3, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8, .adv_w = 80, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 13, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 80, .box_w = 1, .box_h = 2, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 23, .adv_w = 80, .box_w = 2, .box_h = 10, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 26, .adv_w = 80, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 29, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 33, .adv_w = 80, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 36, .adv_w = 80, .box_w = 1, .box_h = 3, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 37, .adv_w = 80, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 38, .adv_w = 80, .box_w = 1, .box_h = 1, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 80, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 46, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 80, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 52, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 60, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 80, .box_w = 1, .box_h = 4, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 86, .adv_w = 80, .box_w = 1, .box_h = 5, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 91, .adv_w = 80, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 93, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 97, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 80, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 106, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 80, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 173, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 80, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 216, .adv_w = 80, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 223, .adv_w = 80, .box_w = 2, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 226, .adv_w = 80, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 228, .adv_w = 80, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 229, .adv_w = 80, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 230, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 237, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 255, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 80, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 80, .box_w = 3, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 266, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 80, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 285, .adv_w = 80, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 289, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 292, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 295, .adv_w = 80, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 80, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 80, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 318, .adv_w = 80, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 80, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 325, .adv_w = 80, .box_w = 1, .box_h = 9, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 327, .adv_w = 80, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 331, .adv_w = 80, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = 3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_Font1 = {
#else
lv_font_t ui_font_Font1 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 10,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FONT1*/

