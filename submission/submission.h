#include <string>
using namespace std;

string readFromFile(string filename);
void writeToFile(string filename, string text);
void asmToCode(string inputFilename, string outputFilename);
void codeToRegisters(string inputFilename, string outputFilename);