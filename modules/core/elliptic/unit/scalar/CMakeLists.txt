##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

SET( SOURCES
  am.cpp
  ellpk.cpp
  ellpe.cpp
  ellint_2.cpp
  ellint_1.cpp
  ellik.cpp
  ellie.cpp
  ellipj.cpp
  ellipke.cpp
# List of scalar test files for toolbox elliptic
   )

nt2_module_add_tests(core.elliptic.scalar.unit ${SOURCES})
