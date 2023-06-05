void macro_12_efficiency() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName1 = "../output/10_dut_analysis_withEfficiency_fullRun.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName1.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "AnalysisEfficiency/ATLASpix_0/chipEfficiencyMap_trackPos";
    string histName2 = "AnalysisEfficiency/ATLASpix_0/pixelEfficiencyMap_trackPos";

    // Read the histogram from the file and assign it to a variable called h1:
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(histName2.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    TCanvas* c1 = new TCanvas("c1","c1",2*800,600);
    c1->Divide(2,1);

    // Draw the histograms:
    c1->cd(1);
    gPad->SetRightMargin(0.13);
    h1->GetZaxis()->SetRangeUser(0.5,1);
    h1->Draw("colz");

    c1->cd(2);
    gPad->SetRightMargin(0.13);
    h2->GetXaxis()->SetRangeUser(-300,100);
    h2->GetZaxis()->SetRangeUser(0.5,1);
    h2->Draw("colz");

    // Remove stat box:
    gStyle->SetOptStat(0);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("../figures/12_efficiency.pdf");
}


