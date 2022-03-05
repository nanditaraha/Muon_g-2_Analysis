{
  TMultiGraph *mg = new TMultiGraph();
  //units of drop / energy. p0=4.267e-6 
  //Used the fact that the minimum is always at 30 us (checked every file - depends on tau_r which is same for all).
  TFile *f1 = TFile::Open("noWiggle_fac6_g320_m100.root");
  TFile *f2 = TFile::Open("noWiggle_fac8_g320_m100.root");
  TFile *f3 = TFile::Open("noWiggle_fac10_g320_m100.root");
  TFile *f4 = TFile::Open("noWiggle_fac12_g320_m100.root");
  TFile *f5 = TFile::Open("noWiggle_fac14_g320_m100.root");
  //For 100 muons
  TH1D *h1 = (TH1D*)f1->Get("Laser");
  TH1D *h2 = (TH1D*)f2->Get("Laser");
  TH1D *h3 = (TH1D*)f3->Get("Laser");
  TH1D *h4 = (TH1D*)f4->Get("Laser");
  TH1D *h5 = (TH1D*)f5->Get("Laser");

  double x1 = h1->GetBinContent(30);
  double x2 = h2->GetBinContent(30);
  double x3 = h3->GetBinContent(30);
  double x4 = h4->GetBinContent(30);
  double x5 = h5->GetBinContent(30);

  double x1_e = 0.02/sqrt(2000);//h1->GetBinError(30);
  
  double gain_min_100[5]={x1, x2, x3, x4, x5};
  double  drop_100[5]={6,8,10,12,14};
  double err_y[5] = {x1_e,x1_e,x1_e,x1_e,x1_e};
  double err_x[5] = {0};
  
  //For 50 muons
  f1 = TFile::Open("noWiggle_fac6_g320_m50.root");
  f2 = TFile::Open("noWiggle_fac8_g320_m50.root");
  f3 = TFile::Open("noWiggle_fac10_g320_m50.root");
  f4 = TFile::Open("noWiggle_fac12_g320_m50.root");
  f5 = TFile::Open("noWiggle_fac14_g320_m50.root");
  
  h1 = (TH1D*)f1->Get("Laser");
  h2 = (TH1D*)f2->Get("Laser");
  h3 = (TH1D*)f3->Get("Laser");
  h4 = (TH1D*)f4->Get("Laser");
  h5 = (TH1D*)f5->Get("Laser");

  x1 = h1->GetBinContent(30);
  x2 = h2->GetBinContent(30);
  x3 = h3->GetBinContent(30);
  x4 = h4->GetBinContent(30);
  x5 = h5->GetBinContent(30);
  
  
  
  double gain_min_50[5]={x1, x2, x3, x4, x5};
  //doubledrop_50={1,5,10,50,100};
  //double err_x_50[5] = {x1_e,x2_e,x3_e,x4_e,x5_e};
  ////////////////////////////////////////////////////////////

  
  //For 10 muons
  f1 = TFile::Open("noWiggle_fac6_g320_m10.root");
  f2 = TFile::Open("noWiggle_fac8_g320_m10.root");
  f3 = TFile::Open("noWiggle_fac10_g320_m10.root");
  f4 = TFile::Open("noWiggle_fac12_g320_m10.root");
  f5 = TFile::Open("noWiggle_fac14_g320_m10.root");
  
  h1 = (TH1D*)f1->Get("Laser");
  h2 = (TH1D*)f2->Get("Laser");
  h3 = (TH1D*)f3->Get("Laser");
  h4 = (TH1D*)f4->Get("Laser");
  h5 = (TH1D*)f5->Get("Laser");

  x1 = h1->GetBinContent(30);
  x2 = h2->GetBinContent(30);
  x3 = h3->GetBinContent(30);
  x4 = h4->GetBinContent(30);
  x5 = h5->GetBinContent(30);

  
  
  double gain_min_10[5]={x1, x2, x3, x4, x5};
  //double err_x_10[5] = {x1_e,x2_e,x3_e,x4_e,x5_e};
  mg->SetTitle("Laser interval 320 #mus and step 5 #mus ;Drop per 100 MeV for a pulse in units of p_{0} = 4.26 #times 10^{-6};G_{min}");
  TGraphErrors *gr1 = new TGraphErrors(5,drop_100,gain_min_100,err_x,err_y);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);
  mg->Add(gr1);

  TGraphErrors *gr2 = new TGraphErrors(5,drop_100,gain_min_50,err_x,err_y);
  gr2->SetMarkerColor(kRed);
  gr2->SetMarkerStyle(20);
  mg->Add(gr2);

  TGraphErrors *gr3 = new TGraphErrors(5,drop_100,gain_min_10,err_x,err_y);
  gr3->SetMarkerColor(kMagenta);
  gr3->SetMarkerStyle(22);

  mg->SetTitle("Laser;Energy drop per pulse in units of #alpha;#DeltaG_{min}");
  mg->Add(gr3);
  TLegend *leg = new TLegend(0.1,0.7,0.48,0.9);
  //TLegend *leg = new TLegend(0.1,0.9,0.3,0.9);
  //leg->SetHeader("","C"); 
  leg->AddEntry(gr1,"100 muons","lep");
  leg->AddEntry(gr2,"50 muons","lep");
  leg->AddEntry(gr3,"10 muons","lep");
  
  mg->Draw("apl");
  leg->Draw();

  TLine *l = new TLine(5.6,0.9887,14.3,0.9887);
  l->SetLineColor(kRed);
  l->SetLineWidth(2);
  l->Draw();

  TLatex tex;
  tex.SetTextSize(0.032);
  tex.DrawLatex(5.6,0.989,"JINST Value of G_{min} = 0.9887");
  
  //cout<<x2;
  
}
