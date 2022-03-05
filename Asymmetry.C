{

  double p0 =    -0.138813;
  double p1 =      -0.3202;
  double p2 =     -2.33637;
  double p3 =      55.7403;
  double p4 =     -299.495;
  double p5 =      833.345;
  double p6 =     -1330.95;
  double p7 =      1230.64;
  double p8 =     -612.486;
  double p9 =      126.984;

  
  TF1* Asy = new TF1("Asy","(-8.*x^2+x+1.)/(4.*x^2-5.*x-5.)",0.,1.);
  TF1* Asypol = new TF1("Asypol","[0] + [1]*x + [2]*x^2 + [3]*x^3 + [4]*x^4 + [5]*x^5 + [6]*x^6 + [7]*x^7 + [8]*x^8 + [9]*x^9",0.,1.);
  Asypol->SetParNames("p0","p1","p2","p3","p4","p5","p6","p7","p8","p9");
  Asypol->SetParameters(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9);

  Asy->SetLineColor(1);
  Asypol->SetLineColor(kBlue);
  TCanvas* c1 = new TCanvas("c1");
  Asy->Draw();
  Asypol->Draw("same");
}
