#include <iostream>
#include <stdlib.h>

using namespace std;

const string suffix = ".cash"; 
string command = "";

void print(string msg){
    cout << msg;
}

void addCommand(string cmd){
    if(command.length() < 1){
        command += cmd;
    } else {
        command += " && " + cmd;
    }
}

int main(int argc, char** argv){
    print("Compiling...\n\n\n");
    
    string fnArg = argv[1];
    
    int dotInd = fnArg.find_last_of(".");

    if(dotInd == string::npos || fnArg.substr(dotInd).compare(suffix) != 0){
        print("invalid file type: " + fnArg.substr(dotInd) + "\n");
        return -1;
    }

    string fn = fnArg.substr(0, dotInd);

    print("Processed arguments\n");
    print("Running commands \n");
    
    addCommand("java -jar compiler.jar " + fn + suffix);
    addCommand("g++ -o " + fn + ".exe " + fn + ".cpp");

    system(command.c_str());
    
    print("Finished running commands\n");

    print("Finished Compiling ... \n\n\n");
    return 0;
}