#pragma once

#include <calibrae/chain/util/asset.hpp>
#include <calibrae/chain/nebula_objects.hpp>

#include <calibrae/protocol/asset.hpp>
#include <calibrae/protocol/config.hpp>
#include <calibrae/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace calibrae { namespace chain { namespace util {

using calibrae::protocol::asset;
using calibrae::protocol::price;
using calibrae::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_sbd;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_steem;
   price      current_nebula_price;
   curve_id   reward_curve = quadratic;
   uint128_t  content_constant = CALIBRAE_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return CALIBRAE_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const curve_id& curve = quadratic, const uint128_t& content_constant = CALIBRAE_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( const price& p, uint64_t nebula_payout )
{
   return to_sbd( p, asset( nebula_payout, NECTAR_SYMBOL ) ) < CALIBRAE_MIN_PAYOUT_SBD;
}

} } } // calibrae::chain::util

FC_REFLECT( calibrae::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_sbd)
   (total_reward_shares2)
   (total_reward_fund_steem)
   (current_nebula_price)
   (reward_curve)
   (content_constant)
   )
