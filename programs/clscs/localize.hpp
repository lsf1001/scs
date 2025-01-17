#pragma once

#include <libintl.h>
#include <fc/variant.hpp>

namespace lcscs { namespace client { namespace localize {
   #if !defined(_)
   #define _(str) str
   #endif

   #define localized(str, ...) localized_with_variant((str), fc::mutable_variant_object() __VA_ARGS__ )

   inline auto localized_with_variant( const char* raw_fmt, const fc::variant_object& args) {
      if (raw_fmt != nullptr) {
         try {
            return fc::format_string(::gettext(raw_fmt), args);
         } catch (...) {
         }
         return std::string(raw_fmt);
      }
      return std::string();
   }
}}}
