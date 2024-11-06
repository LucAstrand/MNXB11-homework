#include "root_class.h"
#include <TTree.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TH1F.h>

void drawScatterPlot() {
    // Open your ROOT file
    auto f = TFile::Open("tree_file.root");

    // Get your TTree from the file
    TTree* T = static_cast<TTree*>(f->Get("tree"));

    // Define the magnitude criterion for filtering
    // For example, we'll filter entries where the magnitude is less than 5
    Double_t magnitudeThreshold = 5.0;

    // Draw a scatter plot of px * py vs pz

    // Note: px*py:pz will put px*py on y-axis and pz on x-axis 
    TCanvas* c1 = new TCanvas("c1", "Scatter Plot", 800, 600);
    // T->Draw("px*py:pz", Form("sqrt(px*px + py*py + pz*pz) < %f", magnitudeThreshold), "colz"); //2D with colormap
    T->Draw("px*py:pz", Form("GetVectorMagnitude() < %f", magnitudeThreshold), "SCATTER"); // 3D no Colormap

    TH1 *hist = (TH1*)gPad->GetPrimitive("htemp");

    if (hist) {
        hist->SetTitle("Scatter Plot of px*py vs. pz; pz; px*py");  
    }

    
    c1->SetGrid();
    c1->Update(); 

    // Cleanup
    f->Close();
    delete f; 
}
