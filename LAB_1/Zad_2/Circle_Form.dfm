object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Form2'
  ClientHeight = 496
  ClientWidth = 864
  Color = clBtnHighlight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 865
    Height = 497
    OnClick = Image1Click
  end
  object Button1: TButton
    Left = 760
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Show'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 760
    Top = 88
    Width = 75
    Height = 25
    Caption = #1076#1083#1080#1085#1072' '#1076#1091#1075#1080
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button5: TButton
    Left = 760
    Top = 128
    Width = 75
    Height = 25
    Caption = #1062#1077#1085#1090#1088' '#1084#1072#1089#1089
    TabOrder = 2
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 760
    Top = 168
    Width = 75
    Height = 25
    Caption = #1055#1083#1086#1097#1072#1076#1100
    TabOrder = 3
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 720
    Top = 208
    Width = 115
    Height = 25
    Caption = #1059#1074#1077#1083#1080#1095#1080#1090#1100' '#1084#1072#1089#1096#1090#1072#1073
    TabOrder = 4
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 720
    Top = 248
    Width = 115
    Height = 25
    Caption = #1059#1084#1077#1085#1100#1096#1080#1090#1100' '#1084#1072#1089#1096#1090#1072#1073
    TabOrder = 5
    OnClick = Button8Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer1Timer
    Left = 824
    Top = 456
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer2Timer
    Left = 784
    Top = 456
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer3Timer
    Left = 744
    Top = 456
  end
end
