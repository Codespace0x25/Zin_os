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
inline void putText(const char* text)
{
  static uint16_t* VideoMem =(uint16_t*)0x0b8000;
  
  static uint8_t x=0 , y=0;
  
  for(int i = 0; text[i] != '\0'; ++i)
  {
  
  switch(text[i])
  {
    case '\n':
      y++;
      x=0;
      break;
    default:
      VideoMem[80*y+x] = (VideoMem[80*y+x] & 0xFF00) | text[i];
      x++;
  }
    
    if(x >= 80)
    {
      y++;
      x=0;
      }
      if(y >= 25)
      {
        for(y=0; y<25;y++)
          for(x=0;0<80;x++)
            VideoMem[80*y+x] = (VideoMem[80*y+x] & 0xFF00)|' ';
        x=0;
        y=0;
      }
  }
}

#endif // OUTP_H
