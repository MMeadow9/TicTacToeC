#include <stdio.h>
#include <stdlib.h>

void print_table(char aa, char ab, char ac, char ba, char bb, char bc, char ca, char cb, char cc) {
    printf("\n       A     B     C\n");
    printf("    +-----+-----+-----+\n");
    printf(" A  |  %c  |  %c  |  %c  |\n", aa, ab, ac);
    printf("    +-----+-----+-----+\n");
    printf(" B  |  %c  |  %c  |  %c  |\n", ba, bb, bc);
    printf("    +-----+-----+-----+\n");
    printf(" C  |  %c  |  %c  |  %c  |\n", ca, cb, cc);
    printf("    +-----+-----+-----+\n");    
}


char is_game_over(char aa, char ab, char ac, char ba, char bb, char bc, char ca, char cb, char cc) {
    if (aa == ab && aa == ac && aa != '-') {
        return aa;
    }
    if (ba == bb && ba == bc && ba != '-') {
        return ba;
    }
    if (ca == cb && ca == cc && ca != '-') {
        return ca;
    }
    if (aa == ba && aa == ca && aa != '-') {
        return aa;
    }
    if (ab == bb && ab == cb && ab != '-') {
        return ab;
    }
    if (ac == bc && ac == cc && ac != '-') {
        return ac;
    }
    if (aa == bb && aa == cc && aa != '-') {
        return aa;
    }
    if (ca == bb && ca == ac && ca != '-') {
        return ca;
    }
    if (aa != '-' && ba != '-' && ca != '-' && ab != '-' && bb != '-' && cb != '-' && ac != '-' && bc != '-' && cc != '-') {
        return '~';
    }
    return '-';
    
}

int main() {
    system("clear");
    char aa='-', ab='-', ac='-', ba='-', bb='-', bc='-', ca='-', cb='-', cc='-';
    //      A    B    C
    //    +----+----+----+
    //  A | AA | AB | AC |
    //    +----+----+----+
    //  B | BA | BB | BC |
    //    +----+----+----+
    //  C | CA | CB | CC |
    //    +----+----+----+

    char mover = 'X';

    char x, y, z;

    int flag = 0;

    while (1) {
        if (is_game_over(aa, ab, ac, ba, bb, bc, ca, cb, cc) != '-') {
            break;
        }
        system("clear");
        print_table(aa, ab, ac, ba, bb, bc, ca, cb, cc);
        printf("Сейчас ходит %c:\n", mover);

        if (flag == 0) {
            scanf("%c%c", &x, &y);
            flag = 1;
        } else {
            scanf("%c%c%c", &z, &x, &y);
        }
        
        if (x == 'a' && y == 'a' && aa == '-') {
            aa = mover;
            mover = (mover == 'X') ? 'O': 'X';
        }
        if (x == 'a' && y == 'b' && ab == '-') {
            ab = mover;
            mover = (mover == 'X') ? 'O': 'X';
        }
        if (x == 'a' && y == 'c' && ac == '-') {
            ac = mover;
            mover = (mover == 'X') ? 'O': 'X';
        }
        if (x == 'b' && y == 'a' && ba == '-') {
            ba = mover;
            mover = (mover == 'X') ? 'O': 'X';
        }
        if (x == 'b' && y == 'b' && bb == '-') {
            bb = mover;
            mover = (mover == 'X') ? 'O': 'X';
        }
        if (x == 'b' && y == 'c' && bc == '-') {
            bc = mover;
            mover = (mover == 'X') ? 'O': 'X';
        }
        if (x == 'c' && y == 'a' && ca == '-') {
            ca = mover;
            mover = (mover == 'X') ? 'O': 'X';
        }
        if (x == 'c' && y == 'b' && cb == '-') {
            cb = mover;
            mover = (mover == 'X') ? 'O': 'X';
        }
        if (x == 'c' && y == 'c' && cc == '-') {
            cc = mover;
            mover = (mover == 'X') ? 'O': 'X';
        }
    }
    printf("Наш победитель - %c\n", is_game_over(aa, ab, ac, ba, bb, bc, ca, cb, cc));

    return 0;
    
}

