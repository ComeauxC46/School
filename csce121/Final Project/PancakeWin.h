#include "Window.h"
#include "Graph.h"
#include "GUI.h"
#include "Pancake.h"
#include "std_lib_facilities_4.h"

//PancakeWin.h
//Header file for Pancake window, Congrats Window, and Scores Window
struct Pancake_Window : Graph_lib::Window 
{
    Pancake_Window(Point xy, int w, int h, const string& title);
	
	
private:
    Button next_button;
    Button quit_button;
	
	In_box user_input;
	Out_box flip_output;
	Out_box score_output;
	Out_box min_flips;

    Vector_ref<Pancake> vp; //vector of pancakes
    Vector_ref<Button> vb; //vector of buttons
    vector<int> pan_orig; //the order of the pancakes
	vector<int> sorted; //holds the sorted vector of ints to test against
	int num_pan; //holds the user input recieved through the user_inout In_Box
	int min; //holds the minimum number of flips the puzzle can be completed in
	int score; //calculates the score

    //actions invoked by callbacks
	void quit();
	int next(); 
    int flip_pressed(); 
       
	//helper functions
	void add_buttons();
	void add_pancakes();
	void detach_buttons();
	void detach_pancakes();
	int out_of_range(); 
	int is_score_neg(); 
	int get_button_num(); 
		
    //callback functions
    static void cb_flip(Address, Address pw) {reference_to<Pancake_Window>(pw).flip_pressed();};
    static void cb_next(Address, Address pw) {reference_to<Pancake_Window>(pw).next();};
    static void cb_quit(Address, Address pw) {reference_to<Pancake_Window>(pw).quit();};
};


struct Congrats_Window : Graph_lib::Window
{
	Congrats_Window(Point xy, int w, int h, const string& title); //constructor
private:
	Text congrats; //congradulations text that get displayed on the screen
	In_box initials; // gets users initials
	string initial; // hold the users initials
	Button Record; // button to record the initials
	
	//used to calculate scores and output them
	ifstream input_scores; //linked to Scores.txt
	ofstream output_scores;
	vector<string> init_vect;
	vector<int> scores_vect;
	
	//functions used to handle scoring and recorinf scores
	void scores_input();
	void sort_input();
	void scores_output();
	
	//functions and callbacks
	int record();
	static void cb_record (Address, Address pw) {reference_to<Congrats_Window>(pw).record();};
};
 
struct Scores_Window : Graph_lib::Window
 {
	Scores_Window(Point xy, int w, int h, const string& title); // constructor
private:
	Text* scores; // used to display scores on the window
	Button Quit_Button; 
	
	ifstream scores_stream; // linked to Scores.txt
	vector<string> initial_vector;
	vector<int> scores_vector;
	
	//helper functions
	void fill_vectors(); // fill the vectors listed above and display Text scores
	
	// Functions and callbacks
	void quit_scores();
	static void cb_quit_scores (Address, Address pw) {reference_to<Scores_Window>(pw).quit_scores();};	 
 };

 struct Error_Window : Graph_lib::Window
 {
 	Error_Window(Point xy, int w, int h, const string& title); // constructor
 private:
 	Button Quit_Button;

	//Functions and their callbacks
 	void quit_error();
 	static void cb_quit_error (Address, Address pw) {reference_to<Error_Window>(pw).quit_error();};
 };