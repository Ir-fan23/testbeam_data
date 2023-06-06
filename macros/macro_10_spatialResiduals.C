void macro_10_spatialResiduals() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName1 = "../output/10_dut_analysis.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName1.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "AnalysisDUT/ATLASpix_0/residualsX";
    string histName2 = "AnalysisDUT/ATLASpix_0/residualsY";

    // Read the histogram from the file and assign it to a variable called h1:
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(histName2.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    TCanvas* c1 = new TCanvas("c1","c1",2*800,600);
    c1->Divide(2,1);

    // Draw the histograms:
    c1->cd(1);
    h1->Draw();

    c1->cd(2);
    h2->Draw();

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("../figures/10_spatialResiduals.pdf");
}


