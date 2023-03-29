//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "UFrmAlgoritmos.h"
#include "UEstatisticaCor.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrmAlgoritmos *FrmAlgoritmos;
//---------------------------------------------------------------------------
__fastcall TFrmAlgoritmos::TFrmAlgoritmos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvCarregarImagemOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	int aux;
	if(pdgAbrirImagem->Execute())
	{
		FrmAlgoritmos->Caption = "Carregando a imagem...";
		caminhoArquivo = pdgAbrirImagem->FileName;
		imgOriginal->Picture->LoadFromFile(caminhoArquivo);
		imgAlteracao->Picture->LoadFromFile(caminhoArquivo);

		linha = imgOriginal->Picture->Height;
		edtAltura->Text = linha;
		coluna = imgOriginal->Picture->Width;
		edtLargura->Text = coluna;
		aux = linha * coluna;
		edtTotalPixels->Text = aux;
		edtPixelsProcessados->Text="";
		gerarHistogramaOriginal();
		gerarHistogramaAlterado();
		FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvBinarizacaoClick(TObject *Sender)
{
	int linha;
	int coluna;
	int pixel;
	TColor cor;
	int qtd=0;
	int auxiliar[256];
	for (int i = 0; i < 256; i++) 
	{
		auxiliar[i] = 0;
	}
	if (imgOriginal ->Picture->Height != 0)
	{		
		if (edtLimiar->Text != "")
		{
			imgAlteracao->Picture = NULL;
			imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
			FrmAlgoritmos->Caption = "Aplicando a binarização...";
			linha = imgOriginal->Picture->Height;
			coluna = imgOriginal->Picture->Width;
			for(int i=0; i<linha; i++)
			{
				for(int j=0; j<coluna; j++)
				{
					 cor=imgOriginal->Canvas->Pixels[j][i];
					 pixel = GetRValue(cor);
					 if(pixel < StrToInt(edtLimiar->Text))
					 {
						 pixel = 0;
					 }
					 else
					 {
						 pixel = 255;
					 }
					 imgAlteracao->Canvas->Pixels[j][i] = RGB(pixel, pixel, pixel);
					 auxiliar[pixel]++;
				}
			}
			gerarHistogramaOriginal();
			gerarHistogramaAlterado();
			for (int i = 0; i < 256; i++) 
			{
				qtd += auxiliar[i];	
			}
			edtPixelsProcessados->Text = qtd;
			FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
		}
		else
		{
			ShowMessage("Preencha o valor do limiar!");
		}
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::gerarHistogramaOriginal()
{
	Series1->Clear();
	int auxiliar[256];
	int auxLinha;
	int auxColuna;
	int auxPixel;
	TColor auxCor;
	int maior = 0;
	if (imgOriginal ->Picture->Height != 0)
	{
		FrmAlgoritmos->Caption = "Gerando histograma da imagem original...";
		for(int x=0; x<256; x++)
		{
			auxiliar[x] = 0;
		}

		auxLinha = imgOriginal->Picture->Height;
		auxColuna = imgOriginal->Picture->Width;

		for(int i=0; i<auxLinha; i++)
		{
			for(int j=0; j<auxColuna; j++)
			{
				 auxCor=imgOriginal->Canvas->Pixels[j][i];
				 auxPixel = GetRValue(auxCor);
				 auxiliar[auxPixel]++;
				 if(maior < auxiliar[auxPixel])
				 {
					maior = auxiliar[auxPixel];
				 }
			}
		}
		grfOriginal -> LeftAxis -> Maximum = maior;
		grfOriginal -> BottomAxis -> Maximum = 255;
		for(int x=0; x<256; x++)
		{
			Series1-> AddXY(x, auxiliar[x], "", TColor(x,x,x));
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::gerarHistogramaAlterado()
{
	Series2->Clear();
	int auxiliar[256];
	int auxLinha;
	int auxColuna;
	int auxPixel;
	TColor auxCor;
	int maior = 0;
	if (imgAlteracao ->Picture->Height != 0)
	{
		FrmAlgoritmos->Caption = "Gerando histograma da imagem alterada...";
		for(int x=0; x<256; x++)
		{
			auxiliar[x] = 0;
		}

		auxLinha = imgAlteracao ->Picture->Height;
		auxColuna = imgAlteracao ->Picture->Width;

		for(int i=0; i<auxLinha; i++)
		{
			for(int j=0; j<auxColuna; j++)
			{
				 auxCor=imgAlteracao->Canvas->Pixels[j][i];
				 auxPixel = GetRValue(auxCor);
				 auxiliar[auxPixel]++;
				 if(maior < auxiliar[auxPixel])
				 {
					maior = auxiliar[auxPixel];
				 }
			}
		}
		grfModificado -> LeftAxis -> Maximum = maior;
		grfModificado -> BottomAxis -> Maximum = 255;
		for(int x=0; x<256; x++)
		{
			Series2-> AddXY(x, auxiliar[x], "", TColor(x,x,x));
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvQuantizacaoOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	TColor cor;
	int pixel;
	int qtd=0;
	int auxiliar[256];
	for (int i = 0; i < 256; i++)
	{
		auxiliar[i] = 0;
	}

	if (imgOriginal ->Picture-> Height != 0)
	{
		if (edtCanal->Text != "")
		{
			if ((StrToInt(edtCanal->Text) > 0) && (StrToInt(edtCanal->Text) <128))
			{
				imgAlteracao->Picture = NULL;
				imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
				FrmAlgoritmos->Caption = "Aplicando a quantização...";
				linha = imgOriginal->Picture->Height;
				coluna = imgOriginal->Picture->Width;
				int divisao = 256/(StrToInt(edtCanal->Text));
				int auxiliarValor;

				for(int i=0; i<linha; i++)
				{
					for(int j=0; j<coluna; j++)
					{
						 cor=imgOriginal->Canvas->Pixels[j][i];
						 pixel = GetRValue(cor);
						 auxiliarValor = pixel%(divisao);
						 auxiliarValor = divisao-auxiliarValor-1;
						 pixel+=auxiliarValor;
						 auxiliar[pixel]++;
						 imgAlteracao->Canvas->Pixels[j][i] = RGB(pixel, pixel, pixel);
					}
				}
				gerarHistogramaOriginal();
				gerarHistogramaAlterado();
				for (int i = 0; i < 256; i++)
				{
					qtd += auxiliar[i];
				}
				edtPixelsProcessados->Text = qtd;
				FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
			}
			else
			{
				ShowMessage("Informe uma quantidade de canais entre 1 e 127!");
			}
		}
		else
		{
			ShowMessage("Informe a quantidade de canais!");
		}
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvEqualizacaoOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	TColor cor;
	int pixel;
	int qtd=0;
	int auxiliar[256];
	int novo[256];
	int ideal;
	for (int i = 0; i < 256; i++)
	{
		auxiliar[i] = 0;
		novo[i] = 0;
	}

	if (imgOriginal ->Picture-> Height != 0)
	{
		imgAlteracao->Picture = NULL;
		imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
		FrmAlgoritmos->Caption = "Aplicando a equalização...";
		linha = imgOriginal->Picture->Height;
		coluna = imgOriginal->Picture->Width;
		ideal = (linha * coluna)/256;

		for(int i=0; i<linha; i++)
		{
			for(int j=0; j<coluna; j++)
			{
				cor=imgOriginal->Canvas->Pixels[j][i];
				pixel = GetRValue(cor);
				auxiliar[pixel]++;
			}
		}
		int auxiliarValor = 0;
		for(int i=0; i<256; i++)
		{
			auxiliarValor += auxiliar[i];
			if(((auxiliarValor/ideal)-1)>0)
			{
				novo[i] = (auxiliarValor/ideal)-1;
			}
			else
			{
				novo[i] = 0;
			}
		}
		for(int i=0; i<linha; i++)
		{
			for(int j=0;j<coluna; j++)
			{
				cor=imgOriginal->Canvas->Pixels[j][i];
				pixel = GetRValue(cor);
				imgAlteracao->Canvas->Pixels[j][i] = RGB(novo[pixel], novo[pixel], novo[pixel]);
			}
		}
		gerarHistogramaOriginal();
		gerarHistogramaAlterado();
		for (int i = 0; i < 256; i++)
		{
			qtd += auxiliar[i];
		}
		edtPixelsProcessados->Text = qtd;
		FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvMediaOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	TColor cor;
	int pixel;
	int qtd=0;
	int soma;
	int media;

	if (imgOriginal ->Picture-> Height != 0)
	{
		imgAlteracao->Picture = NULL;
		imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
		FrmAlgoritmos->Caption = "Aplicando a média de vizinhança...";
		linha = imgOriginal->Picture->Height;
		coluna = imgOriginal->Picture->Width;

		for(int i=1; i<linha-1; i++)
		{
			for(int j=1; j<coluna-1; j++)
			{
				soma = 0;
				for(int l=i-1; l<=i+1;l++)
				{
					for(int c=j-1; c<=j+1; c++)
					{
						cor=imgOriginal->Canvas->Pixels[c][l];
						pixel = GetRValue(cor);
						soma += pixel;
					}
				}
				media = soma/9;
				imgAlteracao->Canvas->Pixels[j][i] = RGB(media, media, media);
				qtd++;
			}
		}
		gerarHistogramaOriginal();
		gerarHistogramaAlterado();
		edtPixelsProcessados->Text = qtd;
		FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvMedianaOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	TColor cor;
	int pixel;
	int qtd=0;
	int contador;
	int auxiliar[9];
	int aux;

	for(int x=0; x<9; x++)
	{
		auxiliar[x] = 0;
	}
	if (imgOriginal ->Picture-> Height != 0)
	{
		imgAlteracao->Picture = NULL;
		imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
		FrmAlgoritmos->Caption = "Aplicando a mediana...";
		linha = imgOriginal->Picture->Height;
		coluna = imgOriginal->Picture->Width;

		for(int i=1; i<linha-1; i++)
		{
			for(int j=1; j<coluna-1; j++)
			{
				contador = 0;
				for(int l=i-1; l<=i+1;l++)
				{
					for(int c=j-1; c<=j+1; c++)
					{
						cor=imgOriginal->Canvas->Pixels[c][l];
						pixel = GetRValue(cor);
						auxiliar[contador] = pixel;
						contador++;
					}
				}
				for(int x=0; x<8; x++)
				{
					for(int y=x+1; y<9; y++)
					{
						if(auxiliar[y] < auxiliar[x])
						{
							aux = auxiliar[x];
							auxiliar[x] = auxiliar[y];
							auxiliar[y] = aux;
						}
					}
				}
				imgAlteracao->Canvas->Pixels[j][i] = RGB(auxiliar[4], auxiliar[4], auxiliar[4]);
				qtd++;
			}
		}
		gerarHistogramaOriginal();
		gerarHistogramaAlterado();
		edtPixelsProcessados->Text = qtd;
		FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvModaOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	TColor cor;
	int pixel;
	int qtd=0;
	int maior;
	int auxiliar[256];
	int aux;
	int pixelEscolhido;
	int diferenca;

	if (imgOriginal ->Picture-> Height != 0)
	{
		imgAlteracao->Picture = NULL;
		imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
		FrmAlgoritmos->Caption = "Aplicando a moda...";
		linha = imgOriginal->Picture->Height;
		coluna = imgOriginal->Picture->Width;

		for(int i=1; i<linha-1; i++)
		{
			for(int j=1; j<coluna-1; j++)
			{
				for (int k = 0; k < 256; k++)
				{
					auxiliar[k] = 0;
				}

				for(int l=i-1; l<=i+1;l++)
				{
					for(int c=j-1; c<=j+1; c++)
					{
						if(!(c==j && l==i))
						{
							cor=imgOriginal->Canvas->Pixels[c][l];
							pixel = GetRValue(cor);
							auxiliar[pixel]++;
						}
					}
				}

				cor=imgOriginal->Canvas->Pixels[j][i];
				pixel = GetRValue(cor);
				pixelEscolhido = pixel;
				maior = auxiliar[pixel];

				for(int x=1; x< 256; x++)
				{
					if((pixel - x) >= 0)
					{
						 if(auxiliar[pixel - x] > maior)
						{
							maior = auxiliar[pixel - x];
							pixelEscolhido = pixel - x;
						}
					}

					if((pixel + x) < 256)
					{
						if(auxiliar[pixel + x] > maior)
						{
							maior = auxiliar[pixel + x];
							pixelEscolhido = pixel + x;
						}
					}
				}
				imgAlteracao->Canvas->Pixels[j][i] = RGB(pixelEscolhido, pixelEscolhido, pixelEscolhido);
				qtd++;
			}
		}
		gerarHistogramaOriginal();
		gerarHistogramaAlterado();
		edtPixelsProcessados->Text = qtd;
		FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvSobelOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	TColor cor;
	int pixel;
	int qtd=0;
	int aux;
	int gradX;
	int gradY;
	int matrizX[3][3] = {{1, 0, -1}, {2, 0, -2}, {1, 0, -1}};
	int matrizY[3][3] = {{1, 2, 1}, {0, 0, 0}, {-1, -2, -1}};

	if (imgOriginal ->Picture-> Height != 0)
	{
		imgAlteracao->Picture = NULL;
		imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
		FrmAlgoritmos->Caption = "Aplicando o filtro de Sobel...";
		linha = imgOriginal->Picture->Height;
		coluna = imgOriginal->Picture->Width;

		for(int i=1; i<linha-1; i++)
		{
			for(int j=1; j<coluna-1; j++)
			{
				gradX = 0;
				gradY = 0;
				for(int l=i-1; l<=i+1;l++)
				{
					for(int c=j-1; c<=j+1; c++)
					{
						cor=imgOriginal->Canvas->Pixels[c][l];
						pixel = GetRValue(cor);
						gradX += pixel * matrizX[l-i+1][c-j+1];
						gradY += pixel * matrizY[l-i+1][c-j+1];
					}
				}
				gradX /= 4;
				gradY /= 4;

				aux = (int) (sqrt(gradX * gradX + gradY * gradY));
				imgAlteracao->Canvas->Pixels[j][i] = RGB(aux, aux, aux);
				qtd++;
			}
		}
		gerarHistogramaOriginal();
		gerarHistogramaAlterado();
		edtPixelsProcessados->Text = qtd;
		FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvRobertsOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	TColor cor;
	int pixel;
	int qtd=0;
	int aux;
	int gradX;
	int gradY;
	int matrizX[3][3] = {{0, 0, -1}, {0, 1, 0}, {0, 0, 0}};
	int matrizY[3][3] = {{-1, 0, 0}, {0, 1, 0}, {0, 0, 0}};

	if (imgOriginal ->Picture-> Height != 0)
	{
		imgAlteracao->Picture = NULL;
		imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
		FrmAlgoritmos->Caption = "Aplicando o filtro de Roberts...";
		linha = imgOriginal->Picture->Height;
		coluna = imgOriginal->Picture->Width;

		for(int i=1; i<linha-1; i++)
		{
			for(int j=1; j<coluna-1; j++)
			{
				gradX = 0;
				gradY = 0;
				for(int l=i-1; l<=i+1;l++)
				{
					for(int c=j-1; c<=j+1; c++)
					{
						cor=imgOriginal->Canvas->Pixels[c][l];
						pixel = GetRValue(cor);
						gradX += pixel * matrizX[l-i+1][c-j+1];
						gradY += pixel * matrizY[l-i+1][c-j+1];
					}
				}

				aux = (int) (sqrt(gradX * gradX + gradY * gradY));
				imgAlteracao->Canvas->Pixels[j][i] = RGB(aux, aux, aux);
				qtd++;
			}
		}
		gerarHistogramaOriginal();
		gerarHistogramaAlterado();
		edtPixelsProcessados->Text = qtd;
		FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvLaplacianoOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	TColor cor;
	int pixel;
	int qtd=0;
	int aux;
	int gradX;
	int gradY;
	int matrizX[3][3] = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};
	int matrizY[3][3] = {{-1, -1, -1}, {-1, 8, -1}, {-1, -1, -1}};

	if (imgOriginal ->Picture-> Height != 0)
	{
		imgAlteracao->Picture = NULL;
		imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
		FrmAlgoritmos->Caption = "Aplicando o filtro Laplaciano...";
		linha = imgOriginal->Picture->Height;
		coluna = imgOriginal->Picture->Width;

		for(int i=1; i<linha-1; i++)
		{
			for(int j=1; j<coluna-1; j++)
			{
				gradX = 0;
				gradY = 0;
				for(int l=i-1; l<=i+1;l++)
				{
					for(int c=j-1; c<=j+1; c++)
					{
						cor=imgOriginal->Canvas->Pixels[c][l];
						pixel = GetRValue(cor);
						gradX += pixel * matrizX[l-i+1][c-j+1];
						gradY += pixel * matrizY[l-i+1][c-j+1];
					}
				}
				gradX /= 4;
				gradY /= 4;

				aux = (int) (sqrt(gradX * gradX + gradY * gradY));
				imgAlteracao->Canvas->Pixels[j][i] = RGB(aux, aux, aux);
				qtd++;
			}
		}
		gerarHistogramaOriginal();
		gerarHistogramaAlterado();
		edtPixelsProcessados->Text = qtd;
		FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TFrmAlgoritmos::EvPrewittOnClick(TObject *Sender)
{
	int linha;
	int coluna;
	TColor cor;
	int pixel;
	int qtd=0;
	int aux;
	int gradX;
	int gradY;
	int matrizX[3][3] = {{-1, 0, 1}, {-1, 0, 1}, {-1, 0, 1}};
	int matrizY[3][3] = {{-1, -1, -1}, {0, 0, 0}, {1, 1, 1}};

	if (imgOriginal ->Picture-> Height != 0)
	{
		imgAlteracao->Picture = NULL;
		imgAlteracao->Picture->Bitmap->SetSize(imgOriginal ->Picture->Width,imgOriginal ->Picture->Height);
		FrmAlgoritmos->Caption = "Aplicando o filtro Prewitt...";
		linha = imgOriginal->Picture->Height;
		coluna = imgOriginal->Picture->Width;

		for(int i=1; i<linha-1; i++)
		{
			for(int j=1; j<coluna-1; j++)
			{
				gradX = 0;
				gradY = 0;
				for(int l=i-1; l<=i+1;l++)
				{
					for(int c=j-1; c<=j+1; c++)
					{
						cor=imgOriginal->Canvas->Pixels[c][l];
						pixel = GetRValue(cor);
						gradX += pixel * matrizX[l-i+1][c-j+1];
						gradY += pixel * matrizY[l-i+1][c-j+1];
					}
				}
				gradX /= 4;
				gradY /= 4;

				aux = (int) (sqrt(gradX * gradX + gradY * gradY));
				imgAlteracao->Canvas->Pixels[j][i] = RGB(aux, aux, aux);
				qtd++;
			}
		}
		gerarHistogramaOriginal();
		gerarHistogramaAlterado();
		edtPixelsProcessados->Text = qtd;
		FrmAlgoritmos->Caption = "Algoritmos de processamento de imagem digital.";
	}
	else
	{
		ShowMessage("Carregue a imagem antes!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TFrmAlgoritmos::EvOnClose(TObject *Sender, TCloseAction &Action)
{
	Action = caFree;
}
//---------------------------------------------------------------------------

