#include <string>
using namespace std;


void asmToCode(string inputFilename, string outputFilename);
void codeToRegisters(string inputFilename, string outputFilename);
string readFromFile(string filename);
void writeToFile(string filename, string text);