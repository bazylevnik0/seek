#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv)
{
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "seek", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );
    // Toggle to fullscreen
    SDL_SetWindowFullscreen(window, 1);

    // Setup renderer
    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red ( background will be rendered in this color )
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );

    // Clear winow
    SDL_RenderClear( renderer );

    // Read file
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("temp.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    //read first string with url
    read = getline(&line, &len, fp);
    char url[100];
    strcpy(url,line);
   
    //read second string with file length
    read = getline(&line, &len, fp);
    int counter_a =  atoi(line);
    int counter_b = 1;
    //read color and draw
    while ((read = getline(&line, &len, fp)) != -1) {
        // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
        SDL_Rect r;
        r.x = 0;
        r.y = (int)(480/counter_a)*counter_b - (int)(480/counter_a);
        r.w = 640;
        r.h = 5;
        r.h = (int)(480/counter_a);

        
        // Set render colors 
        if (strcmp(line, "crimson\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 220, 20, 60, 255 );
        }
        else if (strcmp(line, "orange\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 255, 165, 0, 255 );
        }
        else if (strcmp(line, "olive\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 128, 128, 0, 255 );
        }
        else if (strcmp(line, "yellow\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 255, 255, 0, 255 );
        }
        else if (strcmp(line, "lawn greeen\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 124, 252, 0, 255 );
        }
        else if (strcmp(line, "medium spring green\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 0, 250, 154, 255 );
        }
        else if (strcmp(line, "light green\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 144, 238, 144, 255 );
        }
        else if (strcmp(line, "aqua\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 0, 255, 255, 255 );
        }
        else if (strcmp(line, "aqua marine\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 127, 255, 212, 255 );
        }
        else if (strcmp(line, "dodger blue\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 30, 144, 255, 255 );
        }
        else if (strcmp(line, "midnight blue\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 25, 25, 112, 255 );
        }
        else if (strcmp(line, "blue violet\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 138, 43, 226, 255 );
        }
        else if (strcmp(line, "dark violet\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 148, 0, 211, 255 );
        }
        else if (strcmp(line, "violet\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 238, 130, 238, 255 );
        }
        else if (strcmp(line, "hot pink\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 255, 105, 180, 255 );
        }
        else if (strcmp(line, "bisque\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 255, 228, 196, 255 );
        }
        else if (strcmp(line, "saddle brown\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 139, 69, 19, 255 );
        }
        else if (strcmp(line, "sandy brown\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 244, 164, 96, 255 );
        }
        else if (strcmp(line, "misty rose\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 255, 228, 225, 255 );
        }
        else if (strcmp(line, "mint cream\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 245, 255, 250, 255 );
        }
        else if (strcmp(line, "lavender\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 230, 230, 250, 255 );
        }
        else if (strcmp(line, "floral white\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 255, 250, 240, 255 );
        }
        else if (strcmp(line, "gray\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 128, 128, 128, 255 );
        }
        else if (strcmp(line, "gainsboro\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 220, 220, 220, 255 );
        }
        else if (strcmp(line, "white smoke\n") == 0)
        {
            SDL_SetRenderDrawColor( renderer, 245, 245, 245, 255 );
        }
        else
        {
            SDL_SetRenderDrawColor( renderer, 100, 0, 0, 255 );
        }
        
        // Render rect
        SDL_RenderFillRect( renderer, &r );

        counter_b++;
    }

    //close file and clear line
    fclose(fp);
    if (line)
        free(line);
    
   
   //make screenshot
   // Create an empty RGB surface that will be used to create the screenshot bmp file
   SDL_Surface* pScreenShot = SDL_CreateRGBSurface(0, 640, 480, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

   if(pScreenShot)
   {
      // Read the pixels from the current render target and save them onto the surface
      SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, pScreenShot->pixels, pScreenShot->pitch);
      // Create the bmp screenshot file
      char temp[100] = "";
      strcat(temp,"output/");
      strcat(temp,"(");
      url[strlen(url)-1]='\0';
      strcat(temp,url);
      strcat(temp,")");
      strcat(temp,".bmp");
      SDL_SaveBMP(pScreenShot, temp);
      // Destroy the screenshot surface
      SDL_FreeSurface(pScreenShot);
   }

    // Render the rect to the screen
    SDL_RenderPresent(renderer);


    // Wait for 1 sec
    SDL_Delay( 100 );

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
