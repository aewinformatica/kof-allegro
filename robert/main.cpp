#include <allegro.h>
#include <alpng.h>
#include <algif.h>
#include <alfont.h>
#include <aldumb.h>
#include <string>
#include "Personagem.h"
using namespace std;

int volatile velocidade = 0;

void controla_velocidade();
int main(int argc, char *argv[])
{
	// Inicializa a biblioteca Allegro
	allegro_init();
	alpng_init();
	algif_init ();
	alfont_init();

	// Inicializa o manipulador de teclado
	install_keyboard();
	install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL);

	// Define a profundidade de cores para 16 bits (high color)
	set_color_depth(32);
	set_alpha_blender();

	// Define a resolução de 640x480 no modo automatico
	// set_gfx_mode(GFX_AUTODETECT, 800, 600, 0, 0);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);

	set_volume_per_voice(0);

	ALFONT_FONT *user_font;
	user_font = alfont_load_font("c:/windows/fonts/ALGER.TTF");
	alfont_set_font_size(user_font, 40);


	DUH *duh;          /* Encapsulates the music file. */
	AL_DUH_PLAYER *dp; /* Holds the current playback state. */


	BITMAP *Buffer = NULL;
	Buffer = create_bitmap(SCREEN_W, SCREEN_H);
	BITMAP *BG = NULL;
	BG = load_bitmap("logo.png", NULL);
	BITMAP *CENARIO = NULL;
	CENARIO = load_bitmap("cenario/back.png", NULL);

	Personagem jogador[10];
	jogador[0].Carrega("Robert");
	jogador[0].x = 150;
	jogador[0].y =  236;


	jogador[1].Carrega("Robert");
	jogador[1].x = 250;
	jogador[1].y =  236;


	int pos = 0;

	LOCK_VARIABLE(velocidade);
	LOCK_FUNCTION(controla_velocidade);

	install_int_ex(controla_velocidade, BPS_TO_TIMER(7));

	// Fica em loop até pressionar a tecla ESC
	while(!key[KEY_ESC])
	{
		blit(BG, Buffer, 0, 0, 0, 0, 800, 600);
		blit(CENARIO, Buffer, 0, 0, 30, 200, 800, 600);
		rect(Buffer, 33, 156, 392, 362, makecol(0, 0, 0));

		while(velocidade > 0)
		{
			if(pos >= 0)
			{
				pos++;
			}
			if(pos >= 8)
			{
				pos = 0;
			}
			velocidade--;
		}
		if(key[KEY_RIGHT])
		{
			jogador[1].dir = 0;
			jogador[1].x += 10;
		}
		if(key[KEY_LEFT])
		{
			jogador[1].dir = 1;
			jogador[1].x -= 10;
		}

		if(key[KEY_D])
		{
			jogador[0].dir = 0;
			jogador[0].x += 10;
		}
		if(key[KEY_A])
		{
			jogador[0].dir = 1;
			jogador[0].x -= 10;
		}

		for(int i = 0; i < 2; i++)
		{
//if(key[KEY_H]&& jogador[i])
			{

			}
		}
		jogador[0].Desenha(Buffer, pos);
		jogador[1].Desenha(Buffer, pos);
		 // alfont_textout_centre_aa_ex(Buffer,user_font , "ANIMACAO", SCREEN_W / 2, SCREEN_H/2-180, makecol(255, 255, 255),-1);
		blit(Buffer, screen, 0, 0, 0, 0, 800, 600);
	}

	// Sai do programa
	allegro_exit();

	return 0;
}
// Esta macro converte o main para WinMain()
END_OF_MAIN();
void controla_velocidade()
{
	velocidade ++;
}
END_OF_FUNCTION();
