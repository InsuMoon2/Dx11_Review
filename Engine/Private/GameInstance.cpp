#include "GameInstance.h"
#include "Graphic_Device.h"

IMPLEMENT_SINGLETON(CGameInstance)

CGameInstance::CGameInstance()
{
}

HRESULT CGameInstance::Initialize_Engine(const ENGINE_DESC& EngineDesc, _Out_ ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext)
{
    /* 그래픽 디바이스를 초기화 */
    m_pGraphic_Device = CGraphic_Device::Create(EngineDesc.hWnd, EngineDesc.eWinMode, EngineDesc.iViewportWidth, EngineDesc.iViewportHeight, ppDevice, ppContext);
    NULL_CHECK_RETURN(m_pGraphic_Device, E_FAIL);

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

void CGameInstance::Free()
{
    __super::Free();
}
