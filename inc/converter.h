#ifndef CONVERTER_H
#define CONVERTER_H

#include "ast.h"

class Converter {
public:
    virtual ~Converter();

protected:
    Node* root;
};

#endif //CONVERTER_H
