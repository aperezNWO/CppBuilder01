object Form1: TForm1
  Left = 0
  Top = 0
  Caption = '[ALGORITMOS]'
  ClientHeight = 257
  ClientWidth = 861
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
    Color = clBtnText
    ParentColor = False
  end
  object lblSortBenchMark: TLabel
    Left = 8
    Top = 66
    Width = 63
    Height = 13
    Caption = '[PENDIENTE]'
    Color = clBlack
    ParentColor = False
  end
  object lblRegExManager: TLabel
    Left = 8
    Top = 130
    Width = 63
    Height = 13
    Caption = '[PENDIENTE]'
    Color = clBlack
    ParentColor = False
  end
  object lblSudoku: TLabel
    Left = 8
    Top = 200
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
  object cmdGetSortBenchMark: TButton
    Left = 152
    Top = 92
    Width = 161
    Height = 25
    Caption = '[Get Sort Benchmark]'
    TabOrder = 3
    OnClick = cmdGetSortBenchMarkClick
  end
  object cmdRegExManagerDLL: TButton
    Left = 8
    Top = 157
    Width = 138
    Height = 25
    Caption = 'Call DLL RegExManager'
    TabOrder = 4
    OnClick = cmdRegExManagerDLLClick
  end
  object cmdRegExManager: TButton
    Left = 152
    Top = 157
    Width = 161
    Height = 25
    Caption = '[RegExEval]'
    TabOrder = 5
    OnClick = cmdRegExManagerClick
  end
  object cmdSudokuDLL: TButton
    Left = 8
    Top = 224
    Width = 138
    Height = 25
    Caption = 'Call DLL Sudoku'
    TabOrder = 6
    OnClick = cmdSudokuDLLClick
  end
  object cmdSudoku: TButton
    Left = 152
    Top = 225
    Width = 161
    Height = 25
    Caption = '[Sudoku / Generate && Solve]'
    TabOrder = 7
    OnClick = cmdSudokuClick
  end
end
