#pragma once

#include "Base.h"

NS_BEGIN(Engine)
    class CTimer_Manager;
    class CGraphic_Device;

class ENGINE_DLL CGameInstance : public CBase
{
    DECLARE_SINGLETON(CGameInstance)

private:
    explicit CGameInstance();
    virtual ~CGameInstance() = default;

public:
    HRESULT Initialize_Engine(const ENGINE_DESC& EngineDesc, _Out_ ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext);
    void Update_Engine(_float fTimeDelta);

    
public: /* For Graphic Device*/
    HRESULT Clear_Buffers(const _float4* pClearColor);
    HRESULT Present();

public: /* For Timer_Manager */
    HRESULT Add_Timer(const _wstring& strTimerTag);
    _float  Compoute_TimeDelta(const _wstring& strTimerTag);

private:
    CGraphic_Device*    m_pGraphic_Device = { nullptr };
    CTimer_Manager*     m_pTimer_Manager = { nullptr };

public:
    virtual void Free() override;

};

NS_END
