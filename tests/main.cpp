#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <submission.h>

using namespace std;

int main() {
  string asmToCodeInputDir = "asmToCode/inputs/";
  string asmToCodeOutputDir = "asmToCode/outputs/";
  string codeToRegistersInputDir = "codeToRegisters/inputs/";
  string codeToRegistersOutputDir = "codeToRegisters/outputs/";

  // iterate through asmToCode tests
  for (const auto& entry : filesystem::directory_iterator(asmToCodeInputDir)) {
    if (entry.path().extension() != ".asm") {
      continue;
    }
    string inputFilename = entry.path();
    string filename = entry.path().filename().string();
    string expectedOutput = readFromFile(asmToCodeOutputDir + filename.substr(0, filename.size() - 4) + ".b");

    asmToCode(inputFilename, "temp.b");
    string actualOutput = readFromFile("temp.b");

    if (actualOutput != expectedOutput) {
      cout << "Test failed: " << inputFilename << endl;
    } else {
      cout << "Test passed: " << inputFilename << endl;
    }
  }

  // iterate through codeToRegisters tests
  for (const auto& entry : filesystem::directory_iterator(codeToRegistersInputDir)) {
    if (entry.path().extension() != ".b") {
      continue;
    }
    string inputFilename = entry.path();
    string filename = entry.path().filename().string();
    string expectedOutput = readFromFile(codeToRegistersOutputDir + filename.substr(0, filename.size() - 2) + ".reg");

    codeToRegisters(inputFilename, "temp.reg");
    string actualOutput = readFromFile("temp.reg");

    if (actualOutput != expectedOutput) {
      cout << "Test failed: " << inputFilename << endl;
    } else {
      cout << "Test passed: " << inputFilename << endl;
    }
  }

  return 0;
}