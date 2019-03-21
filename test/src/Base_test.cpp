//
// Created by jonb on 3/21/19.
//

#include <gtest/gtest.h>
#include <memory>

#define private public
#define protected public
#include "../../src/Base.h"

using Friend::DDS::Base;

volatile const string name = "someName";

class BaseTest : public ::testing::Test
{
protected:
    unique_ptr<Base<int>> base;
    void SetUp() override {
        base = unique_ptr<Base<int>>(new Base<int>());
    }
    void TearDown() override {

    }
};

TEST_F(BaseTest, classCreated) {
    ASSERT_TRUE(base != nullptr);
}
TEST_F(BaseTest, setName) {
    base->create(name);
    ASSERT_EQ(name, base->_myName);
}
TEST_F(BaseTest, readLastState) {
    base->_lastState = 42;
    ASSERT_EQ(42, base->read());
}
TEST_F(BaseTest, createClassWithName) {
    auto newBaseWithName = unique_ptr<Base<int>>(new Base<int>(name));
    ASSERT_EQ(name, newBaseWithName->_myName);
}
