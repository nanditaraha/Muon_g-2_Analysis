//Good to learn - a convolution of two functions

#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TTree.h"
#include "TGraphErrors.h"
#include "TGraph.h"
#include "TMinuit.h"
#include "TMath.h"
#include "TRandom.h"

TF1 *g1,*g2,*g3,*g4,*g5;
TH1 *h1,*h2,*h3;
void Convolute()
{
  double sum = 0.0;
  int step = 1;
  TRandom ran;  
  TH1F *h1 = new TH1F("integral","h1",10,0,10);
  
  TH1F *h2 = new TH1F("stat","h2",10,0,10);
  TH1F *h3 = new TH1F("Convoluted","h3",50,-20,30);
  TF1 *f1 = new TF1("f1","2/(2+x)",0,10);
  h1->Eval(f1);
  //h1->Draw();
  
  for (int i=1; i<11;i++)
    {
      h2->SetBinContent(i,sqrt(i));
      //h2->SetBinContent(i,2*TMath::Exp(-0.5*i));
    }
  
  h2->SetLineColor(kRed);
  h2->Draw();
  //h1->Draw("sames");
  /*
  
  for (int j=0; j<50;j++)
   {
     sum=0.0;
     for(int i=0;i<40;i++)
       {
	 //sum += step*TMath::Gaus((j-(i+0.5)*step),0,6)*h1->GetBinContent((i+0.5)*step); More general function
	 sum += step*TMath::Gaus(i,j,2)*h1->GetBinContent(i);
	 //printf("Bin content of h2 %d and sum %d\n",h1->GetBinContent((i+0.5)*step),sum);
       }
             
     h3->SetBinContent(j,sum/5);
   }
 h3->SetLineColor(kGreen);
 h3->Draw("sames");
  */
}
