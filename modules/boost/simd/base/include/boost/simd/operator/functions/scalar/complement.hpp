//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_OPERATOR_FUNCTIONS_SCALAR_COMPLEMENT_HPP_INCLUDED
#define BOOST_SIMD_OPERATOR_FUNCTIONS_SCALAR_COMPLEMENT_HPP_INCLUDED

#include <boost/simd/operator/functions/complement.hpp>
#include <boost/simd/include/functions/scalar/bitwise_cast.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/attributes.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT ( complement_, tag::cpu_
                                    , (A0)
                                    , (scalar_< fundamental_<A0> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE BOOST_SIMD_FUNCTOR_CALL(1) { return ~a0; }
  };

  BOOST_DISPATCH_IMPLEMENT ( complement_, tag::cpu_
                                    , (A0)
                                    , (scalar_< floating_<A0> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE BOOST_SIMD_FUNCTOR_CALL(1)
    {
      typedef typename dispatch::meta::as_integer<A0, unsigned>::type b_t;
      return bitwise_cast<A0>(~bitwise_cast<b_t>(a0));
    }
  };
} } }

#endif
