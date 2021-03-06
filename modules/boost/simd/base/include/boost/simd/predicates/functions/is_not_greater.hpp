//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_IS_NOT_GREATER_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_IS_NOT_GREATER_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>


namespace boost { namespace simd { namespace tag
  {
   /*!
     @brief is_not_greater generic tag

     Represents the is_not_greater function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct is_not_greater_ : ext::elementwise_<is_not_greater_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<is_not_greater_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_is_not_greater_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };}
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::is_not_greater_, Site> dispatching_is_not_greater_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::is_not_greater_, Site>();
   }
   template<class... Args>
   struct impl_is_not_greater_;
  }
  /*!
    Returns True if a0 is not greater than a1 else returns False.

    @par Semantic:

    @code
    logical<T> r = is_not_greater(a0,a1);
    @endcode

    is similar to:

    @code
    logical<T> r = ;
    @endcode

    @par Note:

    Due to existence of nan, this is not equivalent to @c is_less_equal(a0, a1)
    for floating types

    @par Alias:

    @c is_ngt

    @param a0

    @param a1

    @return a logical value
  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_not_greater_, is_not_greater, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::is_not_greater_, is_ngt, 2)
} }

#endif
