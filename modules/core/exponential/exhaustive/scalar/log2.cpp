//==============================================================================
//         Copyright 2009 - 2013 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2013        MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/sdk/unit/exhaustive.hpp>
#include <nt2/include/functions/log2.hpp>

#include <nt2/include/constants/zero.hpp>
#include <nt2/include/constants/valmax.hpp>

struct raw_log2
{
  float operator()(float x) const
  {
    return float(nt2::log2(double(x)));
  }
};

int main(int ac, char* av[])
{
  float mini = 0.0f;
  float maxi = nt2::Valmax<float>();
  if(ac == 3)
  {
    mini = std::atof(av[1]);
    maxi = std::atof(av[2]);
  }
  nt2::exhaustive_test<float> ( mini
                              , maxi
                              , nt2::functor<nt2::tag::log2_>()
                              , raw_log2()
                              );

  return 0;
}