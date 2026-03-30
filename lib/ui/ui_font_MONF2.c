/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font C:/Users/Szoot/SquareLine/assets/monofonto rg.otf -o C:/Users/Szoot/SquareLine/assets\ui_font_MONF2.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_MONF2
#define UI_FONT_MONF2 1
#endif

#if UI_FONT_MONF2

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xf0, 0x30,

    /* U+0022 "\"" */
    0xff, 0xf0,

    /* U+0023 "#" */
    0x14, 0x28, 0x93, 0xf2, 0x85, 0x3f, 0x24, 0x50,
    0xa0,

    /* U+0024 "$" */
    0x20, 0xcf, 0xb3, 0xc3, 0x87, 0x87, 0xf, 0x3f,
    0x98, 0x20,

    /* U+0025 "%" */
    0xe3, 0x4a, 0xa5, 0x4f, 0xe3, 0x4a, 0x95, 0x4b,
    0x1c,

    /* U+0026 "&" */
    0x30, 0xd1, 0xa3, 0xc3, 0xe, 0x33, 0xe6, 0xcc,
    0xec,

    /* U+0027 "'" */
    0xfc,

    /* U+0028 "(" */
    0x36, 0x6c, 0xcc, 0xcc, 0xcc, 0x66, 0x22,

    /* U+0029 ")" */
    0xc6, 0x62, 0x33, 0x33, 0x33, 0x66, 0x44,

    /* U+002A "*" */
    0x10, 0x23, 0x79, 0x82, 0x8d, 0x80, 0x0,

    /* U+002B "+" */
    0x10, 0x4f, 0xc4, 0x10, 0x40,

    /* U+002C "," */
    0x7e,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x6, 0x8, 0x10, 0x40, 0x83, 0x4, 0x18, 0x20,
    0x41, 0x2, 0xc, 0x0,

    /* U+0030 "0" */
    0x76, 0xf7, 0xbd, 0xef, 0x7b, 0xdb, 0x80,

    /* U+0031 "1" */
    0x17, 0xf3, 0x33, 0x33, 0x33,

    /* U+0032 "2" */
    0x7b, 0x3c, 0xc3, 0x1c, 0x63, 0x8c, 0x73, 0xf0,

    /* U+0033 "3" */
    0x7b, 0x30, 0xc3, 0x18, 0x30, 0xc3, 0xcd, 0xe0,

    /* U+0034 "4" */
    0xc, 0x38, 0x71, 0xe2, 0xcd, 0x93, 0x7f, 0xc,
    0x18,

    /* U+0035 "5" */
    0xfb, 0xc, 0x30, 0xfb, 0x30, 0xc3, 0xcd, 0xe0,

    /* U+0036 "6" */
    0x18, 0xc3, 0x18, 0x7b, 0x3c, 0xf3, 0xcd, 0xe0,

    /* U+0037 "7" */
    0xfc, 0x71, 0x86, 0x38, 0xc3, 0x18, 0x61, 0x80,

    /* U+0038 "8" */
    0x7b, 0x3c, 0xf3, 0x7b, 0x3c, 0xf3, 0xcd, 0xe0,

    /* U+0039 "9" */
    0x7b, 0x3c, 0xf3, 0xcd, 0xe1, 0x8c, 0x31, 0x80,

    /* U+003A ":" */
    0xc0, 0x30,

    /* U+003B ";" */
    0xc3, 0xa8,

    /* U+003C "<" */
    0x0, 0x33, 0x30, 0xc0, 0xc0, 0xc0,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0x3, 0x3, 0x3, 0xc, 0xcc, 0x0,

    /* U+003F "?" */
    0x7b, 0x3c, 0xc3, 0x18, 0xc3, 0x0, 0x0, 0xc0,

    /* U+0040 "@" */
    0x7b, 0x1c, 0x77, 0xd7, 0x5d, 0x77, 0xc3, 0x7,
    0xc0,

    /* U+0041 "A" */
    0x38, 0x70, 0xe1, 0xc2, 0x8d, 0x9b, 0x3e, 0x45,
    0x8c,

    /* U+0042 "B" */
    0xfb, 0x3c, 0xf3, 0xfb, 0x3c, 0xf3, 0xcf, 0xe0,

    /* U+0043 "C" */
    0x7b, 0x3c, 0x30, 0xc3, 0xc, 0x30, 0xcd, 0xe0,

    /* U+0044 "D" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0xe0,

    /* U+0045 "E" */
    0xfe, 0x31, 0x8f, 0xe3, 0x18, 0xc7, 0xc0,

    /* U+0046 "F" */
    0xff, 0xc, 0x30, 0xff, 0xc, 0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x7b, 0x3c, 0x30, 0xdf, 0x3c, 0xf3, 0xcd, 0xf0,

    /* U+0048 "H" */
    0xcf, 0x3c, 0xf3, 0xff, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0049 "I" */
    0xfb, 0x18, 0xc6, 0x31, 0x8c, 0x67, 0xc0,

    /* U+004A "J" */
    0x1c, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf, 0xe0,

    /* U+004B "K" */
    0xcf, 0x6d, 0xbc, 0xf3, 0xcd, 0x36, 0xdb, 0x30,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf0,

    /* U+004D "M" */
    0xcf, 0xbf, 0xff, 0xff, 0xfe, 0xf3, 0xcf, 0x30,

    /* U+004E "N" */
    0xef, 0xbe, 0xfb, 0xff, 0xfd, 0xf7, 0xdf, 0x30,

    /* U+004F "O" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcd, 0xe0,

    /* U+0050 "P" */
    0xfb, 0x3c, 0xf3, 0xcf, 0xec, 0x30, 0xc3, 0x0,

    /* U+0051 "Q" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcd, 0xe1,
    0x86,

    /* U+0052 "R" */
    0xfb, 0x3c, 0xf3, 0xff, 0xcf, 0x36, 0xdb, 0x30,

    /* U+0053 "S" */
    0x7b, 0x3c, 0x38, 0xf9, 0xf1, 0xc3, 0xcd, 0xe0,

    /* U+0054 "T" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc0,

    /* U+0055 "U" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcd, 0xe0,

    /* U+0056 "V" */
    0xc6, 0x89, 0xb3, 0x66, 0xc5, 0xe, 0x1c, 0x38,
    0x70,

    /* U+0057 "W" */
    0xc7, 0x8f, 0x5e, 0xb5, 0x4f, 0x9b, 0x36, 0x6c,
    0xd8,

    /* U+0058 "X" */
    0x6c, 0xd9, 0xb1, 0xc3, 0x87, 0xe, 0x36, 0x6c,
    0xd8,

    /* U+0059 "Y" */
    0xcf, 0x37, 0x9e, 0x78, 0xc3, 0xc, 0x30, 0xc0,

    /* U+005A "Z" */
    0xfc, 0x71, 0x8e, 0x30, 0xc7, 0x18, 0xe3, 0xf0,

    /* U+005B "[" */
    0xfb, 0x6d, 0xb6, 0xdb, 0x6d, 0xc0,

    /* U+005C "\\" */
    0xc0, 0x81, 0x1, 0x2, 0x6, 0x4, 0xc, 0x8,
    0x10, 0x10, 0x20, 0x60,

    /* U+005D "]" */
    0xed, 0xb6, 0xdb, 0x6d, 0xb7, 0xc0,

    /* U+005E "^" */
    0x23, 0x95, 0xb8, 0x80,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0x40,

    /* U+0061 "a" */
    0x79, 0x30, 0xdf, 0xcf, 0x37, 0xc0,

    /* U+0062 "b" */
    0xc3, 0xc, 0x3e, 0xcf, 0x3c, 0xf3, 0xcf, 0xe0,

    /* U+0063 "c" */
    0x7b, 0x9c, 0x30, 0xc3, 0x97, 0xc0,

    /* U+0064 "d" */
    0xc, 0x30, 0xdf, 0xcf, 0x3c, 0xf3, 0xcd, 0xf0,

    /* U+0065 "e" */
    0x7b, 0x3c, 0xff, 0xc3, 0x27, 0x80,

    /* U+0066 "f" */
    0x3d, 0x86, 0x3e, 0x61, 0x86, 0x18, 0x61, 0x80,

    /* U+0067 "g" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0x8f, 0xe0,

    /* U+0068 "h" */
    0xc3, 0xc, 0x3e, 0xcf, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0069 "i" */
    0x60, 0xe, 0x66, 0x66, 0x6f,

    /* U+006A "j" */
    0x18, 0x0, 0xf1, 0x8c, 0x63, 0x18, 0xc6, 0x3f,
    0x0,

    /* U+006B "k" */
    0xc3, 0xc, 0x32, 0xdb, 0xcf, 0x34, 0xdb, 0x30,

    /* U+006C "l" */
    0xf3, 0x33, 0x33, 0x33, 0x33,

    /* U+006D "m" */
    0xff, 0x7d, 0xf7, 0xdf, 0x7d, 0xc0,

    /* U+006E "n" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3c, 0xc0,

    /* U+006F "o" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x37, 0x80,

    /* U+0070 "p" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3f, 0xb0, 0xc3, 0x0,

    /* U+0071 "q" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xc, 0x30,

    /* U+0072 "r" */
    0xfb, 0x2c, 0x30, 0xc3, 0xc, 0x0,

    /* U+0073 "s" */
    0x76, 0xf8, 0xe1, 0xed, 0xc0,

    /* U+0074 "t" */
    0x61, 0x8f, 0x98, 0x61, 0x86, 0x18, 0x7c,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x37, 0x80,

    /* U+0076 "v" */
    0xc6, 0xc9, 0xb3, 0x63, 0x87, 0xe, 0x0,

    /* U+0077 "w" */
    0xd7, 0xad, 0x53, 0xe6, 0xcd, 0x9b, 0x0,

    /* U+0078 "x" */
    0xde, 0xdc, 0xe7, 0x6f, 0x60,

    /* U+0079 "y" */
    0xc6, 0xc9, 0xb3, 0x62, 0x87, 0xe, 0x8, 0x30,
    0x60,

    /* U+007A "z" */
    0xf8, 0x63, 0xc, 0x63, 0x8f, 0xc0,

    /* U+007B "{" */
    0x39, 0x8c, 0x63, 0x18, 0xd8, 0x31, 0x8c, 0x63,
    0x1c,

    /* U+007C "|" */
    0xff, 0xf8,

    /* U+007D "}" */
    0xc6, 0x66, 0x66, 0x61, 0x66, 0x66, 0x6c,

    /* U+007E "~" */
    0xe0, 0x70
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 112, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 112, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 112, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 112, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 25, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 112, .box_w = 2, .box_h = 3, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 44, .adv_w = 112, .box_w = 4, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 51, .adv_w = 112, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 58, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 65, .adv_w = 112, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 70, .adv_w = 112, .box_w = 2, .box_h = 4, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 71, .adv_w = 112, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 72, .adv_w = 112, .box_w = 2, .box_h = 1, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 112, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 85, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 112, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 112, .box_w = 2, .box_h = 6, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 164, .adv_w = 112, .box_w = 2, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 112, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 172, .adv_w = 112, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 175, .adv_w = 112, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 181, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 189, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 198, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 246, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 112, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 309, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 325, .adv_w = 112, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 334, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 401, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 112, .box_w = 3, .box_h = 14, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 415, .adv_w = 112, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 427, .adv_w = 112, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 433, .adv_w = 112, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 437, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 438, .adv_w = 112, .box_w = 3, .box_h = 1, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 439, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 481, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 489, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 112, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 112, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 511, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 112, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 550, .adv_w = 112, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 558, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 564, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 112, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 112, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 610, .adv_w = 112, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 616, .adv_w = 112, .box_w = 5, .box_h = 14, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 625, .adv_w = 112, .box_w = 1, .box_h = 13, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 627, .adv_w = 112, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 634, .adv_w = 112, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 4}
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
const lv_font_t ui_font_MONF2 = {
#else
lv_font_t ui_font_MONF2 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_MONF2*/

