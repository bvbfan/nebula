#pragma once

#include <calibrae/account_statistics/account_statistics_plugin.hpp>

#include <fc/api.hpp>

namespace calibrae{ namespace app {
   struct api_context;
} }

namespace calibrae { namespace account_statistics {

namespace detail
{
   class account_statistics_api_impl;
}

class account_statistics_api
{
   public:
      account_statistics_api( const calibrae::app::api_context& ctx );

      void on_api_startup();

   private:
      std::shared_ptr< detail::account_statistics_api_impl > _my;
};

} } // calibrae::account_statistics

FC_API( calibrae::account_statistics::account_statistics_api, )