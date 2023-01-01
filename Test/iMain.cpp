# include "iGraphics.h"
char logo[13] = { "pic\\logo.bmp" };
char menu[13] = "pic\\menu.bmp";
#include <string>
#define screenwidth 900
#define screenheight 480
#define NUMBEROFFISH 5
#define JUMPLIMIT 50
int gamestate = 0;
int position[2];
char under[2][30] = { "pic\\unde1.bmp","pic\\under10.bmp" };
char bimage[2][16] = { "pic\\1.bmp", "pic\\2.bmp" };
int slice = 2;
int width = 900 / 2;
int mposx,  mposy;
char str[100] = "HUNGRY FISH";
int highscore;
bool musicon = true;
int x=0;
int y=0;
int dx = 10;
int dy = 10;
int r = rand()%255;
int g = rand() % 255;
int b = rand() % 155;
int collisionCount = 0;
int score = 0;
char scoretext[50];

int xbox=10;


void change();
/*
	function iDraw() is called again and again by the system.
*/

//shark**************
char shark[8][30] = { "pic\\shark1.bmp", "pic\\shark1.bmp" };
char sharkeat[4][20] = {  "pic\\sharkeat1.bmp","pic\\sharkeat2.bmp" };

int sharkcordinatex=0 ;
int sharkdx = 100;
int sharkdy = 30;
int sharkcordinatey=200 ;
int sharkindex = 0;
bool eat = false;
bool eatup = false;
bool  eatdown = false;

int sharkcordinateeat = 0;
bool eatposition = true;
int eatcounter = 0;


//fish********

char bigfish[4][50] = { "pic\\m.bmp", "pic\\bomb.bmp" , "pic\\m1.bmp","pic\\whale.bmp" };
struct s2{
	int fish1x=1;
	int fish1y=2;
	int fish1dx =20;
	int fish1dy =100;
	int fish1index;
	bool fishshow=true;
}s2;
char fish4[8][50] = { "pic\\fish1.1.bmp", "pic\\fish5.bmp", "pic\\nemo1.bmp", "pic\\bigfish.bmp", "pic\\fish2.bmp", "pic\\fish1.bmp", "pic\\fish1.2.bmp","pic\\dory.bmp" };
struct s{
	int fishx;
	int fishy;
	int fish1dx = 20;
	int fish1dy = 100;
	int fishindex;
	bool fishshow=true;
}s1;
s enemy[NUMBEROFFISH];
char diver[3][15] = { "pic\\diver1.bmp", "pic\\diver2.bmp", "pic\\diver3.bmp" };
int diverx;
int divery;
int diverdx = 10;
int diverdy = 100;
int diverindex;



void iDraw()
{


	//place your drawing codes here
	iClear();
	
	if (gamestate == 0){
		score = 0;
		iShowBMP(0, 0, logo);
	}

	if (gamestate == 1){
		score = score;
		iShowBMP(0, 0, menu);
		iShowBMP2(650, 300, "pic\\logo1.bmp", 0);
		iShowBMP2(700, 200, "pic\\play.bmp",0);
		iShowBMP2(715, 150, "pic\\level.bmp", 0);
		iShowBMP2(715, 100, "pic\\controls.bmp", 0);
		iShowBMP2(702, 50, "pic\\exit.bmp", 0);
	}

	
	if(gamestate==2){
		
		for (int i = 0; i < 2; i++)
		{
			iShowBMP(position[i], 0, bimage[i]);
		}



        
		if (s1.fishshow == true){
			iShowBMP2(s1.fishx, s1.fishy, fish4[s1.fishindex], 0);
		}
	
			
			iShowBMP2(0, 0, "pic\\under11.bmp", 0);
			if (s2.fishshow == true){
				iShowBMP2(s2.fish1x, s2.fish1y, bigfish[s2.fish1index], 0);
			}
			iShowBMP2(diverx, divery, diver[diverindex],0);
		
		


		if (eat){
			if (eat){
				iShowBMP2(sharkcordinatex, sharkcordinatey + sharkcordinateeat, sharkeat[1], 0);
			}
			else{
				iShowBMP2(sharkcordinatex, sharkcordinatey + sharkcordinateeat, shark[0], 0);
			}
		}
		else {
			if (!eatposition){
				iShowBMP2(sharkcordinatex, sharkcordinatey, shark[sharkindex], 0);

				if (eatcounter >= 2){
					eatcounter = 0;
					sharkindex = 0;
					eatposition = true;
				}
			}
			else{
				iShowBMP2(sharkcordinatex, sharkcordinatey, shark[1], 0);
			}
		}
		if ((sharkcordinatex + sharkdx>diverx && sharkcordinatex<diverx + diverdx) && (sharkcordinatey + sharkdy>divery && sharkcordinatey< divery + diverdy)){
			iShowBMP2(diverx, divery, "pic\\blood.bmp", 0);
			iShowBMP2(sharkcordinatex + 10, sharkcordinatey + 60, "pic\\50.bmp", 0);
		}
		if ((sharkcordinatex + sharkdx>s1.fishx && sharkdx<s1.fishx + s1.fish1dx) && (sharkcordinatey + sharkdy>s1.fishy && sharkdy< s1.fishy + s1.fish1dy)){
			iShowBMP2(s1.fishx, s1.fishy, "pic\\blood.bmp", 0);
			iShowBMP2(sharkcordinatex+10, sharkcordinatey+60, "pic\\10.bmp", 0);
		}
		sprintf_s(scoretext, "score: %d", score);
		iText(screenwidth - 200, iScreenHeight - 50, scoretext, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(33, 45, 54);
		if (score == 130){
			gamestate = 6;
		}
		
		
	}
	if (gamestate == 3){
		iShowBMP(0, 0, "pic\\select.bmp");
		}
			
	
	if (gamestate == 4){
		iShowBMP(0, 0, "pic\\control.bmp");
	}
	if (gamestate == 5){

		iShowBMP(0, 0, "pic\\game.bmp");
		score = score;
		sprintf_s(scoretext, "score: %d", score);
		iText(0, iScreenHeight - 50, scoretext, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(33, 45, 54);
	}
	if (gamestate == 6){
		iShowBMP(0, 0, "pic\\level1.bmp");
	}
	if (gamestate == 7){
		iShowBMP(0, 0, "pic\\c.bmp");
	}
	if (gamestate == -1){
		
		exit;
		if (musicon == true)
		{
			musicon = false;
			PlaySound(0, 0, 0);
		}
		
	}
	
	


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	printf("%d %d\n", mx, my);

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gamestate == 0){
			if (mx >= 0 && mx <= 900 && my >= 0 && my <= 400){
				gamestate = 1;
			}
		}
		if (gamestate == 1){
			if (mx >= 2 && mx <= 652 && my >= 177 && my <= 475){
				sharkcordinatex = 0;
				sharkcordinatey = 200;
				score = 0;

			}
		}
			if (gamestate == 1){
				if (mx >= 731 && mx <= 779 && my >= 205 && my <= 233){

					gamestate = 2;
				}
			}
			if (gamestate == 1){
				if (mx >= 718 && mx <= 813 && my >= 153 && my <= 177){
					gamestate = 3;
				}
			}
			if (gamestate == 1){
				if (mx >= 732 && mx <= 794 && my >= 109 && my <= 134){
					gamestate = 4;
				}
			}
			if (gamestate == 1){
				if (mx >= 732 && mx <= 794 && my >= 61 && my <= 81){
					gamestate = -1;
				}
			}
			if (gamestate == 3){
				if (mx >= 140 && mx <= 243 && my >= 251 && my <= 288){
					gamestate = 2;
				}
			}
			if (gamestate == 3){
				if (mx >= 276 && mx <= 372 && my >= 248 && my <= 290){
					gamestate = 7;
				}
			}
			if (gamestate == 5){
				score = 0;
				if (mx >= 718 && mx <= 737 && my >= 156 && my <= 165){
					sharkcordinatex = 0;
					sharkcordinatey = 200;
					gamestate = 2;
				}
			}
			if (gamestate == 5){
				if (mx >= 751 && mx <= 763 && my >= 156 && my <= 161){
					score = 0;
					gamestate = 0;
				}
			}
			if (gamestate == 6){
				if (mx >= 762 && mx <= 885 && my >= 84 && my <= 95){
					score = 0;
					gamestate = 7;
				}
			}

		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	if (key == ' '){
		if (!eat){
			eat = true;
			eatup = true;
		}
		else{
			eat = false;
			eatup = false;
		}
	}
	if (key == 'w')
	{
		sharkcordinatey += 10;
		void collisonCheck();
	}
	else if (key == 's'){

		sharkcordinatey -= 10;
		void collisonCheck();
	}
	else if (key == 'a'){
		sharkcordinatex -= 10;
		void collisonCheck();

		sharkindex--;
		if (sharkindex <0){
			sharkindex = 1;
			eatposition = false;
		}
	}
	else if (key == 'd'){
		sharkcordinatex += 10;
		void collisonCheck();
		sharkindex++;
		if (sharkindex >= 2){
		}

		sharkindex = 1;
	}
	if (key == 'm') //for music control
	{
		if (musicon == true)
		{
			musicon = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicon = true;
			PlaySound("music\\fish.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}

	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_UP)
	{
		sharkcordinatey += 20;
		void collisonCheck();
	}
	else if (key == GLUT_KEY_DOWN){

		sharkcordinatey -= 20;
		void collisonCheck();
	}
	else if (key == GLUT_KEY_LEFT){
		sharkcordinatex -= 20;
		void collisonCheck();

		sharkindex--;
		if (sharkindex <0){
			sharkindex = 1;
			eatposition = false;
		}
	}
	else if (key == GLUT_KEY_RIGHT){
		sharkcordinatex += 20;
		void collisonCheck();
		sharkindex++;
		if (sharkindex >= 2){
	}
	
		sharkindex = 1;
	}
	
	else if (key == GLUT_KEY_END){
		
		if (gamestate == 2){
		}

		gamestate = 1;
	}
	
	eatposition = false;
	//place your codes for other keys here
}

void collisonCheck(){
		if ((sharkcordinatex + sharkdx>s1.fishx && sharkdx<s1.fishx + s1.fish1dx) && (sharkcordinatey + sharkdy>s1.fishy && sharkdy< s1.fishy + s1.fish1dy)){
			score += 10;
			s1.fishx = 1500;
	}
		
	 if ((sharkcordinatex + sharkdx>diverx && sharkcordinatex<diverx + diverdx) && (sharkcordinatey + sharkdy>divery && sharkcordinatey< divery + diverdy)){
		 
		 score+=50;
		diverx = 3000;
	}
	 if ((sharkcordinatex + sharkdx>s2.fish1x && sharkcordinatex<s2.fish1x + s2.fish1dx) && (sharkcordinatey + sharkdy>s2.fish1y && sharkcordinatey< s2.fish1y + s2.fish1dy)){
		 
		 sharkcordinatex = 800;
		 gamestate = 5;
		 highscore = score;




	 }

else{

	}
}
void change2(){
	for (int i = 0; i < 2; i++){


		position[i] -= width;
		if (position[i] < 0)
		{
			position[i] = (slice*width) - width;
		}
	}
}

void change(){
	if (eat){
		
		if (sharkcordinateeat >= JUMPLIMIT){
			eatup = false;
		}
	}
	else{
		
		if (sharkcordinateeat < 0){
			eat = false;
			sharkcordinateeat = 0;
		}
	}


	
		s1.fishx -= 10;
		if (s1.fishx <= 0){
			s1.fishx = screenwidth + rand() % 10;

			s1.fishindex++;
			if (s1.fishindex >= 8){
				s1.fishindex = 0;

			}
		}
		s2.fish1x -= 10;
		if (s2.fish1x <= 0){
			s2.fish1x = screenwidth + rand() % 10;

			s2.fish1index++;
			if (s2.fish1index >= 4){
				s2.fish1index = 0;

			}
	}
		diverx -= 10;
		if (diverx <= 0){
			diverx = screenwidth + rand() % 65;

			diverindex++;
			if (diverindex >= 3){
				diverindex = 0;

			}
		}
			


	
}
void setEnemyvariables(){
		s1.fishx = screenwidth + rand() % 10;
		s1.fishy = 300 + rand() % 100;
		s1.fishindex = rand() % 8;
		s2.fish1x = screenwidth + rand() % 10;
		s2.fish1y =  rand() %40;
		s2.fish1index = rand() % 4;

		diverx = 1000 + rand() % 65;
		divery = 150 + rand() % 140;
		diverindex = rand() % 3;
	
}
void positionfunction(){
	int i, j;
	for (i = 0, j = 0; i < slice; i++)
	{
		position[i] = j;
		j += width;
	}
}

//
int main()
{
	positionfunction();
	iSetTimer(250, change2);
	setEnemyvariables();
	iSetTimer(65, change);
	iSetTimer(65, collisonCheck);
	if (musicon){
		PlaySound("music\\fish.wav", NULL, SND_LOOP|SND_ASYNC);
	}
	
	//place your own initialization codes here.
	iInitialize(screenwidth, screenheight, "demooo");
	return 0;
}
