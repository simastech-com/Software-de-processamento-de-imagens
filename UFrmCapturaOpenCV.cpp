//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFrmCapturaOpenCV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmCapturaOpenCV *FrmCapturaOpenCV;
//---------------------------------------------------------------------------
__fastcall TFrmCapturaOpenCV::TFrmCapturaOpenCV(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmCapturaOpenCV::EvOnClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------
