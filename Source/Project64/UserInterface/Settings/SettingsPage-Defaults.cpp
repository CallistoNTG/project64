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
#include "stdafx.h"
#include "SettingsPage.h"

CDefaultsOptionsPage::CDefaultsOptionsPage(HWND hParent, const RECT & rcDispay)
{
    if (!Create(hParent, rcDispay))
    {
        return;
    }
    UpdatePageSettings();

    SetDlgItemTextW(m_hWnd, IDC_MEMORY_SIZE_TEXT, wGS(ROM_MEM_SIZE).c_str());
	SetDlgItemTextW(m_hWnd, IDC_HLE_GFX, wGS(PLUG_HLE_GFX).c_str());
	SetDlgItemTextW(m_hWnd, IDC_USE_TLB, wGS(ROM_USE_TLB).c_str());
	SetDlgItemTextW(m_hWnd, IDC_VIREFESH_TEXT, wGS(ROM_VIREFRESH).c_str());
	SetDlgItemTextW(m_hWnd, IDC_COUNTPERBYTE_TEXT, wGS(ROM_COUNTPERBYTE).c_str());
	SetDlgItemTextW(m_hWnd, IDC_COUNTFACT_TEXT, wGS(ROM_COUNTER_FACTOR).c_str());
	SetDlgItemTextW(m_hWnd, IDC_ROM_FIXEDAUDIO, wGS(ROM_FIXED_AUDIO).c_str());
	SetDlgItemTextW(m_hWnd, IDC_SYNC_AUDIO, wGS(ROM_SYNC_AUDIO).c_str());
    SetDlgItemTextW(m_hWnd, IDC_UNALIGNED_DMA, wGS(ROM_UNALIGNED_DMA).c_str());

    CModifiedComboBox * ComboBox;
    ComboBox = AddModComboBox(GetDlgItem(IDC_RDRAM_SIZE), Default_RDRamSize);
    if (ComboBox)
    {
        ComboBox->SetTextField(GetDlgItem(IDC_MEMORY_SIZE_TEXT));
        ComboBox->AddItemW(wGS(RDRAM_4MB).c_str(), 0x400000);
        ComboBox->AddItemW(wGS(RDRAM_8MB).c_str(), 0x800000);
    }

	ComboBox = AddModComboBox(GetDlgItem(IDC_COUNTFACT), Default_CounterFactor);
	if (ComboBox)
	{
		ComboBox->SetTextField(GetDlgItem(IDC_COUNTFACT_TEXT));
		ComboBox->AddItemW(wGS(NUMBER_1).c_str(), 1);
		ComboBox->AddItemW(wGS(NUMBER_2).c_str(), 2);
		ComboBox->AddItemW(wGS(NUMBER_3).c_str(), 3);
		ComboBox->AddItemW(wGS(NUMBER_4).c_str(), 4);
		ComboBox->AddItemW(wGS(NUMBER_5).c_str(), 5);
		ComboBox->AddItemW(wGS(NUMBER_6).c_str(), 6);
	}

	CModifiedEditBox * TxtBox = AddModTextBox(GetDlgItem(IDC_VIREFRESH), Default_ViRefreshRate, false);
	TxtBox->SetTextField(GetDlgItem(IDC_VIREFESH_TEXT));
	TxtBox = AddModTextBox(GetDlgItem(IDC_COUNTPERBYTE), Default_AiCountPerBytes, false);
	TxtBox->SetTextField(GetDlgItem(IDC_COUNTPERBYTE_TEXT));

	AddModCheckBox(GetDlgItem(IDC_HLE_GFX), Default_UseHleGfx);
	AddModCheckBox(GetDlgItem(IDC_USE_TLB), Default_UseTlb);
	AddModCheckBox(GetDlgItem(IDC_SYNC_AUDIO), Default_SyncViaAudio);
	AddModCheckBox(GetDlgItem(IDC_ROM_FIXEDAUDIO), Default_FixedAudio);
    AddModCheckBox(GetDlgItem(IDC_UNALIGNED_DMA), Default_UnalignedDMA);

	if (!g_Settings->LoadBool(Setting_SyncViaAudioEnabled))
	{
		GetDlgItem(IDC_SYNC_AUDIO).EnableWindow(false);
	}
	UpdatePageSettings();
}

void CDefaultsOptionsPage::HidePage()
{
    ShowWindow(SW_HIDE);
}

void CDefaultsOptionsPage::ShowPage()
{
    ShowWindow(SW_SHOW);
}

void CDefaultsOptionsPage::ApplySettings(bool UpdateScreen)
{
    CSettingsPageImpl<CDefaultsOptionsPage>::ApplySettings(UpdateScreen);
}

bool CDefaultsOptionsPage::EnableReset(void)
{
    if (CSettingsPageImpl<CDefaultsOptionsPage>::EnableReset()) { return true; }
    return false;
}

void CDefaultsOptionsPage::ResetPage()
{
    CSettingsPageImpl<CDefaultsOptionsPage>::ResetPage();
}

void CDefaultsOptionsPage::UpdatePageSettings(void)
{
    m_InUpdateSettings = true;
    CSettingsPageImpl<CDefaultsOptionsPage>::UpdatePageSettings();
    m_InUpdateSettings = false;
}