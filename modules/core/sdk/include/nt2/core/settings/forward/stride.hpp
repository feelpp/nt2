//==============================================================================
//         Copyright 2009 - 2014   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2014   NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_SETTINGS_FORWARD_STRIDE_HPP_INCLUDED
#define NT2_CORE_SETTINGS_FORWARD_STRIDE_HPP_INCLUDED

#include <boost/mpl/bool.hpp>

namespace nt2
{
  struct strided_
  {
    typedef boost::mpl::true_  stride_type;
  };

  struct uniform_
  {
    typedef boost::mpl::false_  stride_type;
  };

  namespace tag
  {
    struct stride_;
  }
}

#endif
