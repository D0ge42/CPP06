#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter
{
  private:
    ScalarConverter(void);

  public:
    static void convert(char *str);
};

void detectType(char *str);

#endif
