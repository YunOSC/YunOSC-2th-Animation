#include <caca.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "drawing/draws.h"
#include "ascii_art/ascii_art.h"
#include "osca_parameter.h"

int init_caca();
int init_data();
void program_exit();

int draw_frame(caca_canvas_t*);

caca_display_t* dp;
caca_canvas_t* cv;
char drop_line[DL_BUFLEN];
int serial[M_WIDTH];
char text[M_HEIGHT][M_WIDTH];
int color_index = 0;
int hat_y = 3, title_y = 3;

int main(){
    init_data();
    init_caca();    

    int loop = 1;
    while(loop){
        draw_frame(cv);
        caca_refresh_display(dp);
        for(int i = 0;i < M_WIDTH;i++)
            serial[i] = (serial[i] + 1) % DL_BUFLEN;
        
        caca_event_t event;
        if(caca_get_event(dp,CACA_EVENT_KEY_PRESS, &event, FRAME_MS)){
            if(event.data.key.ch == 'c')
                color_index = (color_index + 1) % 4;
            else if(event.data.key.ch == CACA_KEY_ESCAPE)
                loop = 0;
            else if(event.data.key.ch == 'q')
                hat_y++; 
            else if(event.data.key.ch == 'a')
                hat_y--;
            else if(event.data.key.ch == 'w')
                title_y++;
            else if(event.data.key.ch == 's')
                title_y--;
        }
    }
    program_exit(0);
}

int draw_frame(caca_canvas_t* cv){
    int w = caca_get_canvas_width(cv);
    int h = caca_get_canvas_height(cv);

    int res = 1;
    res = res && draw_drop_down(cv,w,h,patterns[color_index],patterns_len[color_index]) ;
    res = res && draw_hat(cv,w,h,hat_y) ;
    res = res && draw_title(cv,w,h,title_y);
#ifdef DEBUG
    caca_put_str(cv,0,0,"Debug");
#endif
    return res;
}

int init_data(){
    srand(time(NULL));
    //spawn a DL_BUFLEN, each drop line length between 12 to 20
    //and ther is a empty space(10-20)
    int i = 0;
    for(int i = 0;i < DL_BUFLEN;i++)
        drop_line[i] = ' ';
    while(i < DL_BUFLEN){
        int totlen = (rand() % (M_HEIGHT*4-MIN_DL) + MIN_DL );  // The total length of line
        int dlen = totlen/5;                                    // The length of drop down text
        int elen = totlen - totlen/5;                           // The length of empty space
        if(dlen + elen + i > DL_BUFLEN)
            break;

        for(int j = 0,part = dlen/7;j < dlen;j++,i++)
            drop_line[i] = (j < part*1) ? 'W' :
                           (j < part*4) ? 'G' :
                           (j < part*6) ? 'D' : 'B';
        i += elen;
    }

    //init serial
    for(int i = 0;i < M_WIDTH;i++)
        serial[i] = rand() % DL_BUFLEN;
    
    for(int i = 0;i < M_HEIGHT;i++)
        for(int j = 0;j < M_WIDTH;j++)
           text[i][j] = rand() % ('z' - '0') + '0'; 

#ifdef DEBUG

    char* str = (char*)malloc(sizeof(drop_line)+sizeof(char));
    if(!str) { perror("malloc"); program_exit(2); }
    strcpy(str,drop_line);
    str[DL_BUFLEN] = '\0';
    fprintf(stderr, "Drop line format string :\n%s\n",str);
    free(str);

    for(int i = 0;i < M_WIDTH;i++)
            fprintf(stderr, "%4d, ",serial[i]);

#endif
    return 1;
}

int init_caca(){
    dp = caca_create_display(NULL);
    if(!dp) { perror("caca_create_display"); program_exit(1); };
    cv = caca_get_canvas(dp);
    
    return 1;
}

void program_exit(int ex){
#ifdef DEBUG
    fprintf(stderr,"exit %d\n",ex);
#endif
    caca_free_display(dp);
    exit(ex);
}
