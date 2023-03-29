object FrmAlgoritmos: TFrmAlgoritmos
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Algoritmos de processamento de imagem digital.'
  ClientHeight = 633
  ClientWidth = 1010
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poMainFormCenter
  Visible = True
  OnClose = EvOnClose
  PixelsPerInch = 96
  TextHeight = 13
  object grfOriginal: TChart
    Left = 228
    Top = 340
    Width = 380
    Height = 285
    Legend.Visible = False
    Title.Text.Strings = (
      'Histograma')
    BottomAxis.Title.Caption = 'Tonalidade'
    LeftAxis.Title.Caption = 'Quantidade'
    TabOrder = 0
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object grfModificado: TChart
    Left = 622
    Top = 340
    Width = 380
    Height = 285
    Legend.Visible = False
    Title.Text.Strings = (
      'Histograma')
    BottomAxis.Title.Caption = 'Tonalidade'
    LeftAxis.Title.Caption = 'Quantidade'
    TabOrder = 1
    ColorPaletteIndex = 13
    object Series2: TBarSeries
      Marks.Arrow.Visible = True
      Marks.Callout.Brush.Color = clBlack
      Marks.Callout.Arrow.Visible = True
      Marks.Visible = False
      Title = 'seriaModificado'
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object pnlImgOriginal: TPanel
    Left = 263
    Top = 10
    Width = 310
    Height = 310
    TabOrder = 2
    object imgOriginal: TImage
      Left = 5
      Top = 5
      Width = 300
      Height = 300
      Stretch = True
    end
  end
  object pnlImgModificado: TPanel
    Left = 657
    Top = 10
    Width = 310
    Height = 310
    TabOrder = 3
    object imgAlteracao: TImage
      Left = 5
      Top = 5
      Width = 300
      Height = 300
      Constraints.MinHeight = 300
      Constraints.MinWidth = 300
      Stretch = True
    end
  end
  object pnlControles: TPanel
    Left = 0
    Top = 0
    Width = 210
    Height = 625
    TabOrder = 4
    object btnCarregarImagem: TButton
      Left = 5
      Top = 5
      Width = 201
      Height = 25
      Caption = 'Carregar imagem...'
      TabOrder = 0
      OnClick = EvCarregarImagemOnClick
    end
    object pnlSegmentacao: TPanel
      Left = 4
      Top = 36
      Width = 200
      Height = 141
      TabOrder = 1
      object lblTituloSegmentacao: TLabel
        Left = 36
        Top = 5
        Width = 128
        Height = 13
        Caption = 'Algorimos de segmenta'#231#227'o'
      end
      object lblLimiar: TLabel
        Left = 12
        Top = 40
        Width = 27
        Height = 13
        Caption = 'Limiar'
      end
      object lblCanais: TLabel
        Left = 12
        Top = 70
        Width = 32
        Height = 13
        Caption = 'Canais'
      end
      object edtLimiar: TEdit
        Left = 50
        Top = 37
        Width = 50
        Height = 21
        NumbersOnly = True
        TabOrder = 0
      end
      object btnBinarizacao: TButton
        Left = 108
        Top = 35
        Width = 84
        Height = 25
        Caption = 'Binariza'#231#227'o'
        TabOrder = 1
        OnClick = EvBinarizacaoClick
      end
      object edtCanal: TEdit
        Left = 50
        Top = 66
        Width = 50
        Height = 21
        NumbersOnly = True
        TabOrder = 2
      end
      object btnQuantizacao: TButton
        Left = 108
        Top = 64
        Width = 84
        Height = 25
        Caption = 'Quantiza'#231#227'o'
        TabOrder = 3
        OnClick = EvQuantizacaoOnClick
      end
      object btnEqualizacao: TButton
        Left = 9
        Top = 100
        Width = 183
        Height = 25
        Caption = 'Equaliza'#231#227'o'
        TabOrder = 4
        OnClick = EvEqualizacaoOnClick
      end
    end
    object pnlInfo: TPanel
      Left = 4
      Top = 472
      Width = 200
      Height = 141
      TabOrder = 2
      object lblAltura: TLabel
        Left = 133
        Top = 35
        Width = 29
        Height = 13
        Caption = 'Altura'
      end
      object lblLargura: TLabel
        Left = 31
        Top = 35
        Width = 37
        Height = 13
        Caption = 'Largura'
      end
      object lblTotalPixels: TLabel
        Left = 15
        Top = 85
        Width = 69
        Height = 13
        Caption = 'Total de pixels'
      end
      object lblPixelsProcessados: TLabel
        Left = 103
        Top = 85
        Width = 90
        Height = 13
        Caption = 'Pixels processados'
      end
      object lblTituloEstatisticas: TLabel
        Left = 73
        Top = 5
        Width = 54
        Height = 13
        Caption = 'Estat'#237'sticas'
      end
      object edtAltura: TEdit
        Left = 103
        Top = 50
        Width = 90
        Height = 21
        Alignment = taCenter
        Enabled = False
        TabOrder = 0
      end
      object edtLargura: TEdit
        Left = 5
        Top = 50
        Width = 90
        Height = 21
        Alignment = taCenter
        Enabled = False
        TabOrder = 1
      end
      object edtTotalPixels: TEdit
        Left = 5
        Top = 100
        Width = 90
        Height = 21
        Alignment = taCenter
        Enabled = False
        TabOrder = 2
      end
      object edtPixelsProcessados: TEdit
        Left = 103
        Top = 100
        Width = 90
        Height = 21
        Alignment = taCenter
        Enabled = False
        TabOrder = 3
      end
    end
    object pnlPassaBaixa: TPanel
      Left = 4
      Top = 178
      Width = 200
      Height = 127
      TabOrder = 3
      object lblTituloPassaBaixa: TLabel
        Left = 44
        Top = 5
        Width = 111
        Height = 13
        Caption = 'Algoritmos passa-baixa'
      end
      object btnMedia: TButton
        Left = 9
        Top = 35
        Width = 183
        Height = 25
        Caption = 'M'#233'dia'
        TabOrder = 0
        OnClick = EvMediaOnClick
      end
      object btnMediana: TButton
        Left = 9
        Top = 60
        Width = 183
        Height = 25
        Caption = 'Mediana'
        TabOrder = 1
        OnClick = EvMedianaOnClick
      end
      object btnModa: TButton
        Left = 9
        Top = 85
        Width = 183
        Height = 25
        Caption = 'Moda'
        TabOrder = 2
        OnClick = EvModaOnClick
      end
    end
    object pnlPassaAlta: TPanel
      Left = 4
      Top = 306
      Width = 200
      Height = 164
      TabOrder = 4
      object lblTituloPassaAlta: TLabel
        Left = 48
        Top = 5
        Width = 103
        Height = 13
        Caption = 'Algoritmos passa-alta'
      end
      object btnSobel: TButton
        Left = 9
        Top = 35
        Width = 183
        Height = 25
        Caption = 'Sobel'
        TabOrder = 0
        OnClick = EvSobelOnClick
      end
      object btnRoberts: TButton
        Left = 9
        Top = 60
        Width = 183
        Height = 25
        Caption = 'Roberts'
        TabOrder = 1
        OnClick = EvRobertsOnClick
      end
      object btnLaplaciano: TButton
        Left = 9
        Top = 85
        Width = 183
        Height = 25
        Caption = 'Laplaciano'
        TabOrder = 2
        OnClick = EvLaplacianoOnClick
      end
      object btnPrewittOnClick: TButton
        Left = 9
        Top = 110
        Width = 183
        Height = 25
        Caption = 'Prewitt'
        TabOrder = 3
        OnClick = EvPrewittOnClick
      end
    end
  end
  object pdgAbrirImagem: TOpenPictureDialog
    InitialDir = 'img'
    Left = 600
    Top = 224
  end
end
