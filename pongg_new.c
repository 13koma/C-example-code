#include <stdio.h>

int move_ball();
int draw();
int move_rackets();

int width = 80;
int height = 25;
int xball = 40;
int yball = 12;
int racket_p_one = 10;
int racket_p_two = 10;
int dxball = -1;
int dyball = 1;
int win1 = 0;
int win2 = 0;
char move;
char space;


int draw()
{

	printf("\33c\e[3J");
	int w, h;
	for (h = 0; h < height; h++) {
		for (w = 0; w < width; w++) {
			if (w == 0 || w == width-1 || h == 0 || h == height-1) printf("#");
			else if (h == 3 && ((win1 < 10 && w == 39)||(win2 < 10 && w == 41))) {
						if(w == 39) printf("%d", win1);
						if(w == 41) printf("%d", win2);
					} else if (h == 3 && ((win1 >= 10 && w == 37)||(win2 >= 10 && w == 41))) {
								if(w == 37) printf("%d", win1);
								if(w == 41) printf("%d", win2);
								w++;
							} else if (w == 4 && (racket_p_one == h || racket_p_one + 1 == h || racket_p_one + 2 == h)) printf("[");
								else if (w == 75 && (racket_p_two == h || racket_p_two + 1 == h || racket_p_two + 2 == h)) printf("[");
										else if (w == xball && h == yball) printf("o");
											else printf(" ");
		}
		printf("\n");
	}



return 0;
}

int move_ball()
{
	xball += dxball;
	yball += dyball;

	if (xball == 5 && (yball == racket_p_one || yball == racket_p_one+1 
	|| yball == racket_p_one+2 || yball == racket_p_one+3 || yball == racket_p_one-1 )) {
		dxball = - dxball;
	}
	if (xball == 74 && (yball == racket_p_two || yball == racket_p_two+1 
	|| yball == racket_p_two+2 || yball == racket_p_two+3 || yball == racket_p_two-1)) {
		dxball = - dxball;
	}
	if (yball == 1 || yball == 23) {
	dyball = - dyball;
	}
	if (xball == 1) {
	win2++;
	xball = 40;
	yball = 12;
	racket_p_one = 10;
	racket_p_two = 10;
	}
	if (xball == 79) {
	win1++;
	xball = 40;
	yball = 12;
	racket_p_one = 10;
	racket_p_two = 10;
	}
	return 0;
}

int move_rackets(){
	char move;
	char space;
	
	scanf("%c%c", &move, &space);
		
		
	if (move == 'a'){ // движение вверх левой ракетки
   		if (racket_p_one == 1){
	    	return 0;
		}     
		racket_p_one += -1;
	} else if (move == 'z'){ //движение вниз левой ракетки
            	if (racket_p_one == 21){
                	return 0;
            	}
            	racket_p_one += 1;
        	} else if (move == 'k') { // движение вверх правой ракетки
                    	if (racket_p_two == 1){
                        	return 0;
                    	}
                    	racket_p_two += -1;
                	} else if (move == 'm'){ //движение вниз правой ракетки
                            	if (racket_p_two == 21){
                                	return 0;
                            	}
                            	racket_p_two += 1;
                        	}
	
return 0;
}

int main()
{
	while (1) {	
		draw();
		move_ball();
		move_rackets();
	}
	return 0;
}
