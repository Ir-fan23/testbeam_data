void macro_06_first_tracking() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName1 = "../output/06_tracking_after_prealignment.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName1.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "Correlations/Timepix3_2/correlationX";
    string histName2 = "Correlations/Timepix3_2/correlationY";

    string histName3 = "Tracking4D/Timepix3_2/residualsX";
    string histName4 = "Tracking4D/Timepix3_2/residualsY";

    string histName5 = "Tracking4D/trackChi2ndof";

    // Read the histogram from the file and assign it to a variable called h1:
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(histName2.c_str()));
    TH1F* h3 = static_cast<TH1F*>(f1->Get(histName3.c_str()));
    TH1F* h4 = static_cast<TH1F*>(f1->Get(histName4.c_str()));
    TH1F* h5 = static_cast<TH1F*>(f1->Get(histName5.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    TCanvas* c1 = new TCanvas("c1","c1",3*800,600);
    c1->Divide(3,1);

    // Draw the histograms:
    c1->cd(1);
    h1->Draw();
    h1->SetTitle("Timepix3_2: Spatial Correlations");
    h1->GetXaxis()->SetRangeUser(-4,4);
    h2->SetLineColor(kRed);
    h2->Draw("same");

    TLegend *leg1 = new TLegend(0.6,0.7,0.9,0.9);
    leg1->AddEntry(h1,"correlation in x");
    leg1->AddEntry(h2,"correlation in y");
    leg1->Draw();

    c1->cd(2);
    h3->SetTitle("Timepix3_2: Spatial Residuals");
    h3->Draw();
    h4->SetLineColor(kRed);
    h4->Draw("same");

    TLegend *leg2 = new TLegend(0.6,0.7,0.9,0.9);
    leg2->AddEntry(h3,"residual in x");
    leg2->AddEntry(h4,"residual in y");
    leg2->Draw();

    c1->cd(3);
    h5->Draw();

    // Add overflow bin to stat box:
    gStyle->SetOptStat(111111);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("../figures/06_first_tracking.pdf");
}


