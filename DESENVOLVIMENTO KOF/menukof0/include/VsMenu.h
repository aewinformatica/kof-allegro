#pragma once 
#include <allegro.h>
#include <alpng.h>
#include <algif.h>
#include <alfont.h>
#include <aldumb.h>
#include <string>

using namespace std;

class VsMenu
{
      public:
             VsMenu();
            ~VsMenu();
             void carregar();
             void Desenhar(BITMAP *Buffer);
             void Atualizar(BITMAP *Buffer);
             BITMAP *BG;
             BITMAP *BG2;
             BITMAP *LOGO;
             BITMAP *INTERROGACAO;
             BITMAP *BGINTERROGACAO;
             BITMAP *BARRABG;
             BITMAP *FACE[10];
             BITMAP *NOME[10];
             BITMAP *PREVIEW[10];
             

             BITMAP *SEL[2];
             public: int pos;
             
             SAMPLE *SAMPSEL;
             SAMPLE *SAMPOK;
};
