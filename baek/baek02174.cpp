#include <stdio.h>

int mat[101][101], robot[101][3]; // x, y, dir
int width, height, bot_cnt, ins_cnt, x, y, bot_ind, repeat;
char dir, action;

int
crashed_into_robot(int x, int y)
{
	int new_x, new_y;

	for(int j = 1; j <= repeat; j++){
		new_x = robot[bot_ind][0] + (j * x);
		new_y = robot[bot_ind][1] + (j * y);
		if(new_x > width || new_x < 1 || new_y > height || new_y < 1){
			printf("Robot %d crashes into the wall\n", bot_ind);
			return 1;
		}
		if(mat[new_y][new_x] != 0){
			printf("Robot %d crashes into robot %d\n", bot_ind, mat[new_y][new_x]);
			return 1;
		}
	}
	return 0;
}

void
update_pos(int x, int y)
{
	mat[robot[bot_ind][1]][robot[bot_ind][0]] = 0;
	robot[bot_ind][0] += x * repeat;
	robot[bot_ind][1] += y * repeat;
	mat[robot[bot_ind][1]][robot[bot_ind][0]] = bot_ind;
}


int 
main()
{
	for(int i = 1; i < 101; i++){
		for(int j = 1; j <= 101; j++) mat[i][j] = 0;
	}
	for(int i = 1; i < 101; i++) robot[i][0] = robot[i][1] = robot[i][2] = 0;

	scanf("%d %d", &width, &height);
	scanf("%d %d", &bot_cnt, &ins_cnt);
	for(int i = 1; i <= bot_cnt; i++){
		scanf("%d %d %c", &x, &y, &dir);
		mat[y][x] = i;
		robot[i][0] = x; robot[i][1] = y;
		if(dir == 'S') robot[i][2] = 0;
		else if(dir == 'E') robot[i][2] = 1;
		else if(dir == 'N') robot[i][2] = 2;
		else if(dir == 'W') robot[i][2] = 3;
	}
	for(int i = 0; i < ins_cnt; i++){
		scanf("%d %c %d", &bot_ind, &action, &repeat);
		if(action == 'F'){
			if(robot[bot_ind][2] == 0){ // upward
				if(crashed_into_robot(0, -1)) return 0;
				else update_pos(0, -1);
			}
			else if(robot[bot_ind][2] == 2){ // downward
				if(crashed_into_robot(0, 1)) return 0;
				else update_pos(0, 1);
			}
			else if(robot[bot_ind][2] == 1){ // right
				if(crashed_into_robot(1, 0)) return 0;
				else update_pos(1, 0);
			}
			else if(robot[bot_ind][2] == 3){ // left
				if(crashed_into_robot(-1, 0)) return 0;
				else update_pos(-1, 0);
			}
		}
		else if(action == 'R'){
			robot[bot_ind][2] = (robot[bot_ind][2] + 4 - (repeat % 4)) % 4;
		}
		else if(action == 'L'){
			robot[bot_ind][2] = (robot[bot_ind][2] + repeat) % 4;
		}
	}
	printf("OK\n");
}
