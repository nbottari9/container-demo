// Copyright 2025 Nick Bottari
#include <iostream>
#include <string>
#include <stdexcept>
#include "FibLFSR.hpp"

using PhotoMagic::FibLFSR;


FibLFSR::FibLFSR(const std::string& seed) : length(seed.length()) {
    if (length <= 15) {
        throw std::invalid_argument("Seed must be 16 chars or greater");
    }
    _register = new int[length];

    for (int i = 0; i < 16; i++) {
        _register[i] = seed[i] - '0';
    }
}

FibLFSR::~FibLFSR() {
    delete[] _register;
}

int FibLFSR::step() {
    int leftMostBit = _register[0];
    int tapPos13 = _register[2];
    int tapPos12 = _register[3];
    int tapPos10 = _register[5];

    int result;
    result = leftMostBit^tapPos13;
    result = result^tapPos12;
    result = result^tapPos10;

    // shift bits 1 position excluding the last bit
    for (int i = 0; i < 15; i++) {
        _register[i] = _register[i + 1];
    }

    _register[15] = result;

    return result;
}

int FibLFSR::generate(int k) {
    if (k < 0 || k > 16) {
        throw std::invalid_argument(
            "generate must use a number >= 0 and < 16");
    }
    int result = 0;
    // use a loop to call step k times
    for (int i = 0; i < k; i++) {
        int extractedBit = step();

        // every time, multiply the result * 2, then add what step returns
        result *= 2;
        result += extractedBit;
    }
    return result;
}

std::string FibLFSR::getRegister() const {
    std::string stringRepresentation;

    for (int i = 0; i < length; i++) {
        stringRepresentation.append(std::to_string(_register[i]));
    }

    return stringRepresentation;
}

std::ostream& PhotoMagic::operator<<(std::ostream& os, const FibLFSR& lfsr) {
    return os << lfsr.getRegister();
}


