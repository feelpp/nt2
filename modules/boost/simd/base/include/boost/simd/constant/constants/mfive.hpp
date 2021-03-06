//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_CONSTANT_CONSTANTS_MFIVE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_CONSTANTS_MFIVE_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>
#include <boost/simd/constant/register.hpp>
#include <boost/simd/constant/hierarchy.hpp>


namespace boost { namespace simd
{
  namespace tag
  {
   /*!
     @brief Mfive generic tag

     Represents the Mfive constant in generic contexts.

     @par Models:
        Hierarchy
   **/
    BOOST_SIMD_CONSTANT_REGISTER( Mfive, double, -5
                                , 0xc0a00000UL,0xc014000000000000ULL
                                )
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::Mfive, Site> dispatching_Mfive(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::Mfive, Site>();
   }
   template<class... Args>
   struct impl_Mfive;
  }
  /*!
    Generates value -5

    @par Semantic:

    @code
    T r = Mfive<T>();
    @endcode

    is similar to:

    @code
    T r = T(-5);
    @endcode
  **/
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Mfive, Mfive)
} }
#include <boost/simd/constant/common.hpp>

#endif

