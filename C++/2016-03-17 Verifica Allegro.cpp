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

const int SCREEN_SIZE = 600;
const int CELLS = 3;
const float CELL_SIZE = ((double)SCREEN_SIZE) / ((double)CELLS);
const float THICKNESS = ((double)SCREEN_SIZE) / ((double)100);
void drawBoard(ALLEGRO_COLOR color);

void drawX(double x, double y, double size, ALLEGRO_COLOR bgColor);
void drawO(double x, double y, double size, ALLEGRO_COLOR color);

struct punto
{
  double x;
  double y;
};

void stampapunto(punto punti[], int n)
{
  for (int i = 0; i < n; i++)
  {
    al_draw_filled_circle(punti[i].x, punti[i].y, 5, al_map_rgb(0, 0, 0));
  }
}

///////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ALLEGRO_DISPLAY *display = NULL;
  if (!al_init())
  {
    fprintf(stderr, "failed to initialize allegro!\n");
    return -1;
  }
  if (!al_init_primitives_addon())
  {
    fprintf(stderr, "failed to initialize primitives!\n");
    return -1;
  }
  if (!al_install_keyboard())
  {
    fprintf(stderr, "failed to initialize the keyboard!\n");
    return -1;
  }
  if (!al_install_mouse())
  {
    fprintf(stderr, "failed to initialize the mouse!\n");
    return -1;
  }
  display = al_create_display(SCREEN_SIZE, SCREEN_SIZE);
  if (!display)
  {
    fprintf(stderr, "failed to create display!\n");
    return -1;
  }
  ALLEGRO_COLOR bgColor = al_map_rgb(255, 255, 255);
  ALLEGRO_COLOR fgColor = al_map_rgb(0, 0, 0);
  ALLEGRO_KEYBOARD_STATE key_state;
  ALLEGRO_MOUSE_STATE mouse_state;
  ///////////////////////////////////////////////////////////////////////
  punto punti[10];
  int n = 0;
  while (n < 11)
  {
    al_clear_to_color(bgColor);
    // leggo lo stato del mouse
    al_get_mouse_state(&mouse_state);
    if (al_mouse_button_down(&mouse_state, 1))
    {
      cout << mouse_state.x << " " << mouse_state.y << endl;
      punti[n].x = mouse_state.x;
      punti[n].y = mouse_state.y;

      /*
      if(n==9)
      {
        for(int w=0;w<9;w++)
        {
          al_draw_line(punti[w].x, punti[w].y, punti[w+1].x, punti[w+1].y, 2, al_map_rgb(0,0,0)); //COMUNQUE FUNZIONAVA
        }
      }
*/
      if (n < 10)
      {
        n++;
      }
      else
      {
        n = 0;
      }
    }
    // leggo lo stato della tastiera
    al_get_keyboard_state(&key_state);
    if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
    {
      break;
    }
    stampapunto(punti, n);

    al_flip_display();
    al_rest(0.1);
  }

  al_destroy_display(display);
  return 0;
}
