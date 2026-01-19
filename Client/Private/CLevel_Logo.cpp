#include "CLevel_Logo.h"

CLevel_Logo::CLevel_Logo(Device* device, Context* context)
    : CLevel { device, context }
{
}

HRESULT CLevel_Logo::Initialize()
{

    return S_OK;
}

void CLevel_Logo::Update(_float fTimeDelta)
{
    CLevel::Update(fTimeDelta);

    int a = 10;
}

void CLevel_Logo::LateUpdate(_float fTimeDelta)
{
    CLevel::LateUpdate(fTimeDelta);

    int a = 20;
}

HRESULT CLevel_Logo::Render()
{
    _int exit = CLevel::Render();



    return exit;
}

CLevel_Logo* CLevel_Logo::Create(Device* device, Context* context)
{
    CLevel_Logo* pInstance = new CLevel_Logo(device, context);

    if (FAILED(pInstance->Initialize()))
    {
        MSG_BOX("Failed to Created : CLevel_Logo");
        Safe_Release(pInstance);
    }

    return pInstance;
}

void CLevel_Logo::Free()
{
    CLevel::Free();
}
