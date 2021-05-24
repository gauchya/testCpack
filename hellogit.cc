
#include <iostream>
#include <string>

#include "HelloGitConfig.h"

int main(int argc, char* argv[])
{

    std::cout << argv[0] << " Version(major.minor) " << HelloGit_VERSION_MAJOR << "."
              << HelloGit_VERSION_MINOR << std::endl;

  std::cout << "Hello ! Full git version is : " << HelloGit_VERSION << std::endl;
  return 0;
}