/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef UTIL_FOREST_HPP_
#define UTIL_FOREST_HPP_

#include <string>

#include "TreeNode.hpp"

std::vector<std::string> Forest_to_string( const std::vector<TreeNode *> &forest );
void Forest_cleanup( const std::vector<TreeNode *> &forest );

#endif /* UTIL_FOREST_HPP_ */
