#include <allegro.h>
#include <alpng.h>
#include <algif.h>
#include <alfont.h>
#include <aldumb.h>
#include <string>
#include "Menu.h"
#include "VsMenu.h"

using namespace std;

int volatile velocidade = 0;
SAMPLE *SAMPBG = NULL;
BITMAP *Buffer = NULL;

void controla_velocidade();
void init_core();

int main(int argc, char *argv[])
{

	init_core();
	Menu Menu_Principal;
	VsMenu selecionar;

	int pos = 0;

	LOCK_VARIABLE(velocidade);
	LOCK_FUNCTION(controla_velocidade);

	install_int_ex(controla_velocidade, BPS_TO_TIMER(15));

	play_sample(SAMPBG, 100, 10, 1000, TRUE);



	// Fica em loop até pressionar a tecla ESC
	while(!key[KEY_ESC])
	{

		while(velocidade > 0)
		{

			// Menu_Principal.Desenhar(Buffer);
			// Menu_Principal.Atualizar(Buffer);

			selecionar.Desenhar(Buffer);
			selecionar.Atualizar(Buffer);

			velocidade--;
		}

		blit(Buffer, screen, 0, 0, 0, 0, 800, 660);

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

void init_core()
{
	// Inicializa a biblioteca Allegro
	allegro_init();
	alpng_init();
	algif_init ();
	alfont_init();

	install_keyboard();
	install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL);

	set_color_depth(32);
	set_alpha_blender();

	// Define a resolução de 640x480 no modo automatico
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

	set_volume_per_voice(0);

	ALFONT_FONT *user_font;
	user_font = alfont_load_font("c:/windows/fonts/ALGER.TTF");
	alfont_set_font_size(user_font, 40);


	DUH *duh;          /* Encapsulates the music file. */
	AL_DUH_PLAYER *dp; /* Holds the current playback state.3*/


	Buffer = create_bitmap(SCREEN_W, SCREEN_H);


	
	SAMPBG = load_sample("sons/bg.wav");
}
