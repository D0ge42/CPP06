#ifndef INFO_HPP
#define INFO_HPP

#include <string>
typedef enum e_type
{
  T_INT = 1 << 1,
  T_CHAR = 1 << 2,
  T_FLOAT = 1 << 3,
  T_DOUBLE = 1 << 4,
} t_type;

class Info
{
  private:
    int data_type;
  public:
    Info(void);
    Info(const Info &other);
    ~Info(void);

    Info &operator=(const Info &other);
    void detectType(char *str);
    int getDataType(void);
    void convertChar(const std::string &str);
    void convertInt(const std::string &str);
    void convertFloat(const std::string &str);
    void convertDouble(const std::string &str);
};

#endif

