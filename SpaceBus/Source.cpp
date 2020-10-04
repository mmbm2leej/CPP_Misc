#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::string; using std::ifstream; using std::map;
using std::cout; using std::cin;

#define vecOfStr std::vector<std::string>


int main() {
    //get the file
    string routes = "routes.txt";
    ifstream inputfile(routes, std::ios::out);
    if (!inputfile.is_open()) {
        std::cerr << "Error: Can't open \"" << routes << "\" text file.\n";
        return false;
    }

    //create variables
    string port0, port1; std::size_t commaPos;

    //this map will list all reachable ports from name;
    map<string, vecOfStr> reachables;

    std::string line;
    while (std::getline(inputfile, line)) {
        //std::cout << line << "\n";
        commaPos = line.find(",");
        port0 = line.substr(0, commaPos);
        port1 = line.substr(commaPos + 2);
        //std::cout << "Port 0 = " << port0 << "\nPort 1 = " << port1 << "\n\n";

        //put them into the map
        if (reachables.find(port0) == reachables.end()) reachables[port0] = { port1 };
        else reachables[port0].emplace_back(port1);
        if (reachables.find(port1) == reachables.end()) reachables[port1] = { port0 };
        else reachables[port1].emplace_back(port0);
    }

    inputfile.close();

    //get input parameters
    string fromPort = "", destPort = "";
    cout << "Please enter starting port:\n";
    std::getline(cin, fromPort);
    
    cout << "\n\nPlease enter destination port:\n";
    std::getline(cin, destPort);

    //std::cout << "\n\n" << fromPort << "\n";
    //std::cout << destPort;
    bool exhausted = false;

    //check if the port exists
    if (    (reachables.find(fromPort) == reachables.end())     ||      (reachables.find(destPort) == reachables.end())     )
        std::cout << "That port doesnt exist!\n";
    else {
        //check base case
        if (reachables[fromPort][0] == destPort) std::cout << "\n\ntrue\n\n";
     
        else {
            vecOfStr searchedList{};

            //go through each port from starting point
            while (reachables[fromPort].size() > 0) {
                for (int i = 0; i < reachables[reachables[fromPort][0]].size(); ++i) {
                    //if we found the target
                    if (reachables[reachables[fromPort][0]][i] == destPort) {
                        std::cout << "\n\ntrue\n\n";
                        return 0;   //end main
                    }
                    else 
                    //add if not in the from port list
                    if ((std::find(reachables[fromPort].begin(),
                        reachables[fromPort].end(),
                        reachables[reachables[fromPort][0]][i]) == reachables[fromPort].end())) {

                        reachables[fromPort].emplace_back(reachables[reachables[fromPort][0]][i]);
                    }
                }
                searchedList.emplace_back(reachables[fromPort][0]);
                reachables[fromPort].erase(reachables[fromPort].begin());
            }

            std::cout << "\n\nfalse\n\n";
        }
    }
  
	return 0;

}