#include "kestrel/graphics/font.h"

const font_t standard_font
    = { .characters = {
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0000 (nul)
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0001
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0002
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0003
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0004
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0005
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0006
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0007
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0008
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0009
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+000A
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+000B
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+000C
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+000D
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+000E
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+000F
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0010
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0011
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0012
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0013
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0014
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0015
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0016
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0017
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0018
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0019
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+001A
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+001B
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+001C
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+001D
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+001E
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+001F
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0020 (space)
            {
                .rows = { 0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00 },
            }, // U+0021 (!)
            {
                .rows = { 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0022 (")
            {
                .rows = { 0x36, 0x36, 0x7F, 0x36, 0x7F, 0x36, 0x36, 0x00 },
            }, // U+0023 (#)
            {
                .rows = { 0x0C, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x0C, 0x00 },
            }, // U+0024 ($)
            {
                .rows = { 0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00 },
            }, // U+0025 (%)
            {
                .rows = { 0x1C, 0x36, 0x1C, 0x6E, 0x3B, 0x33, 0x6E, 0x00 },
            }, // U+0026 (&)
            {
                .rows = { 0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0027 (')
            {
                .rows = { 0x18, 0x0C, 0x06, 0x06, 0x06, 0x0C, 0x18, 0x00 },
            }, // U+0028 (()
            {
                .rows = { 0x06, 0x0C, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x00 },
            }, // U+0029 ())
            {
                .rows = { 0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00 },
            }, // U+002A (*)
            {
                .rows = { 0x00, 0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x00 },
            }, // U+002B (+)
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x06 },
            }, // U+002C (,)
            {
                .rows = { 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00 },
            }, // U+002D (-)
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00 },
            }, // U+002E (.)
            {
                .rows = { 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00 },
            }, // U+002F (/)
            {
                .rows = { 0x3E, 0x63, 0x73, 0x7B, 0x6F, 0x67, 0x3E, 0x00 },
            }, // U+0030 (0)
            {
                .rows = { 0x0C, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x3F, 0x00 },
            }, // U+0031 (1)
            {
                .rows = { 0x1E, 0x33, 0x30, 0x1C, 0x06, 0x33, 0x3F, 0x00 },
            }, // U+0032 (2)
            {
                .rows = { 0x1E, 0x33, 0x30, 0x1C, 0x30, 0x33, 0x1E, 0x00 },
            }, // U+0033 (3)
            {
                .rows = { 0x38, 0x3C, 0x36, 0x33, 0x7F, 0x30, 0x78, 0x00 },
            }, // U+0034 (4)
            {
                .rows = { 0x3F, 0x03, 0x1F, 0x30, 0x30, 0x33, 0x1E, 0x00 },
            }, // U+0035 (5)
            {
                .rows = { 0x1C, 0x06, 0x03, 0x1F, 0x33, 0x33, 0x1E, 0x00 },
            }, // U+0036 (6)
            {
                .rows = { 0x3F, 0x33, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x00 },
            }, // U+0037 (7)
            {
                .rows = { 0x1E, 0x33, 0x33, 0x1E, 0x33, 0x33, 0x1E, 0x00 },
            }, // U+0038 (8)
            {
                .rows = { 0x1E, 0x33, 0x33, 0x3E, 0x30, 0x18, 0x0E, 0x00 },
            }, // U+0039 (9)
            {
                .rows = { 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00 },
            }, // U+003A (:)
            {
                .rows = { 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x06 },
            }, // U+003B (;)
            {
                .rows = { 0x18, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x18, 0x00 },
            }, // U+003C (<)
            {
                .rows = { 0x00, 0x00, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00 },
            }, // U+003D (=)
            {
                .rows = { 0x06, 0x0C, 0x18, 0x30, 0x18, 0x0C, 0x06, 0x00 },
            }, // U+003E (>)
            {
                .rows = { 0x1E, 0x33, 0x30, 0x18, 0x0C, 0x00, 0x0C, 0x00 },
            }, // U+003F (?)
            {
                .rows = { 0x3E, 0x63, 0x7B, 0x7B, 0x7B, 0x03, 0x1E, 0x00 },
            }, // U+0040 (@)
            {
                .rows = { 0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00 },
            }, // U+0041 (A)
            {
                .rows = { 0x3F, 0x66, 0x66, 0x3E, 0x66, 0x66, 0x3F, 0x00 },
            }, // U+0042 (B)
            {
                .rows = { 0x3C, 0x66, 0x03, 0x03, 0x03, 0x66, 0x3C, 0x00 },
            }, // U+0043 (C)
            {
                .rows = { 0x1F, 0x36, 0x66, 0x66, 0x66, 0x36, 0x1F, 0x00 },
            }, // U+0044 (D)
            {
                .rows = { 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x46, 0x7F, 0x00 },
            }, // U+0045 (E)
            {
                .rows = { 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x06, 0x0F, 0x00 },
            }, // U+0046 (F)
            {
                .rows = { 0x3C, 0x66, 0x03, 0x03, 0x73, 0x66, 0x7C, 0x00 },
            }, // U+0047 (G)
            {
                .rows = { 0x33, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x33, 0x00 },
            }, // U+0048 (H)
            {
                .rows = { 0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00 },
            }, // U+0049 (I)
            {
                .rows = { 0x78, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E, 0x00 },
            }, // U+004A (J)
            {
                .rows = { 0x67, 0x66, 0x36, 0x1E, 0x36, 0x66, 0x67, 0x00 },
            }, // U+004B (K)
            {
                .rows = { 0x0F, 0x06, 0x06, 0x06, 0x46, 0x66, 0x7F, 0x00 },
            }, // U+004C (L)
            {
                .rows = { 0x63, 0x77, 0x7F, 0x7F, 0x6B, 0x63, 0x63, 0x00 },
            }, // U+004D (M)
            {
                .rows = { 0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, 0x63, 0x00 },
            }, // U+004E (N)
            {
                .rows = { 0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00 },
            }, // U+004F (O)
            {
                .rows = { 0x3F, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x0F, 0x00 },
            }, // U+0050 (P)
            {
                .rows = { 0x1E, 0x33, 0x33, 0x33, 0x3B, 0x1E, 0x38, 0x00 },
            }, // U+0051 (Q)
            {
                .rows = { 0x3F, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x67, 0x00 },
            }, // U+0052 (R)
            {
                .rows = { 0x1E, 0x33, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x00 },
            }, // U+0053 (S)
            {
                .rows = { 0x3F, 0x2D, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00 },
            }, // U+0054 (T)
            {
                .rows = { 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0x00 },
            }, // U+0055 (U)
            {
                .rows = { 0x33, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00 },
            }, // U+0056 (V)
            {
                .rows = { 0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00 },
            }, // U+0057 (W)
            {
                .rows = { 0x63, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x00 },
            }, // U+0058 (X)
            {
                .rows = { 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x0C, 0x1E, 0x00 },
            }, // U+0059 (Y)
            {
                .rows = { 0x7F, 0x63, 0x31, 0x18, 0x4C, 0x66, 0x7F, 0x00 },
            }, // U+005A (Z)
            {
                .rows = { 0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x00 },
            }, // U+005B ([)
            {
                .rows = { 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00 },
            }, // U+005C (\)
            {
                .rows = { 0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1E, 0x00 },
            }, // U+005D (])
            {
                .rows = { 0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00 },
            }, // U+005E (^)
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF },
            }, // U+005F (_)
            {
                .rows = { 0x0C, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+0060 (`)
            {
                .rows = { 0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00 },
            }, // U+0061 (a)
            {
                .rows = { 0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00 },
            }, // U+0062 (b)
            {
                .rows = { 0x00, 0x00, 0x1E, 0x33, 0x03, 0x33, 0x1E, 0x00 },
            }, // U+0063 (c)
            {
                .rows = { 0x38, 0x30, 0x30, 0x3e, 0x33, 0x33, 0x6E, 0x00 },
            }, // U+0064 (d)
            {
                .rows = { 0x00, 0x00, 0x1E, 0x33, 0x3f, 0x03, 0x1E, 0x00 },
            }, // U+0065 (e)
            {
                .rows = { 0x1C, 0x36, 0x06, 0x0f, 0x06, 0x06, 0x0F, 0x00 },
            }, // U+0066 (f)
            {
                .rows = { 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F },
            }, // U+0067 (g)
            {
                .rows = { 0x07, 0x06, 0x36, 0x6E, 0x66, 0x66, 0x67, 0x00 },
            }, // U+0068 (h)
            {
                .rows = { 0x0C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00 },
            }, // U+0069 (i)
            {
                .rows = { 0x30, 0x00, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E },
            }, // U+006A (j)
            {
                .rows = { 0x07, 0x06, 0x66, 0x36, 0x1E, 0x36, 0x67, 0x00 },
            }, // U+006B (k)
            {
                .rows = { 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00 },
            }, // U+006C (l)
            {
                .rows = { 0x00, 0x00, 0x33, 0x7F, 0x7F, 0x6B, 0x63, 0x00 },
            }, // U+006D (m)
            {
                .rows = { 0x00, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x33, 0x00 },
            }, // U+006E (n)
            {
                .rows = { 0x00, 0x00, 0x1E, 0x33, 0x33, 0x33, 0x1E, 0x00 },
            }, // U+006F (o)
            {
                .rows = { 0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x0F },
            }, // U+0070 (p)
            {
                .rows = { 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x78 },
            }, // U+0071 (q)
            {
                .rows = { 0x00, 0x00, 0x3B, 0x6E, 0x66, 0x06, 0x0F, 0x00 },
            }, // U+0072 (r)
            {
                .rows = { 0x00, 0x00, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x00 },
            }, // U+0073 (s)
            {
                .rows = { 0x08, 0x0C, 0x3E, 0x0C, 0x0C, 0x2C, 0x18, 0x00 },
            }, // U+0074 (t)
            {
                .rows = { 0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00 },
            }, // U+0075 (u)
            {
                .rows = { 0x00, 0x00, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00 },
            }, // U+0076 (v)
            {
                .rows = { 0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00 },
            }, // U+0077 (w)
            {
                .rows = { 0x00, 0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00 },
            }, // U+0078 (x)
            {
                .rows = { 0x00, 0x00, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x1F },
            }, // U+0079 (y)
            {
                .rows = { 0x00, 0x00, 0x3F, 0x19, 0x0C, 0x26, 0x3F, 0x00 },
            }, // U+007A (z)
            {
                .rows = { 0x38, 0x0C, 0x0C, 0x07, 0x0C, 0x0C, 0x38, 0x00 },
            }, // U+007B ({)
            {
                .rows = { 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00 },
            }, // U+007C (|)
            {
                .rows = { 0x07, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0x07, 0x00 },
            }, // U+007D (})
            {
                .rows = { 0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+007E (~)
            {
                .rows = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
            }, // U+007F
        } };