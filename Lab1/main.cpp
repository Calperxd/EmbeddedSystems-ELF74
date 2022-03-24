#include <iostream>


int main()
{
  float value1;
  float value2;
  float result;
  
  
  
  std::cout <<  __DATE__ << std::endl;
  std::cout <<  __TIME__  << std::endl;
  std::cout <<   __LINE__ << std::endl;
  std::cout <<  __STDC__ << std::endl;
  std::cout <<  __STDC_VERSION__ << std::endl;
  std::cout <<  __ARM_ARCH << std::endl;
  
  std::cout <<   __ARM_ARCH_ISA_THUMB << std::endl;
  std::cout <<  __ARM_SIZEOF_MINIMAL_ENUM  << std::endl;
  std::cout <<   __ARM_SIZEOF_WCHAR_T << std::endl;
  std::cout <<  __CORE__ << std::endl;
  
  std::cout << "Input the value 1" << std::endl;
  std::cin >> value1;
  std::cout << "Input the value 2" << std::endl;
  std::cin >> value2;
  
  
  result = value1 + value2;
  std::cout << "The result: " << result <<std::endl;
  
  return 0;
}
