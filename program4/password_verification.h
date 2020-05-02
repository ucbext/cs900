#pragma once

#include <string>

bool has_six_chars(const std::string& password);
bool has_uppercase(const std::string& password);
bool has_lowercase(const std::string& password);
bool has_digit(const std::string& password);

bool verify_password(const std::string& input);
