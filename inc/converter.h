#ifndef CONVERTER_H
#define CONVERTER_H

#include "node.h"

class Converter {
public:
    virtual ~Converter();

protected:
    Node* root;
};

#endif //CONVERTER_H
