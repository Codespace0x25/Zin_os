#ifndef OUTP_H
#define OUTP_H



// Color macros
#define COLOR_BLACK         0x0
#define COLOR_BLUE          0x1
#define COLOR_GREEN         0x2
#define COLOR_CYAN          0x3
#define COLOR_RED           0x4
#define COLOR_MAGENTA       0x5
#define COLOR_BROWN         0x6
#define COLOR_LIGHT_GRAY    0x7
#define COLOR_DARK_GRAY     0x8
#define COLOR_LIGHT_BLUE    0x9
#define COLOR_LIGHT_GREEN   0xA
#define COLOR_LIGHT_CYAN    0xB
#define COLOR_LIGHT_RED     0xC
#define COLOR_LIGHT_MAGENTA 0xD
#define COLOR_YELLOW        0xE
#define COLOR_WHITE         0xF

/// @brief Output a colored text into the screen.
/// @param text The string to print
/// @param color The color used (COLOR_XXX)
inline void putText(const char* text, unsigned short color)
{
    unsigned short* video_mem = (unsigned short*)0xB8000;  // Video memory address where the text will be displayed
    color = color << 8;  // Shift the color value to the appropriate position
    for (int offset = 0; text[offset]; ++offset)  // Iterate through each character in the text
        *video_mem++ = color | text[offset];  // Write the character and color to video memory
}

#endif // OUTP_H
