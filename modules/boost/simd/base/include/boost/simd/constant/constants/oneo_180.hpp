//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_CONSTANT_CONSTANTS_ONEO_180_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_CONSTANTS_ONEO_180_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>
#include <boost/simd/constant/register.hpp>
#include <boost/simd/constant/hierarchy.hpp>


namespace boost { namespace simd
{
  namespace tag
  {
   /*!
     @brief Oneo_180 generic tag

     Represents the Oneo_180 constant in generic contexts.

     @par Models:
        Hierarchy
   **/
    BOOST_SIMD_CONSTANT_REGISTER( Oneo_180, double, 0
                                 , 0x3bb60b61, 0x3f76c16c16c16c17ll
                                )
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::Oneo_180, Site> dispatching_Oneo_180(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::Oneo_180, Site>();
   }
   template<class... Args>
   struct impl_Oneo_180;
  }
  /*!
    Generates value 1/180

    @par Semantic:

    @code
    T r = Oneo_180<T>();
    @endcode

    is similar to:

    @code
    T r = T(1)/T(180);
    @endcode
  **/
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Oneo_180, Oneo_180)
} }

#include <boost/simd/constant/common.hpp>

#endif

