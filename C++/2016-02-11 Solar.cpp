#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <cmath>

const double FPS=60.0;
const int displayX = 800, displayY = 600;
const int centerX=displayX/2,centerY=displayY/2;
////////////////////////////////////////////////
struct Planet
{
    double radius;
    double distance; 
    double angle;
    double aSpeed;
    ALLEGRO_COLOR color;
};
////////////////////////////////////////////////
void drawPlanet(Planet planet) 
{
    double angleRads = planet.angle * 3.14 / 180;
    double x = centerX + cos(angleRads) * planet.distance;
    double y = centerY - sin(angleRads) * planet.distance;
    al_draw_filled_circle(x, y, planet.radius, planet.color);
}

void movePlanet(Planet& planet) 
{
    planet.angle = planet.angle + planet.aSpeed;
    if (planet.angle >= 360) {
    planet.angle = planet.angle - 360;
}
}

struct Star{
int x;
int y;
};

void fillStars(Star stars[],int starN)
{
    for(int i=0;i<starN;i++)
    {
        stars[i].x=rand()%displayX;
        stars[i].y=rand()%displayY;
    }
}
//drawStars()

////////////////////////////////////////////////
int main(int argc, char **argv)
{
    ALLEGRO_DISPLAY *display = NULL;
    if (!al_init())                 {fprintf(stderr, "failed to initialize allegro!\n");return -1;}
    if (!al_init_primitives_addon()){fprintf(stderr, "failed to initialize primitives!\n");return -1;}
    if (!al_install_keyboard())     {fprintf(stderr, "failed to initialize the keyboard!\n");return -1;}
    display = al_create_display(displayX, displayY);
    if(!display)                    {fprintf(stderr, "failed to create display!\n");return -1;}
    ALLEGRO_KEYBOARD_STATE key_state;
    ////////////////////////////////////////////////
    Planet sun=   {100,0,  0,  0,   al_map_rgb(255,0,0)};
    Planet earth= {30, 300,0,  0.3, al_map_rgb(153,203,255)};
    Planet mars=  {25, 200,100,0.5, al_map_rgb(0,255,0)};
    int starN=500;
    Star stars[starN];
    srand(time(NULL));
    fillStars(stars,starN);
    ////////////////////////////////////////////////
    while(true)
    {
        al_get_keyboard_state(&key_state);
        if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE)) 
        {
            break;
        }
        al_clear_to_color(al_map_rgb(0,0,0));
        drawPlanet(sun);
        drawPlanet(earth);
        drawPlanet(mars);
        movePlanet(earth);
        movePlanet(mars);
        al_flip_display();
        al_rest(0.05);
    }
    ////////////////////////////////////////////////
    al_destroy_display(display);
    return 0;
}

