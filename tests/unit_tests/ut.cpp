/*
 *  Copyright (c) 2014 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *  Contact: Jan Olszak <janekolszak@gmail.com>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License
 */


/**
 * @file
 * @author  Jan Olszak (janekolszak@gmail.com)
 * @brief   Main file for the Cargo Daemon unit tests
 */

#include "config.hpp"

#include "cargo-logger/logger.hpp"
#include "cargo-logger/backend-stderr.hpp"

#include <boost/test/included/unit_test.hpp>

#include "cargo-utils/signal.hpp"

using namespace boost::unit_test;
using namespace cargo::logger;

test_suite* init_unit_test_suite(int /*argc*/, char** /*argv*/)
{
    Logger::setLogLevel(LogLevel::TRACE);
    Logger::setLogBackend(new StderrBackend());

    utils::signalBlock(SIGPIPE);
    return NULL;
}
