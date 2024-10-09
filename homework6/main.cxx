#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
  bool hasValidArguementCount = (argc == 3);
  if (hasValidArguementCount) {
    std::string programName{argv[0]};
    auto firstCharOfInput{*(argv[1])};
    auto programNameLength{programName.size()};
    auto targetValue{std::atoi(argv[2])};
    auto checksum{0};
    auto currentIndex{0};
    std::string inputString{argv[1]};
    while (true) {
      checksum += inputString[currentIndex++];
      if (currentIndex >= static_cast<int>(inputString.size())) {
        break;
      }
    }
    if ((checksum ^ firstCharOfInput * 3) << (programNameLength & 0x1f) == targetValue) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}