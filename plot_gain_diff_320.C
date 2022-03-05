{
  TMultiGraph *mg = new TMultiGraph();
  //units of drop / energy. p0=4.267e-6 
  //Used the fact that the minimum is always at 30 us (checked every file - depends on tau_r which is same for all).

  TFile *f1 = TFile::Open("varyDrop_fac6_m100_c60_fil64_320_5.root");
  TFile *f2 = TFile::Open("varyDrop_fac8_m100_c60_fil64_320_5.root");
  TFile *f3 = TFile::Open("varyDrop_fac10_m100_c60_fil64_320_5.root");
  TFile *f4 = TFile::Open("varyDrop_fac12_m100_c60_fil64_320_5.root");
  TFile *f5 = TFile::Open("varyDrop_fac14_m100_c60_fil64_320_5.root");
  
  //For 100 muons
  TH1D *h1 = (TH1D*)f1->Get("Laser");
  TH1D *h2 = (TH1D*)f2->Get("Laser");
  TH1D *h3 = (TH1D*)f3->Get("Laser");
  TH1D *h4 = (TH1D*)f4->Get("Laser");
  TH1D *h5 = (TH1D*)f5->Get("Laser");

  TH1D *h11 = (TH1D*)f1->Get("Muons");
  TH1D *h21 = (TH1D*)f2->Get("Muons");
  TH1D *h31 = (TH1D*)f3->Get("Muons");
  TH1D *h41 = (TH1D*)f4->Get("Muons");
  TH1D *h51 = (TH1D*)f5->Get("Muons");
  

  double x1 = h1->GetBinContent(30);
  double x2 = h2->GetBinContent(30);
  double x3 = h3->GetBinContent(30);
  double x4 = h4->GetBinContent(30);
  double x5 = h5->GetBinContent(30);

  double x11 = h11->GetBinContent(31);
  double x21 = h21->GetBinContent(30);
  double x31 = h31->GetBinContent(31);
  double x41 = h41->GetBinContent(30);
  double x51 = h51->GetBinContent(30);

   double ey_1= sqrt(h1->GetBinError(30)*h1->GetBinError(30)+h11->GetBinError(31)*h11->GetBinError(31));
  double ey_2= sqrt(h2->GetBinError(30)*h2->GetBinError(30)+h21->GetBinError(30)*h21->GetBinError(30));
  double ey_3= sqrt(h3->GetBinError(30)*h3->GetBinError(30)+h31->GetBinError(31)*h31->GetBinError(31));
  double ey_4= sqrt(h4->GetBinError(30)*h4->GetBinError(30)+h41->GetBinError(30)*h41->GetBinError(30));
  double ey_5= sqrt(h5->GetBinError(30)*h5->GetBinError(30)+h51->GetBinError(30)*h51->GetBinError(30));
  
  double gain_min_100[5]={x11-x1, x21-x2, x31-x3, x41-x4, x51-x5};
  double  drop_100[5]={6,8,10,12,14};
  double ex[5]={0};
  double ey_100[5]={ey_1,ey_2,ey_3,ey_4,ey_5};
  
  //For 50 muons
  f1 = TFile::Open("varyDrop_fac6_m50_c60_fil64_320_5.root");
  f2 = TFile::Open("varyDrop_fac8_m50_c60_fil64_320_5.root");
  f3 = TFile::Open("varyDrop_fac10_m50_c60_fil64_320_5.root");
  f4 = TFile::Open("varyDrop_fac12_m50_c60_fil64_320_5.root");
  f5 = TFile::Open("varyDrop_fac14_m50_c60_fil64_320_5.root");
  
  h1 = (TH1D*)f1->Get("Laser");
  h2 = (TH1D*)f2->Get("Laser");
  h3 = (TH1D*)f3->Get("Laser");
  h4 = (TH1D*)f4->Get("Laser");
  h5 = (TH1D*)f5->Get("Laser");

  h11 = (TH1D*)f1->Get("Muons");
  h21 = (TH1D*)f2->Get("Muons");
  h31 = (TH1D*)f3->Get("Muons");
  h41 = (TH1D*)f4->Get("Muons");
  h51 = (TH1D*)f5->Get("Muons");

  x1 = h1->GetBinContent(30);
  x2 = h2->GetBinContent(30);
  x3 = h3->GetBinContent(30);
  x4 = h4->GetBinContent(30);
  x5 = h5->GetBinContent(30);

  x11 = h11->GetBinContent(30);
  x21 = h21->GetBinContent(31);
  x31 = h31->GetBinContent(31);//Should spline - unfortunately 30 is empty
  x41 = h41->GetBinContent(31);
  x51 = h51->GetBinContent(30);
  
  ey_1= sqrt(h1->GetBinError(30)*h1->GetBinError(30)+h11->GetBinError(30)*h11->GetBinError(30));
  ey_2= sqrt(h2->GetBinError(30)*h2->GetBinError(30)+h21->GetBinError(31)*h21->GetBinError(31));
  ey_3= sqrt(h3->GetBinError(30)*h3->GetBinError(30)+h31->GetBinError(31)*h31->GetBinError(31));
  ey_4= sqrt(h4->GetBinError(30)*h4->GetBinError(30)+h41->GetBinError(31)*h41->GetBinError(31));
  ey_5= sqrt(h5->GetBinError(30)*h5->GetBinError(30)+h51->GetBinError(30)*h51->GetBinError(30));

  double ey_50[5]={ey_1,ey_2,ey_3,ey_4,ey_5};
  double gain_min_50[5]={x11-x1, x21-x2, x31-x3, x41-x4, x51-x5};
  //doubledrop_50={1,5,10,50,100};

  //For 10 muons
  f1 = TFile::Open("varyDrop_fac6_m10_c60_fil64_320_5.root");
  f2 = TFile::Open("varyDrop_fac8_m10_c60_fil64_320_5.root");
  f3 = TFile::Open("varyDrop_fac10_m10_c60_fil64_320_5.root");
  f4 = TFile::Open("varyDrop_fac12_m10_c60_fil64_320_5.root");
  f5 = TFile::Open("varyDrop_fac14_m10_c60_fil64_320_5.root");
  
  h1 = (TH1D*)f1->Get("Laser");
  h2 = (TH1D*)f2->Get("Laser");
  h3 = (TH1D*)f3->Get("Laser");
  h4 = (TH1D*)f4->Get("Laser");
  h5 = (TH1D*)f5->Get("Laser");

  h11 = (TH1D*)f1->Get("Muons");
  h21 = (TH1D*)f2->Get("Muons");
  h31 = (TH1D*)f3->Get("Muons");
  h41 = (TH1D*)f4->Get("Muons");
  h51 = (TH1D*)f5->Get("Muons");

  x1 = h1->GetBinContent(30);
  x2 = h2->GetBinContent(30);
  x3 = h3->GetBinContent(30);
  x4 = h4->GetBinContent(30);
  x5 = h5->GetBinContent(30);

  x11 = h11->GetBinContent(31);
  x21 = h21->GetBinContent(30);
  x31 = h31->GetBinContent(30);
  x41 = h41->GetBinContent(30);
  x51 = h51->GetBinContent(30);

  ey_1= sqrt(h1->GetBinError(30)*h1->GetBinError(30)+h11->GetBinError(31)*h11->GetBinError(31));
  ey_2= sqrt(h2->GetBinError(30)*h2->GetBinError(30)+h21->GetBinError(30)*h21->GetBinError(30));
  ey_3= sqrt(h3->GetBinError(30)*h3->GetBinError(30)+h31->GetBinError(30)*h31->GetBinError(30));
  ey_4= sqrt(h4->GetBinError(30)*h4->GetBinError(30)+h41->GetBinError(30)*h41->GetBinError(30));
  ey_5= sqrt(h5->GetBinError(30)*h5->GetBinError(30)+h51->GetBinError(30)*h51->GetBinError(30));

 
  double ey_10[5]={ey_1,ey_2,ey_3,ey_4,ey_5};
  double gain_min_10[5]={x11-x1, x21-x2, x31-x3, x41-x4, x51-x5};

  mg->SetTitle("Laser interval 320 #mus and step 5 #mus ;Drop per 100 MeV for a pulse in units of p_{0} = 4.26 #times 10^{-6};#DeltaG_{min}           ");
  TGraphErrors *gr1 = new TGraphErrors(5,drop_100,gain_min_100, ex, ey_100);
  gr1->SetMarkerColor(kBlue);
  gr1->SetMarkerStyle(21);
  mg->Add(gr1);

  TGraphErrors *gr2 = new TGraphErrors(5,drop_100,gain_min_50, ex, ey_50);
  gr2->SetMarkerColor(kRed);
  gr2->SetMarkerStyle(20);
  mg->Add(gr2);

  TGraphErrors *gr3 = new TGraphErrors(5,drop_100,gain_min_10, ex, ey_10);
  gr3->SetMarkerColor(kMagenta);
  gr3->SetMarkerStyle(22);

  
  mg->Add(gr3);
  TLegend *leg = new TLegend(0.1,0.7,0.48,0.9);
  //TLegend *leg = new TLegend(0.1,0.9,0.3,0.9);
  //leg->SetHeader("","C"); 
  leg->AddEntry(gr1,"100 muons","lep");
  leg->AddEntry(gr2,"50 muons","lep");
  leg->AddEntry(gr3,"10 muons","lep");
  
  mg->Draw("apl");
  leg->Draw();
 
}
