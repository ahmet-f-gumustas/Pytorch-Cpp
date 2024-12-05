import torch
import torch.nn.functional as F
import torchvision.models as models

r18 = models.resnet18(pretrained=True)
r18_scripted = torch.jit.script(r18)
dummy_input = torch.rand(1, 3, 224, 224)

print(f"Model : {r18}")

unscripted_output = r18(dummy_input)
scripted_output = r18_scripted(dummy_input)

unscripted_top5 = F.softmax(unscripted_output, dim=1).topk(5).indices
scripted_top5 = F.softmax(scripted_output, dim=1).topk(5).indices

print(f"Python model top 5 results :\n\t {unscripted_top5}")
print(f"TorchScript model top 5 results :\n\t {scripted_top5}")

r18_scripted.save("resnet18.pt")