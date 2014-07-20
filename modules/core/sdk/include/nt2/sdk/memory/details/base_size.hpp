//==============================================================================
//         Copyright 2009 - 2014   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2014   NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_MEMORY_DETAILS_BASE_SIZE_HPP_INCLUDED
#define NT2_SDK_MEMORY_DETAILS_BASE_SIZE_HPP_INCLUDED

#include <nt2/core/settings/forward/stride.hpp>
#include <nt2/core/settings/forward/storage_order.hpp>
#include <nt2/sdk/meta/permute_view.hpp>

namespace nt2 { namespace details
{
  template<typename Extent, typename Stride, typename StorageOrder>
  struct  base_size;

  template<typename Extent>
  struct  base_size<Extent,nt2::uniform_,nt2::column_major_>
  {
    typedef Extent extent_type;
    typedef Extent physical_extent_type;

    BOOST_FORCEINLINE std::size_t leading_size()  const
    {
      return boost::fusion::at_c<0>(sizes_);
    }

    BOOST_FORCEINLINE physical_extent_type const& physical_extent() const
    {
      return sizes_;
    }

    BOOST_FORCEINLINE extent_type const& extent() const
    {
      return sizes_;
    }

    private:
    extent_type sizes_;
  };

  template<typename Extent, typename StorageOrder>
  struct  base_size<Extent,Stride,nt2::column_major_>
  {
    // TODO: static_assert that Stride contains Extent
    typedef Extent extent_type;
    typedef Stride physical_extent_type;

    BOOST_FORCEINLINE std::size_t leading_size()      const
    {
      return boost::fusion::at_c<0>(physical_sizes_);
    }

    BOOST_FORCEINLINE physical_extent_type const& physical_extent() const
    {
      return physical_sizes_;
    }

    BOOST_FORCEINLINE extent_type const& extent()     const
    {
      return sizes_;
    }

    private:
    extent_type           sizes_;
    physical_extent_type  physical_sizes_;
  };

  template<typename Extent, typename StorageOrder>
  struct  base_size<Extent,nt2::uniform_,StorageOrder>
        : base_size < Extent
                    , permute_view<Extent,StorageOrder>
                    , nt2::column_major_
                    >
  {
  };
} }

#endif
