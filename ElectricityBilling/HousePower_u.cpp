//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HousePower_u.h"                                      // Total: 54
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmEB *frmEB;
//- Q1 ----------------------------------------------------------------------
__fastcall TfrmEB::TfrmEB(TComponent* Owner): TForm(Owner)
{
	countDisplay = -1;
	aList = new TStringList();
}
//------------------------------------------------------------------------
void __fastcall TfrmEB::tmrNumTimer(TObject *Sender)
{
	countDisplay++;
	if (countDisplay < 20)
	{
		int picNum = countDisplay % 10;
		imgNum->Picture->LoadFromFile("..\\..\\myData\\Num" + IntToStr(picNum)
			+ ".bmp");
		imgNum->Left = (picNum) * 68;
		Application->ProcessMessages();
	}
	else
	{
		tmrNum->Enabled = false;
		imgNum->Hide();
	}
}
//-----------------------------------------------------------------------
void __fastcall TfrmEB::btnLoadClick(TObject *Sender)
{
	lstAppliances->Items->LoadFromFile("..\\..\\MyData\\House_EBill.txt");
	btnAdd->Enabled = true;
}
//----------------------------------------------------------------------
void __fastcall TfrmEB::lstAppliancesClick(TObject *Sender)
{
	int indx = lstAppliances->ItemIndex;
	AnsiString ln = lstAppliances->Items->Strings[indx];

	if (indx > 1)
	{
		int posTab = ln.Pos('\t');
		edtPowerRate->Text = ln.SubString(1, posTab-1);
		ln.Delete(1, posTab);

		posTab = ln.Pos('\t');
		trkUsageM->Position = ln.SubString(1, posTab-1).ToInt();
		lblUsageM->Caption = ln.SubString(1, posTab-1) + " min";
		ln.Delete(1, posTab);

		edtAppliance->Text = ln;
	}
}
//-----------------------------------------------------------------------
AnsiString TfrmEB::CalculateExpenses(int mins, int applPower)
{
	double hours = 1.0 * mins / 60;
	double WhpDay = hours * applPower;
	AnsiString WhpDayS = FloatToStrF(WhpDay, ffFixed, 6, 0) + "Wh";
	double kWhpMnth = WhpDay * 30 / 1000;
	AnsiString kWhpMnthS = FloatToStrF(kWhpMnth, ffNumber, 6, 1) + "kWh";
	double costpMnth = kWhpMnth * StrToFloat(edtKWhCost->Text);
	AnsiString costpMnthS = FloatToStrF(costpMnth, ffCurrency, 6, 2);

	return(WhpDayS + "\t" + kWhpMnthS +"\t" + costpMnthS);
}
//----------------------------------------------------------------------
void __fastcall TfrmEB::btnCalculateClick(TObject *Sender)
{
	int total = 0;
	lstUsage->Clear();
	lstUsage->Items->Add("[Wh/Day]\t[kWh/Month]\t[Cost]-[ZAR]");
	lstUsage->Items->Add("========\t===========\t============");
	for (int i = 2; i < lstAppliances->Count; i++)
	{
		AnsiString ln = lstAppliances->Items->Strings[i];

		int posTab = ln.Pos('\t');
		int applPower = ln.SubString(1, posTab-1).ToInt();
		ln.Delete(1, posTab);

		posTab = ln.Pos('\t');
		int mins = ln.SubString(1, posTab-1).ToInt();

		lstUsage->Items->Add(CalculateExpenses(mins, applPower));
	}
	for (int i = 2; i < lstUsage->Items->Count; i++)
	{
		AnsiString ln = lstUsage->Items->Strings[i];
		AnsiString cost = ln.SubString(ln.LastDelimiter("R")+1, 10);
		total += cost.ToDouble();
	}
	edtTotal->Text = FloatToStrF(total, ffCurrency, 10, 2);
}
//-----------------------------------------------------------------------
void __fastcall TfrmEB::trkUsageMChange(TObject *Sender)
{
	lblUsageM->Caption = IntToStr(trkUsageM->Position) + " min";
}
//-----------------------------------------------------------------------
void __fastcall TfrmEB::btnAddClick(TObject *Sender)
{
	int powerRate;
	try
	{
		powerRate = edtPowerRate->Text.ToInt();
		if (powerRate > 3600)
		{
			MessageDlg(
				"No appliance's power rating\nis larger than 3600Watt\nPlease correct ...",
				mtWarning, TMsgDlgButtons()<<mbOK, 0);
		}
		else
		{
			AnsiString aLn = edtPowerRate->Text + "\t" +IntToStr(trkUsageM->Position)
				+ "\t" +  edtAppliance->Text ;
			lstAppliances->Items->Add(aLn);
		}
	}
	catch(...)
	{
		ShowMessage("Double check your 'power rating' input value!");
	}
}
//-----------------------------------------------------------------------
void __fastcall TfrmEB::bttSaveClick(TObject *Sender)
{
	outFile = "..\\..\\MyData\\EBill_"+FormatDateTime("yyyymmmdd", Now())+".dat";
	TStreamWriter *writeF = new TStreamWriter(outFile, false);

	for (int i = 0; i < lstAppliances->Count; i++)
	{
		AnsiString ln =
			lstUsage->Items->Strings[i] + "\t" + lstAppliances->Items->Strings[i];
		while (ln.Pos('\t') > 0)
			ln[ln.Pos('\t')] = '|';
		writeF->WriteLine(ln);
	}
	writeF->WriteLine();
	writeF->WriteLine("|TOTAL|" + edtTotal->Text);
	writeF->Close();
	lblSaved->Show();
}
//--------------------- Provided till here! ---------------------------------
//===========================================================================
//---------------------- CODE FROM HERE! ------------------------------------
AnsiString getFieldNr(AnsiString aLine, int fldNum, char delim)
{
	AnsiString field;
	aLine += delim;
	for(int i = 1; i <= fldNum; i++){
		int pos = aLine.Pos(delim);
		field = aLine.SubString(1, pos - 1);
		aLine.Delete(1, pos);
	}
    return field;
}
//---------------------------------------------------------------------------
void __fastcall TfrmEB::tbs2Show(TObject *Sender)
{
    strgEscom->Cells[0][0] = "Appliance Name";
	strgEscom->Cells[1][0] = "Cost [Rand]";
	strgEscom->Cells[2][0] = "Energy used [KWh / Month]";
	strgEscom->Cells[3][0] = "Time Active [Mins / Month]";
	strgEscom->ColWidths[0] = 120;
	strgEscom->ColWidths[1] = 100;
	strgEscom->ColWidths[2] = 150;
	strgEscom->ColWidths[3] = 160;
}

//---------------------------------------------------------------------------
void __fastcall TfrmEB::bttLoadClick(TObject *Sender)
{
// Load data from file into stringgrid
// aList = new TStringList(); moved to default constructor
	if (outFile.Length() < 10)
	{
		outFile = "..\\..\\MyData\\EBill_2021Feb20.dat";
	}

	aList->LoadFromFile(outFile);
	AnsiString ln, RawValue;
	strgEscom->RowCount = aList->Count-2;
	int i;
	for (i = 2; i < aList->Count-1; i++)
	{
		ln = aList->Strings[i];
		strgEscom->Cells[0][i-1] = getFieldNr(ln, 6, '|');
		strgEscom->Cells[1][i-1] = getFieldNr(ln, 3, '|');
		strgEscom->Cells[2][i-1] = getFieldNr(ln, 2, '|');
		strgEscom->Cells[3][i-1] = getFieldNr(ln, 5, '|');
	}

	ln = aList->Strings[i];
	strgEscom->Cells[0][i-2] = getFieldNr(ln, 2, '|');
	RawValue = getFieldNr(ln, 3, '|');
	RawValue.Delete(RawValue.AnsiPos(char(160))-1,1);
	strgEscom->Cells[1][i-2] = RawValue;
}
//---------------------------------------------------------------------------
void __fastcall TfrmEB::bttSortClick(TObject *Sender)
{
	int lst = strgEscom->RowCount -2;          //store last row
	bool swp = true;
	while (swp)                               //swap if true
	{
		swp = false;
		for (int i = 1; i < lst; i++)
		{
			if (StrToInt(strgEscom->Cells[3][i]) < StrToInt(strgEscom -> Cells[3][i+1]))
			{
				for (int k = 0; k < strgEscom->ColCount-1; k++)
				{
					AnsiString tmp = strgEscom->Cells[k][i];
					strgEscom->Cells[k][i] = strgEscom->Cells[k][i+1];
					strgEscom->Cells[k][i+1] = tmp;
				}
				swp = true;
			}
		}
		lst--;
	}
	 strgEscom->Invalidate();
}
//--- TAB 3 ------------------------------------------------------------------
void __fastcall TfrmEB::bttDisplayClick(TObject *Sender)
{
	if (aList->Count < 3) 								  // test if data is available
	{
		ShowMessage("No data to display - exiting!");
		exit;
	}


	TLabel *aLabel[10];                               	// Bar Graph
	TPanel *aPnlLbl[10];
	TProgressBar *aProgress[10];
	for (int i = 0; i < aList->Count-4; i++)
	{
		aPnlLbl[i] = new TPanel(this);          //Panels
		aPnlLbl[i]->Parent = pnlDiagram;
		aPnlLbl[i]->Top = 50 + (30 * i);
		aPnlLbl[i]->Left = 20;
		aPnlLbl[i]->Color = clAqua;
		aPnlLbl[i]->ParentBackground = false;
		aPnlLbl[i]->Height = 20;
		aPnlLbl[i]->Width = 120;

		aLabel[i] = new TLabel(this);        //Lables for graph
		aLabel[i]->Parent = aPnlLbl[i];
		aLabel[i]->Top = 4;
		aLabel[i]->Left = 10;
		aLabel[i]->Caption = strgEscom->Cells[0][i+1] + " - " + strgEscom->Cells[1][i+1];
		aLabel[i]->Font->Color = clBlack;

		aProgress[i] = new TProgressBar(this);      //Progress Bar
		aProgress[i]->Parent = pnlDiagram;
		aProgress[i]->Top = 50 + (30 * i);
		aProgress[i]->Left = 150;
		aProgress[i]->Width = 450;
		aProgress[i]->Height = 20;
		aProgress[i]->Tag = 5;
		AnsiString tmp = strgEscom->Cells[1][i+1];
		tmp.Delete(1, 1);
		int costs = int (tmp.ToDouble()) * 1;
		aProgress[i]->Max = 500;
		aProgress[i]->Position = costs;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmEB::bttDeleteClick(TObject *Sender)
{
	int cnts = pnlDiagram->ControlCount;
	for (int i = cnts-1; i >= 0; i--)
	{
		if (pnlDiagram->Controls[i]->Tag == 5)
		{
			delete pnlDiagram->Controls[i];
		}
		pnlDiagram->Refresh();

		Application->ProcessMessages();
		Sleep(100);
	}
}
//------------------------------  end of assignm 4  ------------------------


