#include <iostream>
#include <string>


// Function to calculate checksum
int calculateChecksum(const std::string& inputString) {
  int checksum = 0;
  // Iterate through each character in the string and sum their ASCII values
  for (int i = 0; i < static_cast<int>(inputString.size()); ++i) {
    checksum += inputString[i];
  }
  return checksum;  // Return the final checksum
}


int main(int argc, char *argv[]) {
  bool hasValidArguementCount = (argc == 3);
  if (hasValidArguementCount) {
    std::string programName{argv[0]};
    auto firstCharOfInput{*(argv[1])};
    auto programNameLength{programName.size()};
    auto targetValue{std::atoi(argv[2])};
    // auto checksum{0};
    // auto currentIndex{0};
    std::string inputString{argv[1]};

    int checksum = calculateChecksum(inputString);

    /*
    while (true) {
      checksum += inputString[currentIndex++];
      if (currentIndex >= static_cast<int>(inputString.size())) {
        break;
      }
    }
    */

    if ((checksum ^ firstCharOfInput * 3) << (programNameLength & 0x1f) == targetValue) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}