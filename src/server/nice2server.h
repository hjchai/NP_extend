/*
   Copyright 2014 Software Reliability Lab, ETH Zurich

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#ifndef N2_NICE2SERVER_H__
#define N2_NICE2SERVER_H__

#include "glog/logging.h"

namespace jsonrpc {
class HttpServer;
}
class Nice2ServerInternal;

class Nice2Server {
public:
  Nice2Server(jsonrpc::HttpServer* server);
  virtual ~Nice2Server();

  void Listen();

private:
  Nice2ServerInternal* internal_;
};

#endif  // N2_NICE2SERVER_H__
