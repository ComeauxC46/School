#include "PancakeWin.h"
#include "find_solution.h"
/* GLOBAL VERIABLES*/

int total_score; // global variable to access private members
string current_initials; // global variable to access provate members

/*---------------------------------------------------------------------

PANCAKE_WINDOW IMPLEMENTATION*/

//Constructor
Pancake_Window::Pancake_Window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-220,0}, 70, 20, "Add", cb_next},
    quit_button{Point{x_max()-70,0}, 70, 20, "Quit", cb_quit},
	user_input{Point{x_max()-300,0}, 70, 20, "Difficulty"},
	flip_output{Point{x_max()-500,0}, 70, 20, "Flips"},
	score_output{Point{x_max()-500,80}, 70, 20, "Score"},
	min_flips{Point{x_max()-500,40}, 70, 20, "Minimum Flips"}
    {
		attach(next_button);
		attach(quit_button);
		attach(user_input);
		attach(flip_output);
		attach(score_output);
		attach(min_flips);
    }
	
//*************************************************************************************************************
//hide PANCAKE_WINDOW
void Pancake_Window::quit()
{
    hide();
}

//*************************************************************************************************************
//shuffle and display pancakes and buttons (ADD BUTTON)
int Pancake_Window::next() 
{
    detach_pancakes();	
	detach_buttons();
	
	num_pan = user_input.get_int(); //set the number of pancakes to the users input
	out_of_range();// if the user inputs a a number out of range display error window
	pan_orig.resize(num_pan); // resize to the user input
	for (int i = 0; i < pan_orig.size(); ++i) //set each number to it's position {1,2,3...}
		pan_orig[i] = i + 1;
	sorted = pan_orig;// create a copy of pan_orig before it is scrambled. To be used to test if player has won
	srand(time(0)); //shuffle order vector
    random_shuffle(pan_orig.begin(), pan_orig.end());
	
	//find minimal solution
	vector<int> solution = *find_solution(pan_orig);
	min = solution.size();
	min_flips.put(to_string(min));//display the minimal number of flips

	add_pancakes();
	add_buttons();
		
	if( min == 0) //if the pancakes are already sorted deconstruct vectors and rescrable
		next();
	score=0; //reset the score user adds a new set of pancakes
    redraw();
}

//***************************************************************************************************************
//flip pancakes -- The pancake are flipped based on position 
// so the first button flips the first two and so on
int Pancake_Window::flip_pressed()
 {
    vector<int> pan_flip = pan_orig; //make another vector identical to the order vector
    int last = get_button_num(); //this determines how many pancakes will be flipped
    int first = 0;
    int flipped = last;

    while (first < last) // flips the pancakes in the vector
	{ 
		pan_flip[first] = pan_orig[flipped - 1]; 
		++first;
		--flipped;
    }
    pan_orig = pan_flip;
    detach_pancakes();
    add_pancakes();
	
	//keep the user updated on how they are doing
	score++; //updates score
	flip_output.put(to_string(score));
	total_score = (100-10*(score-min))* num_pan;
	score_output.put(to_string(total_score));
	is_score_neg();// if they use too many flips open error window
	
	redraw();
	
	if(pan_orig==sorted) // if the user wins display the Congrats window and record initials this
	{
		Congrats_Window win02{Point{300,300},300,300,"Congrats!!"};
		return gui_main();
	}
}

//*************************************************************************************************************
void Pancake_Window::add_buttons()
{
	for (int i = 0; i < pan_orig.size()-1; ++i) //create vector of buttons and attach them
	{
		vb.push_back(new Button{Point{x_max()-100,i*40+180}, 70, 20, "Flip", cb_flip});
		attach(vb[vb.size()-1]);
    }
}

//*************************************************************************************************************
void Pancake_Window::add_pancakes()
{
	for (int i = 0; i < user_input.get_int(); ++i) //place a pancake of size pan_orig[i] at position i
	{
		vp.push_back(new Pancake{pan_orig[i], i});
		attach(vp[vp.size()-1]);
	}
}

//*************************************************************************************************************
void Pancake_Window::detach_buttons()
{
	for (int i = 0; i < vb.size(); ++i)  //detach any previous buttons
		detach(vb[i]);
}

//*************************************************************************************************************
void Pancake_Window::detach_pancakes()
{
	for (int i = 0; i < vp.size(); ++i)  //detach any previous pancakes
		detach(vp[i]);
}

//*************************************************************************************************************
int Pancake_Window::out_of_range()
{
	if (num_pan < 2 || num_pan > 9) 
	{
		Error_Window win03{Point{300,300},300,300,"Sorry..."};
		Text dummy1{Point{45,115}, "Did you even look at the instructions?"};
		Text dummy2{Point{45,155}, "Please close this window and enter a"};
		Text dummy3{Point{70,195}, "difficulty between 2 and 9."};
		win03.attach(dummy1);
		win03.attach(dummy2);
		win03.attach(dummy3);
		return gui_main();
	}
}

//*************************************************************************************************************
//test to see if player used too many flips
int Pancake_Window::is_score_neg()
{
	if (total_score < 0)
	{
		Error_Window win03{Point{300,300},300,300,"Sorry..."};
		Text loser1{Point{60,115}, "You flipped too many times."};
		Text loser2{Point{40,155}, "Please close this window and enter"};
		Text loser3{Point{50,195}, "another (perhaps easier) difficulty."};
		win03.attach(loser1);
		win03.attach(loser2);
		win03.attach(loser3);
		detach_buttons();
		detach_pancakes();
		return gui_main();
	}
}

//*************************************************************************************************************
// the position of the button deterimes how many pancakes will be flipped
int Pancake_Window::get_button_num()
{
	int y = Fl::event_y(); // find where the user clicked, used to control the number of panckakes flipped
	int n;                 //represents how many pancakes will be flipped--Ex. n=9 means all 9 pancakes will be flipped
	if (y >=460 && y <=480) n=9;
	else if (y >=420 && y <=460) n=8;
	else if (y >=380 && y <=400) n=7;
	else if (y >=340 && y <=360) n=6;
	else if (y >=300 && y <=320) n=5;
	else if (y >=260 && y <=280) n=4;
	else if (y >=220 && y <=240) n=3;
	else n=2;
	return n;
}
/*-----------------------------------------------------------------------

CONGRATS WINDOW IMPLEMENTAION*/	

//Constructor	
Congrats_Window::Congrats_Window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	congrats{Point{60,150}, "Congratulations, you win!!"},
	initials{Point{x_max()-200,0}, 70, 20, "Initials"},
	Record{Point{x_max()-100,0}, 70, 20, "Record", cb_record}
	{
		attach(congrats);
		attach(initials);
		attach(Record);
	}

//*************************************************************************************************************
//record the users initials and display the Scores Window	
int Congrats_Window::record()
{
	hide();
	initial = initials.get_string();
	current_initials = initials.get_string();
	if(initial.length() > 3)// if initials are too long conctinate it to size 3
		initial.resize(3);
	scores_output();
	Scores_Window win20{Point{300,300},300,300,"Top Scores"};
	return gui_main();
}

//*************************************************************************************************************
//input scores from the file names Scores.txt
void Congrats_Window::scores_input()
{
	input_scores.open("Scores.txt");
	if (!input_scores)
		error("cannot open file Scores.txt");
	string I; // holds the initials
	int S; //holds the scores
	while(input_scores >> I >> S)
	{
		init_vect.push_back(I);
		scores_vect.push_back(S);
	}
	input_scores.close();
}

//*************************************************************************************************************
//sort into highest score
void Congrats_Window::sort_input()
{
	scores_input(); // get input from file
	// obtain most recent scores
	init_vect.push_back(initial);
	scores_vect.push_back(total_score);
	
	for (int c = 0; c < scores_vect.size()-1; c++)
	{
		for(int i = c+1; i<scores_vect.size(); i++)
		{
			if(scores_vect[c] < scores_vect[i])
			{
				int tmpi = scores_vect[i];
				string tmps = init_vect[i];
				scores_vect[i] = scores_vect[c];
				init_vect[i] = init_vect[c];
				init_vect[c] = tmps;
				scores_vect[c] = tmpi;
			}
		}
	}
}

//*************************************************************************************************************
// sort and output scores back to Scores.txt
void Congrats_Window::scores_output()
{
	sort_input();
	output_scores.open("Scores.txt");
	if(!output_scores)
		error("cannot open file Scores.txt");
	int size = 5;
	if(init_vect.size() < 5)
		size = init_vect.size();
	for (int i = 0; i < size; i++)
	{
		output_scores << init_vect[i] + " " + to_string(scores_vect[i]) + '\n';
	}
	output_scores.close();
}
/*-------------------------------------------------------------------------------

SCORES WINDOW IMPLEMETAION*/

//Constructor
Scores_Window::Scores_Window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	Quit_Button{Point{x_max()-70,0}, 70, 20, "Quit", cb_quit_scores}
	{
		fill_vectors();
		attach(Quit_Button);
	}
	
//*************************************************************************************************************
//close the Scores Window
void Scores_Window::quit_scores()
{
	hide();
}

//*************************************************************************************************************
//Fill the vectors that hold the data inputed from Scores.txt
//and represent it on the scren as text objects
void Scores_Window::fill_vectors()
{
	//fill the vectors
	scores_stream.open("Scores.txt");
	if (!scores_stream)
		error("cannot open file Scores.txt");
	string I; // holds the initials
	int S; //holds the scores
	while(scores_stream >> I >> S)
	{
		initial_vector.push_back(I);
		scores_vector.push_back(S);
	}
	
	//display the data as text
	int y = 50;
	for(int i = 0; i < initial_vector.size(); ++i)
	{
		scores = new Text{Point{60,y}, to_string(i+1) + ". " + initial_vector[i] + "\t" + to_string(scores_vector[i])};
		attach(*scores);
		scores->set_font_size(20);
		if( initial_vector[i] == current_initials && scores_vector[i] == total_score) // sets current players score to bold if they are one of the top scores
			scores->set_font(FL_HELVETICA_BOLD);
		y += 50;
	}
	scores_stream.close();
}

/*-----------------------------------------------------------------------------------------------------------

ERROR WINDOW IMPLEMENTAION*/

Error_Window::Error_Window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	Quit_Button{Point{x_max()-70,0}, 70, 20, "Quit",cb_quit_error}
	{
		attach(Quit_Button);
	}

//*************************************************************************************************************
void Error_Window::quit_error()
{
	hide();
}