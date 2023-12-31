/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
*
*/

// It contains common definitions for the client and customisation API.
// It should not be modified manually.

#ifndef AKNAPACLAYOUT_CDL_COMMON_H
#define AKNAPACLAYOUT_CDL_COMMON_H


#include <AknLayout2Def.h>


namespace AknApacLayout
{
#include "aknapaclayout.cdl.common.hrh"

// These constants are defined by the CDL interface: AknApacLayout
_LIT(KCdlName, "AknApacLayout");
const TInt KCdlInterfaceUidValue = _CDL_AknApacLayout_KCdlInterfaceUidValue;
const TUid KCdlInterfaceUid = { KCdlInterfaceUidValue };
const TInt KCdlInterfaceMajorVersion = 1;
const TInt KCdlInterfaceMinorVersion = 0;
const TUint KCdlInterfaceFlags = KCdlFlagRomOnly;

// These are the API ids used in this interface.
enum TApiId
	{
	EApiId_Find_pane_elements_Line_6,
	EApiId_popup_fep_china_window,
	EApiId_popup_fep_china_pinyin_window,
	EApiId_Cursor_graphics__16__Line_1,
	EApiId_Cut_copy_and_paste_highlight_graphics__16__Line_1,
	EApiId_Time_and_date_entry_graphics__16__Line_1,
	EApiId_cell_apac_character_popup_pane,
	EApiId_Cell_pane_texts__pop_up_APAC_character__Line_1,
	EApiId_APAC_character_selection_pop_up_window_descendants_Line_1,
	EApiId_grid_apac_character_popup_pane,
	EApiId_APAC_character_selection_pop_up_window_elements_Line_1,
	EApiId_APAC_character_selection_pop_up_window_elements_Line_2,
	EApiId_APAC_character_selection_pop_up_window_graphics_Line_1,
	EApiId_APAC_character_selection_pop_up_window_graphics_Line_2,
	EApiId_APAC_character_selection_pop_up_window_graphics_Line_3,
	EApiId_APAC_character_selection_pop_up_window_graphics_Line_4,
	EApiId_APAC_character_selection_pop_up_window_graphics_Line_5,
	EApiId_APAC_character_selection_pop_up_window_graphics_SUB_TABLE_0_Limits,
	EApiId_APAC_character_selection_pop_up_window_graphics_SUB_TABLE_0,
	EApiId_Chinese_FEP_pop_up_window_elements_and_descendants_panes_Line_1,
	EApiId_fep_china_entry_pane,
	EApiId_fep_china_candidate_pane,
	EApiId_Chinese_FEP_entry_pane_texts_Line_1,
	EApiId_Chinese_FEP_candidate_pane_elements_Line_1,
	EApiId_Chinese_FEP_candidate_pane_elements_Line_2,
	EApiId_Chinese_FEP_candidate_pane_elements_Line_3,
	EApiId_fep_china_highlight_pane,
	EApiId_Chinese_FEP_candidate_pane_elements_SUB_TABLE_0_Limits,
	EApiId_Chinese_FEP_candidate_pane_elements_SUB_TABLE_0,
	EApiId_Chinese_FEP_candidate_pane_texts_Line_1,
	EApiId_Chinese_FEP_candidate_pane_texts_Line_2,
	EApiId_Chinese_FEP_pop_up_window_graphics_Line_1,
	EApiId_Chinese_FEP_pop_up_window_graphics_Line_2,
	EApiId_Chinese_FEP_pop_up_window_graphics_Line_3,
	EApiId_Chinese_FEP_pop_up_window_graphics_Line_4,
	EApiId_Chinese_FEP_pop_up_window_graphics_Line_5,
	EApiId_Chinese_FEP_pop_up_window_graphics_Limits,
	EApiId_Chinese_FEP_pop_up_window_graphics,
	EApiId_Chinese_FEP_highlight_elements_Line_1,
	EApiId_Chinese_FEP_highlight_elements_Line_2,
	EApiId_Chinese_FEP_highlight_elements_Line_3,
	EApiId_Chinese_FEP_highlight_elements_Limits,
	EApiId_Chinese_FEP_highlight_elements,
	EApiId_Chinese_FEP_highlight_texts_Line_1,
	EApiId_Unselected_string_highlight_Line_1,
	EApiId_list_single_fep_china_pinyin_pane,
	EApiId_List_pane_texts__fep_china__Line_1,
	EApiId_Pinyin_T9_candidate_pop_up_window_graphics_Line_1,
	EApiId_Pinyin_T9_candidate_pop_up_window_graphics_Line_2,
	EApiId_Pinyin_T9_candidate_pop_up_window_graphics_Line_3,
	EApiId_Pinyin_T9_candidate_pop_up_window_graphics_Line_4,
	EApiId_Pinyin_T9_candidate_pop_up_window_graphics_Limits,
	EApiId_Pinyin_T9_candidate_pop_up_window_graphics,
	EApiId_Pinyin_T9_candidate_highlight_Line_1,
	EApiId_popup_grid_apac_character_window,
	EApiId_popup_fep_japan_predictive_window,
	EApiId_popup_fep_japan_candidate_window,
	EApiId_candidate_pane,
	EApiId_list_single_popup_jap_candidate_pane,
	EApiId_List_pane_text__single_japan_fep__Line_1,
	EApiId_Predictive_candidate_selection_list_texts_Line_1,
	EApiId_Multiline_Predictive_candidate_selection_list_texts_Line_1,
	EApiId_Predictive_candidate_selection_highlight_Line_1,
	EApiId_Predictive_candidate_selection_popup_window_graphics_Line_1,
	EApiId_Predictive_candidate_selection_popup_window_graphics_Line_2,
	EApiId_Predictive_candidate_selection_popup_window_graphics_Line_3,
	EApiId_Predictive_candidate_selection_popup_window_graphics_Line_4,
	EApiId_Predictive_candidate_selection_popup_window_graphics_Limits,
	EApiId_Predictive_candidate_selection_popup_window_graphics,
	EApiId_Candidate_selection_list_texts_Line_1,
	EApiId_Candidate_selection_pop_up_window_graphics_Line_1,
	EApiId_Candidate_selection_pop_up_window_graphics_Line_2,
	EApiId_Candidate_selection_pop_up_window_graphics_Line_3,
	EApiId_Candidate_selection_pop_up_window_graphics_Line_4,
	EApiId_Candidate_selection_pop_up_window_graphics_Limits,
	EApiId_Candidate_selection_pop_up_window_graphics,
	EApiId_Chinese_FEP_Zi_popup_window_elements_and_descendants_panes_Line_1,
	EApiId_fep_china_zi_entry_pane,
	EApiId_fep_china_zi_candidate_pane,
	EApiId_Chinese_FEP_Zi_entry_pane_elements_Line_1,
	EApiId_Chinese_FEP_Zi_entry_pane_elements_Line_2,
	EApiId_Chinese_FEP_Zi_entry_pane_elements_Limits,
	EApiId_Chinese_FEP_Zi_entry_pane_elements,
	EApiId_Chinese_FEP_Zi_entry_pane_texts_Line_1,
	EApiId_Chinese_FEP_Zi_candidate_pane_elements_Line_1,
	EApiId_Chinese_FEP_Zi_candidate_pane_elements_Line_2,
	EApiId_Chinese_FEP_Zi_candidate_pane_elements_Line_3,
	EApiId_Chinese_FEP_Zi_candidate_pane_elements_Line_4,
	EApiId_fep_china_zi_highlight_pane,
	EApiId_Chinese_FEP_Zi_candidate_pane_elements_Limits,
	EApiId_Chinese_FEP_Zi_candidate_pane_elements,
	EApiId_Chinese_FEP_Zi_candidate_pane_texts_Line_1,
	EApiId_Chinese_FEP_Zi_candidate_pane_texts_Line_2,
	EApiId_Chinese_FEP_Zi_candidate_pane_texts_Line_3,
	EApiId_Chinese_FEP_Zi_candidate_pane_texts_Limits,
	EApiId_Chinese_FEP_Zi_candidate_pane_texts,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_1__Line_1,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_1__Line_2,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_1__Line_3,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_1__Line_4,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_1__Line_5,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_1__SUB_TABLE_0_Limits,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_1__SUB_TABLE_0,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_1__SUB_TABLE_1_Limits,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_1__SUB_TABLE_1,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_2__Line_1,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_2__Line_2,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_2__Line_3,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_2__Line_4,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_2__Line_5,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_2__Limits,
	EApiId_Chinese_FEP_Zi_popup_window_graphics__part_2_,
	EApiId_Input_highlight_elements_Line_1,
	EApiId_Candidate_selection_Line_1,
	EApiId_Candidate_selection_Line_2,
	EApiId_Candidate_selection_Limits,
	EApiId_Candidate_selection,
	EApiId_popup_fep_china_zi_window,
	EApiId_Find_pop_up_window_elements_Line_5,
	EApiId_Chinese_universal_FEP_pop_up_window_elements_and_descendants_panes_Line_1,
	EApiId_fep_china_uni_entry_pane,
	EApiId_fep_china_uni_candidate_pane,
	EApiId_Chinese_universal_FEP_pop_up_window_elements_and_descendants_panes_SUB_TABLE_0_Limits,
	EApiId_Chinese_universal_FEP_pop_up_window_elements_and_descendants_panes_SUB_TABLE_0,
	EApiId_Chinese_universal_FEP_entry_pane_elements_Line_1,
	EApiId_Chinese_universal_FEP_entry_pane_elements_Line_2,
	EApiId_fep_entry_item_pane,
	EApiId_Chinese_universal_FEP_entry_pane_elements_Limits,
	EApiId_Chinese_universal_FEP_entry_pane_elements,
	EApiId_Chinese_universal_FEP_entry_pane_texts_Line_1,
	EApiId_Chinese_universal_FEPcandidate_pane_elements_Line_1,
	EApiId_Chinese_universal_FEPcandidate_pane_elements_Line_2,
	EApiId_Chinese_universal_FEPcandidate_pane_elements_Line_3,
	EApiId_Chinese_universal_FEPcandidate_pane_elements_Line_4,
	EApiId_fep_candidate_item_pane,
	EApiId_Chinese_universal_FEPcandidate_pane_elements_Limits,
	EApiId_Chinese_universal_FEPcandidate_pane_elements,
	EApiId_Chinese_universal_FEP_candidate_pane_texts_Line_1,
	EApiId_Chinese_universal_FEP_candidate_pane_texts_Line_2,
	EApiId_Chinese_universal_FEP_candidate_pane_texts_Line_3,
	EApiId_Chinese_universal_FEP_candidate_pane_texts_Limits,
	EApiId_Chinese_universal_FEP_candidate_pane_texts,
	EApiId_Chinese_universal_FEP_pop_up_window_graphics_Line_1,
	EApiId_Chinese_universal_FEP_pop_up_window_graphics_Line_2,
	EApiId_Chinese_universal_FEP_pop_up_window_graphics_Line_3,
	EApiId_Chinese_universal_FEP_pop_up_window_graphics_Line_4,
	EApiId_Chinese_universal_FEP_pop_up_window_graphics_Limits,
	EApiId_Chinese_universal_FEP_pop_up_window_graphics,
	EApiId_Input_highlight_Line_1,
	EApiId_Candidate_selection_highlight_Line_1,
	EApiId_Candidate_selection_highlight_Line_2,
	EApiId_Candidate_selection_highlight_Limits,
	EApiId_Candidate_selection_highlight,
	EApiId_popup_fep_china_uni_window,
	E_TApiId_TableSize
	};

// This is the CDL interface definition for this interface
const SCdlInterface KCdlInterface =
	{
	KCdlCompilerMajorVersion,
	KCdlCompilerMinorVersion,
	LIT_AS_DESC_PTR(KCdlName),
	{ KCdlInterfaceUidValue },
	KCdlInterfaceMajorVersion,
	KCdlInterfaceMinorVersion,
	KCdlInterfaceFlags,
	E_TApiId_TableSize
	};

// These typedefs define the types for function APIs
typedef TAknWindowLineLayout (TFind_pane_elements_Line_6_sig)();
typedef TAknWindowLineLayout (Tpopup_fep_china_window_sig)(TInt);
typedef TAknWindowLineLayout (Tpopup_fep_china_pinyin_window_sig)(TInt);
typedef TAknWindowLineLayout (TCursor_graphics__16__Line_1_sig)();
typedef TAknWindowLineLayout (TCut_copy_and_paste_highlight_graphics__16__Line_1_sig)();
typedef TAknWindowLineLayout (TTime_and_date_entry_graphics__16__Line_1_sig)();
typedef TAknWindowLineLayout (Tcell_apac_character_popup_pane_sig)(TInt);
typedef TAknTextLineLayout (TCell_pane_texts__pop_up_APAC_character__Line_1_sig)();
typedef TAknWindowLineLayout (TAPAC_character_selection_pop_up_window_descendants_Line_1_sig)(TInt);
typedef TAknWindowLineLayout (Tgrid_apac_character_popup_pane_sig)(TInt, TInt);
typedef TAknWindowLineLayout (TAPAC_character_selection_pop_up_window_elements_Line_1_sig)(TInt);
typedef TAknWindowLineLayout (TAPAC_character_selection_pop_up_window_elements_Line_2_sig)(TInt, TInt);
typedef TAknWindowLineLayout (TAPAC_character_selection_pop_up_window_graphics_Line_1_sig)(const TRect&);
typedef TAknWindowLineLayout (TAPAC_character_selection_pop_up_window_graphics_Line_2_sig)(const TRect&, TInt);
typedef TAknWindowLineLayout (TAPAC_character_selection_pop_up_window_graphics_Line_3_sig)(const TRect&, TInt);
typedef TAknWindowLineLayout (TAPAC_character_selection_pop_up_window_graphics_Line_4_sig)(const TRect&, TInt);
typedef TAknWindowLineLayout (TAPAC_character_selection_pop_up_window_graphics_Line_5_sig)(const TRect&, TInt);
typedef TAknLayoutTableLimits (TAPAC_character_selection_pop_up_window_graphics_SUB_TABLE_0_Limits_sig)();
typedef TAknWindowLineLayout (TAPAC_character_selection_pop_up_window_graphics_SUB_TABLE_0_sig)(TInt, const TRect&, TInt);
typedef TAknWindowLineLayout (TChinese_FEP_pop_up_window_elements_and_descendants_panes_Line_1_sig)(TInt);
typedef TAknWindowLineLayout (Tfep_china_entry_pane_sig)(TInt);
typedef TAknWindowLineLayout (Tfep_china_candidate_pane_sig)(TInt);
typedef TAknTextLineLayout (TChinese_FEP_entry_pane_texts_Line_1_sig)(TInt, TInt);
typedef TAknWindowLineLayout (TChinese_FEP_candidate_pane_elements_Line_1_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_candidate_pane_elements_Line_2_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_candidate_pane_elements_Line_3_sig)();
typedef TAknWindowLineLayout (Tfep_china_highlight_pane_sig)(TInt);
typedef TAknLayoutTableLimits (TChinese_FEP_candidate_pane_elements_SUB_TABLE_0_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_candidate_pane_elements_SUB_TABLE_0_sig)(TInt);
typedef TAknTextLineLayout (TChinese_FEP_candidate_pane_texts_Line_1_sig)(TInt, TInt);
typedef TAknTextLineLayout (TChinese_FEP_candidate_pane_texts_Line_2_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_pop_up_window_graphics_Line_1_sig)(const TRect&, TInt);
typedef TAknWindowLineLayout (TChinese_FEP_pop_up_window_graphics_Line_2_sig)(const TRect&, TInt);
typedef TAknWindowLineLayout (TChinese_FEP_pop_up_window_graphics_Line_3_sig)(const TRect&, TInt);
typedef TAknWindowLineLayout (TChinese_FEP_pop_up_window_graphics_Line_4_sig)(const TRect&, TInt);
typedef TAknWindowLineLayout (TChinese_FEP_pop_up_window_graphics_Line_5_sig)(const TRect&, TInt);
typedef TAknLayoutTableLimits (TChinese_FEP_pop_up_window_graphics_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_pop_up_window_graphics_sig)(TInt, const TRect&, TInt);
typedef TAknWindowLineLayout (TChinese_FEP_highlight_elements_Line_1_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_highlight_elements_Line_2_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_highlight_elements_Line_3_sig)();
typedef TAknLayoutTableLimits (TChinese_FEP_highlight_elements_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_highlight_elements_sig)(TInt);
typedef TAknTextLineLayout (TChinese_FEP_highlight_texts_Line_1_sig)(TInt);
typedef TAknWindowLineLayout (TUnselected_string_highlight_Line_1_sig)(TInt);
typedef TAknWindowLineLayout (Tlist_single_fep_china_pinyin_pane_sig)(TInt);
typedef TAknTextLineLayout (TList_pane_texts__fep_china__Line_1_sig)(TInt);
typedef TAknWindowLineLayout (TPinyin_T9_candidate_pop_up_window_graphics_Line_1_sig)(const TRect&);
typedef TAknWindowLineLayout (TPinyin_T9_candidate_pop_up_window_graphics_Line_2_sig)(const TRect&);
typedef TAknWindowLineLayout (TPinyin_T9_candidate_pop_up_window_graphics_Line_3_sig)(const TRect&);
typedef TAknWindowLineLayout (TPinyin_T9_candidate_pop_up_window_graphics_Line_4_sig)(const TRect&);
typedef TAknLayoutTableLimits (TPinyin_T9_candidate_pop_up_window_graphics_Limits_sig)();
typedef TAknWindowLineLayout (TPinyin_T9_candidate_pop_up_window_graphics_sig)(TInt, const TRect&);
typedef TAknWindowLineLayout (TPinyin_T9_candidate_highlight_Line_1_sig)(const TRect&);
typedef TAknWindowLineLayout (Tpopup_grid_apac_character_window_sig)(TInt);
typedef TAknWindowLineLayout (Tpopup_fep_japan_predictive_window_sig)(TInt, TInt);
typedef TAknWindowLineLayout (Tpopup_fep_japan_candidate_window_sig)(TInt, TInt, TInt);
typedef TAknWindowLineLayout (Tcandidate_pane_sig)(TInt, TInt);
typedef TAknWindowLineLayout (Tlist_single_popup_jap_candidate_pane_sig)(TInt, TInt);
typedef TAknTextLineLayout (TList_pane_text__single_japan_fep__Line_1_sig)(TInt);
typedef TAknTextLineLayout (TPredictive_candidate_selection_list_texts_Line_1_sig)(TInt, TInt);
typedef TAknMultiLineTextLayout (TMultiline_Predictive_candidate_selection_list_texts_Line_1_sig)(TInt, TInt);
typedef TAknWindowLineLayout (TPredictive_candidate_selection_highlight_Line_1_sig)();
typedef TAknWindowLineLayout (TPredictive_candidate_selection_popup_window_graphics_Line_1_sig)(const TRect&);
typedef TAknWindowLineLayout (TPredictive_candidate_selection_popup_window_graphics_Line_2_sig)(const TRect&);
typedef TAknWindowLineLayout (TPredictive_candidate_selection_popup_window_graphics_Line_3_sig)(const TRect&);
typedef TAknWindowLineLayout (TPredictive_candidate_selection_popup_window_graphics_Line_4_sig)(const TRect&);
typedef TAknLayoutTableLimits (TPredictive_candidate_selection_popup_window_graphics_Limits_sig)();
typedef TAknWindowLineLayout (TPredictive_candidate_selection_popup_window_graphics_sig)(TInt, const TRect&);
typedef TAknTextLineLayout (TCandidate_selection_list_texts_Line_1_sig)();
typedef TAknWindowLineLayout (TCandidate_selection_pop_up_window_graphics_Line_1_sig)(const TRect&);
typedef TAknWindowLineLayout (TCandidate_selection_pop_up_window_graphics_Line_2_sig)(const TRect&);
typedef TAknWindowLineLayout (TCandidate_selection_pop_up_window_graphics_Line_3_sig)(const TRect&);
typedef TAknWindowLineLayout (TCandidate_selection_pop_up_window_graphics_Line_4_sig)(const TRect&);
typedef TAknLayoutTableLimits (TCandidate_selection_pop_up_window_graphics_Limits_sig)();
typedef TAknWindowLineLayout (TCandidate_selection_pop_up_window_graphics_sig)(TInt, const TRect&);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_elements_and_descendants_panes_Line_1_sig)();
typedef TAknWindowLineLayout (Tfep_china_zi_entry_pane_sig)(TInt);
typedef TAknWindowLineLayout (Tfep_china_zi_candidate_pane_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_entry_pane_elements_Line_1_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_entry_pane_elements_Line_2_sig)();
typedef TAknLayoutTableLimits (TChinese_FEP_Zi_entry_pane_elements_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_entry_pane_elements_sig)(TInt);
typedef TAknTextLineLayout (TChinese_FEP_Zi_entry_pane_texts_Line_1_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_candidate_pane_elements_Line_1_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_candidate_pane_elements_Line_2_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_candidate_pane_elements_Line_3_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_candidate_pane_elements_Line_4_sig)();
typedef TAknWindowLineLayout (Tfep_china_zi_highlight_pane_sig)();
typedef TAknLayoutTableLimits (TChinese_FEP_Zi_candidate_pane_elements_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_candidate_pane_elements_sig)(TInt);
typedef TAknTextLineLayout (TChinese_FEP_Zi_candidate_pane_texts_Line_1_sig)();
typedef TAknTextLineLayout (TChinese_FEP_Zi_candidate_pane_texts_Line_2_sig)();
typedef TAknTextLineLayout (TChinese_FEP_Zi_candidate_pane_texts_Line_3_sig)();
typedef TAknLayoutTableLimits (TChinese_FEP_Zi_candidate_pane_texts_Limits_sig)();
typedef TAknTextLineLayout (TChinese_FEP_Zi_candidate_pane_texts_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_1__Line_1_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_1__Line_2_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_1__Line_3_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_1__Line_4_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_1__Line_5_sig)();
typedef TAknLayoutTableLimits (TChinese_FEP_Zi_popup_window_graphics__part_1__SUB_TABLE_0_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_1__SUB_TABLE_0_sig)(TInt, TInt);
typedef TAknLayoutTableLimits (TChinese_FEP_Zi_popup_window_graphics__part_1__SUB_TABLE_1_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_1__SUB_TABLE_1_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_2__Line_1_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_2__Line_2_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_2__Line_3_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_2__Line_4_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_2__Line_5_sig)(TInt);
typedef TAknLayoutTableLimits (TChinese_FEP_Zi_popup_window_graphics__part_2__Limits_sig)();
typedef TAknWindowLineLayout (TChinese_FEP_Zi_popup_window_graphics__part_2__sig)(TInt, TInt);
typedef TAknWindowLineLayout (TInput_highlight_elements_Line_1_sig)();
typedef TAknWindowLineLayout (TCandidate_selection_Line_1_sig)(const TRect&);
typedef TAknWindowLineLayout (TCandidate_selection_Line_2_sig)(const TRect&);
typedef TAknLayoutTableLimits (TCandidate_selection_Limits_sig)();
typedef TAknWindowLineLayout (TCandidate_selection_sig)(TInt, const TRect&);
typedef TAknWindowLineLayout (Tpopup_fep_china_zi_window_sig)(TInt);
typedef TAknWindowLineLayout (TFind_pop_up_window_elements_Line_5_sig)();
typedef TAknWindowLineLayout (TChinese_universal_FEP_pop_up_window_elements_and_descendants_panes_Line_1_sig)();
typedef TAknWindowLineLayout (Tfep_china_uni_entry_pane_sig)();
typedef TAknWindowLineLayout (Tfep_china_uni_candidate_pane_sig)(TInt);
typedef TAknLayoutTableLimits (TChinese_universal_FEP_pop_up_window_elements_and_descendants_panes_SUB_TABLE_0_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_universal_FEP_pop_up_window_elements_and_descendants_panes_SUB_TABLE_0_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_universal_FEP_entry_pane_elements_Line_1_sig)();
typedef TAknWindowLineLayout (TChinese_universal_FEP_entry_pane_elements_Line_2_sig)();
typedef TAknWindowLineLayout (Tfep_entry_item_pane_sig)();
typedef TAknLayoutTableLimits (TChinese_universal_FEP_entry_pane_elements_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_universal_FEP_entry_pane_elements_sig)(TInt);
typedef TAknTextLineLayout (TChinese_universal_FEP_entry_pane_texts_Line_1_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_universal_FEPcandidate_pane_elements_Line_1_sig)();
typedef TAknWindowLineLayout (TChinese_universal_FEPcandidate_pane_elements_Line_2_sig)();
typedef TAknWindowLineLayout (TChinese_universal_FEPcandidate_pane_elements_Line_3_sig)();
typedef TAknWindowLineLayout (TChinese_universal_FEPcandidate_pane_elements_Line_4_sig)();
typedef TAknWindowLineLayout (Tfep_candidate_item_pane_sig)();
typedef TAknLayoutTableLimits (TChinese_universal_FEPcandidate_pane_elements_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_universal_FEPcandidate_pane_elements_sig)(TInt);
typedef TAknTextLineLayout (TChinese_universal_FEP_candidate_pane_texts_Line_1_sig)();
typedef TAknTextLineLayout (TChinese_universal_FEP_candidate_pane_texts_Line_2_sig)();
typedef TAknTextLineLayout (TChinese_universal_FEP_candidate_pane_texts_Line_3_sig)();
typedef TAknLayoutTableLimits (TChinese_universal_FEP_candidate_pane_texts_Limits_sig)();
typedef TAknTextLineLayout (TChinese_universal_FEP_candidate_pane_texts_sig)(TInt);
typedef TAknWindowLineLayout (TChinese_universal_FEP_pop_up_window_graphics_Line_1_sig)(const TRect&);
typedef TAknWindowLineLayout (TChinese_universal_FEP_pop_up_window_graphics_Line_2_sig)(const TRect&);
typedef TAknWindowLineLayout (TChinese_universal_FEP_pop_up_window_graphics_Line_3_sig)(const TRect&);
typedef TAknWindowLineLayout (TChinese_universal_FEP_pop_up_window_graphics_Line_4_sig)(const TRect&);
typedef TAknLayoutTableLimits (TChinese_universal_FEP_pop_up_window_graphics_Limits_sig)();
typedef TAknWindowLineLayout (TChinese_universal_FEP_pop_up_window_graphics_sig)(TInt, const TRect&);
typedef TAknWindowLineLayout (TInput_highlight_Line_1_sig)(const TRect&);
typedef TAknWindowLineLayout (TCandidate_selection_highlight_Line_1_sig)(const TRect&);
typedef TAknWindowLineLayout (TCandidate_selection_highlight_Line_2_sig)(const TRect&);
typedef TAknLayoutTableLimits (TCandidate_selection_highlight_Limits_sig)();
typedef TAknWindowLineLayout (TCandidate_selection_highlight_sig)(TInt, const TRect&);
typedef TAknWindowLineLayout (Tpopup_fep_china_uni_window_sig)(TInt, TInt);

} // end of namespace AknApacLayout

#endif // AKNAPACLAYOUT_CDL_COMMON_H
