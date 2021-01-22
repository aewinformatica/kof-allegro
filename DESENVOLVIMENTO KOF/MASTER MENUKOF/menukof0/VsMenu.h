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
             BITMAP *FACE[7];
             BITMAP *NOME[9];
             BITMAP *PREVIEW[9];
             

             BITMAP *SEL[2];
             int pos;
             
             SAMPLE *SAMPSEL;
             SAMPLE *SAMPOK;
};
