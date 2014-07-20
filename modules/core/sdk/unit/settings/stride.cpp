//==============================================================================
//         Copyright 2009 - 2014   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2014   NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/core/settings/option.hpp>
#include <nt2/core/settings/settings.hpp>
#include <nt2/core/settings/stride.hpp>
#include "local_semantic.hpp"

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/basic.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

NT2_TEST_CASE( stride_concept )
{
  using nt2::meta::option;
  using nt2::meta::match_option;

  {
    typedef option<nt2::strided_, nt2::tag::stride_, some_kind_> opt;
    typedef opt::type::stride_type stride_option;

    NT2_TEST( (match_option< nt2::strided_, nt2::tag::stride_ >::value) );
    NT2_TEST_EQUAL( stride_option::value, true );
  }

  {
    typedef option<nt2::uniform_, nt2::tag::stride_, some_kind_> opt;
    typedef opt::type::stride_type stride_option;

    NT2_TEST( (match_option< nt2::uniform_, nt2::tag::stride_ >::value) );
    NT2_TEST_EQUAL( stride_option::value, false );
  }
}

NT2_TEST_CASE( single_stride_ )
{
  using nt2::strided_;
  using nt2::uniform_;
  using nt2::meta::option;
  using boost::mpl::_;

  NT2_TEST_EXPR_TYPE( (strided_())
                      ,(option< _, nt2::tag::stride_, some_kind_>)
                      ,(strided_)
                      );

  NT2_TEST_EXPR_TYPE( (uniform_())
                      ,(option< _, nt2::tag::stride_, some_kind_>)
                      ,(uniform_)
                      );
}

NT2_TEST_CASE( stride_default )
{
  using nt2::uniform_;
  using nt2::settings;
  using nt2::meta::option;

  NT2_TEST_TYPE_IS( (option < settings()
                            , nt2::tag::stride_
                            , some_kind_
                            >::type
                    )
                  , uniform_
                  );

  NT2_TEST_TYPE_IS( (option < settings(int,void*)
                            , nt2::tag::stride_
                            , some_kind_
                            >::type
                    )
                  , uniform_
                  );
}

NT2_TEST_CASE( single_settings_stride_ )
{
  using nt2::strided_;
  using nt2::uniform_;
  using nt2::settings;
  using nt2::meta::option;
  using boost::mpl::_;

  NT2_TEST_TYPE_IS( (option < settings(strided_)
                            , nt2::tag::stride_
                            , some_kind_
                            >::type
                    )
                  , (strided_)
                  );

  NT2_TEST_TYPE_IS( (option < settings(uniform_)
                            , nt2::tag::stride_
                            , some_kind_
                            >::type
                    )
                  , (uniform_)
                  );
}

NT2_TEST_CASE( multi_settings_stride_ )
{
  using nt2::strided_;
  using nt2::uniform_;
  using nt2::settings;
  using nt2::meta::option;
  using boost::mpl::_;

  NT2_TEST_TYPE_IS( (option < settings(strided_,uniform_)
                            , nt2::tag::stride_
                            , some_kind_
                            >::type
                    )
                  , strided_
                  );

  NT2_TEST_TYPE_IS( (option < settings(uniform_,strided_)
                            , nt2::tag::stride_
                            , some_kind_
                            >::type
                    )
                  , uniform_
                  );
}

NT2_TEST_CASE( nested_settings_stride_ )
{
  using nt2::strided_;
  using nt2::uniform_;
  using nt2::settings;
  using nt2::meta::option;
  using boost::mpl::_;

  typedef settings shadow(double,int);
  typedef settings option1(strided_,uniform_);
  typedef settings option2(uniform_,strided_);

  NT2_TEST_TYPE_IS( (option < settings(shadow, option1)
                            , nt2::tag::stride_
                            , some_kind_
                            >::type
                    )
                  , strided_
                  );

  NT2_TEST_TYPE_IS( (option < settings(shadow, option2)
                            , nt2::tag::stride_
                            , some_kind_
                            >::type
                    )
                  , (uniform_)
                  );
}
