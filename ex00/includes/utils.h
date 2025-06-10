#ifndef UTILS
#define UTILS

#include <iostream>

int is_sign(char c);
int is_special(const std::string &str);
int is_there_dot(const std::string &str);
int isAlphaString(const std::string &str);
int dotCount(const std::string &str);
int signCount(const std::string &str);
int isStringAlphaNum(const std::string &str);
int check_float_limits(long double num);
int check_double_limits(long double num);
int check_int_limits(long double num);

#endif // !UTILS
