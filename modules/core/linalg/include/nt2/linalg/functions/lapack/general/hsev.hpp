//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_LAPACK_GENERAL_HSEV_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_LAPACK_GENERAL_HSEV_HPP_INCLUDED

#include <nt2/linalg/functions/hsev.hpp>
#include <nt2/include/functions/width.hpp>
#include <nt2/include/functions/height.hpp>
#include <nt2/linalg/details/utility/workspace.hpp>
#include <nt2/linalg/details/utility/f77_wrapper.hpp>
#include <boost/dispatch/attributes.hpp>
#include <boost/assert.hpp>

extern "C"
{
  void NT2_F77NAME(cheev)( const char* jobz      , const char* uplo
                          , const nt2_la_int* n  , nt2_la_complex* a
                          , const nt2_la_int* lda, float* w
                          , nt2_la_complex* work , const nt2_la_int* lwork
                          , float* rwork         , nt2_la_int* info);

  void NT2_F77NAME(zheev)( const char* jobz      , const char* uplo
                          , const nt2_la_int* n  , nt2_la_complex* a
                          , const nt2_la_int* lda, double* w
                          , nt2_la_complex* work , const nt2_la_int* lwork
                          , double* rwork        , nt2_la_int* info);


  void NT2_F77NAME(dsyev)(const char* jobz       , const char* uplo
                         , const nt2_la_int* n   , double* a
                         , const nt2_la_int* lda , double* w
                         , double* work          , const nt2_la_int* lwork
                         , nt2_la_int* info);

  void NT2_F77NAME(ssyev)(const char* jobz       , const char* uplo
                         , const nt2_la_int* n   , float* a
                         , const nt2_la_int* lda , float* w
                         , float* work          , const nt2_la_int* lwork
                         , nt2_la_int* info);

}


namespace nt2 { namespace ext
{

//---------------------------------------------Real-double------------------------------------------------//

  /// INTERNAL ONLY - Compute the workspace
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::hsev_, tag::cpu_
                            , (A0)(S0)(A1)(S1)(C0)(C1)
                            , ((container_<nt2::tag::table_,  double_<A0>, S0 >)) //a
                              ((container_<nt2::tag::table_,  double_<A1>, S1 >)) //w
                              (scalar_< ints8_<C0> >)                             //jobz
                              (scalar_< ints8_<C1> >)                             //uplo
                            )
  {
    typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()( A0& a, A1& w, C0 jobz, C1 uplo) const
     {
        result_type info;
        details::workspace<typename A0::value_type> wk;
        nt2_la_int n = nt2::width(a);
        BOOST_ASSERT_MSG(n == nt2_la_int(nt2::height(a)), "input must be square");
        nt2_la_int lda = a.leading_size();

        NT2_F77NAME(dsyev) ( &jobz, &uplo, &n, 0, &lda, 0, wk.main(), details::query(), &info);
        wk.prepare_main();
        info = nt2::hsev(a, w, jobz, uplo, wk);

        return info;
     }
  };

  /// INTERNAL ONLY - Workspace is ready
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::hsev_, tag::cpu_
                            , (A0)(S0)(A1)(S1)(C0)(C1)(W0)
                            , ((container_<nt2::tag::table_,  double_<A0>, S0 >)) //a
                              ((container_<nt2::tag::table_,  double_<A1>, S1 >)) //w
                              (scalar_< ints8_<C0> >)                             //jobz
                              (scalar_< ints8_<C1> >)                             //uplo
                              (unspecified_<W0>)                                  //workspace
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()( A0& a, A1& w, C0 jobz, C1 uplo, W0& wk) const
     {
        result_type info;
        nt2_la_int  n   = nt2::width(a);
        BOOST_ASSERT_MSG(n == nt2_la_int(nt2::height(a)), "input must be square");
        nt2_la_int  lda = a.leading_size();

        nt2_la_int  wn = wk.main_size();
        NT2_F77NAME(dsyev) (&jobz, &uplo, &n, a.raw(), &lda, w.raw(), wk.main(), &wn, &info);

        return info;
     }
  };

//---------------------------------------------Real-single------------------------------------------------//
  /// INTERNAL ONLY - Compute the workspace
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::hsev_, tag::cpu_
                            , (A0)(S0)(A1)(S1)(C0)(C1)
                            , ((container_<nt2::tag::table_,  single_<A0>, S0 >)) //a
                              ((container_<nt2::tag::table_,  single_<A1>, S1 >)) //w
                              (scalar_< ints8_<C0> >)                             //jobz
                              (scalar_< ints8_<C1> >)                             //uplo
                            )
  {
    typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()( A0& a, A1& w, C0 jobz, C1 uplo) const
     {
        result_type info;
        details::workspace<typename A0::value_type> wk;
        nt2_la_int  n   = nt2::width(a);
        BOOST_ASSERT_MSG(n == nt2_la_int(nt2::height(a)), "input must be square");
        nt2_la_int  lda = a.leading_size();

        NT2_F77NAME(ssyev) (&jobz, &uplo, &n, 0, &lda, 0, wk.main(), details::query()
                           , &info);

        wk.prepare_main();
        info = nt2::hsev(a, w, jobz, uplo, wk);

        return info;
     }
  };

  /// INTERNAL ONLY - Workspace is ready
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::hsev_, tag::cpu_
                            , (A0)(S0)(A1)(S1)(C0)(C1)(W0)
                            , ((container_<nt2::tag::table_,  single_<A0>, S0 >)) //a
                              ((container_<nt2::tag::table_,  single_<A1>, S1 >)) //w
                              (scalar_< ints8_<C0> >)                             //jobz
                              (scalar_< ints8_<C1> >)                             //uplo
                              (unspecified_<W0>)                                  //workspace
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()( A0& a, A1& w, C0 jobz, C1 uplo, W0& wk) const
     {
        result_type info;
        nt2_la_int  n   = nt2::width(a);
        BOOST_ASSERT_MSG(n == nt2_la_int(nt2::height(a)), "input must be square");
        nt2_la_int  lda = a.leading_size();

        nt2_la_int  wn = wk.main_size();
        NT2_F77NAME(ssyev) (&jobz, &uplo, &n, a.raw(), &lda, w.raw(), wk.main(), &wn, &info);

        return info;
     }
  };


//---------------------------------------------Complex-single------------------------------------------------//

  /// INTERNAL ONLY - Compute the workspace
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::hsev_, tag::cpu_
                            , (A0)(S0)(A1)(S1)(C0)(C1)
                            , ((container_<nt2::tag::table_,  complex_<single_<A0> >, S0 >))//a
                              ((container_<nt2::tag::table_,  complex_<single_<A1> >, S1 >))//ws
                              (scalar_< ints8_<C0> >)                             //jobz
                              (scalar_< ints8_<C1> >)                             //uplo
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()( A0& a, A1& w, C0 jobz, C1 uplo) const
     {
        result_type info;
        details::workspace<typename A0::value_type> wk;
        nt2_la_int  n   = nt2::width(a);
        BOOST_ASSERT_MSG(n == nt2_la_int(nt2::height(a)), "input must be square");
        nt2_la_int  lda = a.leading_size();

        NT2_F77NAME(chsev) (&jobz, &uplo, &n, 0, &lda, 0, wk.main(), details::query(), wk.reals(), &info);

        wk.prepare_main();
        info = nt2::hsev(a, w, jobz, uplo, wk);

        return info;
     }
  };

  /// INTERNAL ONLY - Workspace is ready
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::hsev_, tag::cpu_
                            , (A0)(S0)(A1)(S1)(C0)(C1)(W0)
                            , ((container_<nt2::tag::table_,  complex_<single_<A0> >, S0 >))//a
                              ((container_<nt2::tag::table_,  complex_<single_<A1> >, S1 >))//ws
                              (scalar_< ints8_<C0> >)                              //jobz
                              (scalar_< ints8_<C1> >)                              //uplo
                              (unspecified_<W0>)                                   //w
                            )
  {
     typedef nt2_la_int result_type;


     BOOST_FORCEINLINE result_type operator()( A0& a, A1& w, C0 jobz, C1 uplo, W0& wk) const
     {
        result_type info;
        nt2_la_int  n   = nt2::width(a);
        BOOST_ASSERT_MSG(n == nt2_la_int(nt2::height(a)), "input must be square");
        nt2_la_int  lda = a.leading_size();

        nt2_la_int  wn = w.main_size();
        NT2_F77NAME(shsev) (&jobz, &uplo, &n, a.raw(), &lda, w.raw(), wk.main(), &wn, wk.reals()
                           , &info);

        return info;
     }
  };

//---------------------------------------------Complex-double------------------------------------------------//


  /// INTERNAL ONLY - Compute the workspace
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::hsev_, tag::cpu_
                            , (A0)(S0)(A1)(S1)(C0)(C1)
                            , ((container_<nt2::tag::table_,  complex_<double_<A0> >, S0 >))//a
                              ((container_<nt2::tag::table_,  complex_<double_<A1> >, S1 >))//ws
                              (scalar_< ints8_<C0> >)                             //jobz
                              (scalar_< ints8_<C1> >)                             //uplo
                            )
  {
     typedef nt2_la_int result_type;

     BOOST_FORCEINLINE result_type operator()( A0& a, A1& w, C0 jobz, C1 uplo) const
     {
        result_type info;
        details::workspace<typename A0::value_type> wk;
        nt2_la_int  n   = nt2::width(a);
        BOOST_ASSERT_MSG(n == nt2_la_int(nt2::height(a)), "input must be square");
        nt2_la_int  lda = a.leading_size();

        NT2_F77NAME(zhsev) (&jobz, &uplo, &n, 0, &lda, 0, wk.main(), details::query(), wk.reals()
                           , &info);

        wk.prepare_main();
        info = nt2::hsev(a, w, jobz, uplo, wk);

        return info;
     }
  };

  /// INTERNAL ONLY - Workspace is ready
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::hsev_, tag::cpu_
                            , (A0)(S0)(A1)(S1)(C0)(C1)(W0)
                            , ((container_<nt2::tag::table_,  complex_<double_<A0> >, S0 >))//a
                              ((container_<nt2::tag::table_,  complex_<double_<A1> >, S1 >))//ws
                              (scalar_< ints8_<C0> >)                              //jobz
                              (scalar_< ints8_<C1> >)                              //uplo
                              (unspecified_<W0>)                                   //w
                            )
  {
     typedef nt2_la_int result_type;


     BOOST_FORCEINLINE result_type operator()( A0& a, A1& w, C0 jobz, C1 uplo, W0& wk) const
     {
        result_type info;
        nt2_la_int  n   = nt2::width(a);
        BOOST_ASSERT_MSG(n == nt2_la_int(nt2::height(a)), "input must be square");
        nt2_la_int  lda = a.leading_size();

        nt2_la_int  wn = w.main_size();
        NT2_F77NAME(zhsev) (&jobz, &uplo, &n, a.raw(), &lda, w.raw(), wk.main(), &wn, wk.reals()
                           , &info, &w);

        return info;
     }
  };
} }

#endif