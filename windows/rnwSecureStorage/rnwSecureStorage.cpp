#include "pch.h"
#include "RnwSecureStorage.h"

using namespace winrt;
using namespace Windows::Security::Credentials;
using winrt::to_string;
using winrt::to_hstring;

namespace winrt::rnwSecureStorage
{
	void RnwSecureStorage::Initialize(React::ReactContext const& reactContext) noexcept
  {
    m_context = reactContext;
  }

  void RnwSecureStorage::get(std::string const& key,
                             React::ReactPromise<std::optional<std::string>> &&result) noexcept
  {
    try
    {
      PasswordVault vault;
      auto cred = vault.Retrieve(kResourceName, to_hstring(key));
      cred.RetrievePassword();
      result.Resolve(to_string(cred.Password()));
    }
    catch (...)
    {
      // 항목이 없으면 null 반환
      result.Resolve(std::nullopt);
    }
  }

  void RnwSecureStorage::set(std::string const& key,
                             std::string const& value,
                             React::ReactPromise<void> &&result) noexcept
  {
    try
    {
      PasswordVault vault;
      // 동일 키가 있으면 먼저 삭제
      try { vault.Remove(vault.Retrieve(kResourceName, to_hstring(key))); } catch (...) {}
      vault.Add(PasswordCredential{kResourceName, to_hstring(key), to_hstring(value)});
      result.Resolve();
    }
    catch (hresult_error const& e)
    {
      result.Reject(e.code(), to_string(e.message()));
    }
  }

  void RnwSecureStorage::remove(std::string const& key,
                                React::ReactPromise<void> &&result) noexcept
  {
    try
    {
      PasswordVault vault;
      vault.Remove(vault.Retrieve(kResourceName, to_hstring(key)));
      result.Resolve();
    }
    catch (hresult_error const& e)
    {
      result.Reject(e.code(), to_string(e.message()));
    }
  }

  void RnwSecureStorage::getAll(React::ReactPromise<React::JSValueObject> &&result) noexcept
  {
    try
    {
      PasswordVault vault;
      React::JSValueObject map;

      for (auto const& cred : vault.FindAllByResource(kResourceName))
      {
        auto c = cred;
        c.RetrievePassword();
        map[ to_string(c.UserName()) ] = React::JSValue( to_string(c.Password()) );
      }
      result.Resolve(std::move(map));
    }
    catch (hresult_error const& e)
    {
      result.Reject(e.code(), to_string(e.message()));
    }
  }
}  // namespace winrt::rnwSecureStorage
