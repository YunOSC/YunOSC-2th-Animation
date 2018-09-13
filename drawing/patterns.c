#include "patterns.h"
#include "color_pattern.h"

#define DEFAULT_BACKGROUND CACA_TRANSPARENT

color_pattern green_pattern[] = {
    { .ch='W' , .fcolor=CACA_WHITE, .bcolor=DEFAULT_BACKGROUND },
    { .ch='G' , .fcolor=CACA_LIGHTGREEN, .bcolor=DEFAULT_BACKGROUND },
    { .ch='D' , .fcolor=CACA_GREEN, .bcolor=DEFAULT_BACKGROUND },
    { .ch='B' , .fcolor=CACA_DARKGRAY, .bcolor=DEFAULT_BACKGROUND }
};

color_pattern blue_pattern[] = {
    { .ch='W' , .fcolor=CACA_WHITE, .bcolor=DEFAULT_BACKGROUND },
    { .ch='G' , .fcolor=CACA_LIGHTBLUE, .bcolor=DEFAULT_BACKGROUND },
    { .ch='D' , .fcolor=CACA_BLUE, .bcolor=DEFAULT_BACKGROUND },
    { .ch='B' , .fcolor=CACA_DARKGRAY, .bcolor=DEFAULT_BACKGROUND }
};

color_pattern red_pattern[] = {
    { .ch='W' , .fcolor=CACA_WHITE, .bcolor=DEFAULT_BACKGROUND },
    { .ch='G' , .fcolor=CACA_LIGHTRED, .bcolor=DEFAULT_BACKGROUND },
    { .ch='D' , .fcolor=CACA_RED, .bcolor=DEFAULT_BACKGROUND },
    { .ch='B' , .fcolor=CACA_DARKGRAY, .bcolor=DEFAULT_BACKGROUND }
};

color_pattern cyna_pattern[] = {
    { .ch='W' , .fcolor=CACA_WHITE, .bcolor=DEFAULT_BACKGROUND },
    { .ch='G' , .fcolor=CACA_LIGHTCYAN, .bcolor=DEFAULT_BACKGROUND },
    { .ch='D' , .fcolor=CACA_CYAN, .bcolor=DEFAULT_BACKGROUND },
    { .ch='B' , .fcolor=CACA_DARKGRAY, .bcolor=DEFAULT_BACKGROUND }
};


color_pattern* patterns[] = {
   green_pattern,
   blue_pattern,
   red_pattern,
   cyna_pattern
};

int green_pattern_len = sizeof(green_pattern)/sizeof(color_pattern);
int blue_pattern_len  = sizeof(blue_pattern)/sizeof(color_pattern);
int red_pattern_len   = sizeof(red_pattern)/sizeof(color_pattern);
int cyna_pattern_len  = sizeof(cyna_pattern)/sizeof(color_pattern);

int patterns_len[] = {
    sizeof(green_pattern)/sizeof(color_pattern),
    sizeof(blue_pattern)/sizeof(color_pattern),
    sizeof(red_pattern)/sizeof(color_pattern),
    sizeof(cyna_pattern)/sizeof(color_pattern) 
};
