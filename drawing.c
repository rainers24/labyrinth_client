#include <stdio.h>
#include <locale.h>
#include <ncurses.h>

int inputloop(void);
int handlemovement(int y, int x);
int drawmap(char *filename);
void drawplayer();
int startgame(void);

struct coordinate
{ 
  int x;
  int y;
  
};
struct coordinate player_pos;

int x = 1;
int y = 1;
WINDOW *win;
int currentlvl = 0;


char *levels[] = { "map_file.txt" };

int main(void) {

    setlocale(LC_ALL, "");

    initscr();
    win = newwin(72, 140, 0, 0);

    cbreak();

    noecho();

    nonl();

    intrflush(win, FALSE);

   
    keypad(win, TRUE);

    startgame();
    endwin();
    return 0;
}

int startgame() {
    
    drawmap(levels[currentlvl]);
    drawplayer();
    inputloop();
    return 0;
}


int drawmap(filename) char* filename; {
    wmove(win, 0, 0);
    FILE *fp;
    int c;
    fp = fopen(filename, "r");
    while (1) {
        c = fgetc(fp);
        if (feof(fp)) {
            break;
        }
        switch (c) {
                default:
                wprintw(win, "%c", c);
                break;
        }
    }
    fclose(fp);
    wmove(win, y, x);
    
    return 0;
}

int inputloop() {
    for (;;) {
        int next_y = y;
        int next_x = x;
        int keypress = wgetch(win);
        switch (keypress) {
            case 'q':
                return 0;
            case KEY_LEFT:
                next_x--;
                break;
            case KEY_DOWN:
                next_y++;
                break;
            case KEY_UP:
                next_y--;
                break;
            case KEY_RIGHT:
                next_x++;
                break;
        }
        if (handlemovement(next_y, next_x)) {
            break;
        }
        wrefresh(win);
    }

    return 0;
}

void drawplayer(){ // kkas neiet
  move( y , x);
  addch('a');
}


int handlemovement (int next_y, int next_x) {
    chtype nextchar = mvwinch(win, next_y, next_x);

    switch (nextchar) {
        case ' ':
            x = next_x;
            y = next_y;
            break;
            default:
            
            break;
    }
    wmove(win, y , x );
   
    
    return 0;
}

