#ifndef ROOT_CLASS_H
#define ROOT_CLASS_H

#include <TObject.h>

class root_class : public TObject {
    public:
    root_class(); // default constructor
    root_class(Int_t variable); // some other constructor
    virtual ~root_class(); // destructor
    
    private:
    // some private members
    Int_t fVariable; // Member variable declaration
    ClassDef(root_class, 1); // root_class
};

#endif // This is for ROOT_CLASS_H