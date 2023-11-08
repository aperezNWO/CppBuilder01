object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'ALGORIITMOS DE DISTANCIA MAS CORTA'
  ClientHeight = 150
  ClientWidth = 901
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 13
  object lblGetRandomVertex: TLabel
    Left = 8
    Top = 8
    Width = 63
    Height = 13
    Caption = '[PENDIENTE]'
  end
  object lblSortBenchMark: TLabel
    Left = 8
    Top = 66
    Width = 63
    Height = 13
    Caption = '[PENDIENTE]'
  end
  object cmdGetRandomVertex: TButton
    Left = 152
    Top = 24
    Width = 161
    Height = 25
    Caption = '[Get Ramdom Vertex]'
    TabOrder = 0
    OnClick = cmdGetRandomVertexClick
  end
  object cmdCallDLL: TButton
    Left = 8
    Top = 24
    Width = 138
    Height = 25
    Caption = 'Call DLL Dijkstra'
    TabOrder = 1
    OnClick = cmdCallDLLClick
  end
  object cmdSortBenchMark: TButton
    Left = 8
    Top = 93
    Width = 138
    Height = 25
    Caption = 'Call DLL SortBenchMark'
    TabOrder = 2
    OnClick = cmdSortBenchMarkClick
  end
end
