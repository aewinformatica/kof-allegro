#include "Personagem.h"

Personagem::Personagem()
{
                        
                        estado = "parado";
                        dir = 0;
                        forca = 0;
                        pulou = false;
                        
}

Personagem::~Personagem()
{
}                        
void Personagem::Carrega(string nome_arquivo)
{
     
           nome = nome_arquivo;
           
           string arquivo;
           
           arquivo  = nome;
           arquivo +="/idle/";
           arquivo +="stand01";
           
           arquivo += ".png";
     
     
         ANIM[0]  = load_bitmap(arquivo.c_str(),NULL);
         ANIM[1]  = load_bitmap("robert/idle/stand02.png",NULL);
         ANIM[2]  = load_bitmap("robert/idle/stand03.png",NULL);
         ANIM[3]  = load_bitmap("robert/idle/stand04.png",NULL);
         ANIM[4]  = load_bitmap("robert/idle/stand05.png",NULL);
         ANIM[5]  = load_bitmap("robert/idle/stand06.png",NULL);
         ANIM[6]  = load_bitmap("robert/idle/stand07.png",NULL);
         ANIM[7]  = load_bitmap("robert/idle/stand08.png",NULL);
         ANIM[8]  = load_bitmap("robert/idle/stand09.png",NULL);
         ANIM[9]  = load_bitmap("robert/idle/stand10.png",NULL);
                  
     
 }
void Personagem::Desenha(BITMAP *Destino,int i)
{
     BITMAP *aux = NULL;
             aux = create_bitmap(70,129);     

                  
     
     if(dir ==0)
     {
    draw_trans_sprite(Destino,ANIM[i],x,y);
     }
     else
     {   draw_sprite_h_flip(aux,ANIM[i],0,0);
         draw_trans_sprite(Destino,aux,x,y);
         
         
         
     }
}
void Personagem::Pulo(){
     pulou = true;
     }
