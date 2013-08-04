//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SWAR_FUNCTIONS_SCALAR_SORT_HPP_INCLUDED
#define BOOST_SIMD_SWAR_FUNCTIONS_SCALAR_SORT_HPP_INCLUDED



/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( sort_, tag::cpu_
                            , (A0)
                            , (scalar_< arithmetic_<A0> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return a0;
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( sort_, tag::cpu_
                                     , (A0)(A1)
                                     , (scalar_< arithmetic_<A0> >)
                                     (scalar_< integer_<A1> >)
    )
  {
    typedef A0 result_type;
    result_type operator()(A0 const& a0, A1 const&) const
    {
      return a0;
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( sort_, tag::cpu_
                                     , (A0)(A1)(A2)
                                     , (scalar_< arithmetic_<A0> >)
                                     (scalar_< integer_<A1> >)
                                     (scalar_< int8_<A2> >)
    )
  {
    typedef A0 result_type;
    result_type operator()(A0 const& a0, A1 const&, A2 const&) const
    {
      return a0;
    }
  };
} } }


#endif
