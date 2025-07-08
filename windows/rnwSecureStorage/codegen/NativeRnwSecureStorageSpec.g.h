
/*
 * This file is auto-generated from a NativeModule spec file in js.
 *
 * This is a C++ Spec class that should be used with MakeTurboModuleProvider to register native modules
 * in a way that also verifies at compile time that the native module matches the interface required
 * by the TurboModule JS spec.
 */
#pragma once
// clang-format off


#include <NativeModules.h>
#include <tuple>

namespace rnwSecureStorageCodegen {

struct RnwSecureStorageSpec : winrt::Microsoft::ReactNative::TurboModuleSpec {
  static constexpr auto methods = std::tuple{
      Method<void(std::string, Promise<std::optional<std::string>>) noexcept>{0, L"get"},
      Method<void(std::string, std::string, Promise<void>) noexcept>{1, L"set"},
      Method<void(std::string, Promise<void>) noexcept>{2, L"delete"},
  };

  template <class TModule>
  static constexpr void ValidateModule() noexcept {
    constexpr auto methodCheckResults = CheckMethods<TModule, RnwSecureStorageSpec>();

    REACT_SHOW_METHOD_SPEC_ERRORS(
          0,
          "get",
          "    REACT_METHOD(get) void get(std::string key, ::React::ReactPromise<std::optional<std::string>> &&result) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(get) static void get(std::string key, ::React::ReactPromise<std::optional<std::string>> &&result) noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          1,
          "set",
          "    REACT_METHOD(set) void set(std::string key, std::string value, ::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(set) static void set(std::string key, std::string value, ::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          2,
          "delete",
          "    REACT_METHOD(delete) void delete(std::string key, ::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(delete) static void delete(std::string key, ::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n");
  }
};

} // namespace rnwSecureStorageCodegen
