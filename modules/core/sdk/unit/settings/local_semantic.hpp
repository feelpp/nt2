#ifndef LOCAL_SEMANTIC_HPP
#define LOCAL_SEMANTIC_HPP

#include <nt2/core/settings/allocator.hpp>

#include <vector>
#include <nt2/core/utility/of_size.hpp>

struct some_kind_
{
  template<typename Settings, typename Option>
  struct option
  {
    typedef Settings type;
  };

  template<typename Option>
  struct default_
  {
    typedef typename Option::default_type type;
  };
};

template<>
struct some_kind_::default_<nt2::tag::allocator_>
{
  typedef std::allocator<void*> type;
};

#endif
