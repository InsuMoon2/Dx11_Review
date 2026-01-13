#pragma once

#include "Base.h"

/* 엔진과 클라이언트 개발자와의 소통의 창구가 된다. */
/* 엔진 개발자가 클라이언트 개발자에게 보여주기위한 객체 및 기능들을 게임인스턴스 안에 선언, 정의한다. */
/* 클라개발자는 엔진기능쓰고자한다라면!! 게임인스턴스로 접근하여 호출하념뇓다. */
/* 게임인슽너스는 == 싱글턴. */
/* 기타 엔진을 이용하기위한 주요 매니져들의 사전 준비작업을 수앻나다. IOnmitialize_Engine */
/* 엔진의 갱신이 필요한 경우 모아서 매프레임마다 갱신(Updqte )을 수행해준다 Update_Engine */


NS_BEGIN(Engine)

class ENGINE_DLL CGameInstance final : public CBase
{
	DECLARE_SINGLETON(CGameInstance)
private:
	CGameInstance();
	virtual ~CGameInstance() = default;

public:
	HRESULT Initialize_Engine(const ENGINE_DESC& EngineDesc, _Out_ ID3D11Device** ppDevice, _Out_ ID3D11DeviceContext** ppContext);
	void Update_Engine(_float fTimeDelta);

	/* For.Graphic_Device */
public:
	HRESULT Clear_Buffers(const _float4* pClearColor);
	HRESULT Present();

private:
	class CGraphic_Device*		m_pGraphic_Device = { nullptr };

public:	
	virtual void Free() override;
};

NS_END