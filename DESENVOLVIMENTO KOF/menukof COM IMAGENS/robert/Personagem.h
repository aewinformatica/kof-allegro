#pragma once
#include <allegro.h>
#include <fstream>
#include <string>

using namespace std;
class Personagem
{             

      public:

             Personagem();
             ~Personagem();
             string nome;
             string estado;
             int dir;
             BITMAP *ANIM[10];
             int x,y;
             bool pulou;
             int forca;
             
             
            string pega_nome(ifstream *file);
            void Carrega(string nome_arquivo);
            void Desenha(BITMAP *Destino,int i);
            void Pulo();
            
      
};
