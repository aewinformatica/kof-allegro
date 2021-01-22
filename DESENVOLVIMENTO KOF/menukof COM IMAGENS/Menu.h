#pragma once 
#include <allegro.h>
#include <alpng.h>
//#include <algif.h>
#include <alfont.h>
//#include <aldumb.h>
#include <string>

using namespace std;

class Menu
{
      public:
             Menu();
            ~Menu();
             void carregar();
             void Desenhar(BITMAP *Buffer);
             void Atualizar(BITMAP *Buffer);
             BITMAP *BG;
             BITMAP *BG2;
             BITMAP *LOGO;
             BITMAP *ARCADE;
             BITMAP *VERSUS;
             BITMAP *CPU;
             BITMAP *TRANNING;
             BITMAP *CONFIG;
             BITMAP *DESSEL;
             BITMAP *SEL;
             int pos;
             
             SAMPLE *SAMPSEL;
             SAMPLE *SAMPOK;
};
