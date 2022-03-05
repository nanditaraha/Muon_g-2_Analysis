
{
  //Here I plot the mean vs. sigma square of a ch. for each succesive run
  //TFile *_file0 = TFile::Open("july_1_4.root");
  //TFile *_file0 = TFile::Open("runs_1791_ro_1869_notrace.root");
  TFile *file = TFile::Open("calib_new23.root");
  italianoTree->cd();
  //TGraphErrors *g_amp, *g_chi2;
  TString hist;
  TString name;
  TString condition;


  //TH1F *hmean[24][6];// 2-d array of 2-d hist with 

  TGraph *gr;//[24];
  gStyle->SetPalette(1);
 
  double mean[7];
  double sigma[7];
  double m_err1[7];
  double c_err1[7];
  double ch[7]={0};
  double ch_e[7]={0};
  
  monitors->Draw("area_second_pulse>>h0","channelNum==3 &&area_second_pulse>2000 && amplitude>500 && runNum==2312");
  mean[0]=h0->GetMean();
  sigma[0]=h0->GetRMS()*h0->GetRMS();

  monitors->Draw("area_second_pulse>>h1","channelNum==3 &&area_second_pulse>2000 && amplitude>500 && runNum==2313");
  mean[1]=h1->GetMean();
  sigma[1]=h1->GetRMS()*h1->GetRMS();

  monitors->Draw("area_second_pulse>>h2","channelNum==3 &&area_second_pulse>2000 && amplitude>500 && runNum==2314");
  mean[2]=h2->GetMean();
  sigma[2]=h2->GetRMS()*h2->GetRMS();

  monitors->Draw("area_second_pulse>>h3","channelNum==3 &&area_second_pulse>2000 && amplitude>500 && runNum==2315");
  mean[3]=h3->GetMean();
  sigma[3]=h3->GetRMS()*h3->GetRMS();

  monitors->Draw("area_second_pulse>>h4","channelNum==3 &&area_second_pulse>2000 && amplitude>500 && runNum==2316");
  mean[4]=h4->GetMean();
  sigma[4]=h4->GetRMS()*h4->GetRMS();

  monitors->Draw("area_second_pulse>>h5","channelNum==3 &&area_second_pulse>2000 && amplitude>500 && runNum==2317");
  mean[5]=h5->GetMean();
  sigma[5]=h5->GetRMS()*h5->GetRMS();

  monitors->Draw("area_second_pulse>>h6","channelNum==3 &&area_second_pulse>2000 && amplitude>500 && runNum==2318");
  mean[6]=h6->GetMean();
  sigma[6]=h6->GetRMS()*h6->GetRMS();

  gr = new TGraph(7,mean,sigma); 
  gr->Draw("ap");
  
}
