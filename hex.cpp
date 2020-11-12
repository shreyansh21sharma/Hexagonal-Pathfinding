#include<iostream>
#include<queue>
#include<list>
#include<algorithm>
#include<assert.h>
#include<vector>
#include<time.h>

using namespace std;

struct Hex 
{ // Cube storage, cube constructor
    int q, r, s;
    
	struct Hex *parent;
        Hex(int q_, int r_, int s_): q(q_), r(r_), s(s_) 
	{
	        assert (q + r + s == 0);
		parent=NULL;
	}
};

bool operator == (Hex a, Hex b) {
    return a.q == b.q && a.r == b.r && a.s == b.s;
}

Hex hex_add(Hex a, Hex b) {
    return Hex(a.q + b.q, a.r + b.r, a.s + b.s);
}

Hex hex_subtract(Hex a, Hex b) {
    return Hex(a.q - b.q, a.r - b.r, a.s - b.s);
}

Hex hex_multiply(Hex a, int k) {
    return Hex(a.q * k, a.r * k, a.s * k);
}

int hex_length(Hex hex) {
    return int((abs(hex.q) + abs(hex.r) + abs(hex.s)) / 2);
}

int hex_distance(Hex a, Hex b) {
    return hex_length(hex_subtract(a, b));
}

const vector<Hex> hex_directions = {
    Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
    Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
};

Hex hex_direction(int direction /* 0 to 5 */) {
    assert (0 <= direction && direction < 6);
    return hex_directions[direction];
}

Hex hex_neighbor(Hex hex, int direction) {
    return hex_add(hex, hex_direction(direction));
}

void printHex(Hex hex)
{
	std::cout<<"\nX:"<<hex.q<<"  Y:"<<hex.r<<"  Z:"<<hex.s;
}


int main()
{
int min;

struct Hex start(2,-1,-1);

struct Hex current(2,-1,-1);

struct Hex temp(0,0,0);

struct Hex goal(10,-5,-5);

queue<Hex> frontier;

frontier.push(start);

std::list<Hex> visited;

clock_t begin=clock();

while(!frontier.empty())
{
	
	current=frontier.front();
	
	frontier.pop();

	if(current==goal)
		{
			printHex(current);

			cout<<"\n\nThe destination has been found\n\n";		

			break;
		}
	
		#pragma omp for
		for(int i=0;i<6;i++)
		{
			temp=hex_neighbor(current,i);
			
			printHex(temp);
			
			bool found = (std::find(visited.begin(),visited.end(),temp)!=visited.end());

			if(!found)
			{

				frontier.push(temp);
	
				visited.push_front(temp);

				temp.parent=&current;
			}
		}
}

temp=start;	
cout<<"\nThe path is: \n";
printHex(temp);
cout<<"==>";
volatile bool flag=false;
while(hex_distance(temp,goal)!=0)
{

	#pragma omp parallel for shared(flag)
	for(int i=0;i<6;i++)
	{
	if(flag) continue;
	if(hex_distance(hex_neighbor(temp,i),goal)<hex_distance(temp,goal)){
	temp=hex_neighbor(temp,i);	
	printHex(hex_neighbor(temp,i)); cout<<"==>";	
	
	}	
	/*
		if(hex_distance(hex_neighbor(temp,i),goal)<hex_distance(hex_neighbor(temp,min),goal)){
		min=i;} */
}


}

printHex(temp);

clock_t end=clock();

cout<<"\nClock cycles taken: "<<float(end-begin)<<"\n";
return 0;
}
