#include "../Headers/facade.h"

namespace s21 {
void Facade::InitObject(std::string path) { model_->OpenFile(path); }

void Facade::AfinMove(double moving, int axis) {
  model_->AfinMove(moving, axis);
}

void Facade::AfinRotate(double angle, int axis) {
  model_->AfinRotate(angle, axis);
}

void Facade::AfinScale(double scale) { model_->AfinScale(scale); }

Vertex Facade::GetObject() { return model_->GetObject(); }
}  // namespace s21
