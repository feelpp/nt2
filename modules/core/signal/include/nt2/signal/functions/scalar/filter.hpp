//==============================================================================
//         Copyright 2014          LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2014          NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_SCALAR_FILTER_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_SCALAR_FILTER_HPP_INCLUDED

#ifdef BOOST_SIMD_NO_SIMD

#include <nt2/signal/functions/filter.hpp>

#include <nt2/core/container/table/table.hpp>
#include <nt2/include/functions/zeros.hpp>
#include <nt2/include/functions/tie.hpp>
#include <nt2/core/container/dsl/as_terminal.hpp>
#include <nt2/include/functions/run.hpp>
#include <boost/dispatch/meta/as.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION ( nt2::tag::filter_, tag::cpu_
                             , (A0)(N0)(A1)(N1)
                             , ((node_<A0, nt2::tag::filter_
                                     , N0, nt2::container::domain
                                       >
                               ))
                               ((node_<A1, nt2::tag::tie_
                                     , N1, nt2::container::domain
                                      >
                               ))
                             )
  {
    typedef void  result_type;

    typedef typename boost::proto::result_of::child_c<A0&,0>::value_type child0_t;

    typedef typename boost::proto::result_of::child_c<A0&,1>::value_type::value_type child1_t;

    typedef typename boost::proto::result_of::child_c<A0&, 2>::value_type child2_t;

    typedef typename meta::scalar_of<child2_t>::type f_type;
    typedef typename boost::dispatch::meta::as_floating<f_type>::type real_type;

    typedef typename meta::option<child0_t, nt2::tag::of_size_>::type filt_of_size_;
    typedef typename meta::option<child2_t, nt2::tag::of_size_>::type data_of_size_;

    typedef nt2::memory::container<tag::table_, real_type, filt_of_size_> filt_semantic;
    typedef nt2::memory::container<tag::table_, real_type, data_of_size_> data_semantic;

    BOOST_FORCEINLINE result_type operator()( A0 const& a0, A1 const& a1 ) const
    {
      NT2_AS_TERMINAL_IN(filt_semantic,filt,boost::proto::child_c<0>(a0));
      NT2_AS_TERMINAL_IN(data_semantic,data,boost::proto::child_c<2>(a0));

      NT2_AS_TERMINAL_OUT(data_semantic,result,boost::proto::child_c<0>(a1));

      result = nt2::zeros(data.extent(),nt2::meta::as_<f_type>());

      for (std::size_t ii=0;ii<filt.size()-1;ii++)
      {
        real_type res(0);
        for (std::size_t jj=0;jj<ii+1;jj++)
        {
          real_type dd = nt2::run(data,jj,meta::as_<real_type>());
          real_type ff = nt2::run(filt,jj,meta::as_<real_type>());
          res += dd*ff;
        }
        nt2::run(result,ii,res);
      }

      for (std::size_t ii=filt.size()-1;ii<data.size();ii++)
      {
        real_type res(0);
        for (std::size_t jj=0;jj<filt.size();jj++)
        {
          real_type dd = nt2::run(data,ii-filt.size()+jj+1,meta::as_<real_type>());
          real_type ff = nt2::run(filt,jj,meta::as_<real_type>());
          res += dd*ff;
        }
        nt2::run(result,ii,res);
      }
    }
  };
} }

#endif
#endif
