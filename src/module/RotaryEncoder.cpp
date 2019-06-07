/**
 *  @file   RotaryEncoder.cpp
 *  @brief  疑似ロータリーエンコーダークラス, フィルター処理した角度を4msecで積算する
 *  @author T.Miyaji
 */
#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder() : totalAngle(0), filter() {}

RotaryEncoder::RotaryEncoder(int angle_) : totalAngle(angle_)
{
  // 一度、フィルターを通して前回値を初期化する
  filter.lowPassFilter(angle_);
}

/**
 *  [RotaryEncoder::reset]
 *  @brief  エンコーダーの積算値をすべて初期化する
 */
void RotaryEncoder::reset()
{
  totalAngle = 0;
  filter.reset();
}

/**
 *  [RotaryEncoder::update]
 *  @brief ロータリーエンコーダーの積算値に現在の角度を追加する
 *  @param angle [現在の角度]
 */
void RotaryEncoder::update(int angle)
{
  totalAngle += filter.lowPassFilter(angle);
}

double RotaryEncoder::getCount() const
{
  return totalAngle;
}
