/**
 *  @file   RotaryEncoderTest.cpp
 *  @brief  ロータリーエンコーダークラスのテストファイル
 *  @author T.Miyaji
 */
#include "RotaryEncoder.h"
#include <gtest/gtest.h>

namespace etrobocon2019_test {
  TEST(RotaryEncoder, construct)
  {
    RotaryEncoder leftEncoder;
    ASSERT_DOUBLE_EQ(0.0, leftEncoder.getCount());
  }

  TEST(RotaryEncoder, construct2)
  {
    RotaryEncoder leftEncoder(10);
    ASSERT_DOUBLE_EQ(10.0, leftEncoder.getCount());
  }

  TEST(RotaryEncoder, update)
  {
    RotaryEncoder leftEncoder;
    ASSERT_DOUBLE_EQ(0.0, leftEncoder.getCount());

    leftEncoder.update(10);
    ASSERT_DOUBLE_EQ(10.0, leftEncoder.getCount());

    leftEncoder.update(11);
    double expected = 10.0 + (0.9 * 10 + 0.1 * 11);
    ASSERT_DOUBLE_EQ(expected, leftEncoder.getCount());
  }

  TEST(RotaryEncoder, reset)
  {
    // エンコーダークラスを作成する
    RotaryEncoder leftEncoder;
    ASSERT_DOUBLE_EQ(0.0, leftEncoder.getCount());

    // 合計角度を更新
    leftEncoder.update(10);
    ASSERT_DOUBLE_EQ(10.0, leftEncoder.getCount());

    // 合計角度をリセット
    leftEncoder.reset();
    ASSERT_DOUBLE_EQ(0.0, leftEncoder.getCount());

    // エンコーダーをリセットするとフィルターもリセットされる
    leftEncoder.update(11);
    ASSERT_DOUBLE_EQ(11.0, leftEncoder.getCount());
  }

  TEST(RotaryEncoder, getCount)
  {
    RotaryEncoder leftEncoder;
    ASSERT_DOUBLE_EQ(0.0, leftEncoder.getCount());

    leftEncoder.update(10);
    double expected = 10.0;
    ASSERT_DOUBLE_EQ(expected, leftEncoder.getCount());

    leftEncoder.update(11);
    expected += 10 * 0.9 + 11 * 0.1;
    ASSERT_DOUBLE_EQ(expected, leftEncoder.getCount());

    leftEncoder.update(12);
    expected += 11 * 0.9 + 12 * 0.1;
    ASSERT_DOUBLE_EQ(expected, leftEncoder.getCount());
  }
}  // namespace etrobocon2019_test
