//
// vm project
//

#ifndef __VMP__IVM_HH_
# define __VMP__IVM_HH_

#include "ErrCode.hh"

struct IVM
{
  virtual ~IVM() = default;
  virtual VMP::ErrCode exec() = 0;
};

#endif // __VMP__IVM_HH_
