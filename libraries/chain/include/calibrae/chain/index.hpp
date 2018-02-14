#pragma once

#include <calibrae/chain/database.hpp>

namespace calibrae { namespace chain {

template< typename MultiIndexType >
void add_plugin_index( database& db )
{
    db._plugin_index_signal.connect( [&db](){ db.add_index< MultiIndexType >(); } );
}

}

}
