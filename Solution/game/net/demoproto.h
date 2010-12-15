/********************************************************************
**       This head file is generated by program,                   **
**            Please do not change it directly.                    **
**                   Auther: Zhou Quan                             **
********************************************************************/

/*       Version Number: 1          */

#ifndef DEMOPROTO_H_INCLUDE_VERSION_1
#define DEMOPROTO_H_INCLUDE_VERSION_1

#include "netdata.h"

/*Defines Begin*/
#define MAX_CHAR_NAME_LEN        32
#define MAX_CHAR_COUNT           32
#define MAX_MONSTER_COUNT        32
/*Defines End*/


/*Define Structs and Unions        Begin*/
typedef struct tagCHAR_DATE{
	unsigned int     dwid;
	char             szname[MAX_CHAR_NAME_LEN];
	unsigned int     dwscene_id;
	unsigned int     dwpos_x;
	unsigned int     dwpos_y;
	int              nhp;
	int              nmp;
}CHAR_DATE;

typedef struct tagMONSTER_DATE{
	unsigned int     dwid;
	unsigned int     dwscene_id;
	unsigned int     dwpos_x;
	unsigned int     dwpos_y;
	int              nhp;
	int              nmp;
}MONSTER_DATE;

typedef struct tagPKG_GETCHAR_REQ{
	unsigned int     dwuser_id;
}PKG_GETCHAR_REQ;

typedef struct tagPKG_GETCHAR_ACK{
	CHAR_DATE        stchar_date;
}PKG_GETCHAR_ACK;

typedef struct tagPKG_LOADSCENE_REQ{
}PKG_LOADSCENE_REQ;

typedef struct tagPKG_SCENE_NTF{
	unsigned int     dwMonsterCount;
	unsigned int     dwCharCount;
	CHAR_DATE        astMonsterInfos[MAX_MONSTER_COUNT];
	CHAR_DATE        astCharInfos[MAX_CHAR_COUNT];
}PKG_SCENE_NTF;

typedef struct tagPKG_LOADSCENE_ACK{
}PKG_LOADSCENE_ACK;

typedef struct tagPKG_ENTERGAME_REQ{
}PKG_ENTERGAME_REQ;

typedef struct tagPKG_ENTERGAME_ACK{
	unsigned int     dwerror;
}PKG_ENTERGAME_ACK;

/*Define Structs and Unions        End*/


enum EN_DemoProto_MessageID
{
	PKGID_GETCHAR_REQ        = 5001,
	PKGID_GETCHAR_ACK        = 5002,
	PKGID_LOADSCENE_REQ      = 5003,
	PKGID_SCENE_NTF          = 5004,
	PKGID_LOADSCENE_ACK      = 5004,
	PKGID_ENTERGAME_REQ      = 5004,
	PKGID_ENTERGAME_ACK      = 5004,
};

/*Encode and Decode Function Declare Begin*/
int EncodeCHAR_DATE(void *pHost, CNetData* poNetData);
int DecodeCHAR_DATE(void *pHost, CNetData* poNetData);
int EncodeMONSTER_DATE(void *pHost, CNetData* poNetData);
int DecodeMONSTER_DATE(void *pHost, CNetData* poNetData);
int EncodePKG_GETCHAR_REQ(void *pHost, CNetData* poNetData);
int DecodePKG_GETCHAR_REQ(void *pHost, CNetData* poNetData);
int EncodePKG_GETCHAR_ACK(void *pHost, CNetData* poNetData);
int DecodePKG_GETCHAR_ACK(void *pHost, CNetData* poNetData);
int EncodePKG_LOADSCENE_REQ(void *pHost, CNetData* poNetData);
int DecodePKG_LOADSCENE_REQ(void *pHost, CNetData* poNetData);
int EncodePKG_SCENE_NTF(void *pHost, CNetData* poNetData);
int DecodePKG_SCENE_NTF(void *pHost, CNetData* poNetData);
int EncodePKG_LOADSCENE_ACK(void *pHost, CNetData* poNetData);
int DecodePKG_LOADSCENE_ACK(void *pHost, CNetData* poNetData);
int EncodePKG_ENTERGAME_REQ(void *pHost, CNetData* poNetData);
int DecodePKG_ENTERGAME_REQ(void *pHost, CNetData* poNetData);
int EncodePKG_ENTERGAME_ACK(void *pHost, CNetData* poNetData);
int DecodePKG_ENTERGAME_ACK(void *pHost, CNetData* poNetData);
/*Encode and Decode Function Declare End*/

typedef int (*EnFuncCDemoProto)(void *pHost, CNetData* poNetData);
typedef int (*DeFuncCDemoProto)(void *pHost, CNetData* poNetData);

class CDemoProto
{
public:
	CDemoProto();
	~CDemoProto();
	int Encode(int iMsgID, void *pHost, char *pNet, int iNetSize);
	int Decode(int iMsgID, char *pNet,int iNetSize, void *pHost);
	EnFuncCDemoProto FindEncodeFunc(int iMsgID);
	DeFuncCDemoProto FindDecodeFunc(int iMsgID);
	bool Init();

private:
	EnFuncCDemoProto m_EncodeFuncArray[8192];
	DeFuncCDemoProto m_DecodeFuncArray[8192];
	CNetData m_oData;
};

#endif