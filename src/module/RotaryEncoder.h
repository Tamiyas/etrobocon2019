/**
 *  @file   RotaryEncoder.h
 *  @brief  疑似ロータリーエンコーダークラス, フィルター処理した角度を4msecで積算する
 *  @author T.Miyaji
 */
#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H
#include "Filter.h"

class RotaryEncoder {
 private:
  double totalAngle;
  Filter<int> filter;

 public:
  RotaryEncoder();
  explicit RotaryEncoder(int angle_);
  void reset();
  void update(int angle);
  double getCount() const;
};

#endif
