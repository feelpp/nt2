//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_COMBINATORIAL_FUNCTION_SCALAR_LCM_HPP_INCLUDED
#define NT2_TOOLBOX_COMBINATORIAL_FUNCTION_SCALAR_LCM_HPP_INCLUDED

#include <nt2/include/functions/rdivide.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/gcd.hpp>
#include <nt2/include/functions/trunc.hpp>

namespace nt2 { namespace functors
{

  //  no special validate for lcm

  /////////////////////////////////////////////////////////////////////////////
  // Compute lcm(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<lcm_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> : 
      boost::result_of<meta::arithmetic(A0,A1)>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      A0,
      (2, (real_,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(2,       real_)
    {
      return nt2::abs(trunc(a0)*rdiv(a1,gcd(a0,a1)));
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2, arithmetic_)
    {
     return nt2::abs(a0*rdivide(a1,gcd(a0,a1)));
    }
  };
} }


      
#endif
