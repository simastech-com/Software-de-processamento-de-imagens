object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  Caption = 'Software de processamento de imagens'
  ClientHeight = 573
  ClientWidth = 792
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsMDIForm
  Menu = mnuPrincipal
  OldCreateOrder = False
  WindowState = wsMaximized
  PixelsPerInch = 96
  TextHeight = 13
  object mnuPrincipal: TMainMenu
    Left = 552
    Top = 304
    object mnuProcessamento: TMenuItem
      Caption = 'Processamento de imagens'
      object mniAlgoritmos: TMenuItem
        Caption = 'Algoritmos de processamento de imagem...'
        OnClick = EvAlgoritmosOnClick
      end
      object mniSobre: TMenuItem
        Caption = 'Autor...'
        OnClick = EvSobreOnClick
      end
    end
  end
end
