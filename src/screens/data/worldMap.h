#pragma once
#include "../../display.h"

class WorldMap {
    private:
        LGFX_Sprite mapSprite;
        
        // Zmień te wartości na rzeczywiste wymiary twojego pliku mapy (np. 800x800)
        int map_width = 800; 
        int map_height = 800; 
        
        int camera_x;
        int camera_y;
        const int step = 20; // Szybkość przesuwania
        
        bool move_x_axis = false; // Flaga: false = góra/dół, true = lewo/prawo

    public:
        WorldMap(); 
        void load_worldMap_sprites();
        void drawScreen();
        void up();
        void down();
        void select();
};

