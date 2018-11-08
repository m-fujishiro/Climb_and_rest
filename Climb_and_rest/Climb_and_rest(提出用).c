#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

void inn(int *damage, int *MHP, int *HP);
void ppak();
void Coord(int,int);
void print(int HP, int MHP,int prog);
void log();
void gameover();
void gamecomp();

COORD coord;

int main()
{
	int damage = 0, MHP = 100, HP = 100;
	int prog = 0;

	//上部に表示
	print(HP, MHP, prog);
	//雛型と初期メッセージ
	printf("0a Climb and get treasure!\n0b You  can rest some certain point.\n0c \n0d \n0e \n0f \n0g \n0h \n0i \n0j \n0k \n0l \n0m \n0n \n0o \n0p \n0q \n0r \n0s \n0t ");

	//入力を取得
	char user = 0;
	
	//脱出処理は書いているので無限ループ
	while (1) {

		user = _getch();

		if (user == 's') {
			prog--; HP -= prog; damage += prog;
		}
		else if (user == 'w') {
			prog++; HP -= prog; damage += prog;
		}

		if ( ((user == 's') || (user == 'w')) && 
		((prog <= 0) || (prog == 15) || (prog == 30) || (prog == 50) || (prog == 80) || (prog == 150) || (prog == 180) || (prog == 200) 
		|| (prog == 300) || (prog == 310) || (prog >= 500)) ){
			if (prog < 0)	prog = 0;
			if (prog > 500) prog = 500;

			while (damage >= 10)
			{
				MHP++;	damage -= 10;
			}
			HP = MHP; log(); printf("You rested up.Your are energetic!"); print(HP, MHP, prog);
		}
		if (prog >= 500) { gamecomp(); goto end; }
		else if ((user == 's') || (user == 'w')) {
			log(); printf("You climbed. Your energy was decrese of %d", prog); print(HP, MHP, prog);
		}
		if (HP <= 0) { gameover(); goto end; }
		ppak();

	}
end:
	ppak();
}

void ppak()
{
	while (1) {
		if (_kbhit()) { _getch(); }
		else break;
	};

	while (1) {
		if (_kbhit()) break;
	};
}


void gameover()
{
	int i = 0, k; Sleep(1000);

	char end[11][51] = {
		"◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆",
		"◆◇◇◇◇◇◇◆◇◆◆◆◆◆◆◆◇◆◇◇◇◇◆◆◆",
		"◆◇◆◆◆◆◆◆◇◇◆◆◆◆◆◆◇◆◇◆◆◆◇◆◆",
		"◆◇◆◆◆◆◆◆◇◆◇◆◆◆◆◆◇◆◇◆◆◆◆◇◆",
		"◆◇◆◆◆◆◆◆◇◆◆◇◆◆◆◆◇◆◇◆◆◆◆◇◆",
		"◆◇◇◇◇◇◆◆◇◆◆◆◇◆◆◆◇◆◇◆◆◆◆◇◆",
		"◆◇◆◆◆◆◆◆◇◆◆◆◆◇◆◆◇◆◇◆◆◆◆◇◆",
		"◆◇◆◆◆◆◆◆◇◆◆◆◆◆◇◆◇◆◇◆◆◆◆◇◆",
		"◆◇◆◆◆◆◆◆◇◆◆◆◆◆◆◇◇◆◇◆◆◆◇◆◆",
		"◆◇◇◇◇◇◇◆◇◆◆◆◆◆◆◆◇◆◇◇◇◇◆◆◆",
		"◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆"
	};

	for (i = 0; i < 20; i++)
	{
		Coord(0, i + 5); printf("0%c", i + 'a'); for (k = 0; k < 77; k++)putchar(32);
	}

	for (i = 0; i < 11; i++)
	{
		Coord(3, i + 10);	printf("%s\n", end[i]);
	}

	/*没ネタ集*/

	//配列のほうが綺麗な気がした
/*	Coord(3,5); 	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
	Coord(3,6); 	printf("◆◇◇◇◇◇◇◆◇◆◆◆◆◆◆◆◇◆◇◇◇◇◆◆◆\n");
	Coord(3,7); 	printf("◆◇◆◆◆◆◆◆◇◇◆◆◆◆◆◆◇◆◇◆◆◆◇◆◆\n");
	Coord(3,8); 	printf("◆◇◆◆◆◆◆◆◇◆◇◆◆◆◆◆◇◆◇◆◆◆◆◇◆\n");
	Coord(3,9); 	printf("◆◇◆◆◆◆◆◆◇◆◆◇◆◆◆◆◇◆◇◆◆◆◆◇◆\n");
	Coord(3,10);	printf("◆◇◇◇◇◇◆◆◇◆◆◆◇◆◆◆◇◆◇◆◆◆◆◇◆\n");
	Coord(3,11);	printf("◆◇◆◆◆◆◆◆◇◆◆◆◆◇◆◆◇◆◇◆◆◆◆◇◆\n");
	Coord(3,12);	printf("◆◇◆◆◆◆◆◆◇◆◆◆◆◆◇◆◇◆◇◆◆◆◆◇◆\n");
	Coord(3,13);	printf("◆◇◆◆◆◆◆◆◇◆◆◆◆◆◆◇◇◆◇◆◆◆◇◆◆\n");
	Coord(3,14);	printf("◆◇◇◇◇◇◇◆◇◆◆◆◆◆◆◆◇◆◇◇◇◇◆◆◆\n");
	Coord(3,15);	printf("◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
*/

	//長すぎて入らなかった
/*	printf("   MMMMMOWMMMMM          MMMMMMM       jMMMMW             MMMMMs tHNDDWMMMMMMMMM\n");
	printf("jMMMMMMMvDMMMMMMMl      MMMMMMMM2      M4WMMMM           MMMMaWM MMMM46NNzNNNNBN\n");
	printf("MMMMM        MMMMMc    WMMMM7MMMMv     MM7lMMjNj        zWMMjMMM NlMMD          \n");
	printf("MMMW                  nMMMM2 MMMMMj    MM2  6EWMW     MMMMMhMMMMjhWDMHDNMBMMBMMH\n");
	printf("MjM2      jjj         DMMMM   MMMMM    MBMMW WMMMMj  MMMM2 MMMMM MWMj WMWMMMMMMM\n");
	printf("MMWMj    WMMMMMMMMMj MMMMMlEEHWMMMMM   MMMMW   MMMM MMMMj  MMMMM WNMM5          \n");
	printf("MMMMMj    j jWMMMMt WMMMMhWMMMMMMMMMs  MMMMW    MMM MMM    WMMMM MMMvD          \n");
	printf(" MMBMMMMj MMMMMMMj 6MMMMM       MMMMMv MMMMM     WM M7     MMMMM MMMMH 6BHWWOWD6\n");
	printf("   HMMM674MMMMM    BMMMMj       tMMMMMjMMMMM               MMMMM Wl M4NvWMMMMWWM\n");
	printf("                                                                                \n");
	printf("        MMMMvMMMMl      MM6M7         MhMMMBjMMMvMMMMMMMMMMjMMMMM1MsMMMMM j     \n");
	printf("     MMMMMMMvMMMMMMMv   4MMMMl       WMMMM  WMMM1MMMMMMMMMMjMWWNM4WMMMMWMMM5t   \n");
	printf("   4MMMMM       MMMMMM   WMMMMj     EMMMMl NNM5M1           MMMMM       MMMMW   \n");
	printf("   MMMMM         lMMDMj   MMMMM    jMWMMc  BMOMM1           MMMWM       MMMMM   \n");
	printf("  BBMMM7          s4MBM    MM5MM   MMMMh   BMMMMjMMMMMMMMMc WMMMM4MMMMMMMMWs    \n");
	printf("  cMMMMa          WWMMM     MMMMh MMMWM    N4WzW1j       j  MMNMM4MMMMNMMMMj    \n");
	printf("   MOWMMj        WMMMMc     jMWMM MMMM     BMMMM1           MEtMM      MMMMM    \n");
	printf("    MMMMaMj    WMMMMM1       DMMM MMMj     BMMMM1           MMMMM         MM    \n");
	printf("      MMMMMN 5MMMMM2          WMM MMv      BWWMWvllMMMMOMDB7WMMBj       4MnMM   \n");
	printf("       j  MB1WMv               MM Mn       Hh NMjWWWN5BMWMMtWDWOW       jl BM   ");
	Sleep(1000);*/

}

void gamecomp()
{
	int i = 0, j = 0, k; Sleep(1000);

	char end[1][300] = {
		"          ∧＿∧                                \n"
		"　／＼（　・∀・）／ヽ       　   ∧＿∧        \n"
		"（ ●　と　　　つ　● ）　／＼（　・∀・）／ヽ  \n"
		"　＼/⊂、　 　ノ　＼ノ  （ ●　と　　　つ　● ）\n"
		"　　　　　し’          　＼/⊂、　 　ノ　＼ノ  \n"
		"                        　　　　　し’          "
	};

	for (i = 0; i < 20; i++)
	{
		Coord(0, i + 5); for (k = 0; k < 77; k++)putchar(32);
	}

	for (i = 0; i<3; i++) {
		Coord(0, 7 * i + 5);	printf("%s", end[0]);
	}
	Sleep(1000);
	gameover();
}

void Coord(int x,int y)
{
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print(int HP,int MHP,int prog)
{
	Coord(0, 0);
	printf("energy %08d/%08d point:%03d/500\n", HP, MHP, prog);
	printf("\nw key : go s key : back\n\n");
	printf("　―log message―　");
	Coord(0, 5);
}

void log()
{
	static int i = 1; static int j = 0; int k;
	i++; if (i > 19) { i = 0; j++; }
	if (j >= 10)j = 0;
	Coord(0, i + 5);	putchar(j + 48);
	putchar(i + 97);
	for (k = 0; k < 77; k++)putchar(32);
	Coord(3, i + 5);
}

/*
<製作メモ>
・1ページ80文字*25行
・しかし使えるのは5行目の4文字目から,つまり77*20使える
*/

