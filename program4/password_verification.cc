#include "program4/password_verification.h"

bool verify_password(const std::string& input) {
  return has_six_chars(input) && has_uppercase(input) && has_lowercase(input) && has_digit(input);
}
