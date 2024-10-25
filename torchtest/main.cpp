#include <iostream>
#include <torch/torch.h>

int main () {
   std::cout << "this is firts example for pytorch cpp programming " << std::endl;
   std::cout << std::endl;

   torch::Tensor tensor = torch::rand({5, 5}, torch::kCUDA);
   std::cout << tensor << std::endl;
   
   return 0;
}
