#pragma once

struct ID3D11Device;
struct ID3D11DeviceContext;
struct IDXGISwapChain4;
struct ID3D11RenderTargetView1;
struct ID3D11ShaderResourceView1;

namespace RE
{
	class BSRenderManager
	{
	public:
		static BSRenderManager* GetSingleton()
		{
			static REL::Relocation<BSRenderManager*> singleton{ REL::ID(411393) };
			return singleton.get();
		}

		// members
		std::uint64_t              unk0000[0x48 >> 3];             // 0000
		ID3D11Device*              forwarder;                      // 0048 - Actually CID3D11Forwarder
		ID3D11DeviceContext*       context;                        // 0050 - ID3D11DeviceContext4
		std::uint64_t              unk0058;                        // 0058
		std::uint64_t              unk0060;                        // 0060
		std::uint64_t              unk0068;                        // 0068
		IDXGISwapChain4*           swapChain;                      // 0070
		std::uint64_t              unk0078;                        // 0078
		std::uint64_t              unk0080;                        // 0080
		ID3D11RenderTargetView1*   renderView;                     // 0088
		ID3D11ShaderResourceView1* resourceView;                   // 0090
		std::uint64_t              unk0098[(0x2790 - 0x98) >> 3];  // 0098
		WinAPI::CRITICAL_SECTION   lock;                           // 2790
	};
	static_assert(sizeof(BSRenderManager) == 0x27B8);
}