//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2011 - 2012   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_PREDICATES_FUNCTIONS_SCALAR_ISSYMETRIC_HPP_INCLUDED
#define NT2_PREDICATES_FUNCTIONS_SCALAR_ISSYMETRIC_HPP_INCLUDED

#include <nt2/predicates/functions/issymetric.hpp>

namespace nt2 { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT  ( issymetric_, tag::cpu_
                            , (A0), (scalar_< unspecified_<A0> >)
                            )
  {
    typedef bool result_type;

    BOOST_FORCEINLINE result_type operator()(const A0&) const
    {
      return true;
    }
  };
} }

#endif
