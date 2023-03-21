#include <string>
#include <iostream>
#include <fstream>
#include <submission.h>
using namespace std;

/**
 * Takes in a path to an assembly code as an input and returns the corresponding machine code.
 * Make sure to follow the syntax provided.
 * - exampleInput: "input.asm"
 * - exampleOutput: ******* 
*/
void asmToCode(string inputFilename, string outputFilename) {
  string assemblyCode = readFromFile(inputFilename);
  string machineCode = "";
  // TODO: Implement asmToCode function
  writeToFile(outputFilename, machineCode);
}

/**
 * Takes in a string of machine code as an input and outputs to the specified path the final state of all registers.
 * Make sure to follow the syntax provided.
 * - exampleInput: *******
 * - exampleOutput: "output.txt"
*/
void codeToRegisters(string inputFilename, string outputFilename) {
  string machineCode = readFromFile(inputFilename);
  string registers = "";
  // TODO: Implement codeToRegisters function
  writeToFile(outputFilename, registers);
}

string readFromFile(string filename) {
  ifstream stream;
  stream.open(filename);
  string buffer;
  string line;
  while (getline(stream, line)) {
    buffer += line;
  }
  stream.close();
  return buffer;
}

void writeToFile(string filename, string text) {
  ofstream outputFile;
  outputFile.open(filename);
  outputFile << text;
  outputFile.close();
}