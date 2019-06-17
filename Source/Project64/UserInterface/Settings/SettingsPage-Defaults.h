/****************************************************************************
*                                                                           *
* Project64 - A Nintendo 64 emulator.                                      *
* http://www.pj64-emu.com/                                                  *
* Copyright (C) 2012 Project64. All rights reserved.                        *
*                                                                           *
* License:                                                                  *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                        *
*                                                                           *
****************************************************************************/
#pragma once

class CDefaultsOptionsPage :
	public CSettingsPageImpl<CDefaultsOptionsPage>,
	public CSettingsPage
{
	BEGIN_MSG_MAP_EX(CDefaultsOptionsPage)
		COMMAND_ID_HANDLER_EX(IDC_HLE_GFX, CheckBoxChanged)
		COMMAND_ID_HANDLER_EX(IDC_USE_TLB, CheckBoxChanged)
		COMMAND_ID_HANDLER_EX(IDC_SYNC_AUDIO, CheckBoxChanged)
		COMMAND_ID_HANDLER_EX(IDC_ROM_FIXEDAUDIO, CheckBoxChanged)
        COMMAND_ID_HANDLER_EX(IDC_UNALIGNED_DMA, CheckBoxChanged)
		COMMAND_HANDLER_EX(IDC_RDRAM_SIZE, LBN_SELCHANGE, ComboBoxChanged)
		COMMAND_HANDLER_EX(IDC_COUNTFACT, LBN_SELCHANGE, ComboBoxChanged)
		COMMAND_HANDLER_EX(IDC_VIREFRESH, EN_UPDATE, EditBoxChanged)
		COMMAND_HANDLER_EX(IDC_COUNTPERBYTE, EN_UPDATE, EditBoxChanged)
		COMMAND_HANDLER_EX(IDC_RDRAM_SIZE, EN_UPDATE, EditBoxChanged)
	END_MSG_MAP()

	enum { IDD = IDD_Settings_Defaults };

public:
    CDefaultsOptionsPage(HWND hParent, const RECT & rcDispay );

	LanguageStringID PageTitle ( void ) { return TAB_DEFAULTS; }
	void HidePage ( void );
	void ShowPage ( void );
	void ApplySettings ( bool UpdateScreen );
	bool EnableReset ( void );
	void ResetPage ( void );

private:
	void UpdatePageSettings(void);

	bool m_InUpdateSettings;
};
