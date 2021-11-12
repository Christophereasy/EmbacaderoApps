object frmEB: TfrmEB
  Left = 0
  Top = 0
  Caption = ' Household Electricity Bill Calculator'
  ClientHeight = 395
  ClientWidth = 680
  Color = clBtnFace
  Constraints.MaxWidth = 696
  Constraints.MinWidth = 696
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 3
    Width = 655
    Height = 41
    BevelWidth = 2
    Color = clGradientInactiveCaption
    ParentBackground = False
    TabOrder = 0
    object Label7: TLabel
      Left = 499
      Top = 14
      Width = 126
      Height = 13
      Caption = '(Assume 30 days / month)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clTeal
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 276
      Top = 16
      Width = 129
      Height = 11
      Caption = 'Eskom charge: 1 kWh  = R'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 8
      Top = 10
      Width = 232
      Height = 18
      Caption = 'Usage of Household Appliances'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object edtKWhCost: TEdit
      Left = 411
      Top = 18
      Width = 40
      Height = 21
      Alignment = taRightJustify
      Color = clYellow
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = '2,85'
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 48
    Width = 680
    Height = 347
    ActivePage = TabSheet1
    Align = alBottom
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = ' Data Entry - Assign 1 - Done  '
      object lblSaved: TLabel
        Left = 136
        Top = 289
        Width = 50
        Height = 14
        Caption = 'SAVED! '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = [fsBold, fsItalic]
        ParentFont = False
        Visible = False
      end
      object Label2: TLabel
        Left = 369
        Top = 290
        Width = 145
        Height = 13
        Caption = 'Total household EB exspenses'
      end
      object imgNum: TImage
        Left = 272
        Top = 242
        Width = 70
        Height = 80
        Stretch = True
      end
      object edtTotal: TEdit
        Left = 542
        Top = 286
        Width = 96
        Height = 22
        Alignment = taRightJustify
        Color = clGradientActiveCaption
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
      object bttSave: TBitBtn
        Left = 24
        Top = 285
        Width = 97
        Height = 25
        Caption = '5. Save as CSV'
        TabOrder = 1
        OnClick = bttSaveClick
      end
      object btnCalculate: TButton
        Left = 526
        Top = 3
        Width = 137
        Height = 25
        Caption = '2. Calculate Expenses'
        TabOrder = 2
        OnClick = btnCalculateClick
      end
      object lstUsage: TListBox
        Left = 399
        Top = 35
        Width = 264
        Height = 158
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 15
        ParentFont = False
        TabOrder = 3
        TabWidth = 50
      end
      object btnLoad: TButton
        Left = 243
        Top = 3
        Width = 139
        Height = 25
        Caption = '1. Load Appliances'
        TabOrder = 4
        OnClick = btnLoadClick
      end
      object lstAppliances: TListBox
        Left = 16
        Top = 35
        Width = 365
        Height = 158
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Courier New'
        Font.Style = []
        ItemHeight = 15
        ParentFont = False
        TabOrder = 5
        TabWidth = 60
        OnClick = lstAppliancesClick
      end
      object Panel2: TPanel
        Left = 16
        Top = 199
        Width = 647
        Height = 49
        Color = clGradientInactiveCaption
        ParentBackground = False
        TabOrder = 6
        object Label3: TLabel
          Left = 162
          Top = 3
          Width = 96
          Height = 13
          Caption = 'Power Rating[W]'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold, fsUnderline]
          ParentFont = False
        end
        object lblUsageM: TLabel
          Left = 435
          Top = 25
          Width = 37
          Height = 14
          Caption = '0 min'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Verdana'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object lblHeader2: TLabel
          Left = 311
          Top = 3
          Width = 92
          Height = 13
          Caption = 'Used/ Day [Min]'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold, fsUnderline]
          ParentFont = False
        end
        object lblHeader1: TLabel
          Left = 8
          Top = 3
          Width = 122
          Height = 13
          Caption = 'Appliance Description'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold, fsUnderline]
          ParentFont = False
        end
        object btnAdd: TButton
          Left = 504
          Top = 19
          Width = 118
          Height = 25
          Caption = '4. Add Appliance'
          Enabled = False
          TabOrder = 0
          OnClick = btnAddClick
        end
        object edtAppliance: TEdit
          Left = 9
          Top = 23
          Width = 152
          Height = 21
          TabOrder = 1
        end
        object trkUsageM: TTrackBar
          Left = 299
          Top = 17
          Width = 130
          Height = 27
          Max = 240
          Frequency = 20
          TabOrder = 2
          OnChange = trkUsageMChange
        end
        object edtPowerRate: TEdit
          Left = 214
          Top = 23
          Width = 44
          Height = 21
          Alignment = taRightJustify
          Color = 16252103
          TabOrder = 3
          Text = '0'
        end
      end
    end
    object tbs2: TTabSheet
      Caption = '  Data on String grid  '
      ImageIndex = 1
      OnShow = tbs2Show
      object Label4: TLabel
        Left = 206
        Top = 28
        Width = 191
        Height = 14
        Caption = 'Monthly Electricity Usage Data '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Tahoma'
        Font.Style = [fsBold, fsItalic]
        ParentFont = False
      end
      object strgEscom: TStringGrid
        Left = 63
        Top = 48
        Width = 543
        Height = 257
        DrawingStyle = gdsGradient
        GradientEndColor = clSkyBlue
        TabOrder = 0
      end
      object bttLoad: TBitBtn
        Left = 63
        Top = 17
        Width = 75
        Height = 25
        Caption = 'Load Data'
        TabOrder = 1
        OnClick = bttLoadClick
      end
      object bttSort: TBitBtn
        Left = 440
        Top = 17
        Width = 166
        Height = 25
        Caption = 'Sort according to time usage'
        TabOrder = 2
        OnClick = bttSortClick
      end
    end
    object tbs3: TTabSheet
      Caption = '  Data on Graph   '
      ImageIndex = 2
      object pnlDiagram: TPanel
        Left = 3
        Top = 3
        Width = 666
        Height = 313
        ParentBackground = False
        TabOrder = 0
        object Label5: TLabel
          Left = 196
          Top = 16
          Width = 319
          Height = 18
          Caption = 'Home Appliances - Monthly Electricity Cost'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -15
          Font.Name = 'Tahoma'
          Font.Style = [fsBold, fsItalic]
          ParentFont = False
        end
        object shpLeft: TShape
          Left = 145
          Top = 45
          Width = 4
          Height = 250
          Brush.Color = clNavy
        end
        object shpBottom: TShape
          Left = 24
          Top = 271
          Width = 617
          Height = 3
          Brush.Color = clNavy
        end
        object Label8: TLabel
          Left = 32
          Top = 280
          Width = 97
          Height = 13
          Caption = 'Home Appliances'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label9: TLabel
          Left = 277
          Top = 280
          Width = 161
          Height = 13
          Caption = 'Expenditure in Rand / Month'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object bttDisplay: TBitBtn
          Left = 542
          Top = 14
          Width = 99
          Height = 25
          Caption = 'Display Graph'
          TabOrder = 0
          OnClick = bttDisplayClick
        end
        object bttDelete: TBitBtn
          Left = 24
          Top = 14
          Width = 125
          Height = 25
          Caption = 'Delete Bar indicators'
          TabOrder = 1
          OnClick = bttDeleteClick
        end
      end
    end
  end
  object tmrNum: TTimer
    Interval = 150
    OnTimer = tmrNumTimer
    Left = 168
    Top = 72
  end
end
