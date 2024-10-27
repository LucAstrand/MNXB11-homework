#include "root_class.h"
#include <TTree.h>
#include <TFile.h>
#include <TH2F.h>
#include <TCanvas.h>

void read(){
    // initialize your object
    root_class *event{nullptr};
    // open your file
    auto f = TFile::Open("tree_file.root");
    // get your tree
    TTree *T = static_cast<TTree*>(f->Get("tree"));
    // remember to set the branch address
    T->SetBranchAddress("event",&event);
    Long64_t N = T->GetEntries();

    TH2F *h2 = new TH2F("h2", "Momentum distribution; px; py", 100, -10, 10, 100, -10, 10);
    for (Int_t i{0}; i<N; i++){ // loop over the whole tree
    T->GetEntry(i);
    // do something
    h2->Fill(event->GetPx(),event->GetPy());
    }

    TCanvas *c1 = new TCanvas("c1", "Momentum Distribution", 800, 600);
    h2->Draw("COLZ");
    c1->Update();

    // f->Close();

}