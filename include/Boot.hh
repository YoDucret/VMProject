//
// vm project
//

#ifndef __VMP__BOOT_HH_
# define __VMP__BOOT_HH_

#include <memory>
#include "IVM.hh"
#include "ErrCode.hh"

namespace VMP
{
  class Boot
  {
  public :
    Boot() = default;
    Boot(Boot const&) = delete;
    ~Boot() = default;
    Boot &operator=(Boot const&) = delete;
    ErrCode load(std::string const&);
    bool exec(ErrCode &err);

  private :
    std::shared_ptr<IVM> m_core;
  };
}

#endif // __VMP__BOOT_HH_
