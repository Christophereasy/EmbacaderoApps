//---------------------------------------------------------------------------

#ifndef HousePower_uH
#define HousePower_uH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TfrmEB : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label7;
	TLabel *Label6;
	TEdit *edtKWhCost;
	TLabel *Label1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TEdit *edtTotal;
	TTimer *tmrNum;
	TBitBtn *bttSave;
	TButton *btnCalculate;
	TListBox *lstUsage;
	TButton *btnLoad;
	TListBox *lstAppliances;
	TPanel *Panel2;
	TLabel *Label3;
	TLabel *lblUsageM;
	TLabel *lblHeader2;
	TLabel *lblHeader1;
	TButton *btnAdd;
	TEdit *edtAppliance;
	TTrackBar *trkUsageM;
	TEdit *edtPowerRate;
	TLabel *lblSaved;
	TLabel *Label2;
	TImage *imgNum;
	TTabSheet *tbs2;
	TTabSheet *tbs3;
	TStringGrid *strgEscom;
	TBitBtn *bttLoad;
	TPanel *pnlDiagram;
	TLabel *Label4;
	TLabel *Label5;
	TShape *shpLeft;
	TShape *shpBottom;
	TLabel *Label8;
	TLabel *Label9;
	TBitBtn *bttDisplay;
	TBitBtn *bttDelete;
	TBitBtn *bttSort;
	void __fastcall btnLoadClick(TObject *Sender);
	void __fastcall lstAppliancesClick(TObject *Sender);
	void __fastcall btnCalculateClick(TObject *Sender);
	void __fastcall trkUsageMChange(TObject *Sender);
	void __fastcall btnAddClick(TObject *Sender);
	void __fastcall bttSaveClick(TObject *Sender);
	void __fastcall tmrNumTimer(TObject *Sender);
	void __fastcall tbs2Show(TObject *Sender);
	void __fastcall bttLoadClick(TObject *Sender);
	void __fastcall bttDisplayClick(TObject *Sender);
	void __fastcall bttDeleteClick(TObject *Sender);
	void __fastcall bttSortClick(TObject *Sender);
private:	// User declarations
	 int countDisplay;
	 TStringList *aList;
	 AnsiString outFile;
   int NrAppliances;
public:		// User declarations
	__fastcall TfrmEB(TComponent* Owner);
	AnsiString CalculateExpenses(int mins, int applPower);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmEB *frmEB;
//---------------------------------------------------------------------------
#endif
