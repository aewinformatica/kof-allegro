#include "VsMenu.h"
#include <iostream>
VsMenu::VsMenu()
{
	carregar();
	pos = 9;
}
VsMenu::~VsMenu()
{

}
void VsMenu::carregar()
{
	BG = load_bitmap("imagens/Menu/fundo2.png", NULL);

	BG2 = load_bitmap("imagens/Menu/char/top.png", NULL);

	LOGO = load_bitmap("imagens/Menu/char/logo.png", NULL);

	INTERROGACAO = load_bitmap("imagens/Menu/char/random_face.png", NULL);
	BGINTERROGACAO = load_bitmap("imagens/Menu/char/bg_face.png", NULL);
	BARRABG = load_bitmap("imagens/Menu/char/barra_bg.png", NULL);

	FACE[0] = load_bitmap("imagens/Menu/char/kyo_face.png", NULL);
	FACE[1] = load_bitmap("imagens/Menu/char/k_face.png", NULL);
	FACE[2] = load_bitmap("imagens/Menu/char/iori_face.png", NULL);
	FACE[3] = load_bitmap("imagens/Menu/char/kula_face.png", NULL);
	FACE[4] = load_bitmap("imagens/Menu/char/ryu_face.png", NULL);
	FACE[5] = load_bitmap("imagens/Menu/char/moriya_face.png", NULL);


	NOME[0] = load_bitmap("imagens/Menu/char/kyo_name.png", NULL );
	NOME[1] = load_bitmap("imagens/Menu/char/kyo_name.png", NULL );
	NOME[2] = load_bitmap("imagens/Menu/char/iori_name.png", NULL );
	NOME[3] = load_bitmap("imagens/Menu/char/k_name.png", NULL );
	NOME[4] = load_bitmap("imagens/Menu/char/orochi_name.png", NULL );
	NOME[5] = load_bitmap("imagens/Menu/char/kula_name.png", NULL );
	NOME[6] = load_bitmap("imagens/Menu/char/ryu_name.png", NULL );
	NOME[7] = load_bitmap("imagens/Menu/char/moriya_name.png", NULL );

	PREVIEW[0] = load_bitmap("imagens/Menu/char/kusanagi_preview.png", NULL );
	PREVIEW[1] = load_bitmap("imagens/Menu/char/kyo_preview.png", NULL );
	PREVIEW[2] = load_bitmap("imagens/Menu/char/iori_preview.png", NULL );
	PREVIEW[3] = load_bitmap("imagens/Menu/char/k_preview.png", NULL );
	PREVIEW[4] = load_bitmap("imagens/Menu/char/orochi_preview.png", NULL );
	PREVIEW[5] = load_bitmap("imagens/Menu/char/kula_preview.png", NULL );
	PREVIEW[6] = load_bitmap("imagens/Menu/char/ryu_preview.png", NULL );
	PREVIEW[7] = load_bitmap("imagens/Menu/char/moriya_preview.png", NULL );
	PREVIEW[8] = load_bitmap("imagens/Menu/char/chunlin_preview.png", NULL );
	PREVIEW[9] = load_bitmap("imagens/Menu/char/mai_preview.png", NULL );




	SEL[0] = load_bitmap("imagens/Menu/char/sel1.png", NULL);
	SEL[1] = load_bitmap("imagens/Menu/char/sel2.png", NULL);

	//sons
	SAMPSEL = load_sample("sons/menu-select.wav");
	SAMPOK = load_sample("sons/menu-ok.wav");

}
void VsMenu::Desenhar(BITMAP *Buffer)
{
	/*blit(BG2,Buffer,0,0,0,0,800,600);
	blit(BG,Buffer,0,0,0,20,800,600);
	blit(BG,Buffer,0,0,0,0,800,600);
	*/

	draw_trans_sprite(Buffer, BG, 0, 0);
	draw_trans_sprite(Buffer, BG2, 0, 0);
	draw_trans_sprite(Buffer, LOGO, 245, 25);


//random
	draw_trans_sprite(Buffer, INTERROGACAO, 315, 120);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 315, 120);

//kyo
	draw_trans_sprite(Buffer, FACE[0], 315, 180);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 315, 180);
//k
	draw_trans_sprite(Buffer, FACE[1], 365, 210);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 365, 210);

//iori
	draw_trans_sprite(Buffer, FACE[2], 265, 210);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 265, 210);

//random
	draw_trans_sprite(Buffer, INTERROGACAO, 315, 240);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 315, 240);

//kula
	draw_trans_sprite(Buffer, FACE[3], 370, 270);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 367, 267);

//ryu
	draw_trans_sprite(Buffer, FACE[4], 265, 267);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 265, 267);

//moriya
	draw_trans_sprite(Buffer, FACE[5], 315, 300);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 315, 295);

//random
	draw_trans_sprite(Buffer, INTERROGACAO, 214, 295);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 214, 295);

//random
	draw_trans_sprite(Buffer, INTERROGACAO, 415, 295);
	draw_trans_sprite(Buffer, BGINTERROGACAO, 415, 295);



}
void VsMenu::Atualizar(BITMAP *Buffer)
{



	if(key[KEY_ENTER])
	{
		play_sample(SAMPOK, 100, 10, 1000, FALSE);
	}
	if(pos == 0)
	{
		draw_trans_sprite(Buffer, SEL[0], 315, 120);
		if(key[KEY_S])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos ++;
		}

	}
	else if(pos == 1)
	{
		draw_trans_sprite(Buffer, SEL[0], 315, 120 + 60);

		if(key[KEY_A])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos ++;
		}
		if(key[KEY_D])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos += 2;
		}
		if(key[KEY_W])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos --;
		}
		if(key[KEY_S])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos += 3;
		}


	}
	else if(pos == 2)
	{
		draw_trans_sprite(Buffer, SEL[0], 265, 210);

		if(key[KEY_D])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos --;
		}
		if(key[KEY_S])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos += 4;
		}
	}
	else if(pos == 3)
	{
		draw_trans_sprite(Buffer, SEL[0], 365, 210);
		if(key[KEY_A])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos -= 2;
		}
		if(key[KEY_S])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos += 2;
		}
	}
	else if(pos == 4)
	{
		draw_trans_sprite(Buffer, SEL[0], 315, 240);
		if(key[KEY_A])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos += 2;
		}
		if(key[KEY_D])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos ++;
		}
		if(key[KEY_S])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos += 3;
		}
		if(key[KEY_W])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos -= 3;
		}
	}
	else if(pos == 5)
	{
		draw_trans_sprite(Buffer, SEL[0], 365, 267);
		if(key[KEY_W])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos -= 2;
		}
		if(key[KEY_D])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos += 4;
		}
		if((key[KEY_A]) || (key[KEY_S]))
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos += 2;
		}
	}
	else if(pos == 6)
	{
		draw_trans_sprite(Buffer, SEL[0], 265, 267);
		if(key[KEY_W])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos -= 4;
		}
		if(key[KEY_A])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos += 2;
		}

		if((key[KEY_S]) || (key[KEY_D]))
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos ++;
		}
	}
	else if(pos == 7)
	{
		draw_trans_sprite(Buffer, SEL[0], 315, 295);

		if(key[KEY_A])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos --;
		}
		if(key[KEY_D])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos -= 2;
		}
		if(key[KEY_W])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos -= 3;
		}
	}
	else if(pos == 8)
	{
		draw_trans_sprite(Buffer, SEL[0], 214, 295);
		if(key[KEY_D])
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos -= 2;
		}


	}
	else if(pos == 9)
	{
		draw_trans_sprite(Buffer, SEL[0], 415, 295);
		if((key[KEY_W]) || (key[KEY_A]))
		{
			play_sample(SAMPSEL, 100, 10, 1000, FALSE);
			pos -= 4;
		}


	}
	if(pos < 7)
	{
		draw_trans_sprite(Buffer, NOME[pos], 50, 60);
	}

	if(pos == 7 || pos == 4)
	{
		draw_trans_sprite(Buffer, PREVIEW[pos], -90, 90);

	}
	else
	{
		draw_trans_sprite(Buffer, PREVIEW[pos], 0, 90);
	}
	draw_trans_sprite(Buffer, BARRABG, 0, 440);
	//DEBUG

	std::cout << pos << endl;
}
