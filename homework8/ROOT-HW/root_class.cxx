#include <root_class.h>

// default constructor - ROOT needs the default one where everything is set to 0
root_class::root_class() : fVariable{0} {
}
// another constructor
root_class::root_class(Int_t variable) : fVariable{variable} {
}
// destructor
root_class::~root_class(){
// right now I'm empty

}

ClassImp(root_class)