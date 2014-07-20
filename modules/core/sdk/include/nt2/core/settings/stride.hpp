//==============================================================================
//         Copyright 2009 - 2014   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2014   NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_STRIDE_HPP_INCLUDED
#define NT2_CORE_SETTINGS_STRIDE_HPP_INCLUDED

#include <nt2/core/settings/forward/stride.hpp>

namespace nt2 { namespace tag
{
  struct stride_
  {
    template<class T>
    struct apply : boost::mpl::false_
    {};

    typedef nt2::uniform_ default_type;
  };

  template<>
  struct stride_::apply<nt2::uniform_> : boost::mpl::true_
  {};

  template<>
  struct stride_::apply<nt2::strided_> : boost::mpl::true_
  {};
} }

#endif
