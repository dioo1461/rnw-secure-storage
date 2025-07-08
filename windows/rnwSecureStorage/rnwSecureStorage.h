#pragma once
#include "pch.h"
#include <winrt/Windows.Security.Credentials.h>
#include "resource.h"

#if __has_include("codegen/NativeRnwSecureStorageDataTypes.g.h")
  #include "codegen/NativeRnwSecureStorageDataTypes.g.h"
#endif
#include "codegen/NativeRnwSecureStorageSpec.g.h"
#include "NativeModules.h"

namespace winrt::rnwSecureStorage
{
  REACT_MODULE(RnwSecureStorage)
  struct RnwSecureStorage
  {
    using ModuleSpec = rnwSecureStorageCodegen::RnwSecureStorageSpec;

    REACT_INIT(Initialize)
    void Initialize(React::ReactContext const& reactContext) noexcept;

    REACT_METHOD(get)
    void get(std::string const& key,
             React::ReactPromise<std::optional<std::string>> &&result) noexcept;

    REACT_METHOD(set)
    void set(std::string const& key,
             std::string const& value,
             React::ReactPromise<void> &&result) noexcept;

    // 이름이 예약어이므로 메서드 이름 매핑
    REACT_METHOD(remove, L"delete")
    void remove(std::string const& key,
                React::ReactPromise<void> &&result) noexcept;

  private:
    static constexpr wchar_t kResourceName[] = L"SecureStorage";
    React::ReactContext m_context;
  };
}  // namespace winrt::rnwSecureStorage
