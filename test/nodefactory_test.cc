#include <gtest/gtest.h>

#include "nodefactory.h"

TEST(NodeFactoryTest, NodeFactoryConstruction) {
    NodeFactory node_factory{};
    SUCCEED();
}
