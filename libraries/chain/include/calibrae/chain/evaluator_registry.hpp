#pragma once

#include <boost/array.hpp>
#include <calibrae/chain/evaluator.hpp>

namespace calibrae { namespace chain {

template< typename OperationType >
class evaluator_registry
{
   public:
      evaluator_registry( database& d )
         : _db(d) { }

      template< typename EvaluatorType, typename... Args >
      void register_evaluator( Args... args )
      {
         _op_evaluators[ OperationType::template tag< typename EvaluatorType::operation_type >::value ].reset( new EvaluatorType(_db, args...) );
      }

      evaluator<OperationType>& get_evaluator( const OperationType& op )
      {
         int i_which = op.which();
         uint64_t u_which = uint64_t( i_which );
         if( i_which < 0 )
            assert( "Negative operation tag" && false );
         if( u_which >= _op_evaluators.size() )
            assert( "No registered evaluator for this operation" && false );
         unique_ptr< evaluator<OperationType> >& eval = _op_evaluators[ u_which ];
         if( !eval )
            assert( "No registered evaluator for this operation" && false );
         return *eval;
      }

      boost::array< std::unique_ptr< evaluator<OperationType> >, OperationType::count() > _op_evaluators;
      database& _db;
};

} }
