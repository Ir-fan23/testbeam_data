void macro_05_prealignment() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName1 = "../output/04_correlations_before_prealignment.root";
    string fileName2 = "../output/04_correlations_after_prealignment.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName1.c_str());
    TFile *f2 = TFile::Open(fileName2.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName0x = "Correlations/Timepix3_0/correlationX";
    string histName0y = "Correlations/Timepix3_0/correlationY";

    string histName1x = "Correlations/Timepix3_1/correlationX";
    string histName1y = "Correlations/Timepix3_1/correlationY";

    string histName2x = "Correlations/Timepix3_2/correlationX";
    string histName2y = "Correlations/Timepix3_2/correlationY";

    string histName3x = "Correlations/Timepix3_3/correlationX";
    string histName3y = "Correlations/Timepix3_3/correlationY";

    string histName4x = "Correlations/Timepix3_4/correlationX";
    string histName4y = "Correlations/Timepix3_4/correlationY";

    string histName5x = "Correlations/Timepix3_5/correlationX";
    string histName5y = "Correlations/Timepix3_5/correlationY";

    string histName6x = "Correlations/Timepix3_6/correlationX";
    string histName6y = "Correlations/Timepix3_6/correlationY";

    // Read the histograms from the file and assign them:
    TH1F* h0x_before = static_cast<TH1F*>(f1->Get(histName0x.c_str()));
    TH1F* h0y_before = static_cast<TH1F*>(f1->Get(histName0y.c_str()));
    TH1F* h1x_before = static_cast<TH1F*>(f1->Get(histName1x.c_str()));
    TH1F* h1y_before = static_cast<TH1F*>(f1->Get(histName1y.c_str()));
    TH1F* h2x_before = static_cast<TH1F*>(f1->Get(histName2x.c_str()));
    TH1F* h2y_before = static_cast<TH1F*>(f1->Get(histName2y.c_str()));
    TH1F* h3x_before = static_cast<TH1F*>(f1->Get(histName3x.c_str()));
    TH1F* h3y_before = static_cast<TH1F*>(f1->Get(histName3y.c_str()));
    TH1F* h4x_before = static_cast<TH1F*>(f1->Get(histName4x.c_str()));
    TH1F* h4y_before = static_cast<TH1F*>(f1->Get(histName4y.c_str()));
    TH1F* h5x_before = static_cast<TH1F*>(f1->Get(histName5x.c_str()));
    TH1F* h5y_before = static_cast<TH1F*>(f1->Get(histName5y.c_str()));
    TH1F* h6x_before = static_cast<TH1F*>(f1->Get(histName6x.c_str()));
    TH1F* h6y_before = static_cast<TH1F*>(f1->Get(histName6y.c_str()));

    TH1F* h0x_after = static_cast<TH1F*>(f2->Get(histName0x.c_str()));
    TH1F* h0y_after = static_cast<TH1F*>(f2->Get(histName0y.c_str()));
    TH1F* h1x_after = static_cast<TH1F*>(f2->Get(histName1x.c_str()));
    TH1F* h1y_after = static_cast<TH1F*>(f2->Get(histName1y.c_str()));
    TH1F* h2x_after = static_cast<TH1F*>(f2->Get(histName2x.c_str()));
    TH1F* h2y_after = static_cast<TH1F*>(f2->Get(histName2y.c_str()));
    TH1F* h3x_after = static_cast<TH1F*>(f2->Get(histName3x.c_str()));
    TH1F* h3y_after = static_cast<TH1F*>(f2->Get(histName3y.c_str()));
    TH1F* h4x_after = static_cast<TH1F*>(f2->Get(histName4x.c_str()));
    TH1F* h4y_after = static_cast<TH1F*>(f2->Get(histName4y.c_str()));
    TH1F* h5x_after = static_cast<TH1F*>(f2->Get(histName5x.c_str()));
    TH1F* h5y_after = static_cast<TH1F*>(f2->Get(histName5y.c_str()));
    TH1F* h6x_after = static_cast<TH1F*>(f2->Get(histName6x.c_str()));
    TH1F* h6y_after = static_cast<TH1F*>(f2->Get(histName6y.c_str()));

    // Create a new canvas (background to paint on, like when painting a portrait):
    TCanvas* c1 = new TCanvas("c1","c1",1600,600);
    c1->Divide(4,2);

    // Draw the histograms:
    c1->cd(1);
    h0x_before->GetXaxis()->SetRangeUser(-4,4);
    h0x_before->Draw();
    h0x_after->SetLineColor(kRed);
    h0x_after->Draw("same");
    TLegend *leg1x = new TLegend(0.6,0.7,0.9,0.9);
    leg1x->AddEntry(h0x_before,"before prealignment");
    leg1x->AddEntry(h0x_after,"after prealignment");
    leg1x->Draw();

    c1->cd(2);
    h1x_before->GetXaxis()->SetRangeUser(-4,4);
    h1x_before->Draw();
    h1x_after->SetLineColor(kRed);
    h1x_after->Draw("same");
    TLegend *leg2x = new TLegend(0.6,0.7,0.9,0.9);
    leg2x->AddEntry(h1x_before,"before prealignment");
    leg2x->AddEntry(h1x_after,"after prealignment");
    leg2x->Draw();

    c1->cd(3);
    h2x_before->GetXaxis()->SetRangeUser(-4,4);
    h2x_before->Draw();
    h2x_after->SetLineColor(kRed);
    h2x_after->Draw("same");
    TLegend *leg3x = new TLegend(0.6,0.7,0.9,0.9);
    leg3x->AddEntry(h2x_before,"before prealignment");
    leg3x->AddEntry(h2x_after,"after prealignment");
    leg3x->Draw();

    c1->cd(4);
    h3x_before->GetXaxis()->SetRangeUser(-4,4);
    h3x_before->Draw();
    h3x_after->SetLineColor(kRed);
    h3x_after->Draw("same");
    TLegend *leg4x = new TLegend(0.6,0.7,0.9,0.9);
    leg4x->AddEntry(h3x_before,"before prealignment");
    leg4x->AddEntry(h3x_after,"after prealignment");
    leg4x->Draw();

    c1->cd(5);
    h4x_before->GetXaxis()->SetRangeUser(-4,4);
    h4x_before->Draw();
    h4x_after->SetLineColor(kRed);
    h4x_after->Draw("same");
    TLegend *leg5x = new TLegend(0.6,0.7,0.9,0.9);
    leg5x->AddEntry(h4x_before,"before prealignment");
    leg5x->AddEntry(h4x_after,"after prealignment");
    leg5x->Draw();

    c1->cd(6);
    h5x_before->GetXaxis()->SetRangeUser(-4,4);
    h5x_before->Draw();
    h5x_after->SetLineColor(kRed);
    h5x_after->Draw("same");
    TLegend *leg6x = new TLegend(0.6,0.7,0.9,0.9);
    leg6x->AddEntry(h5x_before,"before prealignment");
    leg6x->AddEntry(h5x_after,"after prealignment");
    leg6x->Draw();

    c1->cd(7);
    h6x_before->GetXaxis()->SetRangeUser(-4,4);
    h6x_before->Draw();
    h6x_after->SetLineColor(kRed);
    h6x_after->Draw("same");
    TLegend *leg7x = new TLegend(0.6,0.7,0.9,0.9);
    leg7x->AddEntry(h6x_before,"before prealignment");
    leg7x->AddEntry(h6x_after,"after prealignment");
    leg7x->Draw();

    // Now the same for Y:
    TCanvas* c2 = new TCanvas("c2","c2",1600,600);
    c2->Divide(4,2);

    c2->cd(1);
    h0y_before->GetXaxis()->SetRangeUser(-4,4);
    h0y_before->Draw();
    h0y_after->SetLineColor(kRed);
    h0y_after->Draw("same");
    TLegend *leg1y = new TLegend(0.6,0.7,0.9,0.9);
    leg1y->AddEntry(h0y_before,"before prealignment");
    leg1y->AddEntry(h0y_after,"after prealignment");
    leg1y->Draw();

    c2->cd(2);
    h1y_before->GetXaxis()->SetRangeUser(-4,4);
    h1y_before->Draw();
    h1y_after->SetLineColor(kRed);
    h1y_after->Draw("same");
    TLegend *leg2y = new TLegend(0.6,0.7,0.9,0.9);
    leg2y->AddEntry(h1y_before,"before prealignment");
    leg2y->AddEntry(h1y_after,"after prealignment");
    leg2y->Draw();

    c2->cd(3);
    h2y_before->GetXaxis()->SetRangeUser(-4,4);
    h2y_before->Draw();
    h2y_after->SetLineColor(kRed);
    h2y_after->Draw("same");
    TLegend *leg3y = new TLegend(0.6,0.7,0.9,0.9);
    leg3y->AddEntry(h2y_before,"before prealignment");
    leg3y->AddEntry(h2y_after,"after prealignment");
    leg3y->Draw();

    c2->cd(4);
    h3y_before->GetXaxis()->SetRangeUser(-4,4);
    h3y_before->Draw();
    h3y_after->SetLineColor(kRed);
    h3y_after->Draw("same");
    TLegend *leg4y = new TLegend(0.6,0.7,0.9,0.9);
    leg4y->AddEntry(h3y_before,"before prealignment");
    leg4y->AddEntry(h3y_after,"after prealignment");
    leg4y->Draw();

    c2->cd(5);
    h4y_before->GetXaxis()->SetRangeUser(-4,4);
    h4y_before->Draw();
    h4y_after->SetLineColor(kRed);
    h4y_after->Draw("same");
    TLegend *leg5y = new TLegend(0.6,0.7,0.9,0.9);
    leg5y->AddEntry(h4y_before,"before prealignment");
    leg5y->AddEntry(h4y_after,"after prealignment");
    leg5y->Draw();

    c2->cd(6);
    h5y_before->GetXaxis()->SetRangeUser(-4,4);
    h5y_before->Draw();
    h5y_after->SetLineColor(kRed);
    h5y_after->Draw("same");
    TLegend *leg6y = new TLegend(0.6,0.7,0.9,0.9);
    leg6y->AddEntry(h5y_before,"before prealignment");
    leg6y->AddEntry(h5y_after,"after prealignment");
    leg6y->Draw();

    c2->cd(7);
    h6y_before->GetXaxis()->SetRangeUser(-4,4);
    h6y_before->Draw();
    h6y_after->SetLineColor(kRed);
    h6y_after->Draw("same");
    TLegend *leg7y = new TLegend(0.6,0.7,0.9,0.9);
    leg7y->AddEntry(h6y_before,"before prealignment");
    leg7y->AddEntry(h6y_after,"after prealignment");
    leg7y->Draw();

    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("../figures/05_prealignment_X.pdf");
    c2->SaveAs("../figures/05_prealignment_Y.pdf");
}

