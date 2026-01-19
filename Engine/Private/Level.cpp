#include "Level.h"

#include "GameInstance.h"

CLevel::CLevel(Device* device, Context* context)
    : m_Device(device)
    , m_Context(context)
    , m_GameInstance(CGameInstance::GetInstance())
{
    Safe_AddRef(m_Device);
    Safe_AddRef(m_Context);

    Safe_AddRef(m_GameInstance);
}

HRESULT CLevel::Initialize()
{

    return S_OK;
}

void CLevel::Update(_float fTimeDelta)
{

}

void CLevel::LateUpdate(_float fTimeDelta)
{

}

HRESULT CLevel::Render()
{

    return S_OK;
}

void CLevel::Free()
{
    CBase::Free();

    Safe_Release(m_Device);
    Safe_Release(m_Context);
    Safe_Release(m_GameInstance);
}
