void macro_02_reading_raw_data() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName = "../output/02_read_data.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "EventLoaderTimepix3/Timepix3_0/hitMap";
    string histName2 = "EventLoaderTimepix3/Timepix3_1/hitMap";
    string histName3 = "EventLoaderTimepix3/Timepix3_2/hitMap";
    string histName4 = "EventLoaderATLASpix/ATLASpix_0/hitMap";
    string histName5 = "EventLoaderTimepix3/Timepix3_3/hitMap";
    string histName6 = "EventLoaderTimepix3/Timepix3_4/hitMap";
    string histName7 = "EventLoaderTimepix3/Timepix3_5/hitMap";
    string histName8 = "EventLoaderTimepix3/Timepix3_6/hitMap";

    // Read the histogram from the file and assign it to a variable called h1:
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(histName2.c_str()));
    TH1F* h3 = static_cast<TH1F*>(f1->Get(histName3.c_str()));
    TH1F* h4 = static_cast<TH1F*>(f1->Get(histName4.c_str()));
    TH1F* h5 = static_cast<TH1F*>(f1->Get(histName5.c_str()));
    TH1F* h6 = static_cast<TH1F*>(f1->Get(histName6.c_str()));
    TH1F* h7 = static_cast<TH1F*>(f1->Get(histName7.c_str()));
    TH1F* h8 = static_cast<TH1F*>(f1->Get(histName8.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    TCanvas* c1 = new TCanvas("c1","c1",1600,800);
    c1->Divide(4,2);

    // Draw the histogram:
    c1->cd(1);
    gPad->SetRightMargin(0.13);
    h1->Draw("colz");
    c1->cd(2);
    gPad->SetRightMargin(0.13);
    h2->Draw("colz");
    c1->cd(3);
    gPad->SetRightMargin(0.13);
    h3->Draw("colz");
    c1->cd(4);
    gPad->SetRightMargin(0.13);
    h4->SetTitle("ATLASpix_0 Hit map");
    h4->Draw("colz");
    c1->cd(5);
    gPad->SetRightMargin(0.13);
    h5->Draw("colz");
    c1->cd(6);
    gPad->SetRightMargin(0.13);
    h6->Draw("colz");
    c1->cd(7);
    gPad->SetRightMargin(0.13);
    h7->Draw("colz");
    c1->cd(8);
    gPad->SetRightMargin(0.13);
    h8->Draw("colz");

    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("../figures/02_read_data_hitmaps.pdf");
}


