/******************************************************************************
 * Copyright(c) 2008 - 2010 Realtek Corporation. All rights reserved.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
******************************************************************************/
#ifndef __INC_QOS_TYPE_H
#define __INC_QOS_TYPE_H

#include "rtllib_endianfree.h"

#define BIT0                    0x00000001
#define BIT1                    0x00000002
#define BIT2                    0x00000004
#define BIT3                    0x00000008
#define BIT4                    0x00000010
#define BIT5                    0x00000020
#define BIT6                    0x00000040
#define BIT7                    0x00000080
#define BIT8                    0x00000100
#define BIT9                    0x00000200
#define BIT10                   0x00000400
#define BIT11                   0x00000800
#define BIT12                   0x00001000
#define BIT13                   0x00002000
#define BIT14                   0x00004000
#define BIT15                   0x00008000
#define BIT16                   0x00010000
#define BIT17                   0x00020000
#define BIT18                   0x00040000
#define BIT19                   0x00080000
#define BIT20                   0x00100000
#define BIT21                   0x00200000
#define BIT22                   0x00400000
#define BIT23                   0x00800000
#define BIT24                   0x01000000
#define BIT25                   0x02000000
#define BIT26                   0x04000000
#define BIT27                   0x08000000
#define BIT28                   0x10000000
#define BIT29                   0x20000000
#define BIT30                   0x40000000
#define BIT31                   0x80000000

#ifndef RTK_DMP_PLATFORM
#if (LINUX_VERSION_CODE < KERNEL_VERSION(2,6,20))
#ifndef bool
typedef enum{false = 0, true} bool;
#endif
#endif
#endif

typedef union _QOS_TSINFO{
	u8		charData[3];
	struct {
		u8		ucTrafficType:1;			
		u8		ucTSID:4;
		u8		ucDirection:2;
		u8		ucAccessPolicy:2;	
		u8		ucAggregation:1;		
		u8		ucPSB:1;				
		u8		ucUP:3;
		u8		ucTSInfoAckPolicy:2;		
		u8		ucSchedule:1;			
		u8		ucReserved:7;
	}field;
}QOS_TSINFO, *PQOS_TSINFO;
typedef union _TSPEC_BODY{
	u8		charData[55];
	
	struct
	{
		QOS_TSINFO	TSInfo;	
		u16	NominalMSDUsize;
		u16	MaxMSDUsize;
		u32	MinServiceItv;
		u32	MaxServiceItv;
		u32	InactivityItv;
		u32	SuspenItv;
		u32	ServiceStartTime;
		u32	MinDataRate;
		u32	MeanDataRate;
		u32	PeakDataRate;
		u32	MaxBurstSize;
		u32	DelayBound;
		u32	MinPhyRate;
		u16	SurplusBandwidthAllowance;
		u16	MediumTime;
	} f;	
}TSPEC_BODY, *PTSPEC_BODY;

typedef struct _WMM_TSPEC{
	u8		ID;
	u8		Length;
	u8		OUI[3];
	u8		OUI_Type;
	u8		OUI_SubType;
	u8		Version;
	TSPEC_BODY	Body;
} WMM_TSPEC, *PWMM_TSPEC;

typedef struct _OCTET_STRING{
        u8        	*Octet;
        u16             Length;
}OCTET_STRING, *POCTET_STRING;
#define	MAX_WMMELE_LENGTH	64

typedef u32 QOS_MODE, *PQOS_MODE;
#define QOS_DISABLE		0
#define QOS_WMM		1
#define QOS_WMMSA		2
#define QOS_EDCA		4
#define QOS_HCCA		8
#define QOS_WMM_UAPSD		16   

#define WMM_PARAM_ELE_BODY_LEN	18

#define MAX_STA_TS_COUNT			16
#define MAX_AP_TS_COUNT			32
#define QOS_TSTREAM_KEY_SIZE		13 

#define WMM_ACTION_CATEGORY_CODE	17
#define WMM_PARAM_ELE_BODY_LEN	18

#define MAX_TSPEC_TSID				15
#define SESSION_REJECT_TSID			0xfe
#define DEFAULT_TSID					0xff

#define ADDTS_TIME_SLOT				100		

#define ACM_TIMEOUT				1000	
#define SESSION_REJECT_TIMEOUT		60000

typedef	enum _ACK_POLICY{
	eAckPlc0_ACK		= 0x00,
	eAckPlc1_NoACK		= 0x01,
}ACK_POLICY,*PACK_POLICY;


#if 0
#define FRAME_OFFSET_QOS_CTRL(_pStart) 				(24 + 6*GET_80211_HDR_FROM_DS(_pStart)*GET_80211_HDR_TO_DS(_pStart))

#define GET_QOS_CTRL(_pStart)					ReadEF2Byte((pu1Byte)(_pStart) + FRAME_OFFSET_QOS_CTRL(_pStart))
#define SET_QOS_CTRL(_pStart, _value)				WriteEF2Byte((pu1Byte)(_pStart) + FRAME_OFFSET_QOS_CTRL(_pStart), _value)

#define GET_QOS_CTRL_WMM_UP(_pStart)				((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 0, 3))
#define SET_QOS_CTRL_WMM_UP(_pStart, _value)			SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 0, 3, (u1Byte)(_value))

#define GET_QOS_CTRL_WMM_EOSP(_pStart)				((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 4, 1))
#define SET_QOS_CTRL_WMM_EOSP(_pStart, _value)			SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 4, 1, (u1Byte)(_value))

#define GET_QOS_CTRL_WMM_ACK_POLICY(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 5, 2))
#define SET_QOS_CTRL_WMM_ACK_POLICY(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 5, 2, (u1Byte)(_value))

#define GET_QOS_CTRL_STA_DATA_TID(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 0, 4))
#define SET_QOS_CTRL_STA_DATA_TID(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 0, 4, (u1Byte)(_value))

#define GET_QOS_CTRL_STA_DATA_QSIZE_FLAG(_pStart)		((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 4, 1))
#define SET_QOS_CTRL_STA_DATA_QSIZE_FLAG(_pStart, _value)	SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 4, 1, (u1Byte)(_value))

#define GET_QOS_CTRL_STA_DATA_ACK_POLICY(_pStart)		((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 5, 2))
#define SET_QOS_CTRL_STA_DATA_ACK_POLICY(_pStart, _value)	SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 5, 2, (u1Byte)(_value))

#define GET_QOS_CTRL_STA_DATA_USRSVD(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 7, 1))
#define SET_QOS_CTRL_STA_DATA_USRSVD(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 7, 1, (u1Byte)(_value))

#define GET_QOS_CTRL_STA_DATA_TXOP(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 8, 8))
#define SET_QOS_CTRL_STA_DATA_TXOP(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 8, 8, (u1Byte)(_value))

#define GET_QOS_CTRL_STA_DATA_QSIZE(_pStart)	GET_QOS_CTRL_STA_DATA_TXOP(_pStart)
#define SET_QOS_CTRL_STA_DATA_QSIZE(_pStart, _value)	SET_QOS_CTRL_STA_DATA_TXOP(_pStart)

#define GET_QOS_CTRL_HC_DATA_TID(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 0, 4))
#define SET_QOS_CTRL_HC_DATA_TID(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 0, 4, (u1Byte)(_value))

#define GET_QOS_CTRL_HC_DATA_EOSP(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 4, 1))
#define SET_QOS_CTRL_HC_DATA_EOSP(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 4, 1, (u1Byte)(_value))

#define GET_QOS_CTRL_HC_DATA_ACK_POLICY(_pStart)		((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 5, 2))
#define SET_QOS_CTRL_HC_DATA_ACK_POLICY(_pStart, _value)	SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 5, 2, (u1Byte)(_value))

#define GET_QOS_CTRL_HC_DATA_PS_BUFSTATE(_pStart)		((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 8, 8))
#define SET_QOS_CTRL_HC_DATA_PS_BUFSTATE(_pStart, _value)	SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 8, 8, (u1Byte)(_value))

#define GET_QOS_CTRL_HC_CFP_TID(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 0, 4))
#define SET_QOS_CTRL_HC_CFP_TID(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 0, 4, (u1Byte)(_value))

#define GET_QOS_CTRL_HC_CFP_EOSP(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 4, 1))
#define SET_QOS_CTRL_HC_CFP_EOSP(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 4, 1, (u1Byte)(_value))

#define GET_QOS_CTRL_HC_CFP_ACK_POLICY(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 5, 2))
#define SET_QOS_CTRL_HC_CFP_ACK_POLICY(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 5, 2, (u1Byte)(_value))

#define GET_QOS_CTRL_HC_CFP_USRSVD(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 7, 1))
#define SET_QOS_CTRL_HC_CFP_USRSVD(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 7, 1, (u1Byte)(_value))

#define GET_QOS_CTRL_HC_CFP_TXOP_LIMIT(_pStart)			((u1Byte)LE_BITS_TO_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 8, 8))
#define SET_QOS_CTRL_HC_CFP_TXOP_LIMIT(_pStart, _value)		SET_BITS_TO_LE_2BYTE((pu1Byte)(_pStart)+FRAME_OFFSET_QOS_CTRL(_pStart), 8, 8, (u1Byte)(_value))
#endif



#define SET_WMM_QOS_INFO_FIELD(_pStart, _val)						WriteEF1Byte(_pStart, _val)

#define GET_WMM_QOS_INFO_FIELD_PARAMETERSET_COUNT(_pStart)		LE_BITS_TO_1BYTE(_pStart, 0, 4)
#define SET_WMM_QOS_INFO_FIELD_PARAMETERSET_COUNT(_pStart, _val)	SET_BITS_TO_LE_1BYTE(_pStart, 0, 4, _val)

#define GET_WMM_QOS_INFO_FIELD_AP_UAPSD(_pStart)					LE_BITS_TO_1BYTE(_pStart, 7, 1)
#define SET_WMM_QOS_INFO_FIELD_AP_UAPSD(_pStart, _val)				SET_BITS_TO_LE_1BYTE(_pStart, 7, 1, _val)

#define GET_WMM_QOS_INFO_FIELD_STA_AC_VO_UAPSD(_pStart)			LE_BITS_TO_1BYTE(_pStart, 0, 1)
#define SET_WMM_QOS_INFO_FIELD_STA_AC_VO_UAPSD(_pStart, _val)		SET_BITS_TO_LE_1BYTE(_pStart, 0, 1, _val)

#define GET_WMM_QOS_INFO_FIELD_STA_AC_VI_UAPSD(_pStart)			LE_BITS_TO_1BYTE(_pStart, 1, 1)
#define SET_WMM_QOS_INFO_FIELD_STA_AC_VI_UAPSD(_pStart, _val)		SET_BITS_TO_LE_1BYTE(_pStart, 1, 1, _val)

#define GET_WMM_QOS_INFO_FIELD_STA_AC_BE_UAPSD(_pStart)			LE_BITS_TO_1BYTE(_pStart, 2, 1)
#define SET_WMM_QOS_INFO_FIELD_STA_AC_BE_UAPSD(_pStart, _val)		SET_BITS_TO_LE_1BYTE(_pStart, 2, 1, _val)
	
#define GET_WMM_QOS_INFO_FIELD_STA_AC_BK_UAPSD(_pStart)			LE_BITS_TO_1BYTE(_pStart, 3, 1)
#define SET_WMM_QOS_INFO_FIELD_STA_AC_BK_UAPSD(_pStart, _val)		SET_BITS_TO_LE_1BYTE(_pStart, 3, 1, _val)

#define GET_WMM_QOS_INFO_FIELD_STA_MAX_SP_LEN(_pStart)			LE_BITS_TO_1BYTE(_pStart, 5, 2)
#define SET_WMM_QOS_INFO_FIELD_STA_MAX_SP_LEN(_pStart, _val)		SET_BITS_TO_LE_1BYTE(_pStart, 5, 2, _val)
		
#if 0
#define WMM_INFO_ELEMENT_SIZE	7

#define GET_WMM_INFO_ELE_OUI(_pStart)					((u8*)(_pStart))
#define SET_WMM_INFO_ELE_OUI(_pStart, _pVal)				memcpy(_pStart, _pVal, 3);

#define GET_WMM_INFO_ELE_OUI_TYPE(_pStart)				( EF1Byte( *((u8*)(_pStart)+3) ) )
#define SET_WMM_INFO_ELE_OUI_TYPE(_pStart, _val)			( *((u8*)(_pStart)+3) = EF1Byte(_val) )

#define GET_WMM_INFO_ELE_OUI_SUBTYPE(_pStart)			( EF1Byte( *((u8*)(_pStart)+4) ) )
#define SET_WMM_INFO_ELE_OUI_SUBTYPE(_pStart, _val)		( *((u8*)(_pStart)+4) = EF1Byte(_val) )

#define GET_WMM_INFO_ELE_VERSION(_pStart)				( EF1Byte( *((u8*)(_pStart)+5) ) )
#define SET_WMM_INFO_ELE_VERSION(_pStart, _val)			( *((u8*)(_pStart)+5) = EF1Byte(_val) )

#define GET_WMM_INFO_ELE_QOS_INFO_FIELD(_pStart)		( EF1Byte( *((u8*)(_pStart)+6) ) )
#define SET_WMM_INFO_ELE_QOS_INFO_FIELD(_pStart, _val)	( *((u8*)(_pStart)+6) = EF1Byte(_val) )


#define CLEAR_TSPEC(_tspec)	( PlatformZeroMemory((_tspec), TSPEC_SIZE) )

#define GET_TSPEC_ID(_tspec) EF1Byte( (_tspec)[0] )
#define SET_TSPEC_ID(_tspec, _value) ( (_tspec)[0] = EF1Byte(_value) )

#define GET_TSPEC_LENGTH(_tspec) EF1Byte( (_tspec)[1] )
#define SET_TSPEC_LENGTH(_tspec, _value) ( (_tspec)[1] = EF1Byte(_value) )

#define GET_TSPEC_OUI(_tspec, _value) \
	{ (_value)[0]=(_tspec)[2];  (_value)[1]=(_tspec)[3];  (_value)[2]=(_tspec)[4]; }
#define SET_TSPEC_OUI(_tspec, _value) \
	{ (_tspec)[2]=(_value)[0];  (_tspec)[3]=(_value)[1];  (_tspec)[4]=(_value)[2]; }

#define GET_TSPEC_OUI_TYPE(_tspec) EF1Byte( (_tspec)[5] )
#define SET_TSPEC_OUI_TYPE(_tspec, _value) ( (_tspec)[5] = EF1Byte(_value) )

#define GET_TSPEC_OUI_SUBTYPE(_tspec) EF1Byte( (_tspec)[6] )
#define SET_TSPEC_OUI_SUBTYPE(_tspec, _value) ( (_tspec)[6] = EF1Byte(_value) )

#define GET_TSPEC_VERSION(_tspec) EF1Byte( (_tspec)[7] )
#define SET_TSPEC_VERSION(_tspec, _value) ( (_tspec)[7] = EF1Byte(_value) )


#define GET_TSPEC_TSINFO_TRAFFIC_TYPE(_tspec) LE_BITS_TO_1BYTE( (_tspec)+8, 0, 1)
#define SET_TSPEC_TSINFO_TRAFFIC_TYPE(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+8, 0, 1, (_value) )

#define GET_TSPEC_TSINFO_TSID(_tspec) LE_BITS_TO_1BYTE( (_tspec)+8, 1, 4)
#define SET_TSPEC_TSINFO_TSID(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+8, 1, 4, (_value) )

#define GET_TSPEC_TSINFO_DIRECTION(_tspec) LE_BITS_TO_1BYTE( (_tspec)+8, 5, 2)
#define SET_TSPEC_TSINFO_DIRECTION(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+8, 5, 2, (_value) )

#define GET_TSPEC_TSINFO_ACCESS_POLICY_BIT0(_tspec) LE_BITS_TO_1BYTE( (_tspec)+8, 7, 1)
#define SET_TSPEC_TSINFO_ACCESS_POLICY_BIT0(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+8, 7, 1, (_value) )


#define GET_TSPEC_TSINFO_ACCESS_POLICY_BIT1(_tspec) LE_BITS_TO_1BYTE( (_tspec)+9, 0, 1)
#define SET_TSPEC_TSINFO_ACCESS_POLICY_BIT1(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+9, 0, 1, (_value) )

#define GET_TSPEC_TSINFO_AGGREGATION(_tspec) LE_BITS_TO_1BYTE( (_tspec)+9, 1, 1)
#define SET_TSPEC_TSINFO_AGGREGATION(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+9, 1, 1, (_value) )

#define GET_TSPEC_TSINFO_PSB(_tspec) LE_BITS_TO_1BYTE( (_tspec)+9, 2, 1)
#define SET_TSPEC_TSINFO_PSB(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+9, 2, 1, (_value) )

#define GET_TSPEC_TSINFO_UP(_tspec) LE_BITS_TO_1BYTE( (_tspec)+9, 3, 3)
#define SET_TSPEC_TSINFO_UP(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+9, 3, 3, (_value) )

#define GET_TSPEC_TSINFO_ACK_POLICY(_tspec) LE_BITS_TO_1BYTE( (_tspec)+9, 6, 2)
#define SET_TSPEC_TSINFO_ACK_POLICY(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+9, 6, 2, (_value) )


#define GET_TSPEC_TSINFO_SCHEDULE(_tspec) LE_BITS_TO_1BYTE( (_tspec)+10, 0, 1)
#define SET_TSPEC_TSINFO_SCHEDULE(_tspec, _value) SET_BITS_TO_LE_1BYTE( (_tspec)+10, 0, 1, (_value) )


#define GET_TSPEC_NOMINAL_MSDU_SIZE(_tspec) LE_BITS_TO_2BYTE( (_tspec)+11, 0, 16)
#define SET_TSPEC_NOMINAL_MSDU_SIZE(_tspec, _value) SET_BITS_TO_LE_2BYTE( (_tspec)+11, 0, 16, (_value) )

#define GET_TSPEC_MAX_MSDU_SIZE(_tspec) LE_BITS_TO_2BYTE( (_tspec)+13, 0, 16)
#define SET_TSPEC_MAX_MSDU_SIZE(_tspec, _value) SET_BITS_TO_LE_2BYTE( (_tspec)+13, 0, 16, (_value) )

#define GET_TSPEC_MIN_SERVICE_INTERVAL(_tspec) LE_BITS_TO_4BYTE( (_tspec)+15, 0, 32)
#define SET_TSPEC_MIN_SERVICE_INTERVAL(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+15, 0, 32, (_value) )

#define GET_TSPEC_MAX_SERVICE_INTERVAL(_tspec) LE_BITS_TO_4BYTE( (_tspec)+19, 0, 32)
#define SET_TSPEC_MAX_SERVICE_INTERVAL(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+19, 0, 32, (_value) )

#define GET_TSPEC_INACTIVITY_INTERVAL(_tspec) LE_BITS_TO_4BYTE( (_tspec)+23, 0, 32)
#define SET_TSPEC_INACTIVITY_INTERVAL(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+23, 0, 32, (_value) )

#define GET_TSPEC_SUSPENSION_INTERVAL(_tspec) LE_BITS_TO_4BYTE( (_tspec)+27, 0, 32)
#define SET_TSPEC_SUSPENSION_INTERVAL(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+27, 0, 32, (_value) )

#define GET_TSPEC_SERVICE_START_TIME(_tspec) LE_BITS_TO_4BYTE( (_tspec)+31, 0, 32)
#define SET_TSPEC_SERVICE_START_TIME(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+31, 0, 32, (_value) )

#define GET_TSPEC_MIN_DATA_RATE(_tspec) LE_BITS_TO_4BYTE( (_tspec)+35, 0, 32)
#define SET_TSPEC_MIN_DATA_RATE(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+35, 0, 32, (_value) )

#define GET_TSPEC_MEAN_DATA_RATE(_tspec) LE_BITS_TO_4BYTE( (_tspec)+39, 0, 32)
#define SET_TSPEC_MEAN_DATA_RATE(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+39, 0, 32, (_value) )

#define GET_TSPEC_PEAK_DATA_RATE(_tspec) LE_BITS_TO_4BYTE( (_tspec)+43, 0, 32)
#define SET_TSPEC_PEAK_DATA_RATE(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+43, 0, 32, (_value) )

#define GET_TSPEC_MAX_BURST_SIZE(_tspec) LE_BITS_TO_4BYTE( (_tspec)+47, 0, 32)
#define SET_TSPEC_MAX_BURST_SIZE(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+47, 0, 32, (_value) )

#define GET_TSPEC_DELAY_BOUND(_tspec) LE_BITS_TO_4BYTE( (_tspec)+51, 0, 32)
#define SET_TSPEC_DELAY_BOUND(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+51, 0, 32, (_value) )

#define GET_TSPEC_MIN_PHY_RATE(_tspec) LE_BITS_TO_4BYTE( (_tspec)+55, 0, 32)
#define SET_TSPEC_MIN_PHY_RATE(_tspec, _value) SET_BITS_TO_LE_4BYTE( (_tspec)+55, 0, 32, (_value) )

#define GET_TSPEC_SURPLUS_BANDWITH_ALLOWANCE(_tspec) LE_BITS_TO_2BYTE( (_tspec)+59, 0, 16)
#define SET_TSPEC_SURPLUS_BANDWITH_ALLOWANCE(_tspec, _value) SET_BITS_TO_LE_2BYTE( (_tspec)+59, 0, 16, (_value) )

#define GET_TSPEC_MEDIUM_TIME(_tspec) LE_BITS_TO_2BYTE( (_tspec)+61, 0, 16)
#define SET_TSPEC_MEDIUM_TIME(_tspec, _value) SET_BITS_TO_LE_2BYTE( (_tspec)+61, 0, 16, (_value) )

#define GET_TSPEC_TSINFO_ACCESS_POLICY(_tspec) \
	( (GET_TSPEC_TSINFO_ACCESS_POLICY_BIT1(_tspec) << 1) | GET_TSPEC_TSINFO_ACCESS_POLICY_BIT0(_tspec) )
#define SET_TSPEC_TSINFO_ACCESS_POLICY(_tspec, _value) \
	{\
		SET_TSPEC_TSINFO_ACCESS_POLICY_BIT0((_tspec), (_value)&0x01);\
		SET_TSPEC_TSINFO_ACCESS_POLICY_BIT1((_tspec), (_value)&0x02);\
	}


#define GET_TSINFO_TRAFFIC_TYPE(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo), 0, 1)
#define SET_TSINFO_TRAFFIC_TYPE(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo), 0, 1, (_value) )

#define GET_TSINFO_TSID(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo), 1, 4)
#define SET_TSINFO_TSID(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo), 1, 4, (_value) )

#define GET_TSINFO_DIRECTION(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo), 5, 2)
#define SET_TSINFO_DIRECTION(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo), 5, 2, (_value) )

#define GET_TSINFO_ACCESS_POLICY_BIT0(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo), 7, 1)
#define SET_TSINFO_ACCESS_POLICY_BIT0(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo), 7, 1, (_value) )


#define GET_TSINFO_ACCESS_POLICY_BIT1(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo) + 1, 0, 1)
#define SET_TSINFO_ACCESS_POLICY_BIT1(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo) + 1, 0, 1, (_value) )

#define GET_TSINFO_AGGREGATION(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo) + 1, 1, 1)
#define SET_TSINFO_AGGREGATION(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo) + 1, 1, 1, (_value) )

#define GET_TSINFO_PSB(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo) + 1, 2, 1)
#define SET_TSINFO_PSB(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo) + 1, 2, 1, (_value) )

#define GET_TSINFO_UP(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo) + 1, 3, 3)
#define SET_TSINFO_UP(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo) + 1, 3, 3, (_value) )

#define GET_TSINFO_ACK_POLICY(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo) + 1, 6, 2)
#define SET_TSINFO_ACK_POLICY(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo) + 1, 6, 2, (_value) )

#define GET_TSINFO_SCHEDULE(_tsinfo) LE_BITS_TO_1BYTE( (_tsinfo) + 2, 0, 1)
#define SET_TSINFO_SCHEDULE(_tsinfo, _value) SET_BITS_TO_LE_1BYTE( (_tsinfo) + 2, 0, 1, (_value) )


#define QOS_RATE_TO_BPS(_rate) ( (u4Byte)( ((_rate)*1000*1000)/2 ) )
#define QOS_BPS_TO_RATE(_bps)  ( (u1Byte)( ((_bps)/(1000*1000))*2 ) ) 
#endif

typedef enum {
	QOSIE_SRC_ADDTSREQ,
	QOSIE_SRC_ADDTSRSP,
	QOSIE_SRC_REASOCREQ,
	QOSIE_SRC_REASOCRSP,
	QOSIE_SRC_DELTS,
} QOSIE_SOURCE;


typedef u32 AC_CODING;
#define AC0_BE	0		
#define AC1_BK	1		
#define AC2_VI	2		
#define AC3_VO	3		
#define AC_MAX	4		

	
#define AC_PARAM_SIZE	4

#define GET_WMM_AC_PARAM_AIFSN(_pStart)				( (u8)LE_BITS_TO_4BYTE(_pStart, 0, 4) )
#define SET_WMM_AC_PARAM_AIFSN(_pStart, _val)		SET_BITS_TO_LE_4BYTE(_pStart, 0, 4, _val)

#define GET_WMM_AC_PARAM_ACM(_pStart)				( (u8)LE_BITS_TO_4BYTE(_pStart, 4, 1) )
#define SET_WMM_AC_PARAM_ACM(_pStart, _val)			SET_BITS_TO_LE_4BYTE(_pStart, 4, 1, _val)

#define GET_WMM_AC_PARAM_ACI(_pStart)				( (u8)LE_BITS_TO_4BYTE(_pStart, 5, 2) )
#define SET_WMM_AC_PARAM_ACI(_pStart, _val)			SET_BITS_TO_LE_4BYTE(_pStart, 5, 2, _val)

#define GET_WMM_AC_PARAM_ACI_AIFSN(_pStart)			( (u8)LE_BITS_TO_4BYTE(_pStart, 0, 8) )
#define SET_WMM_AC_PARAM_ACI_AIFSN(_pStart, _val)	SET_BITS_TO_LE_4BYTE(_pStart, 0, 8, _val)

#define GET_WMM_AC_PARAM_ECWMIN(_pStart)			( (u8)LE_BITS_TO_4BYTE(_pStart, 8, 4) )
#define SET_WMM_AC_PARAM_ECWMIN(_pStart, _val)		SET_BITS_TO_LE_4BYTE(_pStart, 8, 4, _val)

#define GET_WMM_AC_PARAM_ECWMAX(_pStart)			( (u8)LE_BITS_TO_4BYTE(_pStart, 12, 4) )
#define SET_WMM_AC_PARAM_ECWMAX(_pStart, _val)		SET_BITS_TO_LE_4BYTE(_pStart, 12, 4, _val)

#define GET_WMM_AC_PARAM_TXOP_LIMIT(_pStart)		( (u8)LE_BITS_TO_4BYTE(_pStart, 16, 16) )
#define SET_WMM_AC_PARAM_TXOP_LIMIT(_pStart, _val)	SET_BITS_TO_LE_4BYTE(_pStart, 16, 16, _val)



#define WMM_PARAM_ELEMENT_SIZE	(8+(4*AC_PARAM_SIZE))

#if 0
#define GET_WMM_PARAM_ELE_OUI(_pStart)	((pu1Byte)(_pStart))
#define SET_WMM_PARAM_ELE_OUI(_pStart, _pVal)	PlatformMoveMemory(_pStart, _pVal, 3)

#define GET_WMM_PARAM_ELE_OUI_TYPE(_pStart)	( EF1Byte( *((pu1Byte)(_pStart)+3) ) )
#define SET_WMM_PARAM_ELE_OUI_TYPE(_pStart, _val)	( *((pu1Byte)(_pStart)+3) = EF1Byte(_val) )

#define GET_WMM_PARAM_ELE_OUI_SUBTYPE(_pStart)	( EF1Byte( *((pu1Byte)(_pStart)+4) ) )
#define SET_WMM_PARAM_ELE_OUI_SUBTYPE(_pStart, _val)	( *((pu1Byte)(_pStart)+4) = EF1Byte(_val) )

#define GET_WMM_PARAM_ELE_VERSION(_pStart)	( EF1Byte( *((pu1Byte)(_pStart)+5) ) )
#define SET_WMM_PARAM_ELE_VERSION(_pStart, _val)	( *((pu1Byte)(_pStart)+5) = EF1Byte(_val) )

#define GET_WMM_PARAM_ELE_QOS_INFO_FIELD(_pStart)	( EF1Byte( *((pu1Byte)(_pStart)+6) ) )
#define SET_WMM_PARAM_ELE_QOS_INFO_FIELD(_pStart, _val)	( *((pu1Byte)(_pStart)+6) = EF1Byte(_val) )

#define GET_WMM_PARAM_ELE_AC_PARAMS(_pStart)		( (pu1Byte)(_pStart)+8 )
#define SET_WMM_PARAM_ELE_AC_PARAMS(_pStart, _pVal) 	PlatformMoveMemory((_pStart)+8, _pVal, 16)

#define GET_WMM_PARAM_ELE_SINGLE_AC_PARAM(_pStart, acIdx)		( ((pu1Byte)(_pStart))+8+ acIdx*4 )
#define SET_WMM_PARAM_ELE_SINGLE_AC_PARAM(_pStart, acIdx, _pVal)	PlatformMoveMemory( ((pu1Byte)(_pStart))+8+ acIdx*4, _pVal, 4)

#define GET_WMM_PARAM_ELE_AC_PARAM(_pStart)	( (pu1Byte)(_pStart)+8 )
#define SET_WMM_PARAM_ELE_AC_PARAM(_pStart, _pVal) PlatformMoveMemory((_pStart)+8, _pVal, 16)
#endif

typedef	enum _QOS_ELE_SUBTYPE{
	QOSELE_TYPE_INFO		= 0x00,		
	QOSELE_TYPE_PARAM	= 0x01,		
}QOS_ELE_SUBTYPE,*PQOS_ELE_SUBTYPE;


typedef	enum _DIRECTION_VALUE{
	DIR_UP			= 0,		
	DIR_DOWN		= 1,		
	DIR_DIRECT		= 2,		
	DIR_BI_DIR		= 3,		
}DIRECTION_VALUE,*PDIRECTION_VALUE;

#if 0

#define GET_TSPEC_BODY_TSINFO_TRAFFIC_TYPE(_TSpecBody)				LE_BITS_TO_1BYTE( (_TSpecBody), 0, 1)
#define SET_TSPEC_BODY_TSINFO_TRAFFIC_TYPE(_TSpecBody, _value)			SET_BITS_TO_LE_1BYTE( (_TSpecBody), 0, 1 , (_value))

#define GET_TSPEC_BODY_TSINFO_TSID(_TSpecBody)					LE_BITS_TO_1BYTE( (_TSpecBody), 1, 4)
#define SET_TSPEC_BODY_TSINFO_TSID(_TSpecBody, _value)				SET_BITS_TO_LE_1BYTE( (_TSpecBody), 1, 4 , (_value))

#define GET_TSPEC_BODY_TSINFO_DIRECTION(_TSpecBody)				LE_BITS_TO_1BYTE( (_TSpecBody), 5, 2)
#define SET_TSPEC_BODY_TSINFO_DIRECTION(_TSpecBody, _value)			SET_BITS_TO_LE_1BYTE( (_TSpecBody), 5, 2 , (_value))

#define GET_TSPEC_BODY_TSINFO_ACCESS_POLICY_BIT0(_TSpecBody)			LE_BITS_TO_1BYTE( (_TSpecBody), 7, 1)
#define SET_TSPEC_BODY_TSINFO_ACCESS_POLICY_BIT0(_TSpecBody, _value)		SET_BITS_TO_LE_1BYTE( (_TSpecBody), 7, 1 , (_value))

#define GET_TSPEC_BODY_TSINFO_ACCESS_POLICY_BIT1(_TSpecBody)			LE_BITS_TO_1BYTE( (_TSpecBody)+1, 0, 1)
#define SET_TSPEC_BODY_TSINFO_ACCESS_POLICY_BIT1(_TSpecBody, _value)		SET_BITS_TO_LE_1BYTE( (_TSpecBody)+1, 0, 1 , (_value))

#define GET_TSPEC_BODY_TSINFO_ACCESS_POLICY(_TSpecBody) \
		((GET_TSPEC_BODY_TSINFO_ACCESS_POLICY_BIT1(_TSpecBody) << 1 ) | (GET_TSPEC_BODY_TSINFO_ACCESS_POLICY_BIT0(_TSpecBody) ))
#define SET_TSPEC_BODY_TSINFO_ACCESS_POLICY(_TSpecBody, _value) \
		{\
			SET_TSPEC_BODY_TSINFO_ACCESS_POLICY_BIT0((_TSpecBody), (_value) & 0x01); \
			SET_TSPEC_BODY_TSINFO_ACCESS_POLICY_BIT1((_TSpecBody), (_value) & 0x02); \
		}

#define GET_TSPEC_BODY_TSINFO_AGGREGATION(_TSpecBody)				LE_BITS_TO_1BYTE( (_TSpecBody)+1, 1, 1)
#define SET_TSPEC_BODY_TSINFO_AGGREGATION(_TSpecBody, _value)			SET_BITS_TO_LE_1BYTE( (_TSpecBody)+1, 1, 1 , (_value))
		
#define GET_TSPEC_BODY_TSINFO_PSB(_TSpecBody)					LE_BITS_TO_1BYTE( (_TSpecBody)+1, 2, 1)
#define SET_TSPEC_BODY_TSINFO_PSB(_TSpecBody, _value)				SET_BITS_TO_LE_1BYTE( (_TSpecBody)+1, 2, 1 , (_value))

#define GET_TSPEC_BODY_TSINFO_UP(_TSpecBody)					LE_BITS_TO_1BYTE( (_TSpecBody)+1, 3, 3)
#define SET_TSPEC_BODY_TSINFO_UP(_TSpecBody, _value)				SET_BITS_TO_LE_1BYTE( (_TSpecBody)+1, 3, 3 , (_value))

#define GET_TSPEC_BODY_TSINFO_ACK_POLICY(_TSpecBody)				LE_BITS_TO_1BYTE( (_TSpecBody)+1, 6, 2)
#define SET_TSPEC_BODY_TSINFO_ACK_POLICY(_TSpecBody, _value)			SET_BITS_TO_LE_1BYTE( (_TSpecBody)+1, 6, 2 , (_value))

#define GET_TSPEC_BODY_TSINFO_SCHEDULE(_TSpecBody)				LE_BITS_TO_1BYTE( (_TSpecBody)+2, 0, 1)
#define SET_TSPEC_BODY_TSINFO_SCHEDULE(_TSpecBody, _value)			SET_BITS_TO_LE_1BYTE( (_TSpecBody)+2, 0, 1 , (_value))



#define TSPEC_SIZE		(2+6+55)
typedef u8			WMM_TSPEC[TSPEC_SIZE], *PWMM_TSPEC;
#endif

typedef	enum _ACM_METHOD{
	eAcmWay0_SwAndHw		= 0,		
	eAcmWay1_HW			= 1,		
	eAcmWay2_SW			= 2,		
}ACM_METHOD,*PACM_METHOD;


typedef struct _ACM{
	u64		UsedTime;
	u64		MediumTime;
	u8		HwAcmCtl;	
}ACM, *PACM;



typedef	u8		AC_UAPSD, *PAC_UAPSD;

#define	GET_VO_UAPSD(_apsd) ((_apsd) & BIT0)
#define	SET_VO_UAPSD(_apsd) ((_apsd) |= BIT0)
	
#define	GET_VI_UAPSD(_apsd) ((_apsd) & BIT1)
#define	SET_VI_UAPSD(_apsd) ((_apsd) |= BIT1)

#define	GET_BK_UAPSD(_apsd) ((_apsd) & BIT2)
#define	SET_BK_UAPSD(_apsd) ((_apsd) |= BIT2)

#define	GET_BE_UAPSD(_apsd) ((_apsd) & BIT3)
#define	SET_BE_UAPSD(_apsd) ((_apsd) |= BIT3)

typedef union _QOS_TCLAS{

	struct _TYPE_GENERAL{
		u8		Priority;
		u8 		ClassifierType;
		u8 		Mask;
	} TYPE_GENERAL;

	struct _TYPE0_ETH{
		u8		Priority;
		u8 		ClassifierType;
		u8 		Mask;
		u8		SrcAddr[6];
		u8		DstAddr[6];
		u16		Type;
	} TYPE0_ETH;

	struct _TYPE1_IPV4{
		u8		Priority;
		u8 		ClassifierType;
		u8 		Mask;
		u8 		Version;
		u8		SrcIP[4];
		u8		DstIP[4];
		u16		SrcPort;
		u16		DstPort;
		u8		DSCP;
		u8		Protocol;
		u8		Reserved;
	} TYPE1_IPV4;

	struct _TYPE1_IPV6{
		u8		Priority;
		u8 		ClassifierType;
		u8 		Mask;
		u8 		Version;
		u8		SrcIP[16];
		u8		DstIP[16];
		u16		SrcPort;
		u16		DstPort;
		u8		FlowLabel[3];
	} TYPE1_IPV6;

	struct _TYPE2_8021Q{
		u8		Priority;
		u8 		ClassifierType;
		u8 		Mask;
		u16		TagType;
	} TYPE2_8021Q;
} QOS_TCLAS, *PQOS_TCLAS;

typedef struct _QOS_TSTREAM{

	bool			bUsed;
	u16			MsduLifetime;
	bool			bEstablishing;
	u8			TimeSlotCount;
	u8			DialogToken;
	WMM_TSPEC	TSpec;
	WMM_TSPEC	OutStandingTSpec;
	u8			NominalPhyRate;
} QOS_TSTREAM, *PQOS_TSTREAM;

typedef struct _STA_QOS{
	u8				WMMIEBuf[MAX_WMMELE_LENGTH];
	u8*				WMMIE;

	QOS_MODE		QosCapability; 
	QOS_MODE		CurrentQosMode;

	AC_UAPSD		b4ac_Uapsd;  
	AC_UAPSD		Curr4acUapsd;
	u8				bInServicePeriod;
	u8				MaxSPLength;
	int 				NumBcnBeforeTrigger;

	u8 *				pWMMInfoEle;
	u8				WMMParamEle[WMM_PARAM_ELEMENT_SIZE];

	ACM				acm[4];
	ACM_METHOD		AcmMethod;

	QOS_TSTREAM		StaTsArray[MAX_STA_TS_COUNT]; 
	u8				DialogToken;
	WMM_TSPEC		TSpec;
	
	u8				QBssWirelessMode;

	bool				bNoAck;

	bool				bEnableRxImmBA;

}STA_QOS, *PSTA_QOS;

#define QBSS_LOAD_SIZE 5
#define GET_QBSS_LOAD_STA_COUNT(__pStart) 					ReadEF2Byte(__pStart)
#define SET_QBSS_LOAD_STA_COUNT(__pStart, __Value) 			WriteEF2Byte(__pStart, __Value)
#define GET_QBSS_LOAD_CHNL_UTILIZATION(__pStart) 			ReadEF1Byte((u8*)(__pStart) + 2)
#define SET_QBSS_LOAD_CHNL_UTILIZATION(__pStart, __Value) 		WriteEF1Byte((u8*)(__pStart) + 2, __Value)
#define GET_QBSS_LOAD_AVAILABLE_CAPACITY(__pStart) 			ReadEF2Byte((u8*)(__pStart) + 3)
#define SET_QBSS_LOAD_AVAILABLE_CAPACITY(__pStart, __Value) 	WriteEF2Byte((u8*)(__pStart) + 3, __Value)

typedef struct _BSS_QOS{

	QOS_MODE			bdQoSMode;
	u8					bdWMMIEBuf[MAX_WMMELE_LENGTH];
	OCTET_STRING			bdWMMIE;

	QOS_ELE_SUBTYPE		EleSubType;

	u8*					pWMMInfoEle;
	u8*					pWMMParamEle;

	u8					QBssLoad[QBSS_LOAD_SIZE];
	bool					bQBssLoadValid;
}BSS_QOS, *PBSS_QOS;

#define sQoSCtlLng	2
#define QOS_CTRL_LEN(_QosMode)		( (_QosMode > QOS_DISABLE)? sQoSCtlLng : 0 )


#define IsACValid(ac)		( ( ac>=0 && ac<=7 )? true : false )


typedef	union _ACI_AIFSN{
	u8	charData;
	
	struct
	{
		u8	AIFSN:4;
		u8	ACM:1;
		u8	ACI:2;
		u8	Reserved:1;
	}f;	
}ACI_AIFSN, *PACI_AIFSN;

typedef	union _ECW{
	u8	charData;
	struct
	{
		u8	ECWmin:4;
		u8	ECWmax:4;
	}f;	
}ECW, *PECW;

typedef	union _AC_PARAM{
	u32	longData;
	u8	charData[4];

	struct
	{
		ACI_AIFSN	AciAifsn;
		ECW		Ecw;
		u16		TXOPLimit;
	}f;	
}AC_PARAM, *PAC_PARAM;





#endif 
