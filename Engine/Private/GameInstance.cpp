#include "GameInstance.h"
#include "Graphic_Device.h"
#include "Timer_Manager.h"

IMPLEMENT_SINGLETON(CGameInstance)

CGameInstance::CGameInstance()
{
}

HRESULT CGameInstance::Initialize_Engine(const ENGINE_DESC& EngineDesc, _Out_ ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext)
{
    /* 그래픽 디바이스를 초기화 */
    m_pGraphic_Device = CGraphic_Device::Create(EngineDesc.hWnd, EngineDesc.eWinMode, EngineDesc.iViewportWidth, EngineDesc.iViewportHeight, ppDevice, ppContext);
    NULL_CHECK_RETURN(m_pGraphic_Device, E_FAIL);

    /* 타이머 매니저 생성 */
    m_pTimer_Manager = CTimer_Manager::Create();
    NULL_CHECK_RETURN(m_pTimer_Manager, E_FAIL);



    return S_OK;
}

void CGameInstance::Update_Engine(_float fTimeDelta)
{
}

HRESULT CGameInstance::Clear_Buffers(const _float4* pClearColor)
{
    if (FAILED(m_pGraphic_Device->Clear_BackBuffer_View(pClearColor)))
        return E_FAIL;

    if (FAILED(m_pGraphic_Device->Clear_DepthStencil_View()))
        return E_FAIL;

}

HRESULT CGameInstance::Present()
{
    return m_pGraphic_Device->Present();
}

HRESULT CGameInstance::Add_Timer(const _wstring& strTimerTag)
{
    return m_pTimer_Manager->Add_Timer(strTimerTag);
}

_float CGameInstance::Compoute_TimeDelta(const _wstring& strTimerTag)
{
    return m_pTimer_Manager->Compute_TimeDelta(strTimerTag);
}

void CGameInstance::Free()
{
    __super::Free();

    Safe_Release(m_pTimer_Manager);
    Safe_Release(m_pGraphic_Device);

}
