#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>


#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

int BlocoDestruido;
int InimigoMorto;




bool ChecarColisaowblocos(SDL_Rect gRect, SDL_Rect RectBlocoIndestrutivel[])
{
	int i = 0;

	for (i = 0; i<30; i++)
	{
		int state = 0;
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = gRect.x;
		rightA = gRect.x + gRect.w;
		topA = gRect.y;
		bottomA = gRect.y + gRect.h;

		leftB = RectBlocoIndestrutivel[i].x;
		rightB = RectBlocoIndestrutivel[i].x + RectBlocoIndestrutivel[i].w;
		topB = RectBlocoIndestrutivel[i].y;
		bottomB = RectBlocoIndestrutivel[i].y + RectBlocoIndestrutivel[i].h;


		if (bottomA <= topB)
		{
			state = 1;
		}

		if (topA >= bottomB)
		{
			state = 1;
		}

		if (rightA <= leftB)
		{
			state = 1;
		}

		if (leftA >= rightB)
		{
			state = 1;
		}
		if (state == 0)
			return true;

		leftB = 0;
		rightB = 0;
		topB = 0;
		bottomB = 0;
		state = 0;

	}
	return false;
}

bool ChecarColisaobetrect(SDL_Rect bloco1, SDL_Rect bloco2)
{
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = bloco1.x;
		rightA = bloco1.x + bloco1.w;
		topA = bloco1.y;
		bottomA = bloco1.y + bloco1.h;

		leftB = bloco2.x;
		rightB = bloco2.x + bloco2.w;
		topB = bloco2.y;
		bottomB = bloco2.y + bloco2.h;


		if (bottomA <= topB)
		{
			return false;
		}

		if (topA >= bottomB)
		{
			return false;
		}

		if (rightA <= leftB)
		{
			return false;
		}

		if (leftA >= rightB)
		{
			return false;
		}
		return true;
}

bool ChecarColisaovetorwrect(SDL_Rect *bloco1, SDL_Rect bloco2, int k)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = bloco1[k].x;
	rightA = bloco1[k].x + bloco1[k].w;
	topA = bloco1[k].y;
	bottomA = bloco1[k].y + bloco1[k].h;

	leftB = bloco2.x;
	rightB = bloco2.x + bloco2.w;
	topB = bloco2.y;
	bottomB = bloco2.y + bloco2.h;


	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}
	return true;
}

bool ChecarColisaovetorwblocos(SDL_Rect *gRect, SDL_Rect RectBlocoIndestrutivel[], int k)
{
	int i = 0;

	for (i = 0; i<30; i++)
	{
		int state = 0;
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = gRect[k].x;
		rightA = gRect[k].x + gRect[k].w;
		topA = gRect[k].y;
		bottomA = gRect[k].y + gRect[k].h;

		leftB = RectBlocoIndestrutivel[i].x;
		rightB = RectBlocoIndestrutivel[i].x + RectBlocoIndestrutivel[i].w;
		topB = RectBlocoIndestrutivel[i].y;
		bottomB = RectBlocoIndestrutivel[i].y + RectBlocoIndestrutivel[i].h;


		if (bottomA <= topB)
		{
			state = 1;
		}

		if (topA >= bottomB)
		{
			state = 1;
		}

		if (rightA <= leftB)
		{
			state = 1;
		}

		if (leftA >= rightB)
		{
			state = 1;
		}
		if (state == 0)
			return true;

		leftB = 0;
		rightB = 0;
		topB = 0;
		bottomB = 0;
		state = 0;

	}
	return false;
}

bool ChecarColisaorectwblocosdestrutiveis(SDL_Rect gRect, SDL_Rect RectBlocoDestrutivel[])
{
	int i = 0;

	for (i = 0; i<20; i++)
	{
		int state = 0;
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = gRect.x;
		rightA = gRect.x + gRect.w;
		topA = gRect.y;
		bottomA = gRect.y + gRect.h;

		leftB = RectBlocoDestrutivel[i].x;
		rightB = RectBlocoDestrutivel[i].x + RectBlocoDestrutivel[i].w;
		topB = RectBlocoDestrutivel[i].y;
		bottomB = RectBlocoDestrutivel[i].y + RectBlocoDestrutivel[i].h;


		if (bottomA <= topB)
		{
			state = 1;
		}

		if (topA >= bottomB)
		{
			state = 1;
		}

		if (rightA <= leftB)
		{
			state = 1;
		}

		if (leftA >= rightB)
		{
			state = 1;
		}
		if (state == 0)
		{
			BlocoDestruido = i;
			return true;
		}
			

		leftB = 0;
		rightB = 0;
		topB = 0;
		bottomB = 0;
		state = 0;

	}
	return false;
}

bool ChecarColisaorectwenemy(SDL_Rect gRect, SDL_Rect RectBlocoDestrutivel[], int k)
{
	int i = 0;

	for (i = 0; i<k; i++)
	{
		int state = 0;
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = gRect.x;
		rightA = gRect.x + gRect.w;
		topA = gRect.y;
		bottomA = gRect.y + gRect.h;

		leftB = RectBlocoDestrutivel[i].x;
		rightB = RectBlocoDestrutivel[i].x + RectBlocoDestrutivel[i].w;
		topB = RectBlocoDestrutivel[i].y;
		bottomB = RectBlocoDestrutivel[i].y + RectBlocoDestrutivel[i].h;


		if (bottomA <= topB)
		{
			state = 1;
		}

		if (topA >= bottomB)
		{
			state = 1;
		}

		if (rightA <= leftB)
		{
			state = 1;
		}

		if (leftA >= rightB)
		{
			state = 1;
		}
		if (state == 0)
		{
			BlocoDestruido = i;
			InimigoMorto = i;
			return true;
		}


		leftB = 0;
		rightB = 0;
		topB = 0;
		bottomB = 0;
		state = 0;

	}
	return false;
}

bool ChecarColisaovetorwblocosdestrutiveis(SDL_Rect *gRect, SDL_Rect RectBlocoDestrutivel[], int k)
{
	int i = 0;
	for (i = 0; i<20; i++)
	{
		int state = 0;
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		leftA = gRect[k].x;
		rightA = gRect[k].x + gRect[k].w;
		topA = gRect[k].y;
		bottomA = gRect[k].y + gRect[k].h;

		leftB = RectBlocoDestrutivel[i].x;
		rightB = RectBlocoDestrutivel[i].x + RectBlocoDestrutivel[i].w;
		topB = RectBlocoDestrutivel[i].y;
		bottomB = RectBlocoDestrutivel[i].y + RectBlocoDestrutivel[i].h;


		if (bottomA <= topB)
		{
			state = 1;
		}
		if (topA >= bottomB)
		{
			state = 1;
		}
		if (rightA <= leftB)
		{
			state = 1;
		}
		if (leftA >= rightB)
		{
			state = 1;
		}
		if (state == 0)
		{
			return true;
		}

		leftB = 0;
		rightB = 0;
		topB = 0;
		bottomB = 0;
		state = 0;

	}
	return false;
}


int main( int argc, char* args[] )
{
	int k = 0;
	int a = 0;
	int contx = 0;
	int conty = 0;
	int j = 0;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* Window = NULL;
	srand((unsigned)time(NULL));
	if (TTF_Init() < 0) {
		printf("%s\n", TTF_GetError());
	}

	SDL_Color cor;
	cor.r = 0;
	cor.g = 0;
	cor.b = 0;
	SDL_Rect rect;
	SDL_Rect RectPoints;
	SDL_Rect RectTimer;
	SDL_Rect RectPontuacao;
	SDL_Surface *MenuPrincipal;
	SDL_Surface *Controls;
	SDL_Surface *Credits;
	SDL_Surface *Records;
	SDL_Surface *pontos;
	SDL_Surface *GameTime;
	SDL_Surface *Pontuacao;

	TTF_Font *fonte;
	char Score[30];
	fonte = TTF_OpenFont("fonts/font.ttf", 26);
	TTF_SetFontStyle(fonte, TTF_STYLE_BOLD);
	char msgprincipal[15] = "MENU";
	char msgcontrol[15] = "CONTROLS";
	char msgcredits[15] = "CREDITS";
	char msgrecords[15] = "RECORDS";
	
	
	MenuPrincipal = TTF_RenderText_Blended(fonte, msgprincipal, cor);
	Controls = TTF_RenderText_Blended(fonte, msgcontrol, cor);
	Records = TTF_RenderText_Blended(fonte, msgcredits, cor);
	Credits = TTF_RenderText_Blended(fonte, msgrecords, cor);
	
	
	rect.x = 270;
	rect.y = 604;

	RectPoints.x = 200;
	RectPoints.y = 605;

	RectTimer.x = 500;
	RectTimer.y = 605;

	RectPontuacao.x = 100;
	RectPontuacao.y = 350;


	////////////////CRIAR JANELA
	SDL_Surface* Tela = NULL;
	Window = SDL_CreateWindow("Jogo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	Tela = SDL_GetWindowSurface(Window);



	///////////////SURFACES
	SDL_Surface* BlocoDestrutivel = IMG_Load("images/blocoDestrutivel.png");
	SDL_Surface* Personup = IMG_Load("images/bmanup.png");
	SDL_Surface* Personup2 = IMG_Load("images/bmanup2.png");
	SDL_Surface* Personup3 = IMG_Load("images/bmanup3.png");
	SDL_Surface* Personright = IMG_Load("images/bmanright.png");
	SDL_Surface* Personright2 = IMG_Load("images/bmanright2.png");
	SDL_Surface* Personright3 = IMG_Load("images/bmanright3.png");
	SDL_Surface* Persondown = IMG_Load("images/bmandown.png");
	SDL_Surface* Persondown2 = IMG_Load("images/bmandown2.png");
	SDL_Surface* Persondown3 = IMG_Load("images/bmandown3.png");
	SDL_Surface* Personleft = IMG_Load("images/bmanleft.png");
	SDL_Surface* Personleft2 = IMG_Load("images/bmanleft2.png");
	SDL_Surface* Personleft3 = IMG_Load("images/bmanleft3.png");
	SDL_Surface* Bomb1 = IMG_Load("images/bomb1.png");
	SDL_Surface* Bomb2 = IMG_Load("images/bomb2.png");
	SDL_Surface* Bomb3 = IMG_Load("images/bomb3.png");
	SDL_Surface* Exploup = IMG_Load("images/exploup.png");
	SDL_Surface* Exploright = IMG_Load("images/exploright.png");
	SDL_Surface* Explomiddle = IMG_Load("images/explomiddle.png");
	SDL_Surface* Explodown = IMG_Load("images/explodown.png");
	SDL_Surface* Exploleft = IMG_Load("images/exploleft.png");
	SDL_Surface* Bodyup = IMG_Load("images/bodyup.png");
	SDL_Surface* Bodyright = IMG_Load("images/bodyright.png");
	SDL_Surface* Bodydown = IMG_Load("images/bodydown.png");
	SDL_Surface* Bodyleft = IMG_Load("images/bodyleft.png");
	SDL_Surface* Title = IMG_Load("images/title.png");
	SDL_Surface* Selecionador = IMG_Load("images/selecionador.png");
	SDL_Surface* Menu = IMG_Load("images/menu.png");
	SDL_Surface* Recordes = IMG_Load("images/highscore.png");
	SDL_Surface* Creditos = IMG_Load("images/credits.png");
	SDL_Surface* Vida = IMG_Load("images/vida.png");
	SDL_Surface* Clock = IMG_Load("images/clock.png");
	SDL_Surface* Youlose = IMG_Load("images/Youlose.png");
	SDL_Surface* Enemy = IMG_Load("images/enemy.png");
	SDL_Surface* Enemy2 = IMG_Load("images/enemy2.png");
	SDL_Surface* Enemy3 = IMG_Load("images/enemy3.png");
	SDL_Surface* Survive = IMG_Load("images/survive.png");



	SDL_Surface* gBlocoDestrutivel = NULL;
	SDL_Surface* gPersonup = NULL;
	SDL_Surface* gPersonup2 = NULL;
	SDL_Surface* gPersonup3 = NULL;
	SDL_Surface* gPersonright = NULL;
	SDL_Surface* gPersonright2 = NULL;
	SDL_Surface* gPersonright3 = NULL;
	SDL_Surface* gPersondown = NULL;
	SDL_Surface* gPersondown2 = NULL;
	SDL_Surface* gPersondown3 = NULL;
	SDL_Surface* gPersonleft = NULL;
	SDL_Surface* gPersonleft2 = NULL;
	SDL_Surface* gPersonleft3 = NULL;
	SDL_Surface* gBomb1 = NULL;
	SDL_Surface* gBomb2 = NULL;
	SDL_Surface* gBomb3 = NULL;
	SDL_Surface* gExploup = NULL;
	SDL_Surface* gExploright = NULL;
	SDL_Surface* gExplomiddle = NULL;
	SDL_Surface* gExplodown = NULL;
	SDL_Surface* gExploleft = NULL;
	SDL_Surface* gBodyup = NULL;
	SDL_Surface* gBodyright = NULL;
	SDL_Surface* gBodydown = NULL;
	SDL_Surface* gBodyleft = NULL;
	SDL_Surface* gTitle = NULL;
	SDL_Surface* gSelecionador = NULL;
	SDL_Surface* gMenu = NULL;
	SDL_Surface* gYoulose = NULL;
	SDL_Surface* gEnemy = NULL;
	SDL_Surface* gEnemy2 = NULL;
	SDL_Surface* gEnemy3 = NULL;
	SDL_Surface* gRecordes = NULL;
	SDL_Surface* gCreditos = NULL;
	SDL_Surface* gVida = NULL;
	SDL_Surface* gClock = NULL;
	SDL_Surface* gSurvive = NULL;

	SDL_Surface* Mapa = IMG_Load("images/mapa.png");
	SDL_Surface* gMapa = NULL;

	


	////////////////CONVERTER IMAGENS
	gBlocoDestrutivel = SDL_ConvertSurface(BlocoDestrutivel, Tela->format, 0);
	gPersonup = SDL_ConvertSurface(Personup, Tela->format, 0);
	gPersonup2 = SDL_ConvertSurface(Personup2, Tela->format, 0);
	gPersonup3 = SDL_ConvertSurface(Personup3, Tela->format, 0);
	gPersonright = SDL_ConvertSurface(Personright, Tela->format, 0);
	gPersonright2 = SDL_ConvertSurface(Personright2, Tela->format, 0);
	gPersonright3 = SDL_ConvertSurface(Personright3, Tela->format, 0);
	gPersondown = SDL_ConvertSurface(Persondown, Tela->format, 0);
	gPersondown2 = SDL_ConvertSurface(Persondown2, Tela->format, 0);
	gPersondown3 = SDL_ConvertSurface(Persondown3, Tela->format, 0);
	gPersonleft = SDL_ConvertSurface(Personleft, Tela->format, 0);
	gPersonleft2 = SDL_ConvertSurface(Personleft2, Tela->format, 0);
	gPersonleft3 = SDL_ConvertSurface(Personleft3, Tela->format, 0);
	gBomb1 = SDL_ConvertSurface(Bomb1, Tela->format, 0);
	gBomb2 = SDL_ConvertSurface(Bomb2, Tela->format, 0);
	gBomb3 = SDL_ConvertSurface(Bomb3, Tela->format, 0);
	gExploup = SDL_ConvertSurface(Exploup, Tela->format, 0);
	gExploright = SDL_ConvertSurface(Exploright, Tela->format, 0);
	gExplomiddle = SDL_ConvertSurface(Explomiddle, Tela->format, 0);
	gExplodown = SDL_ConvertSurface(Explodown, Tela->format, 0);
	gExploleft = SDL_ConvertSurface(Exploleft, Tela->format, 0);
	gBodyup = SDL_ConvertSurface(Bodyup, Tela->format, 0);
	gBodyright = SDL_ConvertSurface(Bodyright, Tela->format, 0);
	gBodydown = SDL_ConvertSurface(Bodydown, Tela->format, 0);
	gBodyleft = SDL_ConvertSurface(Bodyleft, Tela->format, 0);
	gMapa = SDL_ConvertSurface(Mapa, Tela->format, 0);
	gTitle = SDL_ConvertSurface(Title, Tela->format, 0);
	gSelecionador = SDL_ConvertSurface(Selecionador, Tela->format, 0);
	gMenu = SDL_ConvertSurface(Menu, Tela->format, 0);
	gYoulose = SDL_ConvertSurface(Youlose, Tela->format, 0);
	gEnemy = SDL_ConvertSurface(Enemy, Tela->format, 0);
	gEnemy2 = SDL_ConvertSurface(Enemy2, Tela->format, 0);
	gEnemy3 = SDL_ConvertSurface(Enemy3, Tela->format, 0);
	gSurvive = SDL_ConvertSurface(Survive, Tela->format, 0);

	gCreditos = SDL_ConvertSurface(Creditos, Tela->format, 0);
	gVida = SDL_ConvertSurface(Vida, Tela->format, 0);
	gRecordes = SDL_ConvertSurface(Recordes, Tela->format, 0);
	gClock = SDL_ConvertSurface(Clock, Tela->format, 0);


	///////////////EXCLUIR IMAGENS ANTIGAS
	SDL_FreeSurface(BlocoDestrutivel);
	SDL_FreeSurface(Personup);
	SDL_FreeSurface(Personup2);
	SDL_FreeSurface(Personup3);
	SDL_FreeSurface(Personright);
	SDL_FreeSurface(Personright2);
	SDL_FreeSurface(Personright3);
	SDL_FreeSurface(Persondown);
	SDL_FreeSurface(Persondown2);
	SDL_FreeSurface(Persondown3);
	SDL_FreeSurface(Personleft);
	SDL_FreeSurface(Personleft2);
	SDL_FreeSurface(Personleft3);
	SDL_FreeSurface(Bomb1);
	SDL_FreeSurface(Bomb2);
	SDL_FreeSurface(Bomb3);
	SDL_FreeSurface(Exploup);
	SDL_FreeSurface(Explomiddle);
	SDL_FreeSurface(Exploright);
	SDL_FreeSurface(Explodown);
	SDL_FreeSurface(Exploleft);
	SDL_FreeSurface(Bodyup);
	SDL_FreeSurface(Bodyright);
	SDL_FreeSurface(Bodydown);
	SDL_FreeSurface(Bodyleft);
	SDL_FreeSurface(Mapa);
	SDL_FreeSurface(Title);
	SDL_FreeSurface(Selecionador);
	SDL_FreeSurface(Menu);
	SDL_FreeSurface(Youlose);
	SDL_FreeSurface(Enemy);
	SDL_FreeSurface(Enemy2);
	SDL_FreeSurface(Enemy3);
	SDL_FreeSurface(Survive);
	SDL_FreeSurface(Clock);
	SDL_FreeSurface(Vida);
	SDL_FreeSurface(Recordes);
	SDL_FreeSurface(Creditos);

	//////////////////////////////////////////////////TRANSPARENCIA
	SDL_SetColorKey(gPersonup, SDL_TRUE, SDL_MapRGB(gPersonright->format, 0, 255, 0));
	SDL_SetColorKey(gPersonup2, SDL_TRUE, SDL_MapRGB(gPersonright2->format, 0, 255, 0));
	SDL_SetColorKey(gPersonup3, SDL_TRUE, SDL_MapRGB(gPersonright3->format, 0, 255, 0));
	SDL_SetColorKey(gPersonright, SDL_TRUE, SDL_MapRGB(gPersonright->format, 0, 255, 0));
	SDL_SetColorKey(gPersonright2, SDL_TRUE, SDL_MapRGB(gPersonright2->format, 0, 255, 0));
	SDL_SetColorKey(gPersonright3, SDL_TRUE, SDL_MapRGB(gPersonright3->format, 0, 255, 0));
	SDL_SetColorKey(gPersondown, SDL_TRUE, SDL_MapRGB(gPersonright->format, 0, 255, 0));
	SDL_SetColorKey(gPersondown2, SDL_TRUE, SDL_MapRGB(gPersonright2->format, 0, 255, 0));
	SDL_SetColorKey(gPersondown3, SDL_TRUE, SDL_MapRGB(gPersonright3->format, 0, 255, 0));
	SDL_SetColorKey(gPersonleft, SDL_TRUE, SDL_MapRGB(gPersonright->format, 0, 255, 0));
	SDL_SetColorKey(gPersonleft2, SDL_TRUE, SDL_MapRGB(gPersonright2->format, 0, 255, 0));
	SDL_SetColorKey(gPersonleft3, SDL_TRUE, SDL_MapRGB(gPersonright3->format, 0, 255, 0));
	SDL_SetColorKey(gBomb1, SDL_TRUE, SDL_MapRGB(gBomb1->format, 0, 255, 0));
	SDL_SetColorKey(gBomb2, SDL_TRUE, SDL_MapRGB(gBomb2->format, 0, 255, 0));
	SDL_SetColorKey(gBomb3, SDL_TRUE, SDL_MapRGB(gBomb3->format, 0, 255, 0));
	SDL_SetColorKey(gExploup, SDL_TRUE, SDL_MapRGB(gExploup->format, 0, 255, 0));
	SDL_SetColorKey(gExplomiddle, SDL_TRUE, SDL_MapRGB(gExplomiddle->format, 0, 255, 0));
	SDL_SetColorKey(gExploright, SDL_TRUE, SDL_MapRGB(gExploright->format, 0, 255, 0));
	SDL_SetColorKey(gExplodown, SDL_TRUE, SDL_MapRGB(gExplodown->format, 0, 255, 0));
	SDL_SetColorKey(gExploleft, SDL_TRUE, SDL_MapRGB(gExploleft->format, 0, 255, 0));
	SDL_SetColorKey(gBodyup, SDL_TRUE, SDL_MapRGB(gBodyup->format, 0, 255, 0));
	SDL_SetColorKey(gBodyright, SDL_TRUE, SDL_MapRGB(gBodyright->format, 0, 255, 0));
	SDL_SetColorKey(gBodydown, SDL_TRUE, SDL_MapRGB(gBodydown->format, 0, 255, 0));
	SDL_SetColorKey(gBodyleft, SDL_TRUE, SDL_MapRGB(gBodyleft->format, 0, 255, 0));
	SDL_SetColorKey(gSelecionador, SDL_TRUE, SDL_MapRGB(gSelecionador->format, 255, 255, 255));
	SDL_SetColorKey(gYoulose, SDL_TRUE, SDL_MapRGB(gYoulose->format, 0, 255, 0));
	SDL_SetColorKey(gEnemy, SDL_TRUE, SDL_MapRGB(gEnemy->format, 0, 255, 0));
	SDL_SetColorKey(gEnemy2, SDL_TRUE, SDL_MapRGB(gEnemy2->format, 0, 255, 0));
	SDL_SetColorKey(gEnemy3, SDL_TRUE, SDL_MapRGB(gEnemy3->format, 0, 255, 0));
	////////////////////////////////////////////////////


	//////////////RECTS
	SDL_Rect RectBomb;
	SDL_Rect RectPerson;
	SDL_Rect gRectPerson;
	SDL_Rect RectBlocoIndestrutivel[30];
	SDL_Rect RectSelect;
	SDL_Rect RectEnemy[40];
	SDL_Rect gRectEnemy[40];
	SDL_Rect RectBoxes[20];

	RectSelect.x = 270;
	RectSelect.y = 315;
	RectSelect.w = 0;
	RectSelect.h = 0;

	RectPerson.x = 47;
	RectPerson.y = 1;
	RectPerson.w = 47;
	RectPerson.h = 74;

	gRectPerson.x = 47;
	gRectPerson.y = 33;
	gRectPerson.w = 47;
	gRectPerson.h = 41;

	RectBomb.x = 0;
	RectBomb.y = 0;
	RectBomb.w = 55;
	RectBomb.h = 45;


	contx = 100;
	conty = 80;
	for (k = 0; k<30; k++)
	{
		RectBlocoIndestrutivel[k].x = contx;
		RectBlocoIndestrutivel[k].y = conty;
		RectBlocoIndestrutivel[k].w = 52;
		RectBlocoIndestrutivel[k].h = 46;
		contx += 109;
		if (k == j + 5)
		{
			j += 6;
			conty += 97;
			contx = 100;
		}
	}

	/////////////////////////////////////////////


	int imgFlags = IMG_INIT_PNG;
	////////////////////////VARIAVEIS
	int RandPosX = 0;
	int RandPosY = 0;
	int op = 0;
	int aux = 0;
	int gUp = 0;
	int gRight = 0;
	int gDown = 0;
	int gLeft = 0;
	int fWay = 0;
	int frame = 0;
	int gKey = 2;
	long fpsTimer = 0;
	long ticks = 0;
	long BomberTimer = 0;
	char GameTimer[20];
	long EnemyTimer = 0;
	long Time=0;
	int explosion = 0;
	int BombPlanted = 0;
	int BombFrame = -1;
	int tempx = 0;
	int tempy = 0;
	int GameRun = 0;
	int kstate = 0;
	int nBlocos = 15;
	int control = 0;
	int tamanhoexplosao = 3;
	int nEnemies = 3;
	int nRandom = 0;
	int EnemyMovTime = 0;
	int ChooseDirec = 0;
	int PointsTimer = 0;
	int surv = 0;
	int EnemyDirect[20];
	int BlocosTimer = 0;
	long score = 0;
	int RandDirect = 0;
	int direcframe = 0;
	int EnemyFrame = 0;
	int EnemyFrameTime = 0;
	bool keystate = false;
	bool quit = false;
	const Uint8* state = SDL_GetKeyboardState(0);
	SDL_Event e;
	GameRun = 0;
	///////////////////////////////////////////////////JOGO
	while (!quit)
	{
		ticks = SDL_GetTicks();
		SDL_FillRect(Tela, NULL, SDL_MapRGB(Tela->format, 255, 255, 255));
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
					quit = true;
				if (e.type == SDL_KEYDOWN)
					keystate = true;
				if (e.type == SDL_KEYUP)
				{
					keystate = false;
					switch (e.key.keysym.sym)
					{
					case SDLK_UP:
						frame = 0;
						break;
					case SDLK_RIGHT:
						frame = 0;
						break;
					case SDLK_DOWN:
						frame = 0;
						break;
					case SDLK_LEFT:
						frame = 0;
						break;
					}
				}
			}

		/////////////////////TELA INICIAL
		if (GameRun == 0)
		{
			if (control == 0)
			{
				SDL_BlitSurface(gTitle, NULL, Tela, 0);
				SDL_BlitSurface(MenuPrincipal, NULL, Tela, &RectPoints);
				SDL_BlitSurface(gSelecionador, NULL, Tela, &RectSelect);
			}
			else if (control == 1)
			{
				SDL_BlitSurface(gMenu, NULL, Tela, 0);
				SDL_BlitSurface(Controls, NULL, Tela, &RectPoints);
			}
			else if (control == 2)
			{
				SDL_BlitSurface(gCreditos, NULL, Tela, 0);
				SDL_BlitSurface(Records, NULL, Tela, &RectPoints);
			}
			else if (control == 3)
			{
				SDL_BlitSurface(gRecordes, NULL, Tela, 0);
				SDL_BlitSurface(Credits, NULL, Tela, &RectPoints);
			}		

				if (e.type == SDL_KEYDOWN)
				{
					switch (e.key.keysym.sym)
					{
					case SDLK_UP:
						if (op != 0 && kstate == 0 && control == 0)
						{
							RectSelect.y -= 41;
							op--;
							kstate = 1;
						}
						break;
					case SDLK_DOWN:
						if (op != 4 && kstate == 0 && control == 0)
						{
							kstate = 1;
							RectSelect.y += 41;
							op++;
						}
						break;
					case SDLK_RETURN:							
						if (op == 0)
						{
							kstate = 0;
							GameRun = 5;
							for (k = 0; k < nBlocos; k++)
							{

								RandPosX = rand() % 13;
								RandPosY = rand() % 11;

								RectBoxes[k].x = 53.5*RandPosX + 48 + 0.8*RandPosX;
								RectBoxes[k].y = 48.5*RandPosY + 31 + 0.35*RandPosY;
								RectBoxes[k].w = 47;
								RectBoxes[k].h = 41;
								if (ChecarColisaovetorwblocos(RectBoxes, RectBlocoIndestrutivel, k) || ChecarColisaovetorwrect(RectBoxes, gRectPerson, k))
									k--;
							}
							for (k = 0; k < nEnemies; k++)
							{
								RandPosX = rand() % 13;
								RandPosY = rand() % 11;

								gRectEnemy[k].x = 53.5*RandPosX + 48 + 0.8*RandPosX;
								gRectEnemy[k].y = 48.5*RandPosY + 31 + 0.35*RandPosY;
								gRectEnemy[k].w = 47;
								gRectEnemy[k].h = 35;

								RectEnemy[k].x = gRectEnemy[k].x;
								RectEnemy[k].y = gRectEnemy[k].y - 18;
								RectEnemy[k].w = 47;
								RectEnemy[k].h = 74;

								if (ChecarColisaovetorwblocos(gRectEnemy, RectBlocoIndestrutivel, k) || ChecarColisaovetorwrect(gRectEnemy, gRectPerson, k) || ChecarColisaovetorwblocosdestrutiveis(gRectEnemy, RectBoxes, k))
									k--;
							}
							for (k = 0; k < 20; k++)
							{
								RandDirect = rand() % 4;
								EnemyDirect[k] = RandDirect;
							}
							surv = 1;								
						}
						else if (op == 1)
						{
							control = 1;
						}
						else if (op == 2)
						{
							control = 2;
						}
						else if (op == 3)
						{
							control = 3;
						}
						else if (op == 4)
							quit = 1;
						break;
					case SDLK_ESCAPE:
							control = 0;
							break;
					}					
				}
				if (e.type == SDL_KEYUP)
					kstate = 0;
				
				SDL_Delay(10);
		}
		////////////////////////CONTROLE
		if (GameRun == 1 && fpsTimer <= ticks)
		{
			
			if (state[SDL_SCANCODE_UP])
			{
				gRectPerson.y -= 1;
				RectPerson.y -= 1;
				if ((gRectPerson.y < 37 || ChecarColisaowblocos(gRectPerson, RectBlocoIndestrutivel)) || ChecarColisaorectwblocosdestrutiveis(gRectPerson, RectBoxes))
				{
					gRectPerson.y += 1;
					RectPerson.y += 1;
				}
				else
				{
					if (gUp == 20)
					{
						if (fWay == 0)
						{
							frame += 1;
							if (frame == 3)
							{
								frame -= 1;
								fWay = 1;
							}
						}

						if (fWay == 1)
						{
							frame -= 1;
							if (frame == 1)
								fWay = 0;
						}
						gUp = 0;
					}
					gUp++;
					gKey = 0;
				}
			}
			if (state[SDL_SCANCODE_RIGHT])
			{
				gRectPerson.x += 1;
				RectPerson.x += 1;
				if ((gRectPerson.x + gRectPerson.w > 756 || ChecarColisaowblocos(gRectPerson, RectBlocoIndestrutivel)) || ChecarColisaorectwblocosdestrutiveis(gRectPerson, RectBoxes))
				{
					gRectPerson.x -= 1;
					RectPerson.x -= 1;
				}
				else
				{
					if (gRight == 20)
					{
						if (fWay == 0)
						{
							frame += 1;
							if (frame == 3)
							{
								frame -= 1;
								fWay = 1;
							}
						}
						if (fWay == 1)
						{
							frame -= 1;
							if (frame == 1)
								fWay = 0;
						}
						gRight = 0;
					}
					gRight++;
					gKey = 1;
				}
			}
			if (state[SDL_SCANCODE_DOWN])
			{
				gRectPerson.y += 1;
				RectPerson.y += 1;
				if ((gRectPerson.y + gRectPerson.h > 566 || ChecarColisaowblocos(gRectPerson, RectBlocoIndestrutivel)) || ChecarColisaorectwblocosdestrutiveis(gRectPerson, RectBoxes))
				{
					gRectPerson.y--;
					RectPerson.y--;
				}
				else
				{
					if (gDown == 20)
					{
						if (fWay == 0)
						{
							frame += 1;
							if (frame == 3)
							{
								frame -= 1;
								fWay = 1;
							}
						}
						if (fWay == 1)
						{
							frame -= 1;
							if (frame == 1)
								fWay = 0;
						}
						gDown = 0;
					}
					gDown++;
					gKey = 2;
				}
			}
			if (state[SDL_SCANCODE_LEFT])
			{
				gRectPerson.x -= 1;
				RectPerson.x -= 1;					
				if ((gRectPerson.x < 46 || ChecarColisaowblocos(gRectPerson, RectBlocoIndestrutivel)) || ChecarColisaorectwblocosdestrutiveis(gRectPerson, RectBoxes))
				{
					gRectPerson.x += 1;
					RectPerson.x += 1;
				}
				else
				{
					if (gLeft == 20)
					{
						if (fWay == 0)
						{
							frame += 1;
							if (frame == 3)
							{
								frame -= 1;
								fWay = 1;
							}
						}
						if (fWay == 1)
						{
							frame -= 1;
							if (frame == 1)
								fWay = 0;
						}
						gLeft = 0;
					}
					gLeft++;
					gKey = 3;
				}
			}
			if (state[SDL_SCANCODE_SPACE])
			{
				if (BombPlanted == 0)
				{
					BombPlanted = 1;

					tempx = gRectPerson.x + 23;
					tempy = gRectPerson.y + 17;

					RectBomb.x = ((tempx - 46) / 54)*54.5 + 46;
					RectBomb.y = ((tempy - 33) / 48)*48.5 + 32;
				}
			}
			if (state[SDL_SCANCODE_ESCAPE])
			{
				GameRun = 0;
				aux = 0;
				gUp = 0;
				gRight = 0;
				gDown = 0;
				gLeft = 0;
				fWay = 0;
				frame = 0;
				gKey = 2;
				fpsTimer = 0;
				ticks = 0;
				BomberTimer = 0;
				explosion = 0;
				BombPlanted = 0;
				BombFrame = -1;
				tempx = 0;
				nBlocos = 15;
				tempy = 0;
				RectPerson.x = 47;
				RectPerson.y = 1;
				RectPerson.w = 47;
				RectPerson.h = 74;
				gRectPerson.x = 47;
				gRectPerson.y = 33;
				gRectPerson.w = 47;
				gRectPerson.h = 41;
				tamanhoexplosao = 3;
				score = 0;
				Time = 0;
				nEnemies = 3;
			}
				
			fpsTimer = ticks + 3;
		}


		

		if (GameRun == 1)
		{ 
			pontos = TTF_RenderText_Blended(fonte, Score, cor);
			GameTime = TTF_RenderText_Blended(fonte, GameTimer, cor);

			SDL_BlitSurface(pontos, NULL, Tela, &RectPoints);
			SDL_BlitSurface(GameTime, NULL, Tela, &RectTimer);
			sprintf(Score, "Score: %ld", score);
			SDL_FreeSurface(pontos);
			
			SDL_BlitSurface(gMapa, NULL, Tela, 0);
			
			for (k = 0; k < nBlocos; k++)
			{
				SDL_BlitSurface(gBlocoDestrutivel, NULL, Tela, &RectBoxes[k]);
			}


		}
		///////////////////////////HUD
		if ((GameRun == 1) && (PointsTimer <= ticks))
		{
			int hora = 0;
			int minuto = 0;
			hora = Time / 60;
			minuto = Time % 60;
			sprintf(Score, "Score: %ld", score);
			sprintf(GameTimer, "Time: %d:%d", hora, minuto);
			score++;
			Time++;
			PointsTimer = ticks + 1000;
		}

		///////////////////////////////////ENEMY A.I.
		if (GameRun == 1)
		{
			if (nEnemies < 40 && EnemyTimer <= ticks)
			{
				for (k = 0; k < 1; k++)
				{
					RandPosX = rand() % 13;
					RandPosY = rand() % 11;

					gRectEnemy[nEnemies].x = 53.5*RandPosX + 48 + 0.8*RandPosX;
					gRectEnemy[nEnemies].y = 48.5*RandPosY + 31 + 0.35*RandPosY;
					gRectEnemy[nEnemies].w = 47;
					gRectEnemy[nEnemies].h = 33;

					RectEnemy[nEnemies].x = gRectEnemy[nEnemies].x;
					RectEnemy[nEnemies].y = gRectEnemy[nEnemies].y - 18;
					RectEnemy[nEnemies].w = 47;
					RectEnemy[nEnemies].h = 74;

					if (ChecarColisaovetorwblocos(gRectEnemy, RectBlocoIndestrutivel, nEnemies) || ChecarColisaovetorwrect(gRectEnemy, gRectPerson, nEnemies) || ChecarColisaovetorwblocosdestrutiveis(gRectEnemy, RectBoxes, nEnemies))
						k--;
				}
				nEnemies++;
				EnemyTimer = ticks + 2500;
			}

			if (EnemyFrameTime <= ticks)
			{
				if (direcframe == 0)
				{
					EnemyFrame += 1;
					if (EnemyFrame == 2)
					{
						direcframe = 1;
					}
				}
				else if (direcframe == 1)
				{
					EnemyFrame -= 1;
					if (EnemyFrame == 0)
						direcframe = 0;
				}
				EnemyFrameTime = ticks + 150;
			}
			/////////////A.I. MOV
			if (EnemyMovTime <= ticks)
			{

				for (k = 0; k < nEnemies; k++)
				{
					if (ChecarColisaovetorwrect(gRectEnemy, gRectPerson, k))
					{
						GameRun = 2;
					}
						

					switch (EnemyDirect[k])
					{
					case 0:
						gRectEnemy[k].y -= 1;
						RectEnemy[k].y -= 1;
						if (gRectEnemy[k].y < 37 || ChecarColisaovetorwblocos(gRectEnemy, RectBlocoIndestrutivel, k) || ChecarColisaovetorwblocosdestrutiveis(gRectEnemy, RectBoxes, k) || ChecarColisaovetorwrect(gRectEnemy, RectBomb, k))
						{
							gRectEnemy[k].y += 1;
							RectEnemy[k].y += 1;
							RandDirect = rand() % 4;
							EnemyDirect[k] = RandDirect;

						}
						break;
					case 1:
						gRectEnemy[k].x += 1;
						RectEnemy[k].x += 1;
						if (gRectEnemy[k].x + gRectEnemy[k].w > 756 || ChecarColisaovetorwblocos(gRectEnemy, RectBlocoIndestrutivel, k) || ChecarColisaovetorwblocosdestrutiveis(gRectEnemy, RectBoxes, k) || ChecarColisaovetorwrect(gRectEnemy, RectBomb, k))
						{
							gRectEnemy[k].x -= 1;
							RectEnemy[k].x -= 1;
							RandDirect = rand() % 4;
							EnemyDirect[k] = RandDirect;

						}
						break;
					case 2:
						gRectEnemy[k].y += 1;
						RectEnemy[k].y += 1;
						if (gRectEnemy[k].y + gRectEnemy[k].h > 560 || ChecarColisaovetorwblocos(gRectEnemy, RectBlocoIndestrutivel, k) || ChecarColisaovetorwblocosdestrutiveis(gRectEnemy, RectBoxes, k) || ChecarColisaovetorwrect(gRectEnemy, RectBomb, k))
						{
							gRectEnemy[k].y -= 1;
							RectEnemy[k].y -= 1;
							RandDirect = rand() % 4;
							EnemyDirect[k] = RandDirect;

						}
						break;
					case 3:
						gRectEnemy[k].x -= 1;
						RectEnemy[k].x -= 1;
						if (gRectEnemy[k].x < 46 || ChecarColisaovetorwblocos(gRectEnemy, RectBlocoIndestrutivel, k) || ChecarColisaovetorwblocosdestrutiveis(gRectEnemy, RectBoxes, k) || ChecarColisaovetorwrect(gRectEnemy, RectBomb, k))
						{
							gRectEnemy[k].x += 1;
							RectEnemy[k].x += 1;
							RandDirect = rand() % 4;
							EnemyDirect[k] = RandDirect;
						}
						break;
					}
				}
				EnemyMovTime = ticks + 15;
			}

			for (k = 0; k < nEnemies; k++)
			{
				switch (EnemyFrame)
				{
				case 0:
					SDL_BlitSurface(gEnemy, NULL, Tela, &RectEnemy[k]);
					break;
				case 1:
					SDL_BlitSurface(gEnemy2, NULL, Tela, &RectEnemy[k]);
					break;
				case 2:
					SDL_BlitSurface(gEnemy3, NULL, Tela, &RectEnemy[k]);
					break;
				}
			}
		}
		
		if (nBlocos < 15 && BlocosTimer <= ticks)
		{
			for (k = 0; k < 1; k++)
			{

				RandPosX = rand() % 13;
				RandPosY = rand() % 11;

				RectBoxes[nBlocos].x = 53.5*RandPosX + 48 + 0.8*RandPosX;
				RectBoxes[nBlocos].y = 48.5*RandPosY + 31 + 0.35*RandPosY;
				RectBoxes[nBlocos].w = 47;
				RectBoxes[nBlocos].h = 41;
				if (RectBoxes[nBlocos].x < 46 || ChecarColisaovetorwblocos(RectBoxes, RectBlocoIndestrutivel, nBlocos) || ChecarColisaovetorwrect(RectBoxes, gRectPerson, nBlocos) || ChecarColisaovetorwblocosdestrutiveis(gRectEnemy, RectBoxes, nBlocos))
					k--;
			}
			for (k = 0; k < nEnemies; k++)
			{
				RandDirect = rand() % 4;
				EnemyDirect[k] = RandDirect;
			}
			nBlocos++;
			BlocosTimer = ticks + 4000;
		}
		if (GameRun == 1 && ChooseDirec <= ticks)
		{
			for (k = 0; k < nEnemies; k++)
			{
				RandDirect = rand() % 4;
				if ((RectEnemy[k].x < gRectPerson.x) && (RandDirect == 0 || RandDirect == 1))
					EnemyDirect[k] = 1;
				else if ((RectEnemy[k].x > gRectPerson.x) && (RandDirect == 0 || RandDirect == 1))
					EnemyDirect[k] = 3;
				else
				{
					RandDirect = rand() % 4;
					EnemyDirect[k] = RandDirect;
				}
			}
			ChooseDirec = ticks + 2400;
		}

		//////////////////////////////////////////BLITS
		if (GameRun == 1)
		{
			//-----BOMBS
			if (BombPlanted == 1)
			{
				if (BomberTimer <= ticks)
				{
					switch (explosion)
					{
					case 0:
						BomberTimer = ticks + 1000;
						BombFrame++;
						break;
					}
				}
			}

			if (BombPlanted == 1)
			{
				switch (BombFrame)
				{
				case 0:
					SDL_BlitSurface(gBomb1, NULL, Tela, &RectBomb);
					break;
				case 1:
					SDL_BlitSurface(gBomb2, NULL, Tela, &RectBomb);
					break;
				case 2:
					SDL_BlitSurface(gBomb3, NULL, Tela, &RectBomb);
					break;
				case 3:
					SDL_BlitSurface(gExplomiddle, NULL, Tela, &RectBomb);
					//////////////UP
					while (aux < tamanhoexplosao)
					{
						aux++;
						RectBomb.y -= 45;
						if (ChecarColisaobetrect(RectBomb, gRectPerson))
						{
							GameRun = 2;
							break;
						}
						if (ChecarColisaorectwenemy(RectBomb, RectBoxes, nBlocos))
						{
							for (k = BlocoDestruido; k < nBlocos; k++)
							{
								RectBoxes[k] = RectBoxes[k + 1];
							}
							score += 5;
							nBlocos--;
							break;
						}

						if (ChecarColisaorectwenemy(RectBomb, gRectEnemy, nEnemies))
						{
							for (k = InimigoMorto; k < nEnemies; k++)
							{
								gRectEnemy[k] = gRectEnemy[k + 1];
								RectEnemy[k] = RectEnemy[k + 1];
								EnemyDirect[k] = EnemyDirect[k + 1];
								score += 10;
							}
							nEnemies--;
						}

						if ((RectBomb.y < 35 || ChecarColisaowblocos(RectBomb, RectBlocoIndestrutivel)))
						{
							break;
						}
						else
						{
							if (aux == tamanhoexplosao)
								SDL_BlitSurface(gExploup, NULL, Tela, &RectBomb);
							else
								SDL_BlitSurface(gBodyup, NULL, Tela, &RectBomb);
						}
					}
					RectBomb.y += 45 * aux;
					aux = 0;
					//////////RIGHT
					while (aux < tamanhoexplosao)
					{
						aux++;
						RectBomb.x += 54;
						if (ChecarColisaobetrect(RectBomb, gRectPerson))
						{
							GameRun = 2;
							break;
						}

						if (ChecarColisaorectwenemy(RectBomb, RectBoxes, nBlocos))
						{
							for (k = BlocoDestruido; k < nBlocos; k++)
							{
								RectBoxes[k] = RectBoxes[k + 1];
							}
							score += 5;
							nBlocos--;
							break;
						}
						if (ChecarColisaorectwenemy(RectBomb, gRectEnemy, nEnemies))
						{
							for (k = InimigoMorto; k<nEnemies; k++)
							{
								gRectEnemy[k] = gRectEnemy[k + 1];
								RectEnemy[k] = RectEnemy[k + 1];
								EnemyDirect[k] = EnemyDirect[k + 1];
							}
							score += 10;
							nEnemies--;
						}
						if ((RectBomb.x > 756 - 54 || ChecarColisaowblocos(RectBomb, RectBlocoIndestrutivel)))
						{
							break;
						}
						else
						{
							if (aux == tamanhoexplosao)
								SDL_BlitSurface(gExploright, NULL, Tela, &RectBomb);
							else
								SDL_BlitSurface(gBodyright, NULL, Tela, &RectBomb);
						}
					}
					RectBomb.x -= 54 * aux;
					aux = 0;
					/////////////DOWN
					while (aux < tamanhoexplosao)
					{
						aux++;
						RectBomb.y += 45;
						if (ChecarColisaobetrect(RectBomb, gRectPerson))
						{
							GameRun = 2;
							break;
						}
						if (ChecarColisaorectwenemy(RectBomb, RectBoxes, nBlocos))
						{
							for (k = BlocoDestruido; k < nBlocos; k++)
							{
								RectBoxes[k] = RectBoxes[k + 1];
							}
							score += 5;
							nBlocos--;
							break;
						}
						if (ChecarColisaorectwenemy(RectBomb, gRectEnemy, nEnemies))
						{
							for (k = InimigoMorto; k<nEnemies; k++)
							{
								gRectEnemy[k] = gRectEnemy[k + 1];
								RectEnemy[k] = RectEnemy[k + 1];
								EnemyDirect[k] = EnemyDirect[k + 1];
							}
							score += 10;
							nEnemies--;
						}
						if ((RectBomb.y > 566 - 45 || ChecarColisaowblocos(RectBomb, RectBlocoIndestrutivel)))
						{
							break;
						}
						else
						{
							if (aux == tamanhoexplosao)
								SDL_BlitSurface(gExplodown, NULL, Tela, &RectBomb);
							else
								SDL_BlitSurface(gBodydown, NULL, Tela, &RectBomb);
						}
					}
					RectBomb.y -= 45 * aux;
					aux = 0;
					//////////////LEFT
					while (aux < tamanhoexplosao)
					{
						aux++;
						RectBomb.x -= 54;
						if (ChecarColisaobetrect(RectBomb, gRectPerson))
						{
							GameRun = 2;
							break;
						}
						if (ChecarColisaorectwenemy(RectBomb, RectBoxes, nBlocos))
						{
							for (k = BlocoDestruido; k < nBlocos; k++)
							{
								RectBoxes[k] = RectBoxes[k + 1];
							}
							score += 5;
							nBlocos--;
							break;
						}
						if (ChecarColisaorectwenemy(RectBomb, gRectEnemy, nEnemies))
						{
							for (k = InimigoMorto; k<nEnemies; k++)
							{
								gRectEnemy[k] = gRectEnemy[k + 1];
								RectEnemy[k] = RectEnemy[k + 1];
								EnemyDirect[k] = EnemyDirect[k + 1];
							}
							score += 10;
							nEnemies--;
						}
						if ((RectBomb.x < 46 || ChecarColisaowblocos(RectBomb, RectBlocoIndestrutivel)))
						{
							break;
						}
						else
						{
							if (aux == tamanhoexplosao)
								SDL_BlitSurface(gExploleft, NULL, Tela, &RectBomb);
							else
								SDL_BlitSurface(gBodyleft, NULL, Tela, &RectBomb);
						}
					}
					RectBomb.x += 54 * aux;
					aux = 0;
					////////////////////////////
					break;
				case 4:
					BombFrame = -1;
					BombPlanted = 0;
					BomberTimer = 0;
					break;
				}
			}

			///////////////////////////////////////CHARACTER MOVEMENT
			switch (gKey)
			{
			case 0:
				switch (frame)
				{
				case 0:
					SDL_BlitSurface(gPersonup, NULL, Tela, &RectPerson);
					break;
				case 1:
					SDL_BlitSurface(gPersonup2, NULL, Tela, &RectPerson);
					break;
				case 2:
					SDL_BlitSurface(gPersonup3, NULL, Tela, &RectPerson);
					break;
				}
				break;

			case 1:
				switch (frame)
				{
				case 0:
					SDL_BlitSurface(gPersonright, NULL, Tela, &RectPerson);
					break;
				case 1:
					SDL_BlitSurface(gPersonright2, NULL, Tela, &RectPerson);
					break;
				case 2:
					SDL_BlitSurface(gPersonright3, NULL, Tela, &RectPerson);
					break;
				}
				break;

			case 2:
				switch (frame)
				{
				case 0:
					SDL_BlitSurface(gPersondown, NULL, Tela, &RectPerson);
					break;
				case 1:
					SDL_BlitSurface(gPersondown2, NULL, Tela, &RectPerson);
					break;
				case 2:
					SDL_BlitSurface(gPersondown3, NULL, Tela, &RectPerson);
					break;
				}
				break;

			case 3:
				switch (frame)
				{
				case 0:
					SDL_BlitSurface(gPersonleft, NULL, Tela, &RectPerson);
					break;
				case 1:
					SDL_BlitSurface(gPersonleft2, NULL, Tela, &RectPerson);
					break;
				case 2:
					SDL_BlitSurface(gPersonleft3, NULL, Tela, &RectPerson);
					break;
				}
				break;
			}
		}
		////////////////////////////////////////////////////////////////////
		if (GameRun == 2)
		{
			SDL_BlitSurface(gYoulose, NULL, Tela, 0);
			cor.r = 255;
			cor.g = 0;
			cor.b = 255;
			fonte = TTF_OpenFont("fonts/font.ttf", 60);
			sprintf(Score, "SUA PONTUACAO %ld", score);
			Pontuacao = TTF_RenderText_Blended(fonte, Score, cor);
			SDL_BlitSurface(Pontuacao, NULL, Tela, &RectPontuacao);
			SDL_UpdateWindowSurface(Window);
			SDL_Delay(3000);
			fonte = TTF_OpenFont("fonts/font.ttf", 26);
			cor.r = 0;
			cor.g = 0;
			cor.b = 0;

			GameRun = 0;
			aux = 0;
			nBlocos = 15;
			gUp = 0;
			gRight = 0;
			gDown = 0;
			gLeft = 0;
			fWay = 0;
			frame = 0;
			gKey = 2;
			fpsTimer = 0;
			ticks = 0;
			BomberTimer = 0;
			explosion = 0;
			BombPlanted = 0;
			BombFrame = -1;
			tempx = 0;
			tempy = 0;
			RectPerson.x = 47;
			RectPerson.y = 1;
			RectPerson.w = 47;
			RectPerson.h = 74;
			gRectPerson.x = 47;
			gRectPerson.y = 33;
			gRectPerson.w = 47;
			gRectPerson.h = 41;
			tamanhoexplosao = 3;
			score = 0;
			Time = 0;
			nEnemies = 3;
		}
		if (GameRun == 5 && surv == 1)
		{
			SDL_BlitSurface(gSurvive, NULL, Tela, 0);
			SDL_UpdateWindowSurface(Window);
			SDL_Delay(2000);
			surv = 0;
			GameRun = 1;
		}
		SDL_UpdateWindowSurface(Window);
	}
	SDL_Quit();

	return 0;
}
