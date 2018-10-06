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

const int SCREEN_X = 800, SCREEN_Y = 600;

struct Rettangolo 
{
    double x, y, width, height;
    ALLEGRO_COLOR color;
    bool selected;
};



void drawRectangle(Rettangolo r) 
{
    al_draw_filled_rectangle(r.x, r.y, r.x + r.width, r.y + r.height, r.color);
    if (r.selected) 
    {
        al_draw_rectangle(r.x, r.y, r.x + r.width, r.y + r.height, al_map_rgb(0, 0, 0), 3);
    }
}
 
void drawRectangles(Rettangolo rs[], int n) 
{
    for(int i = 0; i < n; i++) 
    {
        drawRectangle(rs[i]);
    }
}
 
bool clicked(Rettangolo r, double x, double y) 
{
    return x >= r.x && x <= (r.x + r.width) && y >= r.y && y <= (r.y + r.height);
}
 
void setSelected(Rettangolo rs[], int n, double x, double y) 
{
    for(int i = 0; i < n; i++) 
    {
      rs[i].selected = clicked(rs[i], x, y);
    }
}
 
void moveRectangles(Rettangolo rs[], int n, double x, double y) 
{
    for(int i = 0; i < n; i++) 
    {
    if (rs[i].selected) 
        {
            rs[i].x += x;
            rs[i].y += y;
        }
    }
}

void restoreStatus(Rettangolo rs[],int n)
    
{
}

void saveStatus(Rettangolo rs[],int n)
{
unsigned char r,g,b;
ofstreeam of;
of.open("status.txt");
for(int i=0;i<n;i++)
{
al_unmap_rgb(rs[i],color,&r,&g,&b);
of<<rs[i].x <<" ";
of<<rs[i].y <<" ";
of<<rs[i].width <<" ";
of<<rs[i].height <<" ";
of<<(int)r<<" ";
of<<(int)g<<" ";
of<<(int)b<<" ";
of<<rs[i].selected<<endl;
}
of.close();
}

int main(int argc, char**argv) {
    ALLEGRO_DISPLAY *display = NULL;
 
    if (!al_init()) {fprintf(stderr, "failed to initialize allegro!\n");return -1;}
    if (!al_init_primitives_addon()) {fprintf(stderr, "failed to initialize primitives!\n");return -1;}
    if (!al_install_keyboard()) {fprintf(stderr, "failed to initialize the keyboard!\n");return -1;}
    if (!al_install_mouse()) {
    fprintf(stderr, "failed to initialize the mouse!\n");
    return -1;}
 
    display = al_create_display(SCREEN_X, SCREEN_Y);
    if (!display) 
    {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }
    ALLEGRO_COLOR bgColor = al_map_rgb(255, 255, 255);
    ALLEGRO_KEYBOARD_STATE key_state;
    ALLEGRO_MOUSE_STATE mouse_state;
    const int N = 5;
    Rettangolo rectangles[N] = 
    {
        { 0, 0, 50, 50, al_map_rgb(10, 200, 30), false },
        { 100, 100, 50, 50, al_map_rgb(20, 10, 230), false },
        { 200, 200, 50, 50, al_map_rgb(30, 50, 130), false },
        { 300, 300, 50, 50, al_map_rgb(70, 20, 30), false },
        { 400, 400, 50, 50, al_map_rgb(50, 200, 230), false }
    };

    while (true) 
    {
        al_clear_to_color(bgColor);
        al_get_mouse_state(&mouse_state);
        if (al_mouse_button_down(&mouse_state, 1)) {setSelected(rectangles, N, mouse_state.x, mouse_state.y);cout << mouse_state.x << " " << mouse_state.y << endl;}
        al_get_keyboard_state(&key_state);
        if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE)) {break;}
        if (al_key_down(&key_state, ALLEGRO_KEY_UP)) {moveRectangles(rectangles, N, 0, -1);}
        if (al_key_down(&key_state, ALLEGRO_KEY_DOWN)) {moveRectangles(rectangles, N, 0, 1);}
        if (al_key_down(&key_state, ALLEGRO_KEY_LEFT)) {moveRectangles(rectangles, N, -1, 0);}
        if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT)) {moveRectangles(rectangles, N, 1, 0);}
        drawRectangles(rectangles, N);
        al_flip_display();
        al_rest(0.01);
    }

  al_destroy_display(display);
  return 0;
}
