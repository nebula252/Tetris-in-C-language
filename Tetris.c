#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
// one step at a time;
int position[20][10],px=4,py=0,ppx,ppy,tick,times=60,shape=5,rotation=1,lv=0,kill=1,score=0;
int i,a,temp,temp2,temp3;
int right,left,hdown,down=1,turn,placementX[4],placementY[4];
void gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void gamestart(){
	for(i=0;i<20;i++){
		printf("<!");
		for(a=0;a<10;a++){
			printf(" .");
			
			}
		printf("!>\n");
		}
	printf("<!====================!>");
	
}
void gameupdate(){
	for(i=0;i<20;i++){
		gotoxy(22,i);
		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		for(a=0;a<10;a++){
			if(position[i][a]==1){
				printf("[]");
			}
			if(position[i][a]==0){
				printf(" .");
			}
		}
	}
	gotoxy(24,0);

}
void gravity(){
	times=60-(lv*5);
	int num=0,b,c,score=0;
	if(tick>=times&&down==1){
		py++;
		tick=0;
	}
	if(down==0){
		if(py==0){
			kill=0;
		}
		shape=rand()%7 +1;
		py=0;
		ppy=0;
		px=4;
		ppx=4;
		for(i=0;i<20;i++){
			for(a=0;a<10;a++){
				if(position[i][a]==1){
					num++;
				}
			}
			if(num==10){
				for(b=0;b<10;b++){
					position[i][b]=0;
				}
				for(a=0;a<i;a++){
					c=i-a;
					for(b=0;b<10;b++){
						if(position[c][b]==1){
							position[c][b]=0;
							position[c+1][b]=1;
						}
					}
				}
			}
			num=0;
		}
	}
}
void tshape(int turn){
	int l = turn%2;
	int plus=0;
	switch(shape){
		case 1://I [][|][][]
			switch(l){
				case 0:
					for(i=0;i<4;i++){
						placementY[i]=0;
						placementX[i]=i-1;
					}
					
					break;
				case 1:
					for(i=0;i<4;i++){
						placementX[i]=0;
						placementY[i]=i-1;
					}
					
					break;
			}
			break;
		case 2://O[|][]
		       // [] []
		       		placementY[0]=0;placementX[0]=0;
		       		placementY[1]=0;placementX[1]=1;
		       		placementY[2]=1;placementX[2]=0;
		       		placementY[3]=1;placementX[3]=1;
			break;
		case 3://Z
			switch(l){
				case 0:
					placementY[0]=0;placementX[0]=-1;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=1;placementX[2]=0;
		       		placementY[3]=1;placementX[3]=1;
					break;
				case 1:
					placementY[0]=-1;placementX[0]=0;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=0;placementX[2]=-1;
		       		placementY[3]=1;placementX[3]=-1;
					break;
			}
			break;
		case 4://S
			switch(l){
				case 0:
					placementY[0]=0;placementX[0]=1;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=1;placementX[2]=0;
		       		placementY[3]=1;placementX[3]=-1;
					break;
				case 1:
					placementY[0]=-1;placementX[0]=0;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=0;placementX[2]=1;
		       		placementY[3]=1;placementX[3]=1;
					break;
			}
			break;
		case 5://L
			switch(turn){
				case 1:
					placementY[0]=-1;placementX[0]=0;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=1;placementX[2]=0;
		       		placementY[3]=1;placementX[3]=1;
					break;
				case 2:
					placementY[0]=0;placementX[0]=-1;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=0;placementX[2]=1;
		       		placementY[3]=1;placementX[3]=-1;
					break;
				case 3:
					placementY[0]=-1;placementX[0]=-1;
		       		placementY[1]=-1;placementX[1]=0;
		       		placementY[2]=0;placementX[2]=0;
		       		placementY[3]=1;placementX[3]=0;
					break;
				case 4:
					placementY[0]=0;placementX[0]=-1;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=0;placementX[2]=1;
		       		placementY[3]=-1;placementX[3]=1;
					break;
			}
			break;
		case 6://J
			switch(turn){
				case 1:
					placementY[0]=-1;placementX[0]=0;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=1;placementX[2]=0;
		       		placementY[3]=1;placementX[3]=-1;
					break;
				case 2:
					placementY[0]=0;placementX[0]=-1;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=0;placementX[2]=1;
		       		placementY[3]=-1;placementX[3]=-1;
					break;
				case 3:
					placementY[0]=-1;placementX[0]=0;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=1;placementX[2]=0;
		       		placementY[3]=-1;placementX[3]=1;
					break;
				case 4:
					placementY[0]=0;placementX[0]=-1;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=0;placementX[2]=1;
		       		placementY[3]=1;placementX[3]=1;
					break;
			}
			break;
		case 7://T
			switch(turn){
				case 1:
					placementY[0]=0;placementX[0]=-1;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=0;placementX[2]=1;
		       		placementY[3]=-1;placementX[3]=0;
					break;
				case 2:
					placementY[0]=-1;placementX[0]=0;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=1;placementX[2]=0;
		       		placementY[3]=0;placementX[3]=1;
					break;
				case 3:
					placementY[0]=0;placementX[0]=-1;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=0;placementX[2]=1;
		       		placementY[3]=1;placementX[3]=0;
					break;
				case 4:
					placementY[0]=-1;placementX[0]=0;
		       		placementY[1]=0;placementX[1]=0;
		       		placementY[2]=1;placementX[2]=0;
		       		placementY[3]=0;placementX[3]=-1;
					break;
			}
			break;
	}
	
}
void shape2(int x,int y,int bit){
	position[y+placementY[0]][x+placementX[0]]=bit;
	position[y+placementY[1]][x+placementX[1]]=bit;
	position[y+placementY[2]][x+placementX[2]]=bit;
	position[y+placementY[3]][x+placementX[3]]=bit;
}
void sensordown(){
	int compare=-3,compare2=3;
	for(i=0;i<4;i++){
		if(placementX[i]>compare){//biggest
			compare=placementX[i];
		}
		if(placementX[i]<compare2){//smallest
			compare2=placementX[i];
		}
	}
	int bottom=-3,count=0;
	for(i=compare2;i<=compare;i++){//range
		for(a=0;a<4;a++){//scan
			if(placementX[a]==i){
				if(placementY[a]>bottom){
					bottom=placementY[a];
			}
		}
	}
		if(position[py+bottom+1][px+i]==1){
			count++;
		}
		bottom=-3;
	}
	int floor=0;
	for(i=0;i<4;i++){
		if(placementY[i]>floor){
			floor=placementY[i];
		}}
	if(py+floor<19&&count==0){
		hdown=1;
		down=1;
	}
	else{
		down=0;
		hdown=0;
	}
}
void sensorleft(){
	int compare=-3,compare2=3;
	for(i=0;i<4;i++){
		if(placementY[i]>compare){//biggest
			compare=placementY[i];
		}
		if(placementY[i]<compare2){//smallest
			compare2=placementY[i];
		}
	}
	int bottom=3,count=0;
	for(i=compare2;i<=compare;i++){//range
		for(a=0;a<4;a++){//scan
			if(placementY[a]==i){
				if(placementX[a]<bottom){
					bottom=placementX[a];
			}
		}
	}
		if(position[py+i][px+bottom-1]==1){
			count++;
		}
		bottom=3;
	}
	int floor=3;
	for(i=0;i<4;i++){
		if(placementX[i]<floor){
			floor=placementX[i];
		}}
	if(px+floor>0&&count==0){
		left=1;
	}
	else{
		left=0;
	}
}
	
void sensorright(){
	int compare=-3,compare2=3;
	for(i=0;i<4;i++){
		if(placementY[i]>compare){//biggest
			compare=placementY[i];
		}
		if(placementY[i]<compare2){//smallest
			compare2=placementY[i];
		}
	}
	int bottom=-3,count=0;
	for(i=compare2;i<=compare;i++){//range
		for(a=0;a<4;a++){//scan
			if(placementY[a]==i){
				if(placementX[a]>bottom){
					bottom=placementX[a];
			}
		}
	}
		if(position[py+i][px+bottom+1]==1){
			count++;
		}
		bottom=-3;
	}
	int floor=-3;
	for(i=0;i<4;i++){
		if(placementX[i]>floor){
			floor=placementX[i];
		}}
	if(px+floor<9&&count==0){
		right=1;
	}
	else{
		right=0;
	}
}

void control(){
	char input;
	int trigger=1,cap=py;
	if(kbhit()){
		input = getch();
		switch(input){
			case ' ':
				if(down=1){
				for(i=cap;i<20;i++){
					py++;
					tshape(rotation);
					sensorleft();
					sensorright();
					sensordown();
					if(down==0){
						break;
					}
				}
			}
			break;
			case 'a':
				if(left==1){
					px--;
				}
				break;
			case 'd':
				if(right==1){
					px++;
				}
				break;
			case 's':
				if(down==1){
					py++;
				}
				break;
			case 'w':
				switch(rotation){
					case 4:
						tshape(rotation);
						shape2(px,py,0);
						shape2(ppx,ppy,0);
						tshape(1);
						sensordown();
						sensorright();
						sensorleft();
						tshape(rotation);
						rotation=1;
						if(down==0){
							py--;
						}
						if(right==0){
							px--;
						}
						if(left==0){
							px++;
						}
						if(down==0&&right==0&&left==0){
							rotation=4;
							py++;
						}
						sensordown();
						sensorright();
						sensorleft();
						tshape(rotation);
						shape2(px,py,1);
						shape2(ppx,ppy,1);
						break;
					default:
						tshape(rotation);
						shape2(px,py,0);
						shape2(ppx,ppy,0);
						tshape(rotation+1);
						sensordown();
						sensorright();
						sensorleft();
						tshape(rotation);
						rotation++;
						if(down==0){
							py--;
						}
						if(right==0){
							px--;
						}
						if(left==0){
							px++;
						}
						if(down==0&&right==0&&left==0){
							rotation--;
							py++;
						}
						sensordown();
						sensorright();
						sensorleft();
						tshape(rotation);
						shape2(px,py,1);
						shape2(ppx,ppy,1);
						break;
				}
		}
	}
}
void start(){
	gotoxy(8,8);
	printf("[]");
	gotoxy(8,9);
	printf("���֬��ڬ�");
	gotoxy(18,10);
	printf("[]");
	gotoxy(0,19);
	printf("������ \n��������������? (0-9) -");
	scanf("%d",&lv);
	gotoxy(0,0);
}
void main(void){
	time_t seconds;
	time(&seconds);
	srand(seconds);
	shape=rand()%7 +1;
	start();
	gamestart();
	while(1){
		if(kill==0){
			break;
		}
		tshape(rotation);
		sensordown();
		sensorleft();
		sensorright();
		control();
		shape2(ppx,ppy,0);
		shape2(px,py,1);
		ppx=px;
		ppy=py;
		gravity();
		gameupdate();
		tick++;
	}
	scanf("%d",&i);
}