// Copyright 2025 Nick Bottari
#include "./FibLFSR.hpp"

int main(int argc, char* argv[]) {
    PhotoMagic::FibLFSR lfsr("1011011000110110");
    std::cout << lfsr << std::endl;
    return 0;
}
