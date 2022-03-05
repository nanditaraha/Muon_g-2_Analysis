
{
  //Here I plot the mean vs. sigma square of a ch. for each succesive run
  //TFile *_file0 = TFile::Open("july_1_4.root");
  //TFile *_file0 = TFile::Open("runs_1791_ro_1869_notrace.root");
  TFile *file = TFile::Open("calib_all.root");
  italianoTree->cd();
  //TGraphErrors *g_amp, *g_chi2;
  TString channel;
  TString name;
  TString condition;

  TH1F *hStable[6][24];// 2-d array of 2-d hist with # of runs (6) and channels

  TGraphErrors *h1[24];
  gStyle->SetPalette(1);
 
  double mean1[24];
  double chi2_1[24];
  double m_err1[24];
  double c_err1[24];
  double ch[24];
  double ch_e[24]={0};
  /*
  for (Int_t r = 2031; r < 2060; r++) {
    for (Int_t c = 0; c < 24; c++) {
      name.Form("h%d_%d",r,c);
      hStable[r-2031][c] = new TH2F(name.Data(),"",24,0,24,3000, 0, 60000);
    }
    }*/

for (Int_t r = 0; r < 6; r++) {
  for (Int_t c = 0; c < 24; c++) {
    condition.Form("channelNum==%d &&area_second_pulse>2000 && amplitude>500 && (runNum==2031+%d || runNum==2038+%d || runNum==2045+%d || runNum==2053+%d)",c,r,r,r,r);
    monitors->Draw("area_second_pulse>>h0", condition.Data(),"goff");
    TH1F *hmean = (TH1F*)gDirectory->Get("h0");
    //TF1 *f1 = new TF1("f1","[0]*exp(-0.5*((x-[1])/[2])**2)", hmean->GetMean()-5*hmean->GetRMS(), hmean->GetMean()+5*hmean->GetRMS() );
    //f1->SetParameters(20,hmean->GetMean(), hmean->GetRMS());
    cout<<"**************  IN THE LOOP c:"<<c+1<<" and run:"<<r<<"\n";
    hmean->Fit("gaus");
    if(r==0&&c==0) hmean->Draw();
    //h1[c]->SetPoint(r+1,f1->GetParameter(1),f1->GetParameter(2)*f1->GetParameter(2));
    //h1[c]->SetPointError(r+1,f1->GetParError(1),f1->GetParError(2)*2);
    //hStable[0][0]=h0;
    //hStable[0][0]->Draw();
    //h0->Draw();
  }
 }

//hStable[1][1]->Draw();
  /*
  for (Int_t c = 0; c < 24; c++) {
    name.Form("h1%d",c);
    h1[c] = new TGraphErrors(6);
    
  }
  
  int k;
  for (Int_t r = 0; r < 6; r++) {
    for (Int_t c = 0; c < 24; c++) {
      if(runNum<2051) k=r;
      if(runNum>2051) k=r+1;
      if(runNum!=2051){
	monitors->Draw("area_second_pulse:channelNum>h2","channelNum==c && amplitude>500 && area_second_pulse>2000 &&runNum==2031+k || runNum==2038+k || runNum==2045+k || runNum==2053+k");  
	hStable[r][c]= (TH2F*)gDirectory->Get("h2");
      }
    }
  }
  

  for(int i=0;i<6;i++){
    for (Int_t c = 0; c < 24; c++) {
      TH1F *hmean = (TH1F*)hStable[i][c]->ProjectionY();
      TF1 *f1 = new TF1("f1","[0]*exp(-0.5*((x-[1])/[2])**2)", hmean->GetMean()-5*hmean->GetRMS(), hmean->GetMean()+5*hmean->GetRMS() );
      f1->SetParameters(20,hmean->GetMean(), hmean->GetRMS());
      
      hmean->Fit("f1","RQ","", hmean->GetMean()-5*hmean->GetRMS(), hmean->GetMean()+5*hmean->GetRMS());
      //double mean = f1->GetParameter(1);
      
      //cout<<"Mean:"<<mean<<"\n";
      h1[c]->SetPoint(i+1,f1->GetParameter(1),f1->GetParameter(2)*f1->GetParameter(2));
      h1[c]->SetPointError(i+1,f1->GetParError(1),f1->GetParError(2)*2);
    }
  }
  
  //TProfile *p = hStable[0][0]->ProfileY();
  */
  //p->Draw();
  h1[0]->Draw("ap");
  
}
