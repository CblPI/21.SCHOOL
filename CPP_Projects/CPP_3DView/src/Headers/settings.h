#ifndef SRC_HEADERS_SETTINGS_H_
#define SRC_HEADERS_SETTINGS_H_

#include "memory.h"

namespace s21 {
class Settings {
 public:
  Settings();
  explicit Settings(StatusStorage values);
  ~Settings() = default;

  StatusStorage Save();
  void Restore(Memory mem);

  void SetTypeProection(int value);
  void SetBGColor(QColor color);
  void SetTypeLines(int value);
  void SetEdgeColor(QColor color);
  void SetSizeLines(double value);
  void SetTypeVertexes(int value);
  void SetVertexColor(QColor color);
  void SetSizeVertexes(double value);
  void SetTypeModel(int value);
  void SetModelColor(QColor color);
  void SetLightColor(QColor color);
  void SetLightPower(double value);

  void SetTextureStatus(bool val);
  bool GetTextureStatus();

 private:
  StatusStorage info_;
  bool texture_status_;
};
}  // namespace s21

#endif  // SRC_HEADERS_SETTINGS_H_
