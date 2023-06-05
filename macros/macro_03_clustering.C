void macro_03_clustering() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName = "../output/03_clustering.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "Clustering4D/Timepix3_2/clusterSize";
    string histName2 = "Clustering4D/ATLASpix_0/clusterSize";

    string histName3 = "Clustering4D/ATLASpix_0/clusterWidthColumn";
    string histName4 = "Clustering4D/ATLASpix_0/clusterWidthRow";

    string histName5 = "Clustering4D/Timepix3_2/clusterSeedTot";
    string histName6 = "Clustering4D/Timepix3_2/clusterTot";

    string histName7 = "Clustering4D/ATLASpix_0/clusterSeedTot";
    string histName8 = "Clustering4D/ATLASpix_0/clusterTot";

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
    TCanvas* c1 = new TCanvas("c1","c1",2*800,2*600);
    c1->Divide(2,2);

    // Draw the histograms:
    c1->cd(1);
    gPad->SetLeftMargin(0.15);
    h1->SetTitle("cluster sizes");
    h1->GetXaxis()->SetRangeUser(0,20);
    h1->Draw();
    h2->SetLineColor(kRed);
    h2->Draw("same");

    TLegend *leg1 = new TLegend(0.6,0.7,0.9,0.9);
    leg1->AddEntry(h1,"Timepix3_2");
    leg1->AddEntry(h2,"ATLASpix_0");
    leg1->Draw();

    c1->cd(2);
    h3->SetTitle("ATLASpix_0: clusterWidthColumn/Row");
    h3->GetXaxis()->SetTitle("cluster width [px]");
    gPad->SetLeftMargin(0.15);
    h3->GetXaxis()->SetRangeUser(0,10);
    h3->Draw();
    h4->SetLineColor(kRed);
    h4->Draw("same");

    TLegend *leg2 = new TLegend(0.6,0.7,0.9,0.9);
    leg2->AddEntry(h1,"columns");
    leg2->AddEntry(h2,"rows");
    leg2->Draw();

    c1->cd(3);
    gPad->SetLeftMargin(0.15);
    h5->SetTitle("Timepix3_2: cluster ToT");
    h5->Draw();
    h6->SetLineColor(kRed);
    h6->Draw("same");

    TLegend *leg3 = new TLegend(0.6,0.7,0.9,0.9);
    h5->GetXaxis()->SetTitle("ToT [lsb]");
    leg3->AddEntry(h5,"cluster seed ToT");
    leg3->AddEntry(h6,"cluster ToT");
    leg3->Draw();

    c1->cd(4);
    gPad->SetLeftMargin(0.15);
    h7->GetXaxis()->SetRangeUser(0,30);
    h7->Draw();
    h8->SetLineColor(kRed);
    h8->Draw("same");

    TLegend *leg4 = new TLegend(0.6,0.7,0.9,0.9);
    h7->SetTitle("ATLASpix_0: cluster ToT");
    h7->GetXaxis()->SetTitle("ToT [lsb]");
    leg4->AddEntry(h7,"cluster seed ToT");
    leg4->AddEntry(h8,"cluster ToT");
    leg4->Draw();



    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("../figures/03_clustering.pdf");
}


