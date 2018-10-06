#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

////////////////////////////////////////////////////////////////////////////////
const int displayX = 800, displayY = 600;
struct Ball 
{
    double x;
    double y;
    double radius;
    double speedx;
    double speedy;
    ALLEGRO_COLOR color;
};

void drawBall(Ball b) { al_draw_filled_circle(b.x,b.y,b.radius,b.color); }
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
 
    ALLEGRO_DISPLAY *display = NULL;
    if(!al_init()) {fprintf(stderr, "failed to initialize allegro!\n");return -1;}
    if (!al_init_primitives_addon()) {fprintf(stderr, "failed to initialize primitives!\n");return -1;}
    if (!al_install_keyboard()) {fprintf(stderr, "failed to initialize the keyboard!\n");return -1;}
    display = al_create_display(displayX, displayY);
    if(!display){fprintf(stderr, "failed to create display!\n");return -1;}
 
    ALLEGRO_KEYBOARD_STATE key_state;
 
    Ball Ball1={100,100,30,1,1,al_map_rgb(255,0,0)};
    Ball Ball2={200,200,35,2,2,al_map_rgb(0,255,0)};
    Ball Ball3={200,200,40,3,3,al_map_rgb(0,0,255)};
    ////////////////////////////////////////////////////////////////////////////////   
    while(true) 
    {
        al_get_keyboard_state(&key_state);
        if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE)) {break;}
        else if(al_key_down(&key_state,ALLEGRO_KEY_W))     {Ball1.y=Ball1.y-1;}
        else if(al_key_down(&key_state,ALLEGRO_KEY_S))     {Ball1.y=Ball1.y+1;}
        else if(al_key_down(&key_state,ALLEGRO_KEY_A))     {Ball1.x=Ball1.x-1;}
        else if(al_key_down(&key_state,ALLEGRO_KEY_D))     {Ball1.x=Ball1.x+1;}
        else if(al_key_down(&key_state,ALLEGRO_KEY_UP))    {Ball1.radius=Ball1.radius+1;}
        else if(al_key_down(&key_state,ALLEGRO_KEY_DOWN))  {Ball1.radius=Ball1.radius-1;}

        al_clear_to_color(al_map_rgb(255,255,255));
        ////////////////////////////////////////////////////////////////////////////////
        double mm=sqrt((Ball1.x-Ball3.x)*(Ball1.x-Ball3.x)+(Ball1.y-Ball3.y)*(Ball1.y-Ball3.y));
        if (mm <= Ball1.radius+Ball3.radius) {Ball1.speedx=Ball1.speedx*-1;}
        ////////////////
        drawBall(Ball1); 
        ////////////////
        drawBall(Ball2);               
        if(Ball2.x>=800-Ball2.radius){Ball2.speedx=Ball2.speedx*-1;}          
        if(Ball2.x<=100-Ball2.radius){Ball2.speedx=Ball2.speedx*-1;} 
        if(Ball2.y>=600-Ball2.radius){Ball2.speedy=Ball2.speedy*-1;}             
        if(Ball2.y<=100-Ball2.radius){Ball2.speedy=Ball2.speedy*-1;} 
        Ball2.y=Ball2.y+Ball2.speedy;
        Ball2.x=Ball2.x+Ball2.speedx;   
        ////////////////
        drawBall(Ball3);          
        if(Ball3.x>=800-Ball3.radius){Ball3.speedx=Ball3.speedx*-1;}          
        if(Ball3.x<=100-Ball3.radius){Ball3.speedx=Ball3.speedx*-1;} 
        if(Ball3.y>=600-Ball3.radius){Ball3.speedy=Ball3.speedy*-1;}             
        if(Ball3.y<=100-Ball3.radius){Ball3.speedy=Ball3.speedy*-1;}        
        Ball3.y=Ball3.y+Ball3.speedy;
        Ball3.x=Ball3.x+Ball3.speedx;               
        al_flip_display();      
        al_rest(0.005);
    }
    ////////////////////////////////////////////////////////////////////////////////
    al_destroy_display(display);
    return 0;
}
