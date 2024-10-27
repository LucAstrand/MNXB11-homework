#include <root_class.h>
#include <cmath>

// default constructor - ROOT needs the default one where everything is set to 0
root_class::root_class() :
ev{0}, 
px{0}, 
py{0}, 
pz{0} 
{

}
// another constructor
root_class::root_class(Int_t ev, Double_t px, Double_t py, Double_t pz) :  
ev{ev},
px{px}, 
py{py}, 
pz{pz} 
{
    VectorMagnitude();
}
// destructor
root_class::~root_class(){
// right now I'm empty

}

Double_t root_class::VectorMagnitude(){
    return std::sqrt((px*px) + (py*py) + (pz*pz));
}

ClassImp(root_class)