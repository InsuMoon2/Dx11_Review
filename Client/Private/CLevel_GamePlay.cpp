#include "CLevel_GamePlay.h"

CLevel_GamePlay::CLevel_GamePlay(Device* device, Context* context)
    : CLevel { device, context }
{
}

HRESULT CLevel_GamePlay::Initialize()
{

    return S_OK;
}

void CLevel_GamePlay::Update(_float fTimeDelta)
{
    CLevel::Update(fTimeDelta);

    int a = 10;
}

void CLevel_GamePlay::LateUpdate(_float fTimeDelta)
{
    CLevel::LateUpdate(fTimeDelta);

    int a = 20;
}

HRESULT CLevel_GamePlay::Render()
{
    _int exit = CLevel::Render();



    return exit;
}

CLevel_GamePlay* CLevel_GamePlay::Create(Device* device, Context* context)
{
    CLevel_GamePlay* pInstance = new CLevel_GamePlay(device, context);

    if (FAILED(pInstance->Initialize()))
    {
        MSG_BOX("Failed to Created : CLevel_GamePlay");
        Safe_Release(pInstance);
    }

    return pInstance;
}

void CLevel_GamePlay::Free()
{
    CLevel::Free();
}
