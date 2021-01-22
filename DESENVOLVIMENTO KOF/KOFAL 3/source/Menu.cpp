#include "Menu.h"

Menu::Menu()
{
         carregar(); 
         pos = 0;
         escolha = 0;
}
Menu::~Menu()
{
             
}
void Menu::carregar()
{
        BG = load_bitmap("imagens/Menu/fundo.png",NULL);
       
        BG2 = load_bitmap("imagens/Menu/fundo2.png",NULL);

        LOGO = load_bitmap("imagens/Menu/logo.png",NULL);

        ARCADE = load_bitmap("imagens/Menu/arcade.png",NULL);
        
        VERSUS = load_bitmap("imagens/Menu/versus.png",NULL);
        
        CPU = load_bitmap("imagens/Menu/CPU.png",NULL);

        TRANNING = load_bitmap("imagens/Menu/TRANNING.png",NULL);

        CONFIG = load_bitmap("imagens/Menu/conf.png",NULL);
        
        DESSEL = load_bitmap("imagens/Menu/dessel.png",NULL);

        SEL = load_bitmap("imagens/Menu/sel.png",NULL);
        
        //sons
        SAMPSEL = load_sample("sons/menu-select.wav");
        SAMPOK = load_sample("sons/menu-ok.wav");
     
 }
void Menu::Desenhar(BITMAP *Buffer){


blit(BG,Buffer,0,0,0,20,800,600);
blit(BG2,Buffer,0,456,0,0,800,600);
draw_trans_sprite(Buffer,LOGO,30,0);

draw_trans_sprite(Buffer,ARCADE,60,60);
draw_trans_sprite(Buffer,VERSUS,60,55*2);
draw_trans_sprite(Buffer,CPU,60,50*3);
draw_trans_sprite(Buffer,TRANNING,60,50*4);
draw_trans_sprite(Buffer,CONFIG,60,51*5);


draw_trans_sprite(Buffer,DESSEL,40,55);
draw_trans_sprite(Buffer,DESSEL,50,52*2);
draw_trans_sprite(Buffer,DESSEL,50,49*3);
draw_trans_sprite(Buffer,DESSEL,50,49*4);
draw_trans_sprite(Buffer,DESSEL,50,50*5);

blit(BG2,Buffer,0,406,0,390,800,600);

Atualizar(Buffer);
 }
void Menu::Atualizar(BITMAP *Buffer){
     
     if(key[KEY_S]||key[KEY_DOWN]){
play_sample(SAMPSEL,100,100,1000,FALSE);
if((pos >= 0)&& (pos <4)){
pos++;

}
else{
     pos = 0; 
}
}
if(key[KEY_W]||key[KEY_UP]){
play_sample(SAMPSEL,100,10,1000,FALSE);

if((pos >= 0)&& (pos <5)){

pos--;
if(pos <0){
       pos = 4;
}

}

}
if(key[KEY_ENTER] ){
 play_sample(SAMPOK,100,10,1000,FALSE);
 if( pos==0){
	 escolha = 1;
 }                 
}
if(pos == 0)
{
 draw_trans_sprite(Buffer,SEL,40,55);
       
}
else if(pos == 1)
{
    draw_trans_sprite(Buffer,SEL,50,52*2);
 }
 else if(pos == 2)
{
    draw_trans_sprite(Buffer,SEL,50,48*3);
 }
else if(pos == 3)
{
    draw_trans_sprite(Buffer,SEL,50,48*4);
 }
 else if(pos == 4)
{
    draw_trans_sprite(Buffer,SEL,50,50*5);
 }

 }
