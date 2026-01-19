#include "CLevel_Loading.h"

CLevel_Loading::CLevel_Loading(Device* device, Context* context)
    : CLevel { device, context }
{
}

HRESULT CLevel_Loading::Initialize()
{

    return S_OK;
}

void CLevel_Loading::Update(_float fTimeDelta)
{
    CLevel::Update(fTimeDelta);

    int a = 10;
}

void CLevel_Loading::LateUpdate(_float fTimeDelta)
{
    CLevel::LateUpdate(fTimeDelta);

    int a = 20;
}

HRESULT CLevel_Loading::Render()
{
    _int exit = CLevel::Render();



    return exit;
}

CLevel_Loading* CLevel_Loading::Create(Device* device, Context* context)
{
    CLevel_Loading* pInstance = new CLevel_Loading(device, context);

    if (FAILED(pInstance->Initialize()))
    {
        MSG_BOX("Failed to Created : CLevel_Loading");
        Safe_Release(pInstance);
    }

    return pInstance;
}

void CLevel_Loading::Free()
{
    CLevel::Free();
}
