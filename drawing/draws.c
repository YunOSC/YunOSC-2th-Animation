#include "draws.h"

char drop_line[DL_BUFLEN];
int serial[M_WIDTH];
char text[M_HEIGHT][M_WIDTH];

int draw_drop_down(caca_canvas_t* cv, int w,int h, color_pattern* patterns, int plen){

    for(int i = 0;i < w;i++){
        for(int j = 0;j < h;j++){
            int sel = (serial[i] - j + DL_BUFLEN) % DL_BUFLEN;
            char ch = drop_line[sel];
            if(ch != ' '){
                set_color_from_set(cv,ch,patterns,plen);
                caca_put_char(cv,i,j,text[j][i]); 
            }else{
                caca_put_char(cv,i,j,' ');
            }
        }
    }
    return 1;
}

void set_color_from_set(caca_canvas_t* cv,char ch,color_pattern* p,int plen){
    for(int i = 0;i < plen;i++)
        if(p[i].ch == ch)
            caca_set_color_ansi(cv,p[i].fcolor, p[i].bcolor);
}

int draw_hat(caca_canvas_t* cv,int w,int h,int y){
    caca_set_color_ansi(cv,CACA_LIGHTBLUE,CACA_TRANSPARENT);
    for(int i = 0, j = y;i < aa_hat_len;i++,j++)
        for(int k = 0, len = strlen(aa_hat[i]); k < len;k++)
            if(aa_hat[i][k] != '~')
                caca_put_char(cv,w/2-len/2+k,j,aa_hat[i][k]);
    return 1;
}

int draw_title(caca_canvas_t* cv,int w,int h,int y){
    caca_set_color_ansi(cv,CACA_LIGHTMAGENTA ,CACA_TRANSPARENT);
    for(int i = 0, j = h - y - aa_title_len; i < aa_title_len;i++,j++)
        for(int k = 0, len = strlen(aa_title[i]); k < len;k++)
            if(aa_title[i][k] != '~')
                caca_put_char(cv,w/2-len/2+k,j,aa_title[i][k]);
    return 1;
}
