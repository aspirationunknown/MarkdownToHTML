#ifndef CONVERTER_H
#define CONVERTER_H

class Converter {
public:
  Converter() = default;
  virtual ~Converter();
  Converter(const Converter &) = default;
  Converter &operator=(const Converter &) = default;
  Converter(Converter &&) = default;
  Converter &operator=(Converter &&) = default;
};

#endif // CONVERTER_H
