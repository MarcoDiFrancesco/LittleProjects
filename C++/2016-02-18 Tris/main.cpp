#include <allegro5/allegro_primitives.h>
#include <allegro5/altime.h>
#include <allegro5/color.h>
#include <allegro5/display.h>
#include <allegro5/drawing.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <allegro5/mouse.h>
#include <allegro5/system.h>
#include <iostream>

using namespace std;
const int CELLS=3;
const int SCREEN_SIZE = 600;
const int EMPTY_CELL='a';
const int PLAYER_X='b';
const int PLAYER_Y='c';
const float CELL_SIZE = SCREEN_SIZE / CELLS;
const float THICKNESS = SCREEN_SIZE / 100;void drawBoard(ALLEGRO_COLOR color);
void drawX(double x, double y, double size, ALLEGRO_COLOR color);
void drawO(double x, double y, double size, ALLEGRO_COLOR color);
void drawBoard(ALLEGRO_COLOR color);
void reset(char board[CELLS][CELLS]);
void play(char board[CELLS][CELLS],double x,double y,char player);
////////////////////////////////////////////////
int main() 
{
    if (!al_init())                 {fprintf(stderr, "failed to initialize allegro!\n");     return -1;}
    if (!al_init_primitives_addon()){fprintf(stderr, "failed to initialize primitives!\n");  return -1;}
    if (!al_install_keyboard())     {fprintf(stderr, "failed to initialize the keyboard!\n");return -1;}
    ALLEGRO_DISPLAY *display = NULL;
    if (!al_install_mouse())        {fprintf(stderr, "failed to initialize the mouse!\n");   return -1;}
    display = al_create_display(SCREEN_SIZE, SCREEN_SIZE);
    ////////////////////////////////////////////////
    if (!display) {fprintf(stderr, "failed to create display!\n");return -1;}
    ALLEGRO_COLOR bgColor = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR fgColor = al_map_rgb(0, 0, 0);
    ALLEGRO_KEYBOARD_STATE key_state;
    ALLEGRO_MOUSE_STATE mouse_state;
    char board[CELLS][CELLS];
    ////////////////////////////////////////////////
    while(true) 
    {
        al_clear_to_color(bgColor);
        al_get_mouse_state(&mouse_state);
        if (al_mouse_button_down(&mouse_state, 1)) 
        {cout << mouse_state.x << " " << mouse_state.y << endl;}
        al_get_keyboard_state(&key_state);
        if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE)) 
        {break;}
        drawBoard(fgColor);
        al_flip_display();
        al_rest(0.1);
    }
        
    al_destroy_display(display);
    return 0;
}
////////////////////////////////////////////////
void drawX(double x, double y, double size, ALLEGRO_COLOR color) 
{
    float thickness=size/30;
    float oneTenth=size/10;
    al_draw_line(x+oneTenth,y+oneTenth,x+size-oneTenth,y+size-oneTenth,color,thickness);
}
////////////////////////////////////////////////
void drawO(double x, double y, double size, ALLEGRO_COLOR color) 
{
    float thickness=size/30;
    float oneTenth=size/10;
    al_draw_circle(x+size/2,y+size/2,size/2-oneTenth,color,thickness);
}
////////////////////////////////////////////////
void drawBoard(ALLEGRO_COLOR color) 
{
    for(int t=1;t<CELLS;t++)
    {
        al_draw_line(CELL_SIZE*t,0,CELL_SIZE*t,SCREEN_SIZE,color,THICKNESS);
        al_draw_line(0,CELL_SIZE*t,SCREEN_SIZE,CELL_SIZE*t,color,THICKNESS);
    }
}
////////////////////////////////////////////////
void reset(char board[CELLS][CELLS])
{
    for(int y=0;y<CELLS;y++)
    {
        for(int w=0;w<CELLS;w++)
        {
            board[y][w]=EMPTY_CELL;
        }
    }
}
////////////////////////////////////////////////
void drawGame(char board[CELLS][CELLS],ALLEGRO_COLOR color)
{
    for(int y=0;y<CELLS;y++)
    {
        for(int w=0;w<CELLS;w++)
        {
            if(board[y][w]=='a')
            {
                reset();
            }
            else if(board[y][w]=='b')
            {
                drawX(CELL_SIZE*y,CELL_SIZE*w,CELL_SIZE,color);
            }
            else if(board[y][w]=='c')
            {
                drawY();
            }
        }
    }
}
////////////////////////////////////////////////
void play(char board[CELLS][CELLS],double x,double y,char player)
{
    
}
