#include <iostream>
#include <torch/torch.h>
#include <network.h>


using namespace torch;


int main () {
   std::cout << "this is our model for name is Net" << std::endl;
   std::cout << std::endl;

   Net network(50, 10);
   std::cout << network << "\n\n" << std::endl;

   Tensor x, output;
   x = torch::randn({2, 50});
   output = network->forward(x);
   std::cout << output << std::endl;

}
