
Double_t myAccept (Double_t *Emev, Double_t *par)
{
    Double_t y = Emev[0];
    /*
    Double_t par[10];
    par[0] =  4.10647e-4;
    par[1] =  8.27328e-4;
    par[2] = -9.66426e-7;
    par[3] =  7.24172e-10;
    par[4] = -2.38441e-13;
    par[5] =  2.90055e-17;
    par[6] =  1.27802e-21;
    par[7] = -5.47863e-25;
    par[8] =  3090.42;
    par[9] =     8.0975;
    */
    //
    Double_t Pol = 0;
    for(Int_t i=0; i<8; i++) Pol += pow(y,i)*par[i];
    Double_t Out = 0;
    if(y>20/3090 && y<3090/3090)Out = Pol*(1-exp((y-par[8])/par[9]));//use when normalized from 0 to 1
    //if(y>20 && y<3090)Out = Pol*(1-exp((y-par[8])/par[9]));
//
    return Out;
}


void myfunc()
{

  int bin =1000;
  //int bin =310;
  //PHASE def...
  //Convert mrad to rad....
  double p0 =    -0.255134/1000.;
  double p1 =      65.3034/1000.;
  double p2 =     -705.492/1000.;
  double p3 =      5267.21/1000.;
  double p4 =     -23986.5/1000.;
  double p5 =      68348.1/1000.;
  double p6 =      -121761/1000.;
  double p7 =       131393/1000.;
  double p8 =       -78343/1000.;
  double p9 =      19774.1/1000.;

  TF1* phase = new TF1("phase","([0] + [1]*x + [2]*x^2 + [3]*x^3 + [4]*x^4 + [5]*x^5 + [6]*x^6 + [7]*x^7 + [8]*x^8 + [9]*x^9)",0.,1.);
  phase->SetParNames("p0","p1","p2","p3","p4","p5","p6","p7","p8","p9");
  phase->SetParameters(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9);
  phase->SetNpx(10000000);
  phase->SetLineColor(2);
  //phase->Draw();
  //TH1D* hp = new TH1D("hp","Phi(y)",bin,0.,1.);
  TH1D* hp = new TH1D("hp","Phi(y)",bin,0.,1.);
  hp->Eval(phase);
  double para[10]={p0,p1,p2,p3,p4,p5,p6,p7,p8,p9};
  double average = phase->Mean(0,1,para,0.00001);


  //ASYMMETRY...
  TF1* Asy = new TF1("Asy","(-8.*x^2+x+1.)/(4.*x^2-5.*x-5.)",0.,1.);
  Asy->SetNpx(10000000);
  TH1D* ha = new TH1D("ha","A(y)",bin,0.,1.);
  ha->Eval(Asy);
  //ha->Draw();

  //Nfunction...
  //TF1* N = new TF1("N","(1./3.)*(x-1.)*(4.*x*x-5*x-5.)*(3./5.)*0.008536",0.,1.);
  TF1* N = new TF1("N","(x-1.)*(4.*x*x-5*x-5.)",0.,1.);
  TF1* N_x = new TF1("N_x","x*(x-1.)*(4.*x*x-5*x-5.)",0.,1.); //this is x*N
  N_x->SetNpx(10000000);
  //N->Draw();
  TH1D* hnx = new TH1D("hnx","yN(y)",bin,0.,1.);
  hnx->Eval(N_x);
  //hnx->Draw();

  TF1* N_Asy = new TF1("N_Asy","N*Asy",0.,1.);
  N_Asy->SetNpx(10000000);
  //N_Asy->Draw();

  TF1* N_Asy_p = new TF1("Asy_p","N*Asy*phase",0.,1.);
  N_Asy_p->SetNpx(10000000);
  //N_Asy_p->Draw();

  TF1* N_Asy_p_sin = new TF1("Asy_p_s","-Asy*sin(phase)*x",0.,1.);
  N_Asy_p_sin->SetNpx(10000000);
  //N_Asy_p_sin->Draw();
  //double average = N_Asy_p_sin->Mean(0,1,para,0.00001);
  //printf("%f\n",average);
  TH1D* hb_1 = new TH1D("hb_1","a1(y)",bin,0.,1.);
  hb_1->Eval(N_Asy_p_sin);

  TF1* N_Asy_p_cos = new TF1("Asy_p_c","Asy*cos(phase)",0.,1.);
  N_Asy_p_cos->SetNpx(10000000);
  //N_Asy_p_cos->Draw();
  double average1 = N_Asy_p_cos->Mean(0,1,para,0.00001);
  TH1D* ha_1 = new TH1D("ha_1","a1(y)",bin,0.,1.);
  ha_1->Eval(N_Asy_p_cos);
  
  //printf("%f\n",average1);
  //ACCEPTANCE ..
  //TF1 *f1 = new TF1("f1",myAccept,0,3090,10);
  TF1 *f1 = new TF1("f1",myAccept,0,1,10);
  //These fit parameters are taken from after fitting the histogram for limits 0 to 1 (E/Emax)...
  f1->SetParameters(-0.013,2.83,-10.94,24.11,-18.4,-6.57,16.58,-6.87,0.998,0.0026);
  //f1->Draw();
  /*
  TF1 *avg_N = new TF1("avg_N","N_x*f1",0,1);
  //printf("Integral avg:%f \n", avg_N->Integral(0,1,0.001));
  avg_N->Draw();
  */
  //These are twhen energy ranges from 0 to 3090 MeV
  //f1->SetParameters(4.10647e-4, 8.27328e-4, -9.66426e-7, 7.24172e-10, -2.38441e-13, 2.90055e-17, 1.27802e-21,-5.47863e-25, 3090.42, 8.0975);
  

  TFile *f=new TFile("~/work/gain_study/root_files/gm2ringsim_truth.root");
  TString title="truthAnalyzer/track_e_all";
  TH1F *h2 = (TH1F *)f->Get(title);//gives N
  h2->GetXaxis()->SetLimits(0,1);
  
  TFile *f2 = new TFile("acceptance.root","READ");
  TH1F *acc = (TH1F *)f2->Get("overallAcceptance");//Has 1000 bins...
  //acc->Rebin(3.226);
  acc->GetXaxis()->SetLimits(0,1);
  acc->Fit("f1");
  
  TH1D* h_a = new TH1D("h_a","a1",bin,0.,1.);
  TH1D* h_b = new TH1D("h_b","b1",bin,0.,1.);
  TH1D* h_n = new TH1D("h_n","<N>",bin,0.,1.);
  for (Int_t i=1;i < bin+1; i++){ 
    //h_a1->SetBinContent(i,ha->GetBinContent(i)*TMath::Cos(hp->GetBinContent(i))*h->GetBinContent(i));
    //h_b1->SetBinContent(i,ha->GetBinContent(i)*TMath::Sin(hp->GetBinContent(i))*h->GetBinContent(i));
    //h_a1->SetBinContent(i,ha->GetBinContent(i)*hn->GetBinContent(i)*TMath::Cos(hp->GetBinContent(i))*h->GetBinContent(i));
    //h_b1->SetBinContent(i,ha->GetBinContent(i)*hn->GetBinContent(i)*TMath::Sin(hp->GetBinContent(i))*h->GetBinContent(i));

    h_a->SetBinContent(i,ha_1->GetBinContent(i)*acc->GetBinContent(i));
    h_b->SetBinContent(i,h2->GetBinContent(i)*hb_1->GetBinContent(i)*acc->GetBinContent(i));
    h_n->SetBinContent(i,hnx->GetBinContent(i)*acc->GetBinContent(i));
  }

  double total_a = h_a->Integral();
  double total_b = h_b->Integral();
  double total_n = h_n->Integral();

  TF1 *func = h_n->GetFunction("func");
  //printf("Integral histo n:%f, Integral func:%f \n", total_n,func->Integral(0,1,0.1));
  printf("Avg. phase %f \n", average);
 

  h_a->Draw();
  //h->Fit("f1");
  //h->Draw();
  //f1->Draw("same");
  //f1->Draw();
}


