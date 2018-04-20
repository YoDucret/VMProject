//
// vm project
//

#include <string>
#include <iostream>
#include "ErrCode.hh"
#include "Boot.hh"

namespace
{
  struct Fct
  {
    static bool errHandler(const VMP::ErrCode err)
    {
      if (err != VMP::ErrCode::NOERR)
	std::cerr << "I doesn\'t expected that, like the Spanish Inquisition ! (Error: " << static_cast<unsigned short>(err) << ")" << std::endl;
      return (err < VMP::ErrCode::CRITFAIL);
    }
  };
}

int main()
{
  std::cout << "..." << std::endl;

  std::string input("");
  bool run = true;
  VMP::ErrCode err = VMP::ErrCode::NOERR;
  VMP::Boot boot;

  std::cout << "Welcome, I am the VMPI (Virtual Machine Project Initializer)" << std::endl;
  std::cout << "You can call me the VaMPIre" << std::endl << std::endl;
  std::cout << "Please enter the path to a library that implement the IVM interface" << std::endl;

  while (run)
    {
      std::cout << "> ";
      std::getline(std::cin, input);
      err = boot.load(input);
      run = Fct::errHandler(err);
      if (err == VMP::ErrCode::NOERR)
	{
	  std::cout << "So long and thans for all the blood" << std::endl;
	  run = boot.exec(err);
	}
    }
  return ((int)err);
}
