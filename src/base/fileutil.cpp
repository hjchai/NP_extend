/*
   Copyright 2015 Software Reliability Lab, ETH Zurich

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

#include "fileutil.h"

void ReadFileToStringOrDie(const char* filename, std::string* r) {
  r->clear();
  FILE* f = fopen(filename, "rt");
  CHECK(f != NULL) << "Could not open " << filename << " for reading.";
  char buf[4096];
  while (!feof(f)) {
    if (fgets(buf, 4096, f) == buf) {
      r->append(buf);
    } else {
      if (!feof(f))
        LOG(FATAL) << "Read error from " << filename;
    }
  }
  fclose(f);
}
