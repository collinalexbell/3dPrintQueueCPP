// io
#include <stdio.h>

// basic file operations
#include <iostream>
#include <fstream>

// std
#include <string>
#include <vector>

using namespace std;
fstream open_3d_print_queue(){
  fstream queue;
  string home = getenv("HOME");
  queue.open(home +"/tree/3dPrintQueue");
  return queue;
}

int main(int arg_count, char** args) {
  if(arg_count == 1) {
    fstream queue = open_3d_print_queue();
    vector<string> toPrint;
    while(queue.peek() != EOF) {
      std::string line;
      getline(queue,line);
      toPrint.push_back(line);
    }

    for(auto it = toPrint.begin(); it != toPrint.end(); it++) {
      std::string three_d_printable = *it;
      cout << three_d_printable << endl;
    }

    queue.close();
    return 0;
  }

  if(arg_count == 3) {
    if(args[2] == "add") {
      string toAdd = args[3]; // could be made into class ToAdd(char* filename)
    }
  }
}

