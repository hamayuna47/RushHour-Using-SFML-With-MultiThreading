
#include <SFML/Graphics.hpp>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
using namespace sf;
using namespace std;

class player
{
	public:
	string name;
	int scores;
	
};

void* inputdata(void* arg)
{
	player* pl = new player;	
	cout << "Please Enter Your Name: ";
	getline(cin,pl->name);
	pthread_exit((void*)pl);
	
}


void* updateval(void* arg)
{
	int* tempvals = (int*)arg;
	int tempxval1 =  tempvals[0];
	int tempyval1 =  tempvals[1];
	int tempxval2 =  tempvals[2];
	int tempyval2 =  tempvals[3];
	int count1 = tempvals[4];
	int count2 = tempvals[5];
	int cc = 6;
	bool flagtreasure[10]{false};
	
	vector <CircleShape> treas(10);
	
	for(int i =0 ; i< 10 ; i++)
	{
		treas[i].setPosition(Vector2f(tempvals[cc],tempvals[cc+10]));
		flagtreasure[i] = tempvals[cc+20];
		cc++;
	}
	
	int incx = 0;
	int incy = 0;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			tempyval1-=2;
			incy = -2;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			tempyval1+=2;
			incy = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			tempxval1-=2;
			incx = -2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			tempxval1+=2;
			incx = 2;
		}
		

	if( ( (tempxval1 > (tempxval2-20) && tempxval1 < (tempxval2+20))  && (tempyval1 > (tempyval2-20) && tempyval1 < (tempyval2+20)) ) )
			{
				tempxval1 = tempvals[0];
				tempyval1 = tempvals[1];	
				incx = 0;
				incy = 0;
			}
			
		
		for(int i =0 ; i < 10 ; i++)
		{
		if(flagtreasure[i]==false){
			if( ( (tempxval1 > (treas[i].getPosition().x-20) && tempxval1 < (treas[i].getPosition().x+20))  && (tempyval1 > (treas[i].getPosition().y-20) && tempyval1 < (treas[i].getPosition().y+20)) ) )
			{
				flagtreasure[i] = true;
				count1++;

			}
			
			}
		}
		

	int* pl = new int [16];
	pl[0] = tempxval1;
	pl[1] = tempyval1;
	pl[2] = incx; 
	pl[3] = incy;
	pl[4] = count1;
	pl[5] = count2;
	
	for(int i=0 ; i<10;i++)
	{
		pl[i+6] = flagtreasure[i];
	}
	
	pthread_exit((void*)pl);
	
}



void* updateval2(void* arg)
{
	int* tempvals = (int*)arg;
	int tempxval2 =  tempvals[2];
	int tempyval2 =  tempvals[3];
	int tempxval1 =  tempvals[0];
	int tempyval1 =  tempvals[1];
	
	int count1 = tempvals[4];
	int count2 = tempvals[5];
	int cc = 6;
	bool flagtreasure[10]{false};
	
	vector <CircleShape> treas(10);
	
	for(int i =0 ; i< 10 ; i++)
	{
		treas[i].setPosition(Vector2f(tempvals[cc],tempvals[cc+10]));
		flagtreasure[i] = tempvals[cc+20];
		cc++;
	}
	
	
	
	int incx1 = 0;
	int incy1 = 0;
	
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			tempyval2-=2;
			incy1 = -2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			tempyval2+=2;
			incy1 = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			tempxval2-=2;
			incx1 = -2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			tempxval2+=2;
			incx1 = 2;
		}
		
	
	if( ( (tempxval2 > (tempxval1-20) && tempxval2 < (tempxval1+20))  && (tempyval2 > (tempyval1-20) && tempyval2 < (tempyval1+20)) ) )
			{
				tempxval2 = tempvals[0];
				tempyval2 = tempvals[1];	
				incx1 = 0;
				incy1 = 0;
			}
			
				
		for(int i =0 ; i < 10 ; i++)
		{
		if(flagtreasure[i]==false){
			
			if( ( (tempxval2 > (treas[i].getPosition().x-20) && tempxval2 < (treas[i].getPosition().x+20))  && (tempyval2 > (treas[i].getPosition().y-20) && tempyval2 < (treas[i].getPosition().y+20)) ) )
			{
				flagtreasure[i] = true;
				count2++;

			}
			}
		}
	
	int* pl = new int [16];
	pl[0] = tempxval2;
	pl[1] = tempyval2;
	pl[2] = incx1;
	pl[3] = incy1;
	pl[4] = count1;
	pl[5] = count2;
	
	for(int i=0 ; i<10;i++)
	{
		pl[i+6] = flagtreasure[i];
	}
	
	pthread_exit((void*)pl);
	
}




int main()
{
	
	pthread_t t1,t2,t3,t4;		
	srand(time(0));	    
	int n=(rand()%90)+10;
	n=n*2;
	n=662/n;
	n=n%25;
	if(n<10)
	{
		n=n+15;
	}
	int arrsize= n;
	int xval =0;
	int yval=0;
	n*=n;
	
	vector <RectangleShape> gridarray(n);
	for(int i=0; i< n;i++)
	{
		if(i%arrsize == 0 && i!=0)
		{
			xval+=20;
			yval=0;
		}
		gridarray[i].setSize(Vector2f(20.f,20.f));
		gridarray[i].setPosition(Vector2f(xval,yval));
		gridarray[i].setFillColor(Color::White);
		yval+=20;
	}
	
	int boxgame = 20;
	int treasure = 10;
	bool flagtreasure[10]{false};
	
	vector <RectangleShape> boxes(boxgame);
	vector <CircleShape> treas(treasure);
	vector <CircleShape> players(2);
	
	
	players[0].setFillColor(Color::Red);
	players[0].setRadius(10);
	players[0].setPosition(Vector2f( gridarray[0].getPosition().x , gridarray[0].getPosition().y ));
	players[0].setPointCount(100);
	
	players[1].setFillColor(Color::Red);
	players[1].setRadius(10);
	players[1].setPosition(Vector2f( gridarray[n-1].getPosition().x , gridarray[n-1].getPosition().y ));
	players[1].setPointCount(100);
			
	int temparray[boxgame];

	
	for(int i =0 ; i<boxgame ; i++)
	{
		int temp=(rand()%(n-2))+1;
		boxes[i].setSize(Vector2f(20.f,20.f));
		boxes[i].setPosition(Vector2f( gridarray[temp].getPosition().x , gridarray[temp].getPosition().y ));
		boxes[i].setFillColor(Color::Black);
		temparray[i] = temp;
	}
	
	for(int i =0 ; i< treasure ; i++)
	{
		int temp=(rand()%(n-2))+1;
		bool flag =true;
		for(int j =0 ; j< boxgame;j++)
		{
			if(temp == temparray[j])
			{
				flag = false;
				i--;
			}
		}
		if(flag == true)
		{
			treas[i].setFillColor(Color::Cyan);
			treas[i].setRadius(10);
			treas[i].setPosition(Vector2f( gridarray[temp].getPosition().x , gridarray[temp].getPosition().y ));
			treas[i].setPointCount(3);
		}
		
	} 
	
	
	
	RenderWindow window(VideoMode(720,720),"Rush Hour NON-PTA");
	window.setFramerateLimit(60);		
	RectangleShape rec;
	rec.setSize(Vector2f(20.f,20.f));
	rec.setPosition(Vector2f(2,4));
	rec.setFillColor(Color::White);
	
	void* player1t;
	void* player2t;
	cout<<"\n*************** WELCOME TO Rush Hour NON-PTA ***************\n\n";
	cout<<"\n*************** INPUT MENU ***************\n\n";
	pthread_create(&t1,NULL,inputdata,NULL);
	pthread_join(t1,&player1t);
	
	pthread_create(&t2,NULL,inputdata,NULL);
	pthread_join(t2,&player2t);
	
	player* player1 = (player*)player1t;
	player* player2 = (player*)player2t;
	
	int count1 =0,count2=0,maxcount=0;
	bool endgame = false;
	while(window.isOpen()){
		
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type == Event::Closed)
			{
				window.close();
			}
		}
		if(endgame == false)
		{
		window.clear();
		}
		for(int i=0; i< n;i++)
		{
			
			window.draw(gridarray[i]);
			
			
		}
		
		boxes.push_back(RectangleShape());
		treas.push_back(CircleShape());
		players.push_back(CircleShape());
		if(endgame == false)
		{
		for(int i =0 ; i<boxgame ; i++)
		{
			window.draw(boxes[i]);
			
		}
		
		for(int i =0 ; i<treasure ; i++)
		{
			if(flagtreasure[i] == false){
			window.draw(treas[i]);
			}
			
		}
		
		}
		
		
		
		int tempxval1 = players[0].getPosition().x;
		int tempyval1 = players[0].getPosition().y;
		
		
		int tempxval2 = players[1].getPosition().x;
		int tempyval2 = players[1].getPosition().y;
		float incx=0,incy=0;
		float incx1=0,incy1=0;
		
		if(endgame == false)
		{
		window.draw(players[0]);
		window.draw(players[1]);
		}
		
		int*tempvals1 = new int[36];
		tempvals1[0] = tempxval1;
		tempvals1[1] = tempyval1;
		tempvals1[2] = tempxval2;
		tempvals1[3] = tempyval2;
		tempvals1[4] = count1;
		tempvals1[5] = count2;
		int cc = 6;
		for(int i=0; i< treasure ;i++)
		{
			tempvals1[cc]= treas[i].getPosition().x;
			cc++;
		}
		for(int i=0; i< treasure ;i++)
		{
			tempvals1[cc]= treas[i].getPosition().y;
			cc++;
		}
		for(int i=0; i< treasure ;i++)
		{
			tempvals1[cc]= flagtreasure[i];
			cc++;
		}

		
		
		pthread_t t5;
		void* playernew1;
		pthread_create(&t5,NULL,updateval,(void*)tempvals1);
		pthread_join(t5,&playernew1);
		int* rets = (int*)playernew1;
		tempxval1 = rets[0];
		tempyval1 = rets[1];
		incx = rets[2];
		incy = rets[3];
		count1 = rets[4];
		count2 = rets[5];
		
		tempvals1[4] = count1;
		tempvals1[5]  = count2;
		for(int i =0 ; i< treasure ; i++)
		{
			flagtreasure[i] = rets[i+6];
		}
		cc-=10;
		for(int i=0; i< treasure ;i++)
		{
			tempvals1[cc]= flagtreasure[i];
			cc++;
		}

		
		
		pthread_t t6;
		void* playernew2;
		pthread_create(&t6,NULL,updateval2,(void*)tempvals1);
		pthread_join(t6,&playernew2);
		int* rets2 = (int*)playernew2;
		tempxval2 = rets2[0];
		tempyval2 = rets2[1];
		incx1 = rets2[2];
		incy1 = rets2[3];
		
	
		count1 = rets2[4];
		count2 = rets2[5];
		
		for(int i =0 ; i< treasure ; i++)
		{
			flagtreasure[i] = rets2[i+6];

		}

		
		
		
		bool movflag1 =true;
		bool movflag2 =true;
		for(int i =0 ; i < boxgame ; i++)
		{
			if( ( (tempxval1 > (boxes[i].getPosition().x-20) && tempxval1 < (boxes[i].getPosition().x+20))  && (tempyval1 > (boxes[i].getPosition().y-20) && tempyval1 < (boxes[i].getPosition().y+20)) ) )
			{
				movflag1 = false;
			}
			if( ( (tempxval2 > (boxes[i].getPosition().x-20) && tempxval2 < (boxes[i].getPosition().x+20))  && (tempyval2 > (boxes[i].getPosition().y-20) && tempyval2 < (boxes[i].getPosition().y+20)) ) )
			{
				movflag2 = false;
			}
		}
		
		
		if( ( (tempxval1 < (gridarray[0].getPosition().x) )) )
			{
				movflag1 = false;
			}
		
		if( ( (tempxval1 > (20*(arrsize-1)) )) )
			{
				movflag1 = false;
			}
		
		if( ( (tempyval1 > (20*(arrsize-1)) )) )
			{
				movflag1 = false;
			}
		
		if( ( (tempyval1 < (gridarray[0].getPosition().y) )) )
			{
				movflag1 = false;
			}
		
		if( ( (tempxval2 < (gridarray[0].getPosition().x) )) )
			{
				movflag2 = false;
			}
		
		if( ( (tempxval2 > (20*(arrsize-1)) )) )
			{
				movflag2 = false;
			}
		
		if( ( (tempyval2 > (20*(arrsize-1)) )) )
			{
				movflag2 = false;
			}
		
		if( ( (tempyval2 < (gridarray[0].getPosition().y) )) )
			{
				movflag2 = false;
			}
			
				
			
			
			
			
		
		maxcount = count1+count2;
		if(movflag1 == true)
		{
			players[0].move(incx,incy);
		}
		if(movflag2 == true)
		{
			players[1].move(incx1,incy1 );
		}	
		
 		
 		
		
		if(maxcount>=10)
		{
			
			window.clear();
			endgame = true;
			

		
				string winner = "";
				sf::Text text;

				if(count1>count2)
				{
					winner+="CONGRATULATIONS!!! ";
					winner+= player1->name;
					winner+=" WON....";
				}
				else
				{
					winner+="CONGRATULATIONS!!! ";
					winner+= player2->name;
					winner+=" WON....";
				}
				
				Font font;

				if(!font.loadFromFile("BAUHS93.TTF"))
				{
				    cout << "can't load font" << endl;
				}
				text.setPosition(120,120);
				text.setFont(font);
				text.setString(winner);
				text.setCharacterSize(24);
				text.setFillColor(sf::Color::Red);
				text.setStyle(sf::Text::Bold | sf::Text::Underlined);

				window.draw(text);
		

		}
					
		window.display();	
	}
	if(count1> count2)
	{
		cout<<player1->name << " won.\n";
	}
	else
		cout<<player2->name << " won.\n";
	
}
