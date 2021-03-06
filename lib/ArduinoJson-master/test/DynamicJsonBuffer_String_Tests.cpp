// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://bblanchon.github.io/ArduinoJson/
// If you like this project, please add a star!

#include <ArduinoJson.h>
#include <gtest/gtest.h>

TEST(DynamicJsonBuffer_String_Tests, WorksWhenBufferIsBigEnough) {
  DynamicJsonBuffer jsonBuffer(6);

  DynamicJsonBuffer::String str = jsonBuffer.startString();
  str.append('h');
  str.append('e');
  str.append('l');
  str.append('l');
  str.append('o');

  ASSERT_STREQ("hello", str.c_str());
}

TEST(DynamicJsonBuffer_String_Tests, GrowsWhenBufferIsTooSmall) {
  DynamicJsonBuffer jsonBuffer(5);

  DynamicJsonBuffer::String str = jsonBuffer.startString();
  str.append('h');
  str.append('e');
  str.append('l');
  str.append('l');
  str.append('o');

  ASSERT_STREQ("hello", str.c_str());
}

TEST(DynamicJsonBuffer_String_Tests, SizeIncreases) {
  DynamicJsonBuffer jsonBuffer(5);

  DynamicJsonBuffer::String str = jsonBuffer.startString();
  ASSERT_EQ(0, jsonBuffer.size());

  str.append('h');
  ASSERT_EQ(1, jsonBuffer.size());

  str.c_str();
  ASSERT_EQ(2, jsonBuffer.size());
}
