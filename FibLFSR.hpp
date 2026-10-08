// Copyright 2025 Nick Bottari
#pragma once

#include <iostream>
#include <string>

namespace PhotoMagic {
class FibLFSR {
 public:
  explicit FibLFSR(const std::string& seed);
  explicit FibLFSR(unsigned int seed);  // Optional
  static FibLFSR fromPassword(const std::string& password);  // Optional
  int step();
  int generate(int k);
  std::string getRegister() const;
  ~FibLFSR();
 private:
  int* _register;
  int length;
};

std::ostream& operator<<(std::ostream&, const FibLFSR& lfsr);
}  // namespace PhotoMagic
