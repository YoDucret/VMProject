//
// vm project
//

#include <dlfcn.h>
#include "Boot.hh"

VMP::ErrCode VMP::Boot::load(std::string const& path)
{
  void *handle;

  typedef IVM*(*fct_t)();
  fct_t fct;
  if ((handle = dlopen(path.c_str(), RTLD_LAZY | RTLD_GLOBAL)) == NULL)
    return (VMP::ErrCode::LIBERR);
  if ((fct = (fct_t)dlsym(handle, "build")) == NULL)
    {
      dlclose(handle);
      return (VMP::ErrCode::LIBERR);
    }
  m_core.reset(fct());
  return (VMP::ErrCode::NOERR);
}

bool	VMP::Boot::exec(VMP::ErrCode &err)
{
  err = m_core->exec();
  return (false);
}
