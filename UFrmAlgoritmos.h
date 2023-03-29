//---------------------------------------------------------------------------

#ifndef UFrmAlgoritmosH
#define UFrmAlgoritmosH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TFrmAlgoritmos : public TForm
{
__published:	// IDE-managed Components
	TOpenPictureDialog *pdgAbrirImagem;
	TChart *grfOriginal;
	TChart *grfModificado;
	TBarSeries *Series2;
	TBarSeries *Series1;
	TPanel *pnlImgOriginal;
	TImage *imgOriginal;
	TPanel *pnlImgModificado;
	TImage *imgAlteracao;
	TPanel *pnlControles;
	TButton *btnCarregarImagem;
	TPanel *pnlSegmentacao;
	TPanel *pnlInfo;
	TLabel *lblAltura;
	TEdit *edtAltura;
	TEdit *edtLargura;
	TLabel *lblLargura;
	TLabel *lblTotalPixels;
	TEdit *edtTotalPixels;
	TEdit *edtPixelsProcessados;
	TLabel *lblPixelsProcessados;
	TLabel *lblTituloSegmentacao;
	TLabel *lblLimiar;
	TEdit *edtLimiar;
	TButton *btnBinarizacao;
	TLabel *lblCanais;
	TEdit *edtCanal;
	TButton *btnQuantizacao;
	TButton *btnEqualizacao;
	TPanel *pnlPassaBaixa;
	TLabel *lblTituloPassaBaixa;
	TButton *btnMedia;
	TButton *btnMediana;
	TButton *btnModa;
	TLabel *lblTituloEstatisticas;
	TPanel *pnlPassaAlta;
	TLabel *lblTituloPassaAlta;
	TButton *btnSobel;
	TButton *btnRoberts;
	TButton *btnLaplaciano;
	TButton *btnPrewittOnClick;
	void __fastcall EvCarregarImagemOnClick(TObject *Sender);
	void __fastcall EvBinarizacaoClick(TObject *Sender);
	void __fastcall gerarHistogramaOriginal();
	void __fastcall gerarHistogramaAlterado();
	void __fastcall EvQuantizacaoOnClick(TObject *Sender);
	void __fastcall EvEqualizacaoOnClick(TObject *Sender);
	void __fastcall EvMediaOnClick(TObject *Sender);
	void __fastcall EvMedianaOnClick(TObject *Sender);
	void __fastcall EvModaOnClick(TObject *Sender);
	void __fastcall EvSobelOnClick(TObject *Sender);
	void __fastcall EvRobertsOnClick(TObject *Sender);
	void __fastcall EvLaplacianoOnClick(TObject *Sender);
	void __fastcall EvPrewittOnClick(TObject *Sender);
	void __fastcall EvOnClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
	String caminhoArquivo;
public:		// User declarations
	__fastcall TFrmAlgoritmos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrmAlgoritmos *FrmAlgoritmos;
//---------------------------------------------------------------------------
#endif
