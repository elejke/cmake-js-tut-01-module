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

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#define w 400

using namespace cv;

// Simple synchronous access to the `Estimate()` function
NAN_METHOD(CalculateSync) {
  // expect a number as the first argument
  int points = info[0]->Uint32Value(info.GetIsolate()->GetCurrentContext()).ToChecked();
  double est = Estimate(points);
  auto a = (char*)zlibVersion();
  Mat atom_image = Mat::zeros( w, w, CV_8UC3 );
  Mat rook_image = Mat::zeros( w, w, CV_8UC3 );
  info.GetReturnValue().Set(est);
}
