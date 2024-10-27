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
    // For example, we'll filter entries where the magnitude is less than 10
    Double_t magnitudeThreshold = 10.0;

    // Draw a scatter plot of px * py vs pz
    // The formula "px*py:pz" specifies the x and y axes, and we use a criterion based on the magnitude
    TCanvas* c1 = new TCanvas("c1", "Scatter Plot", 800, 600);
    T->Draw("px*py:pz", Form("sqrt(px*px + py*py + pz*pz) < %f", magnitudeThreshold), "SCATTER");

    // Optionally, you can set labels for axes
    c1->SetGrid();
    c1->Update(); // Ensure the canvas updates to show the scatter plot

    // Cleanup: Close the file if not needed further
    f->Close();
    delete f; // Also delete the pointer to free up memory
}
