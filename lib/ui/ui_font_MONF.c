/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --font C:/Users/Szoot/SquareLine/assets/monofonto rg.otf -o C:/Users/Szoot/SquareLine/assets\ui_font_MONF.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_MONF
#define UI_FONT_MONF 1
#endif

#if UI_FONT_MONF

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xf, 0xc0,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x9, 0xd, 0x86, 0xc2, 0x47, 0xfb, 0xf8, 0xc8,
    0x6c, 0x7f, 0x7f, 0x89, 0xd, 0x84, 0x80,

    /* U+0024 "$" */
    0x18, 0x31, 0xfe, 0x3c, 0x78, 0x3c, 0x3c, 0x3c,
    0x1c, 0x1e, 0x3c, 0x6f, 0x86, 0xc,

    /* U+0025 "%" */
    0xf0, 0xbc, 0x6f, 0x33, 0xcc, 0xf6, 0x3d, 0xf,
    0xf8, 0x7b, 0x1e, 0xcd, 0xb2, 0x6d, 0x9b, 0xc3,
    0x80,

    /* U+0026 "&" */
    0x38, 0x3e, 0x1b, 0xd, 0x86, 0xc1, 0xc1, 0xc0,
    0xf2, 0xcf, 0x67, 0x33, 0x9f, 0xe7, 0x30,

    /* U+0027 "'" */
    0xff,

    /* U+0028 "(" */
    0x32, 0x66, 0xcc, 0xcc, 0xcc, 0xcc, 0xc6, 0x62,
    0x30,

    /* U+0029 ")" */
    0xc4, 0x66, 0x63, 0x33, 0x33, 0x33, 0x26, 0x64,
    0xc0,

    /* U+002A "*" */
    0x8, 0x4, 0x12, 0x7f, 0xf1, 0xc0, 0xa0, 0xd8,
    0x46,

    /* U+002B "+" */
    0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18,

    /* U+002C "," */
    0xdb, 0x68,

    /* U+002D "-" */
    0xff, 0xf0,

    /* U+002E "." */
    0xfc,

    /* U+002F "/" */
    0x1, 0x80, 0x80, 0xc0, 0x40, 0x60, 0x30, 0x10,
    0x18, 0x8, 0xc, 0x4, 0x6, 0x3, 0x1, 0x1,
    0x80, 0x80, 0xc0, 0x0,

    /* U+0030 "0" */
    0x7d, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1f, 0xf7, 0xc0,

    /* U+0031 "1" */
    0x17, 0xff, 0x33, 0x33, 0x33, 0x33, 0x30,

    /* U+0032 "2" */
    0x79, 0xfb, 0x1e, 0x30, 0x61, 0xc3, 0xe, 0x18,
    0x70, 0xc3, 0xf7, 0xe0,

    /* U+0033 "3" */
    0x79, 0xfb, 0x18, 0x30, 0x63, 0x87, 0x3, 0x6,
    0xf, 0x1f, 0xe7, 0x80,

    /* U+0034 "4" */
    0xe, 0x7, 0x7, 0x83, 0xc3, 0x61, 0xb1, 0x98,
    0xcc, 0xff, 0xff, 0xc1, 0x80, 0xc0, 0x60,

    /* U+0035 "5" */
    0xff, 0xff, 0x6, 0xc, 0x1f, 0xbf, 0x63, 0x6,
    0xf, 0x1f, 0xe7, 0x80,

    /* U+0036 "6" */
    0xe, 0x1c, 0x18, 0x38, 0x30, 0x7c, 0x7e, 0xe7,
    0xc3, 0xc3, 0xe7, 0x7e, 0x3c,

    /* U+0037 "7" */
    0xff, 0xfe, 0xe, 0xe, 0xc, 0x1c, 0x1c, 0x18,
    0x38, 0x38, 0x30, 0x70, 0x70,

    /* U+0038 "8" */
    0x79, 0xff, 0x1e, 0x3c, 0x6f, 0x9f, 0x63, 0xc7,
    0x8f, 0x1b, 0xe3, 0x80,

    /* U+0039 "9" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e, 0x7e,
    0xc, 0x1c, 0x18, 0x38, 0x70,

    /* U+003A ":" */
    0xfc, 0x3f,

    /* U+003B ";" */
    0xfc, 0xe, 0xa8,

    /* U+003C "<" */
    0x1, 0x7, 0x1c, 0x70, 0xc0, 0xe0, 0x38, 0xe,
    0x3,

    /* U+003D "=" */
    0xff, 0xff, 0x0, 0x0, 0xff, 0xff,

    /* U+003E ">" */
    0x80, 0xe0, 0x38, 0xe, 0x3, 0x7, 0x1c, 0x70,
    0xc0,

    /* U+003F "?" */
    0x7d, 0xff, 0x1e, 0x30, 0xe3, 0x8e, 0x18, 0x0,
    0x0, 0xc1, 0x83, 0x0,

    /* U+0040 "@" */
    0x3e, 0x3f, 0xf8, 0x79, 0xfd, 0xfe, 0xcf, 0x67,
    0xb3, 0xdf, 0xe7, 0xf0, 0x1c, 0x7, 0xf9, 0xfc,

    /* U+0041 "A" */
    0x1c, 0xe, 0x7, 0x3, 0x83, 0xe1, 0xb0, 0xd8,
    0x6c, 0x77, 0x3f, 0x9f, 0xcc, 0x6e, 0x38,

    /* U+0042 "B" */
    0xfd, 0xff, 0x1e, 0x3c, 0x7f, 0xbf, 0x63, 0xc7,
    0x8f, 0x3f, 0xff, 0xc0,

    /* U+0043 "C" */
    0x3c, 0x7e, 0xc7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc7, 0x7e, 0x3c,

    /* U+0044 "D" */
    0xfd, 0xfb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1f, 0xef, 0xc0,

    /* U+0045 "E" */
    0xff, 0xff, 0x6, 0xc, 0x18, 0x3f, 0xff, 0xc1,
    0x83, 0x7, 0xff, 0xe0,

    /* U+0046 "F" */
    0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xfe,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0x3c, 0xff, 0x1e, 0x3c, 0x18, 0x33, 0xe7, 0xc7,
    0x8f, 0x1b, 0xf3, 0xe0,

    /* U+0048 "H" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7f, 0xff, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x60,

    /* U+0049 "I" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0x3f, 0xfc,

    /* U+004A "J" */
    0xe, 0x1c, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6,
    0xc, 0x3f, 0xef, 0x80,

    /* U+004B "K" */
    0xc7, 0x9b, 0x36, 0xcd, 0x9e, 0x3c, 0x7c, 0xd9,
    0xbb, 0x36, 0x7c, 0x60,

    /* U+004C "L" */
    0xc1, 0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1,
    0x83, 0x7, 0xff, 0xe0,

    /* U+004D "M" */
    0xe3, 0xe7, 0xe7, 0xf7, 0xff, 0xff, 0xdb, 0xdb,
    0xdb, 0xd3, 0xc3, 0xc3, 0xc3,

    /* U+004E "N" */
    0xe7, 0xcf, 0x9f, 0xbf, 0x7e, 0xff, 0xef, 0xdf,
    0x9f, 0x3e, 0x7c, 0x60,

    /* U+004F "O" */
    0x38, 0xfb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1b, 0xe3, 0x80,

    /* U+0050 "P" */
    0xf9, 0xfb, 0x3e, 0x3c, 0x78, 0xf3, 0xfe, 0xf9,
    0x83, 0x6, 0xc, 0x0,

    /* U+0051 "Q" */
    0x38, 0xfb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1b, 0xe7, 0xc1, 0x83, 0x0,

    /* U+0052 "R" */
    0xf9, 0xfb, 0x3e, 0x3c, 0x78, 0xff, 0x7c, 0xf9,
    0xbb, 0x36, 0x7c, 0x60,

    /* U+0053 "S" */
    0x7d, 0xff, 0x1e, 0xc, 0xe, 0xf, 0xf, 0x7,
    0x8f, 0x1f, 0xe7, 0x80,

    /* U+0054 "T" */
    0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xe7, 0x7e, 0x3c,

    /* U+0056 "V" */
    0xe3, 0xb1, 0x98, 0xce, 0x67, 0x71, 0xb0, 0xd8,
    0x6c, 0x3e, 0xe, 0x7, 0x3, 0x81, 0xc0,

    /* U+0057 "W" */
    0xe1, 0xf1, 0xfa, 0xfd, 0x76, 0xb3, 0x59, 0xfc,
    0xfe, 0x77, 0x3b, 0x9d, 0xce, 0xe6, 0x20,

    /* U+0058 "X" */
    0xc7, 0xdf, 0xbb, 0x67, 0xc7, 0xe, 0x1c, 0x7c,
    0xdb, 0xbf, 0x7c, 0x60,

    /* U+0059 "Y" */
    0xe7, 0xe7, 0x66, 0x7e, 0x3c, 0x3c, 0x3c, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+005A "Z" */
    0xfe, 0xfe, 0xe, 0xc, 0x1c, 0x18, 0x38, 0x38,
    0x30, 0x70, 0x60, 0xff, 0xff,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
    0xff,

    /* U+005C "\\" */
    0xc0, 0x20, 0x18, 0x4, 0x3, 0x1, 0x80, 0x40,
    0x30, 0x8, 0x6, 0x1, 0x0, 0xc0, 0x60, 0x10,
    0xc, 0x2, 0x1, 0x80,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0xff,

    /* U+005E "^" */
    0x38, 0x71, 0xb3, 0x6c, 0x78, 0xc0,

    /* U+005F "_" */
    0xff, 0xff, 0xc0,

    /* U+0060 "`" */
    0x61, 0x8c,

    /* U+0061 "a" */
    0x3e, 0x7f, 0x3, 0x7f, 0xff, 0xc3, 0xc7, 0xff,
    0x7b,

    /* U+0062 "b" */
    0xc1, 0x83, 0x6, 0xf, 0xdf, 0xb1, 0xe3, 0xc7,
    0x8f, 0x1f, 0xef, 0xc0,

    /* U+0063 "c" */
    0x3c, 0xff, 0x9e, 0xc, 0x18, 0x39, 0xbf, 0x3c,

    /* U+0064 "d" */
    0x6, 0xc, 0x18, 0x37, 0xff, 0xf1, 0xe3, 0xc7,
    0x8f, 0x1f, 0xf7, 0xe0,

    /* U+0065 "e" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xff, 0xc0, 0xe2, 0x7e,
    0x3c,

    /* U+0066 "f" */
    0x1f, 0x3f, 0x30, 0x30, 0xfc, 0xfc, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x30,

    /* U+0067 "g" */
    0x7f, 0xff, 0x3e, 0x3c, 0x78, 0xf3, 0xff, 0x7e,
    0xf, 0x1f, 0xe7, 0x80,

    /* U+0068 "h" */
    0xc1, 0x83, 0x6, 0xf, 0xdf, 0xf9, 0xe3, 0xc7,
    0x8f, 0x1e, 0x3c, 0x60,

    /* U+0069 "i" */
    0x30, 0xc0, 0x0, 0xf3, 0xc3, 0xc, 0x30, 0xc3,
    0x3f, 0xfc,

    /* U+006A "j" */
    0x18, 0xc0, 0x7, 0xbc, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x7f, 0xf0,

    /* U+006B "k" */
    0xc1, 0x83, 0x6, 0xc, 0xdb, 0xb6, 0x78, 0xf1,
    0xf3, 0x76, 0x6c, 0xe0,

    /* U+006C "l" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0x30,

    /* U+006D "m" */
    0xff, 0xff, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdb,
    0xdb,

    /* U+006E "n" */
    0xfd, 0xff, 0x9e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,

    /* U+006F "o" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e,
    0x3c,

    /* U+0070 "p" */
    0xfd, 0xfb, 0x1e, 0x3c, 0x78, 0xf1, 0xfe, 0xfd,
    0x83, 0x6, 0xc, 0x0,

    /* U+0071 "q" */
    0x7f, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xff, 0x7e,
    0xc, 0x18, 0x30, 0x60,

    /* U+0072 "r" */
    0xdd, 0xff, 0x96, 0xc, 0x18, 0x30, 0x60, 0xc0,

    /* U+0073 "s" */
    0x79, 0xfb, 0x1f, 0x3, 0x81, 0xf1, 0xff, 0x7c,

    /* U+0074 "t" */
    0x30, 0x63, 0xf7, 0xe3, 0x6, 0xc, 0x18, 0x30,
    0x7c, 0x78,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0x7e,
    0x3c,

    /* U+0076 "v" */
    0x63, 0x31, 0x9c, 0xc6, 0xc3, 0x61, 0xb0, 0xf8,
    0x38, 0x1c, 0x0,

    /* U+0077 "w" */
    0xe9, 0xf5, 0xda, 0xcd, 0x66, 0xf3, 0xf9, 0xdc,
    0x6c, 0x36, 0x0,

    /* U+0078 "x" */
    0xc6, 0xd9, 0xb1, 0xc3, 0x87, 0x1b, 0x36, 0xc6,

    /* U+0079 "y" */
    0x63, 0x31, 0x9c, 0xc6, 0xe3, 0x61, 0xb0, 0xf8,
    0x38, 0x1c, 0xe, 0x7, 0x3, 0x1, 0x80,

    /* U+007A "z" */
    0xff, 0xf8, 0x70, 0xc3, 0x86, 0x18, 0x7f, 0xfe,

    /* U+007B "{" */
    0x19, 0xcc, 0x63, 0x18, 0xc6, 0xe7, 0xc, 0x63,
    0x18, 0xc6, 0x38, 0xc0,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xe3, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x1c, 0x73,
    0xc, 0x30, 0xc3, 0xc, 0xf3, 0x80,

    /* U+007E "~" */
    0xf1, 0xff, 0x8f
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 144, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 144, .box_w = 2, .box_h = 13, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 144, .box_w = 5, .box_h = 4, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 8, .adv_w = 144, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 144, .box_w = 7, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 37, .adv_w = 144, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 144, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 144, .box_w = 2, .box_h = 4, .ofs_x = 4, .ofs_y = 9},
    {.bitmap_index = 70, .adv_w = 144, .box_w = 4, .box_h = 18, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 79, .adv_w = 144, .box_w = 4, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 88, .adv_w = 144, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 97, .adv_w = 144, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 105, .adv_w = 144, .box_w = 3, .box_h = 5, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 107, .adv_w = 144, .box_w = 6, .box_h = 2, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 109, .adv_w = 144, .box_w = 2, .box_h = 3, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 144, .box_w = 9, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 130, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 144, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 144, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 188, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 144, .box_w = 2, .box_h = 8, .ofs_x = 3, .ofs_y = 2},
    {.bitmap_index = 253, .adv_w = 144, .box_w = 2, .box_h = 11, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 256, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 265, .adv_w = 144, .box_w = 8, .box_h = 6, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 271, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 280, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 292, .adv_w = 144, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 308, .adv_w = 144, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 144, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 431, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 455, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 504, .adv_w = 144, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 518, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 144, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 144, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 598, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 623, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 636, .adv_w = 144, .box_w = 4, .box_h = 18, .ofs_x = 5, .ofs_y = -4},
    {.bitmap_index = 645, .adv_w = 144, .box_w = 9, .box_h = 17, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 665, .adv_w = 144, .box_w = 4, .box_h = 18, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 674, .adv_w = 144, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 680, .adv_w = 144, .box_w = 9, .box_h = 2, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 683, .adv_w = 144, .box_w = 5, .box_h = 3, .ofs_x = 2, .ofs_y = 10},
    {.bitmap_index = 685, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 694, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 726, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 735, .adv_w = 144, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 760, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 772, .adv_w = 144, .box_w = 6, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 782, .adv_w = 144, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 793, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 805, .adv_w = 144, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 812, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 821, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 829, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 838, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 850, .adv_w = 144, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 862, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 870, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 878, .adv_w = 144, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 888, .adv_w = 144, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 908, .adv_w = 144, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 919, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 927, .adv_w = 144, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 942, .adv_w = 144, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 950, .adv_w = 144, .box_w = 5, .box_h = 18, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 962, .adv_w = 144, .box_w = 2, .box_h = 17, .ofs_x = 4, .ofs_y = -3},
    {.bitmap_index = 967, .adv_w = 144, .box_w = 6, .box_h = 18, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 981, .adv_w = 144, .box_w = 8, .box_h = 3, .ofs_x = 1, .ofs_y = 5}
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
const lv_font_t ui_font_MONF = {
#else
lv_font_t ui_font_MONF = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if UI_FONT_MONF*/

