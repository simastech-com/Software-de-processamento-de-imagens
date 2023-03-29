//---------------------------------------------------------------------------

#ifndef UFrmPrincipalH
#define UFrmPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TfrmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *mnuPrincipal;
	TMenuItem *mnuProcessamento;
	TMenuItem *mniAlgoritmos;
	TMenuItem *mniSobre;
	void __fastcall EvAlgoritmosOnClick(TObject *Sender);
	void __fastcall EvSobreOnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
