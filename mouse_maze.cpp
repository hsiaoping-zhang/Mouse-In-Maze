#include <iostream>
#include <stack>
using namespace std;
int row,column;  
int direction_x[8]={ 0, 1,1,1,0,-1,-1,-1};
int direction_y[8]={-1,-1,0,1,1, 1, 0,-1};
int main(){
	int x,y;
	//use type of stack to store the route of x and y position
	stack<int> route_x;
	stack<int> route_y;
	while(cin>>y>>x){
		char disk[y][x]={'0'};
		int start_x,start_y,end_x,end_y;
		//input the assigned disk
		for(int i=0;i<y;i++){
			for(int j=0;j<x;j++){
				cin>>disk[i][j];
				if(disk[i][j]=='s'){  //the first step
					start_x=j;
					start_y=i;
					route_x.push(j);
					route_y.push(i);
				}
				else if(disk[i][j]=='d'){  //ended position
					end_x=j;
					end_y=i;
				}
			}
		}
		int current_x=start_x,current_y=start_y;
		bool found=false;  //whether the exit is founded
		int step;
		for(step=2;!found;step++){ //step is 2 because the first step is 's' already
			bool step_found=false;
			//update variables by taking top data
			current_x=route_x.top();
			current_y=route_y.top();
			for(int num=0;num<8;num++){
				int new_x=current_x+direction_x[num],new_y=current_y+direction_y[num];
				if(new_x>=0&&new_x<x&&new_y>=0&&new_y<y){  //inside the disk
					if(disk[new_y][new_x]=='0'){  //one possible next position
						route_x.push(new_x);
						route_y.push(new_y);
						disk[current_y][current_x]='*'; //current position has been passed
						step_found=true;  //one of 8 direction is valid for the current position
						break;  //find the next step's next step
				    }
				    else if(disk[new_y][new_x]=='d'){  //find the exit
				    	found=true;  //allow to jump out the exteral for loop
						route_x.push(new_x);
						route_y.push(new_y);
						disk[current_y][current_x]='*';
						step_found=true;
				    	break;
				    }
				}
			}
			if(step_found==false){
				if(step==2){  //there is no next step when the mouse return to first position
				    cout<<"No route"<<endl;
				    break;
				} 
				else{
					disk[current_y][current_x]='1';  //there is no route ,so the mouse return the previous step
					route_x.pop();
					route_y.pop();
					step-=2;  //-2 because when update the for loop will be plus 1 
				}
			}
			disk[start_y][start_x]='s';  //allow the revised start position to be marked as 's'
			//output the result
			if(found==true){
				for(int a=0;a<y;a++){
					for(int b=0;b<x;b++){
						cout<<disk[a][b];
					}
					cout<<endl;
				}
				cout<<step<<" steps"<<endl;
			}
		}
	}
}
