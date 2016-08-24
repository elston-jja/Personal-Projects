#include <iostream>
#include <fstream>
#include <string>

bool FileExists(std::string);

int main() {

  //Vars
  std::string filename;
  std::string userinput;
  std::ofstream writefile;
  bool verifyfile;
  
  std::cout << "Starting Program..." << std::endl;
  std::cout << "Tne following program is able to create and write to any text document" << std::endl;
  std::cout << "Write To: ";				    // Get filename to write to 
  std::getline(std::cin, filename);
  filename = filename + ".txt";				    // File Concantenation, using txt suffix
  std::cout << "Checking If File Exists...";
  verifyfile = FileExists(filename);			    // Call function to check file's existance
  
  if (verifyfile) {
    // File does exist
    std::cout << "File Exists" << std::endl; 
    writefile.open(filename, std::ios_base::app);	    // Open the current file and write to it
  }
  else {
    // File does not exits
    std::cout << "File Does Not Exist" << std::endl;
    std::cout << "Creating File...";
    std::ofstream writefile(filename);			    // Create new file with filename
    std::cout << "File Created" << std::endl;
  }
  std::cout << "Please enter anything to be added to the contents of " << filename << "\n> ";
  std::getline(std::cin, userinput);
  writefile << userinput << std::endl;			    // Add all the userinput to file

  std::cout << "File Written" << std::endl;		    // Ending Program
  
  return 0;
}

bool FileExists(std::string filename)
{
  std::ifstream infile(filename);
  return infile.good();
}
