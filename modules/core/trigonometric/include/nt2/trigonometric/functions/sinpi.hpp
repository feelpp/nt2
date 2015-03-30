//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_SINPI_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_SINPI_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief sinpi generic tag

     Represents the sinpi function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct sinpi_ : ext::elementwise_<sinpi_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<sinpi_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_sinpi_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site>
   BOOST_FORCEINLINE generic_dispatcher<tag::sinpi_, Site> dispatching_sinpi_(adl_helper, boost::dispatch::meta::unknown_<Site>, ...)
   {
     return generic_dispatcher<tag::sinpi_, Site>();
   }
   template<class... Args>
   struct impl_sinpi_;
  }
  /*!
    sine of angle in \f$\pi\f$ multiples.

    @par Semantic:

    For every parameter of floating type T0

    @code
    T0 r = sinpi(x);
    @endcode

    is similar to:

    @code
    T0 r = sin(Pi<T0>()*x);
    @endcode

    @see @funcref{sine}, @funcref{fast_sin}, @funcref{sincospi}, @funcref{sin}, @funcref{sind}
    @param a0

    @return a value of the same type as the parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::sinpi_, sinpi, 1)
}

#endif



