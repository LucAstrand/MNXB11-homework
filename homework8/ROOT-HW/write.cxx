#include <root_class.h>
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>

void write(){

    // Define number of events to generate
    const Int_t nEvents{10000};

    // Initialize your object e.g. as a pointer
    root_class *event{nullptr};

    // Create your root file here
    TFile f("tree_file.root","RECREATE");

    // Create your TTree here
    TTree *tree = new TTree("tree","momentum tree");

    // And the associated branches underneath
    // for example a branch with your personal object type
    tree->Branch("event", &event);

    // Now we create our loop for filling the tree with some random data
    // For loop here
    Double_t px,py,pz;
    Int_t ev;
    for (Int_t i{0}; i<nEvents; i++){ // define how many events you want
    // Initialize your new object below
        gRandom->Rannor(px,py);
        pz = px*px + py*py;
        ev = i;
        event = new root_class(ev,px,py,pz);
    // Now fill tree
        tree->Fill();
    // Remember to delete it again otherise you will have memory leak!
        delete event;
        event = nullptr;
    }
// save the tree/file
    // tree->AutoSave();
    tree->Write();
    f.Close();
}
