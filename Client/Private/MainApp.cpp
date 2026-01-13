#include "MainApp.h"

#include "GameInstance.h"

CMainApp::CMainApp()
    : m_pGameInstance { CGameInstance::GetInstance()}
{
    Safe_AddRef(m_pGameInstance);
}

HRESULT CMainApp::Initialize()
{
    /* 내 게임을 구동하기 위한 기초 초기화 작업을 수행한다. */

    /* 엔진을 이용하기 위해 엔진 프로젝트를 준비시킨다. */
    ENGINE_DESC EngineDesc{};
    EngineDesc.hWnd = g_hWnd;
    EngineDesc.iViewportWidth = g_iWinSizeX;
    EngineDesc.iViewportHeight = g_iWinSizeY;
    EngineDesc.eWinMode = WINMODE::WIN;

    if (FAILED(m_pGameInstance->Initialize_Engine(EngineDesc, &m_pDevice, &m_pContext)))
        return E_FAIL;

    /* 내 게임의 시작을 위해 시작되는 레벨 할당과 동작을 시킨다. */
    

    return S_OK;
}

void CMainApp::Update(float fTimeDelta)
{
}

HRESULT CMainApp::Render()
{
    _float4 vClearColor = { 0.f, 0.f, 1.f, 1.f };
    if (FAILED(m_pGameInstance->Clear_Buffers(&vClearColor)))
        return E_FAIL;

    if (FAILED(m_pGameInstance->Present()))
        return E_FAIL;

    return S_OK;
}

CMainApp* CMainApp::Create()
{
    CMainApp* pInstance = new CMainApp();

    if (FAILED(pInstance->Initialize()))
    {
        MSG_BOX("Create Faield : MainApp");
        Safe_Release(pInstance);
    }

    return pInstance;
}

void CMainApp::Free()
{
	__super::Free();

    Safe_Release(m_pGameInstance);
}
