void macro_08_DUTalignment() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName1 = "../output/08_dut_association_prealigned.root";
    string fileName2 = "../output/08_dut_association_aligned.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName1.c_str());
    TFile *f2 = TFile::Open(fileName2.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "AnalysisDUT/ATLASpix_0/residualsX";
    string histName2 = "AnalysisDUT/ATLASpix_0/residualsX";

    string histName3 = "AnalysisDUT/ATLASpix_0/residualsY";
    string histName4 = "AnalysisDUT/ATLASpix_0/residualsY";

    // Read the histogram from the file and assign it to a variable called h1:
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f2->Get(histName2.c_str()));
    TH1F* h3 = static_cast<TH1F*>(f1->Get(histName3.c_str()));
    TH1F* h4 = static_cast<TH1F*>(f2->Get(histName4.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    TCanvas* c1 = new TCanvas("c1","c1",2*800,600);

    c1->Divide(2,1);
    // Draw the histograms:
    c1->cd(1);
    h1->Draw();
    h2->SetLineColor(kRed);
    h2->Draw("same");

    TLegend *leg1 = new TLegend(0.6,0.7,0.9,0.9);
    leg1->AddEntry(h1,"before alignment");
    leg1->AddEntry(h2,"after alignment");
    leg1->Draw();

    c1->cd(2);
    h3->Draw();
    h4->SetLineColor(kRed);
    h4->Draw("same");

    TLegend *leg2= new TLegend(0.6,0.7,0.9,0.9);
    leg2->AddEntry(h3,"before alignment");
    leg2->AddEntry(h4,"after alignment");
    leg2->Draw();

    // Remove stat box:
    gStyle->SetOptStat(0);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("../figures/08_dut_alignment.pdf");
}


