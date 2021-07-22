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

#ifndef WINRT_Windows_ApplicationModel_Calls_Provider_1_H
#define WINRT_Windows_ApplicationModel_Calls_Provider_1_H
#include "winrt/impl/Windows.ApplicationModel.Calls.Provider.0.h"
WINRT_EXPORT namespace winrt::Windows::ApplicationModel::Calls::Provider
{
    struct __declspec(empty_bases) IPhoneCallOrigin :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOrigin>
    {
        IPhoneCallOrigin(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOrigin(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPhoneCallOrigin(IPhoneCallOrigin const&) noexcept = default;
        IPhoneCallOrigin(IPhoneCallOrigin&&) noexcept = default;
        IPhoneCallOrigin& operator=(IPhoneCallOrigin const&) & noexcept = default;
        IPhoneCallOrigin& operator=(IPhoneCallOrigin&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPhoneCallOrigin2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOrigin2>,
        impl::require<winrt::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin2, winrt::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin>
    {
        IPhoneCallOrigin2(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOrigin2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPhoneCallOrigin2(IPhoneCallOrigin2 const&) noexcept = default;
        IPhoneCallOrigin2(IPhoneCallOrigin2&&) noexcept = default;
        IPhoneCallOrigin2& operator=(IPhoneCallOrigin2 const&) & noexcept = default;
        IPhoneCallOrigin2& operator=(IPhoneCallOrigin2&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPhoneCallOrigin3 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOrigin3>,
        impl::require<winrt::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin3, winrt::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin, winrt::Windows::ApplicationModel::Calls::Provider::IPhoneCallOrigin2>
    {
        IPhoneCallOrigin3(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOrigin3(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPhoneCallOrigin3(IPhoneCallOrigin3 const&) noexcept = default;
        IPhoneCallOrigin3(IPhoneCallOrigin3&&) noexcept = default;
        IPhoneCallOrigin3& operator=(IPhoneCallOrigin3 const&) & noexcept = default;
        IPhoneCallOrigin3& operator=(IPhoneCallOrigin3&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPhoneCallOriginManagerStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOriginManagerStatics>
    {
        IPhoneCallOriginManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOriginManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPhoneCallOriginManagerStatics(IPhoneCallOriginManagerStatics const&) noexcept = default;
        IPhoneCallOriginManagerStatics(IPhoneCallOriginManagerStatics&&) noexcept = default;
        IPhoneCallOriginManagerStatics& operator=(IPhoneCallOriginManagerStatics const&) & noexcept = default;
        IPhoneCallOriginManagerStatics& operator=(IPhoneCallOriginManagerStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPhoneCallOriginManagerStatics2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOriginManagerStatics2>,
        impl::require<winrt::Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2, winrt::Windows::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics>
    {
        IPhoneCallOriginManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOriginManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPhoneCallOriginManagerStatics2(IPhoneCallOriginManagerStatics2 const&) noexcept = default;
        IPhoneCallOriginManagerStatics2(IPhoneCallOriginManagerStatics2&&) noexcept = default;
        IPhoneCallOriginManagerStatics2& operator=(IPhoneCallOriginManagerStatics2 const&) & noexcept = default;
        IPhoneCallOriginManagerStatics2& operator=(IPhoneCallOriginManagerStatics2&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IPhoneCallOriginManagerStatics3 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOriginManagerStatics3>
    {
        IPhoneCallOriginManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOriginManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IPhoneCallOriginManagerStatics3(IPhoneCallOriginManagerStatics3 const&) noexcept = default;
        IPhoneCallOriginManagerStatics3(IPhoneCallOriginManagerStatics3&&) noexcept = default;
        IPhoneCallOriginManagerStatics3& operator=(IPhoneCallOriginManagerStatics3 const&) & noexcept = default;
        IPhoneCallOriginManagerStatics3& operator=(IPhoneCallOriginManagerStatics3&&) & noexcept = default;
    };
}
#endif