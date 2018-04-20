//
// vm project
//

#ifndef __VMP__ERRCODE_HH_
# define __VMP__ERRCODE_HH_

namespace VMP
{
  enum class ErrCode : unsigned short
  {
    NOERR = 0,
      LIBERR,
      CRITFAIL = 500
      };
}

#endif // __VMP__ERRCODE_HH_
