#ifndef OSCA_DRAWING_HEADER_GUARD
#define OSCA_DRAWING_HEADER_GUARD

#include <caca.h>
#include <string.h>
#include "../osca_parameter.h"
#include "../ascii_art/ascii_art.h"
#include "patterns.h"
#include "color_pattern.h"

extern char drop_line[];
extern int serialp[];
extern char* textp[];


int draw_drop_down(caca_canvas_t* cv, int,int,color_pattern*,int);
int draw_hat(caca_canvas_t* cv, int,int,int);
int draw_title(caca_canvas_t* cv, int,int,int);
void set_color_from_set(caca_canvas_t*,char,color_pattern*,int);

#endif
