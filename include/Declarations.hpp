// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_DECLARATIONS_HPP_
#define INCLUDE_DECLARATIONS_HPP_

#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup.hpp>

const char endSequence[] = "0000";
const size_t endSequenceLength = 4;
void init();
#endif  // INCLUDE_DECLARATIONS_HPP_
