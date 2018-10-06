#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(int argc, char **argv){
 
   ALLEGRO_DISPLAY *display = NULL;
 
   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
      if(!al_init_primitives_addon()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   } 
   display = al_create_display(700,700);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }
 
   ALLEGRO_COLOR color1= al_map_rgb(255,0,0);
   ALLEGRO_COLOR color2= al_map_rgb(0,0,255); 
   
 
   int i,giri,t;
   t=t+100;
    for(giri=0;giri<2;giri++)
    {
        for(i=100;i<600;i=i+1)
        {
            al_draw_filled_circle(i,t,50,color2);
            al_flip_display();
            al_clear_to_color(color1);
            al_rest(0.001);
        }    
        for(i=600;i<100;i=i-100)
        {
            al_draw_filled_circle(i,t,50,color2);
            al_flip_display();
            al_clear_to_color(color1);
            al_rest(0.001); 
        } 
    } 
 
 
   al_flip_display();
 
   al_rest(0.1);
 
   al_destroy_display(display);
 
   return 0;
}
