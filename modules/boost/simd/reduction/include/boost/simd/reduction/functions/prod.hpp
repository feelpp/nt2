//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef BOOST_SIMD_REDUCTION_FUNCTIONS_PROD_HPP_INCLUDED
#define BOOST_SIMD_REDUCTION_FUNCTIONS_PROD_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>
#include <boost/simd/operator/functions/multiplies.hpp>
#include <boost/simd/constant/constants/one.hpp>

/*!
 * \ingroup boost_simd_reduction
 * \defgroup boost_simd_reduction_prod prod
 *
 * \par Description
 * Returns the product of the elements of the SIMD vector
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/prod.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::prod_(A0)>::type
 *     prod(const A0 & a0);
 * }
 * \endcode
 *
 * \param a0 the unique parameter of prod
 *
 * \return always a scalar value
 *
 * \par Notes
 * \par
 * This is a reduction operation. As such it has no real interest outside
 * SIMD mode.
 * \par
 * Such an operation always has a scalar result which translate a property
 * of the whole SIMD vector.
 * \par
 * If usable and used in scalar mode, it reduces to the operation as acting
 * on a one element vector.
 *
**/

namespace boost { namespace simd { namespace tag
  {
    /*!
     * \brief Define the tag prod_ of functor prod
     *        in namespace boost::simd::tag for toolbox boost.simd.reduction
    **/
    struct prod_ : ext::reduction_<prod_, tag::multiplies_, tag::One>
    {
      typedef ext::reduction_<prod_, tag::multiplies_, tag::One> parent;
    };
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::prod_, prod, 1)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::prod_, prod, 2)
} }

#endif

// modified by jt the 25/12/2010
