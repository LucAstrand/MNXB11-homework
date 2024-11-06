#ifndef ROOT_CLASS_H
#define ROOT_CLASS_H

#include <TObject.h>

class root_class : public TObject {
    public:
    root_class(); // default constructor
    root_class(Int_t ev, Double_t px, Double_t py, Double_t pz); // some other constructor
    virtual ~root_class(); // destructor

    // Getter methods to access private members
    Int_t GetEv() const { return ev; }
    Double_t GetPx() const { return px; }
    Double_t GetPy() const { return py; }
    Double_t GetPz() const { return pz; }
    
    Double_t GetVectorMagnitude() { return VectorMagnitude(); }

    private:
    // some private members
    Int_t ev;
    Double_t px;
    Double_t py;
    Double_t pz;

    Double_t VectorMagnitude();

    ClassDef(root_class, 1); // root_class
};

#endif // This is for ROOT_CLASS_H