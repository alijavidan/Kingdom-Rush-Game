#include "rsdl.hpp"
#include <sys/time.h>
#include <vector>

using namespace std;

const int Window_Width=800 , Window_Height=800;

double down_scale_width = 0.47505938;
double down_scale_height = 0.47477745;

int x,y;

Window w ( Window_Width , Window_Height );


vector<int> i;
vector<int> j;
vector<string> whattomove;


// #<Section_Detector


int Section_Detector ( int x , int y ) {


		if ( y <= 620 && y >= 600 ) {  
			if ( x > 1210 && x <= 1675 ) 
				return 1;
		}

		if ( y <= 600 && y >= 350 ) {
			if ( x > 1125 && x <= 1210 )
				return 2;
		}

		
		if ( y <= 350 && y >= 290 ) {  
			if ( x > 1005 && x <= 1125 ) 
				return 3;
		}


		if ( y <= 335 && y >= 290 ) {  
			if ( x > 925 && x <= 1005 ) 
				return 4;

		}

		if ( y <= 595 && y >= 335 ) {  
			if ( x > 810 && x <= 925 )  
				return 5;
		}


		if ( y <= 640 && y >= 595 ) {  
			if ( x > 550 && x <= 810 ) 
				return 6;
		}

		if ( y <= 715 && y >= 640 ) {  
			if ( x > 465 && x <= 550 ) 
				return 7;
		}

		if ( y <= 865 && y >= 715 ) {  
			if ( x >= 465 && x < 485 ) 
				return 8;
		}

		if ( y <= 930 && y >= 865 ) {  
			if ( x >= 485 && x < 635 ) 
				return 9;
		}


		if ( y <= 930 && y >= 875 ) {  
			if ( x >= 635 && x < 920 ) 
				return 10;
		}

		if ( y <= 955 && y >= 875 ) {  
			if ( x >= 920 && x < 1050 ) 
				return 11;
		}

		if ( y <= 1150 && y >= 955 ) {  
			if ( x > 990 && x <= 1050 ) 
				return 12;
		}

		if ( y <= 1250 && y >= 1150 ) {  
			if ( x > 750 && x <= 990 ) 
				return 13;
		}

		if ( y <= 1700 && y >= 1250 ) {  
			if ( x > 700 && x <= 750 ) 
				return 14;
		}

}

// #Section_Detector>


// #<tower

bool check_if_is_strategic ( int x , int y ) {

	return true; 

}


void build_tower ( char chr , int x , int y ) {

	const int tower_size = 50;

	if ( chr == 'a' ) 
		w.draw_png ( "towers/archer.png" , x , y , tower_size , tower_size );
		else if ( chr == 'c' )
			w.draw_png ( "towers/canon.png" , x , y , tower_size , tower_size );
			else if ( chr == 'm' )
				w.draw_png ( "towers/mage.png" , x , y , tower_size , tower_size );
		
	w.update_screen ( );

}

// #tower>


// #<print

void print ( vector<string> whattoprint , vector<int> x , vector<int> y ) {

	int enemy_size = 25;

	string str_1 = "orc";
	string str_2 = "armored";
	string str_3 = "wolf";
	string str_4 = "demon";
	
	w.draw_png ( "levels/1/level1-map.png" , 0 , 0 , 800 , 800 );

	int Mouse_X , Mouse_Y;

	for ( int c = 0; c < whattoprint.size ( ); c++ ) {

	x[c] *= down_scale_width;
	y[c] *= down_scale_height;

	if ( whattoprint[c] == str_1 )
			
		w.draw_png ( "enemies/orc/right.png" , x[c] , y[c]  , enemy_size , enemy_size );
				
		else if ( whattoprint[c] == str_2 )

			w.draw_png ( "enemies/armored/right.png" , x[c] , y[c]  , enemy_size , enemy_size );
			
				else if ( whattoprint[c] == str_3 )

					w.draw_png ( "enemies/wolf/right.png" , x[c] , y[c]  , enemy_size , enemy_size);

						else if ( whattoprint[c] == str_4 )

							w.draw_png ( "enemies/demon/right.png" , x[c] , y[c]  , enemy_size , enemy_size );
			
	}

	w.update_screen ( );

	Event My_Event = w.pollForEvent ( );

	if ( My_Event.type ( ) == LCLICK ) {
		
		Mouse_X = My_Event.mouseX ( );
		Mouse_Y = My_Event.mouseY ( );

	}

	if ( My_Event.type ( ) == KEY_PRESS ) {

		if ( My_Event.pressedKey ( ) == 'a' ) {
			if ( check_if_is_strategic ( Mouse_X , Mouse_Y ) ) 
				build_tower ( 'a' , Mouse_X , Mouse_Y );

			} else if ( My_Event.pressedKey ( ) == 'c' ) {
				if ( check_if_is_strategic ( Mouse_X , Mouse_Y ) )
					build_tower ( 'c' , Mouse_X , Mouse_Y );

				} else if ( My_Event.pressedKey ( ) == 'm' ) {
					if ( check_if_is_strategic ( Mouse_X , Mouse_Y ) )
						build_tower ( 'm' , Mouse_X , Mouse_Y );
				}

	}


}

// #print>

// #<move

void move ( void ) {

	while ( !( i[0] == 700 && j[0] == 1700 ) ) { 

		for ( int c = 0 ; c < whattomove.size ( ); c++ ) { 

			if ( Section_Detector ( i[c] , j[c] ) == 1 ) {

				i[c] -= 1;

				j[c] = (int)( (4.0/93.0) * (double)i[c] + (620.0 - (4.0/93.0) * 1675.0) ); 

			}

			else if ( Section_Detector ( i[c] , j[c] ) == 2 ) {
				
				i[c] -= 1;
				
				j[c] = (int)( (50.0/17.0) * (double)i[c] + (600.0 - (50.0/17.0) * 1210.0) ); 

			}

			else if ( Section_Detector ( i[c] , j[c] ) == 3 ) {
			
				i[c] -= 1;
				j[c] = (int)( (1.0/2.0) * (double)i[c] + (350.0 - (1.0/2.0) * 1125.0) ); 
				
				
			}

			else if ( Section_Detector ( i[c] , j[c] ) == 4 ) {
				
				i[c] -= 1;
				
				j[c] = (int)( (-9.0/16.0) * (double)i[c] + (290.0 - (-9.0/16.0) * 1005.0) );
				
				
			}

			else if ( Section_Detector ( i[c] , j[c] ) == 5 ) {
				
				i[c] -= 1;
				
				j[c] = (int)( (-52.0/23.0) * (double)i[c] + (335.0 - (-52.0/23.0) * 925.0) ); 
				

			}

			else if ( Section_Detector ( i[c] , j[c] ) == 6 ) {
		
				i[c] -= 1;
				
				j[c] = (int)( (-9.0/52.0) * (double)i[c] + (595.0 - (-9.0/52.0) * 810.0) );  
				
				if ( j[c] == 639 )
					j[c] = 640;

			}

			else if ( Section_Detector ( i[c] , j[c] ) == 7 ) {

				i[c] -= 1;
				
				j[c] = (int)( (-15.0/17.0) * (double)i[c] + (640.0 - (-15.0/17.0) * 550.0) );  
				
				
			}

			else if ( Section_Detector ( i[c] , j[c] ) == 8 ) {
				
				i[c] += 1;
				
				j[c] = (int)( (15.0/2.0) * (double)i[c] + (715.0 - (15.0/2.0) * 465.0) ); 
				
				
			}

			else if ( Section_Detector ( i[c] , j[c] ) == 9 ) {
				
				i[c] += 1;
				
				j[c] = (int)( (13.0/30.0) * (double)i[c] + (865.0 - (13.0/30.0) * 485.0) );  
				
				
			}

			

			else if ( Section_Detector ( i[c] , j[c] ) == 10 ) {
			
				i[c] += 1;
				
				j[c] = (int)( (-11.0/57.0) * (double)i[c] + (930.0 - (-11.0/57.0) * 635.0) ); 
				
				
			}


			else if ( Section_Detector ( i[c] , j[c] ) == 11 ) {

				i[c] += 1;
				
				j[c] = (int)( (8.0/13.0) * (double)i[c] + (875.0 - (8.0/13.0) * 920.0) ) ;
				

			}


			else if ( Section_Detector ( i[c] , j[c] ) == 12 ) {
				
				i[c] -= 1;
				
				j[c] = (int)( (-39.0/12.0) * (double)i[c] + (955.0 - (-39.0/12.0) * 1050.0) );
				

			}


			else if ( Section_Detector ( i[c] , j[c] ) == 13 ) {

				i[c] -= 1;

				j[c] = (int)( (-5.0/12.0) * (double)i[c] + (1150.0 - (-5.0/12.0) * 990.0) );

			}


			else if ( Section_Detector ( i[c] , j[c] ) == 14 ) {
				
				i[c] -= 1;
				
				j[c] = (int)( (-9.0) * (double)i[c] + (1250.0 - (-9.0) * 750.0) );
				
			}

		}		
	
		print ( whattomove , i , j );
		Delay ( 20 );


	}

}

// #move>

// #<wave

void wave_loader ( int wave_number ) {

	string str_1 = "orc";
	string str_2 = "armored";
	string str_3 = "orc";
	string str_4 = "armored";

	int x_0 = 1675;
	int y_0 = 620;

	switch ( wave_number ) {

		case ( 1 ) : 

				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 100 );
				j.push_back ( (int)( (4/93) * (x_0 - 100) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );

				move ( );
				
			break;
	
			case ( 2 ) :

			i.push_back ( x_0 );
			j.push_back ( y_0 );
			whattomove.push_back ( str_1 );
			
			i.push_back ( x_0 - 50 );
			j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
			whattomove.push_back ( str_1 );
			
			i.push_back ( x_0 - 100 );
			j.push_back ( (int)( (4/93) * (x_0 - 100) + (620 - 4/93 * 1675) ) );
			whattomove.push_back ( str_1 );

			Delay ( 4000 );

			i.push_back ( x_0 );
			j.push_back ( y_0 );
			whattomove.push_back ( str_1 );
			
			i.push_back ( x_0 - 50 );
			j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
			whattomove.push_back ( str_1 );
			
			i.push_back ( x_0 - 100 );
			j.push_back ( (int)( (4/93) * (x_0 - 100) + (620 - 4/93 * 1675) ) );
			whattomove.push_back ( str_1 );
			

			break;

			case ( 3 ) :

			i.push_back ( x_0 );
			j.push_back ( y_0 );
			whattomove.push_back ( str_2 );
			
			i.push_back ( x_0 - 50 );
			j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
			whattomove.push_back ( str_2 );
			

			break;

			case ( 4 ) :

				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_2 );
				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
			
				Delay (6000);

			
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_2 );
				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
			
			
			break;

			case ( 5 ) :

				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_2 );
				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				
				Delay(5000);

				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				

				Delay(6000);

				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_2 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 );
				j.push_back ( y_0 );
				whattomove.push_back ( str_1 );
				
				i.push_back ( x_0 - 50 );
				j.push_back ( (int)( (4/93) * (x_0 - 50) + (620 - 4/93 * 1675) ) );
				whattomove.push_back ( str_1 );
				


			break;
			
			
		}		


}

void wave_detector ( void ) {

	struct timeval t1 , t2;
	gettimeofday ( &t1 , NULL );

	for ( int t = 0; t < 90000; ) {

		switch ( t ) {

			case ( 5000 ) :
			 	wave_loader ( 1 );


			case ( 20000 ) :
				wave_loader ( 2 );


			 case ( 44000 ) :
			 
				wave_loader ( 3 );

			break;

			 case ( 60000 ) :
			 
				wave_loader ( 4 );

			break;

			 case ( 90000 ) :
			 
				wave_loader ( 5 );

			break;
			
		}

	gettimeofday ( &t2 , NULL );
	t = (t2.tv_sec - t1.tv_sec) * 1000 + (t2.tv_usec - t1.tv_usec)/1000; 
	}

}

// #wave>

// #<level

void load_level ( int arg0 ) {

	if ( arg0 == 1 )

		w.draw_png ( "levels/1/level1-map.png" , 0 , 0 , 800 , 800 );

		
		else if ( arg0 == 2 )

			w.draw_png ( "levels/2/level2-map.png" , 0 , 0 , 800 , 800 );	


	w.update_screen ( );

	wave_detector ( );

}

	
void get_level ( void ) {

	int level;
	cin >> level;
	load_level ( level );

}

// #level>

int main ( ) {

	get_level ( );

	bool quit=false;

	while ( !quit ) {

		Event My_Event = w.pollForEvent ( );

		if ( My_Event.type ( ) == QUIT )

			quit = true ;

	
		}	

} 

 