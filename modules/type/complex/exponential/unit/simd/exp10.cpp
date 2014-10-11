//==============================================================================
//         Copyright 2003 - 2013   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/include/functions/exp10.hpp>

#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <boost/simd/sdk/simd/io.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <complex>
#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/dry.hpp>
#include <nt2/sdk/unit/tests/ulp.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/sdk/config.hpp>

#include <nt2/include/constants/mone.hpp>
#include <nt2/include/constants/mzero.hpp>
#include <nt2/include/constants/one.hpp>
#include <nt2/include/constants/ten.hpp>
#include <nt2/include/constants/two.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/include/constants/inf.hpp>
#include <nt2/include/constants/minf.hpp>
#include <nt2/include/constants/nan.hpp>
#include <nt2/include/constants/cnan.hpp>
#include <nt2/include/constants/i.hpp>
#include <nt2/include/constants/hundred.hpp>
#include <nt2/include/functions/multiplies.hpp>

NT2_TEST_CASE_TPL ( exp10_real,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using nt2::exp10;
  using nt2::tag::exp10_;
  typedef typename std::complex<T> cT;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef native<cT,ext_t>                vcT;

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf<vT>(), nt2::Zero<vT>())),vcT(nt2::Inf<vcT>()),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Minf<vT>(), nt2::Zero<vT>())),vcT(nt2::Zero<vcT>()),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Nan<vT>(), nt2::Zero<vT>())),vcT(nt2::Nan<vcT>()),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf  <vT>(), nt2::Zero<vT>())),nt2::Inf<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Nan  <vT>(), nt2::Zero<vT>())),nt2::Nan <vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::One  <vT>(), nt2::Inf <vT>())),nt2::Cnan<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::One  <vT>(), nt2::Nan <vT>())),nt2::Cnan<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Minf <vT>(), nt2::One <vT>())),nt2::Zero<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Minf <vT>(), nt2::Mone<vT>())),nt2::Zero<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf  <vT>(), nt2::One <vT>())),nt2::Inf <vT>()*nt2::exp10(vcT(nt2::Zero<vT>(), nt2::One <vT>())), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf  <vT>(), nt2::Mone<vT>())),nt2::Inf <vT>()*nt2::exp10(vcT(nt2::Zero<vT>(), nt2::Mone<vT>())), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Minf <vT>(), nt2::Inf<vT>())), nt2::Zero<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf  <vT>(), nt2::Inf<vT>())), nt2::Cnan <vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Minf <vT>(), nt2::Nan<vT>())), nt2::Zero<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf  <vT>(), nt2::Nan<vT>())), nt2::Cnan<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Nan  <vT>(), nt2::One<vT>())), nt2::Cnan<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Nan  <vT>(), nt2::Nan<vT>())), nt2::Cnan<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::One  <vT>(), -nt2::Inf <vT>())),nt2::Cnan<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::One  <vT>(), -nt2::Nan <vT>())),nt2::Cnan<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Minf <vT>(), -nt2::One <vT>())),nt2::Zero<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Minf <vT>(), -nt2::Mone<vT>())),nt2::Zero<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf  <vT>(), -nt2::One <vT>())),nt2::Inf <vT>()*nt2::exp10(vcT(nt2::Zero<vT>(), -nt2::One <vT>())), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf  <vT>(), -nt2::Mone<vT>())),nt2::Inf <vT>()*nt2::exp10(vcT(nt2::Zero<vT>(), -nt2::Mone<vT>())), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Minf <vT>(), -nt2::Inf<vT>())), nt2::Zero<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf  <vT>(), -nt2::Inf<vT>())), nt2::Cnan <vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Minf <vT>(), -nt2::Nan<vT>())), nt2::Zero<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Inf  <vT>(), -nt2::Nan<vT>())), nt2::Cnan <vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Nan  <vT>(), -nt2::One<vT>())), nt2::Cnan <vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(vcT(nt2::Nan  <vT>(), -nt2::Nan<vT>())), nt2::Cnan <vcT>(), 0.75);
#endif
  NT2_TEST_ULP_EQUAL(nt2::exp10(nt2::One<vcT>()  ),  nt2::Ten<vcT>(),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(nt2::Zero<vcT>() ),  nt2::One<vcT>(),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(nt2::Two<vcT>()  ),  nt2::Hundred<vcT>(),0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(nt2::Zero<vcT>() ),  nt2::One<vcT>(), 0.75);
  NT2_TEST_ULP_EQUAL(nt2::exp10(nt2::Mzero<vcT>()),  nt2::One<vcT>(), 0.75);
}
