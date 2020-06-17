
#include <iostream>
#include <fstream>
#include <string>

#include "formats.h"
#include "m_v_verifications.h"

using namespace std;
std::string filepath = "/home/pi/test.fen2";

bool format_error = false; //Set to true upon error in Formatting

string get_contents(string filepath) { //Retrieve file contents of specified path
    ifstream readfile(filepath);
    if (! readfile.is_open()){
        cout << "Error While opening file.\n";
        return "Error.";
    }
    string returner;
    string line;
    while (getline(readfile, line)) {
        returner += line + "\n";
    }
    readfile.close();
    return returner;
}


void data_format(string code) { //Generate .fen2c
    cout << "File Length: " << code.length() << endl;
    cout << endl;
    cout << "Generating .fen2c...\n" << endl;

    int char_count = 0;
    int temp_char_count;
    int function_breakpoint;
    string raw_function;
    string called_class;
    string called_function;
    string FINAL;
    char code1;
    char code2;
    char code3;


    while (char_count != code.length() - 1) { //Read characters 1 by 1
        code1 = code[char_count];
        code2 = code[char_count + 1];
        code3 = code[char_count + 2];

        if (code1 == ':' && code2 == ':') { //Detect Standard Function call
            cout << "- Detected Function Call.\n";
            raw_function = "";
            temp_char_count = char_count - 1;
            while (true) { //Discover Function Call name

                if (temp_char_count < 0 | (code[temp_char_count] == '.' && code[temp_char_count - 1] == '.')) {
                    cout << "Error while formatting: Lack of function call start.\n";
                    format_error = true;
                    break;

                }
                if (code[temp_char_count] == '-') {
                    break;
                }
                raw_function = code[temp_char_count] + raw_function;



                temp_char_count -= 1;
            }
            
            function_breakpoint = split_class_function_breakpoint_provider(raw_function); //Get the class-function breakpoint
            called_class = raw_function.substr(0, function_breakpoint); //gain function class
            called_function = raw_function.substr(function_breakpoint + 1, raw_function.length() - 1);//gain function
            cout << called_class << " " << called_function << endl;
            FINAL += "func" + to_string(called_class.length()) + called_class + to_string(called_function.length()) + called_function;
            cout << FINAL;

        }
        char_count += 1;
        if (format_error) { //Detect Formatting Error and break
            cout << "Terminating format process due to Error.\n";
            break;
        }

    }
}
int main(int argc, char** argv) { //Main
    std::cout << "Fenris 2.0-v1.0 C++ Execution Engine: Fenris 2.0 Standard and Executer by Jacob Scrapchansky.\n\n"; //Name and Credits
	std::cout << "Opening file: " << argv[1] << endl << endl;
	
	string compile_mode = "speed0"; //Set default Parse Mode

	if (argc > 2) { //Search for custom Parse and set if applicable
		compile_mode = argv[2];
	}
	
	if (format_mode_exists(compile_mode)) { //Detect if Parse mode is valid
		cout << "Parsing using Mode: " << compile_mode << endl << endl;
	} else {
		cout << "Unknown Parse Mode: " << compile_mode << endl << endl;
		return 1;
	}
	
	string file_contents = get_contents(argv[1]); //Gain Fen File contents
    if (file_contents == "Error.") { //close upon opening file if Error is detected
		return 1;
	}
	
	data_format(file_contents); //Begin Parse

    return 0;

}


