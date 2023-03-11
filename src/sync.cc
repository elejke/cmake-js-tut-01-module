/*********************************************************************
* NAN - Native Abstractions for Node.js
 *
 * Copyright (c) 2015 NAN contributors
 *
 * MIT License <https://github.com/nodejs/nan/blob/master/LICENSE.md>
 ********************************************************************/

#include <nan.h>
#include <zlib.h>
#include "pi_est.h"  // NOLINT(build/include)
#include "sync.h"  // NOLINT(build/include)
#include <string>

// Simple synchronous access to the `Estimate()` function
NAN_METHOD(CalculateSync) {
  // expect a number as the first argument
  int points = info[0]->Uint32Value(info.GetIsolate()->GetCurrentContext()).ToChecked();
  double est = Estimate(points);
  auto a = (char*)zlibVersion();
  info.GetReturnValue().Set(*a);
}
