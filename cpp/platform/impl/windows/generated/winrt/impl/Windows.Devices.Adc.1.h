// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Devices_Adc_1_H
#define WINRT_Windows_Devices_Adc_1_H
#include "winrt/impl/Windows.Foundation.0.h"
#include "winrt/impl/Windows.Devices.Adc.0.h"
WINRT_EXPORT namespace winrt::Windows::Devices::Adc
{
    struct __declspec(empty_bases) IAdcChannel :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAdcChannel>,
        impl::require<winrt::Windows::Devices::Adc::IAdcChannel, winrt::Windows::Foundation::IClosable>
    {
        IAdcChannel(std::nullptr_t = nullptr) noexcept {}
        IAdcChannel(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IAdcChannel(IAdcChannel const&) noexcept = default;
        IAdcChannel(IAdcChannel&&) noexcept = default;
        IAdcChannel& operator=(IAdcChannel const&) & noexcept = default;
        IAdcChannel& operator=(IAdcChannel&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IAdcController :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAdcController>
    {
        IAdcController(std::nullptr_t = nullptr) noexcept {}
        IAdcController(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IAdcController(IAdcController const&) noexcept = default;
        IAdcController(IAdcController&&) noexcept = default;
        IAdcController& operator=(IAdcController const&) & noexcept = default;
        IAdcController& operator=(IAdcController&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IAdcControllerStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAdcControllerStatics>
    {
        IAdcControllerStatics(std::nullptr_t = nullptr) noexcept {}
        IAdcControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IAdcControllerStatics(IAdcControllerStatics const&) noexcept = default;
        IAdcControllerStatics(IAdcControllerStatics&&) noexcept = default;
        IAdcControllerStatics& operator=(IAdcControllerStatics const&) & noexcept = default;
        IAdcControllerStatics& operator=(IAdcControllerStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IAdcControllerStatics2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAdcControllerStatics2>
    {
        IAdcControllerStatics2(std::nullptr_t = nullptr) noexcept {}
        IAdcControllerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IAdcControllerStatics2(IAdcControllerStatics2 const&) noexcept = default;
        IAdcControllerStatics2(IAdcControllerStatics2&&) noexcept = default;
        IAdcControllerStatics2& operator=(IAdcControllerStatics2 const&) & noexcept = default;
        IAdcControllerStatics2& operator=(IAdcControllerStatics2&&) & noexcept = default;
    };
}
#endif