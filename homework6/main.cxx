#include <iostream>
#include <string>


bool validateInput(int argc) {
  if (argc != 3) {
    std::cerr << "Invalid number of arguments.\n";
    std::cerr << "Usage: ./program_name <string> <expected_value>\n";
    std::cerr << " - <string>: A string for checksum calculation.\n";
    std::cerr << " - <expected_value>: An integer that is the expected key.\n";
    return false;  // Return false if input is invalid
  }
  return true;  // Input is valid
}

int calculateChecksum(const std::string& inputString) {
  int checksum = 0;
  // Iterate through each character in the string and sum their ASCII values
  for (int i = 0; i < static_cast<int>(inputString.size()); ++i) {
    checksum += inputString[i];
  }
  return checksum;  
}

void compareKeys(int checksum, char firstCharOfInput, size_t programNameLength, int expectedKey) {
  int calculatedKey = (checksum ^ firstCharOfInput * 3) << (programNameLength & 0x1f); 

  std::cout << "Calculated key: " << calculatedKey << std::endl;
  std::cout << "Expected key: " << expectedKey << std::endl;

  if (calculatedKey == expectedKey) {
    std::cout << "Correct!" << std::endl;
  } else {
    std::cout << "Wrong!" << std::endl;
  }
}


int main(int argc, char *argv[]) {
    if (!validateInput(argc)) {
      return 1;
      }
    std::string programName{argv[0]};
    auto firstCharOfInput{*(argv[1])};
    auto programNameLength{programName.size()};
    auto targetValue{std::atoi(argv[2])};
    std::string inputString{argv[1]};

    int checksum = calculateChecksum(inputString);

    compareKeys(checksum, firstCharOfInput, programNameLength, targetValue);

}