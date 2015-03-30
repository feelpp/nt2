//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_IEEE_FUNCTIONS_NEXTAFTER_HPP_INCLUDED
#define BOOST_SIMD_IEEE_FUNCTIONS_NEXTAFTER_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>


namespace boost { namespace simd { namespace tag
  {
   /*!
     @brief nextafter generic tag

     Represents the nextafter function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct nextafter_ : ext::elementwise_<nextafter_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<nextafter_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_nextafter_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::nextafter_, Site> dispatching_nextafter_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::nextafter_, Site>();
   }
   template<class... Args>
   struct impl_nextafter_;
  }
  /*!
    Returns the next element in the a1 direction.
    \par
    rg if a1 is greater than a0 this is next(a0)
    rg if a1 is equal to a0 this is a0
    rg if a1 is less than a0 this is prev(a0)

    @par Semantic:

    @code
    T r = nextafter(x, y);
    @endcode

    is similar to:

    @code
    if (y >  x)  r = next(a0);
    else if (y == x)  r = a0;
    else if (y <  x)  r = prev(a0);
    @endcode

    @param a0

    @param a1

    @return a value of same type as the inputs
  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::nextafter_, nextafter, 2)
} }

#endif
