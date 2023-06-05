void macro_07_alignment() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName1 = "../output/06_tracking_after_prealignment.root";
    string fileName2 = "../output/06_tracking_after_alignment.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName1.c_str());
    TFile *f2 = TFile::Open(fileName2.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName0 = "Tracking4D/trackChi2ndof";

    string histName0x = "Tracking4D/Timepix3_2/residualsX";
    string histName1x = "Tracking4D/Timepix3_2/residualsX";
    string histName2x = "Tracking4D/Timepix3_2/residualsX";
    string histName3x = "Tracking4D/Timepix3_2/residualsX";
    string histName4x = "Tracking4D/Timepix3_2/residualsX";
    string histName5x = "Tracking4D/Timepix3_2/residualsX";
    string histName6x = "Tracking4D/Timepix3_2/residualsX";

    string histName0y = "Tracking4D/Timepix3_2/residualsY";
    string histName1y = "Tracking4D/Timepix3_2/residualsY";
    string histName2y = "Tracking4D/Timepix3_2/residualsY";
    string histName3y = "Tracking4D/Timepix3_2/residualsY";
    string histName4y = "Tracking4D/Timepix3_2/residualsY";
    string histName5y = "Tracking4D/Timepix3_2/residualsY";
    string histName6y = "Tracking4D/Timepix3_2/residualsY";

    // Read the histograms from the file and assign them:
    TH1F* h0_before = static_cast<TH1F*>(f1->Get(histName0.c_str()));
    TH1F* h0_after = static_cast<TH1F*>(f2->Get(histName0.c_str()));

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

    TCanvas* c0 = new TCanvas("c0","c0",800,600);
    h0_after->SetLineColor(kRed);
    h0_after->GetYaxis()->SetTitle("normalized entries");
    h0_after->DrawNormalized();
    h0_before->DrawNormalized("same");

    TLegend *leg0 = new TLegend(0.6,0.7,0.9,0.9);
    leg0->AddEntry(h0_before,"before alignment");
    leg0->AddEntry(h1x_after,"after alignment");
    leg0->Draw();

    // All residuals in X:
    TCanvas* c1 = new TCanvas("c1","c1",1600,600);
    c1->Divide(4,2);

    c1->cd(1);
    h0x_after->SetLineColor(kRed);
    h0x_after->GetXaxis()->SetRangeUser(-4,4);
    h0x_after->GetYaxis()->SetTitle("normalized entries");
    h0x_after->DrawNormalized();
    h0x_before->DrawNormalized("same");
    TLegend *leg1x = new TLegend(0.6,0.7,0.9,0.9);
    leg1x->AddEntry(h0x_before,"before prealignment");
    leg1x->AddEntry(h0x_after,"after prealignment");
    leg1x->Draw();

    c1->cd(2);
    h1x_after->SetLineColor(kRed);
    h1x_after->GetXaxis()->SetRangeUser(-4,4);
    h1x_after->GetYaxis()->SetTitle("normalized entries");
    h1x_after->DrawNormalized();
    h1x_before->DrawNormalized("same");
    TLegend *leg2x = new TLegend(0.6,0.7,0.9,0.9);
    leg2x->AddEntry(h1x_before,"before prealignment");
    leg2x->AddEntry(h1x_after,"after prealignment");
    leg2x->Draw();

    c1->cd(3);
    h2x_after->SetLineColor(kRed);
    h2x_after->GetXaxis()->SetRangeUser(-4,4);
    h2x_after->GetYaxis()->SetTitle("normalized entries");
    h2x_after->DrawNormalized();
    h2x_before->DrawNormalized("same");
    TLegend *leg3x = new TLegend(0.6,0.7,0.9,0.9);
    leg3x->AddEntry(h2x_before,"before prealignment");
    leg3x->AddEntry(h2x_after,"after prealignment");
    leg3x->Draw();

    c1->cd(4);
    h3x_after->SetLineColor(kRed);
    h3x_after->GetXaxis()->SetRangeUser(-4,4);
    h3x_after->GetYaxis()->SetTitle("normalized entries");
    h3x_after->DrawNormalized();
    h3x_before->DrawNormalized("same");
    TLegend *leg4x = new TLegend(0.6,0.7,0.9,0.9);
    leg4x->AddEntry(h3x_before,"before prealignment");
    leg4x->AddEntry(h3x_after,"after prealignment");
    leg4x->Draw();

    c1->cd(5);
    h4x_after->SetLineColor(kRed);
    h4x_after->GetXaxis()->SetRangeUser(-4,4);
    h4x_after->GetYaxis()->SetTitle("normalized entries");
    h4x_after->DrawNormalized();
    h4x_before->DrawNormalized("same");
    TLegend *leg5x = new TLegend(0.6,0.7,0.9,0.9);
    leg5x->AddEntry(h4x_before,"before prealignment");
    leg5x->AddEntry(h4x_after,"after prealignment");
    leg5x->Draw();

    c1->cd(6);
    h5x_after->SetLineColor(kRed);
    h5x_after->GetXaxis()->SetRangeUser(-4,4);
    h5x_after->GetYaxis()->SetTitle("normalized entries");
    h5x_after->DrawNormalized();
    h5x_before->DrawNormalized("same");
    TLegend *leg6x = new TLegend(0.6,0.7,0.9,0.9);
    leg6x->AddEntry(h5x_before,"before prealignment");
    leg6x->AddEntry(h5x_after,"after prealignment");
    leg6x->Draw();

    c1->cd(7);
    h6x_after->SetLineColor(kRed);
    h6x_after->GetXaxis()->SetRangeUser(-4,4);
    h6x_after->GetYaxis()->SetTitle("normalized entries");
    h6x_after->DrawNormalized();
    h6x_before->DrawNormalized("same");
    TLegend *leg7x = new TLegend(0.6,0.7,0.9,0.9);
    leg7x->AddEntry(h6x_before,"before prealignment");
    leg7x->AddEntry(h6x_after,"after prealignment");
    leg7x->Draw();

    // All residuals in Y:
    TCanvas* c2 = new TCanvas("c2","c2",1600,600);
    c2->Divide(4,2);

    c2->cd(1);
    h0y_after->SetLineColor(kRed);
    h0y_after->GetXaxis()->SetRangeUser(-4,4);
    h0y_after->GetYaxis()->SetTitle("normalized entries");
    h0y_after->DrawNormalized();
    h0y_before->DrawNormalized("same");
    TLegend *leg1y = new TLegend(0.6,0.7,0.9,0.9);
    leg1y->AddEntry(h0y_before,"before prealignment");
    leg1y->AddEntry(h0y_after,"after prealignment");
    leg1y->Draw();

    c2->cd(2);
    h1y_after->SetLineColor(kRed);
    h1y_after->GetXaxis()->SetRangeUser(-4,4);
    h1y_after->GetYaxis()->SetTitle("normalized entries");
    h1y_after->DrawNormalized();
    h1y_before->DrawNormalized("same");
    TLegend *leg2y = new TLegend(0.6,0.7,0.9,0.9);
    leg2y->AddEntry(h1y_before,"before prealignment");
    leg2y->AddEntry(h1y_after,"after prealignment");
    leg2y->Draw();

    c2->cd(3);
    h2y_after->SetLineColor(kRed);
    h2y_after->GetXaxis()->SetRangeUser(-4,4);
    h2y_after->GetYaxis()->SetTitle("normalized entries");
    h2y_after->DrawNormalized();
    h2y_before->DrawNormalized("same");
    TLegend *leg3y = new TLegend(0.6,0.7,0.9,0.9);
    leg3y->AddEntry(h2y_before,"before prealignment");
    leg3y->AddEntry(h2y_after,"after prealignment");
    leg3y->Draw();

    c2->cd(4);
    h3y_after->SetLineColor(kRed);
    h3y_after->GetXaxis()->SetRangeUser(-4,4);
    h3y_after->GetYaxis()->SetTitle("normalized entries");
    h3y_after->DrawNormalized();
    h3y_before->DrawNormalized("same");
    TLegend *leg4y = new TLegend(0.6,0.7,0.9,0.9);
    leg4y->AddEntry(h3y_before,"before prealignment");
    leg4y->AddEntry(h3y_after,"after prealignment");
    leg4y->Draw();

    c2->cd(5);
    h4y_after->SetLineColor(kRed);
    h4y_after->GetXaxis()->SetRangeUser(-4,4);
    h4y_after->GetYaxis()->SetTitle("normalized entries");
    h4y_after->DrawNormalized();
    h4y_before->DrawNormalized("same");
    TLegend *leg5y = new TLegend(0.6,0.7,0.9,0.9);
    leg5y->AddEntry(h4y_before,"before prealignment");
    leg5y->AddEntry(h4y_after,"after prealignment");
    leg5y->Draw();

    c2->cd(6);
    h5y_after->SetLineColor(kRed);
    h5y_after->GetXaxis()->SetRangeUser(-4,4);
    h5y_after->GetYaxis()->SetTitle("normalized entries");
    h5y_after->DrawNormalized();
    h5y_before->DrawNormalized("same");
    TLegend *leg6y = new TLegend(0.6,0.7,0.9,0.9);
    leg6y->AddEntry(h5y_before,"before prealignment");
    leg6y->AddEntry(h5y_after,"after prealignment");
    leg6y->Draw();

    c2->cd(7);
    h6y_after->SetLineColor(kRed);
    h6y_after->GetXaxis()->SetRangeUser(-4,4);
    h6y_after->GetYaxis()->SetTitle("normalized entries");
    h6y_after->DrawNormalized();
    h6y_before->DrawNormalized("same");
    TLegend *leg7y = new TLegend(0.6,0.7,0.9,0.9);
    leg7y->AddEntry(h6y_before,"before prealignment");
    leg7y->AddEntry(h6y_after,"after prealignment");
    leg7y->Draw();

    // Remove stat box:
    gStyle->SetOptStat(0);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c0->SaveAs("../figures/07_alignment_trackChi2.pdf");
    c1->SaveAs("../figures/07_alignment_residualsX.pdf");
    c2->SaveAs("../figures/07_alignment_residualsY.pdf");
}


