#ifndef SRC_HEADERS_FACADE_H_
#define SRC_HEADERS_FACADE_H_

#include "parsingmodel.h"

namespace s21 {
class Facade {
 public:
  Facade() = default;
  explicit Facade(s21::ParsingModel *model) : model_(model) {}
  ~Facade() = default;

  void InitObject(std::string path);
  void AfinMove(double moving, int axis);
  void AfinRotate(double angle, int axis);
  void AfinScale(double scale);

  Vertex GetObject();

 private:
  s21::ParsingModel *model_;
};
}  // namespace s21

#endif  // SRC_HEADERS_FACADE_H_
