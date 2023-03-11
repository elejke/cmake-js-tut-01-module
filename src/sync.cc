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

#include <gst/gst.h>
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
  // test opencv:
  Mat atom_image = Mat::zeros( w, w, CV_8UC3 );
  Mat rook_image = Mat::zeros( w, w, CV_8UC3 );
  // test gstreamer:
  auto v = gst_version_string();
  gst_init(NULL, NULL);
  GstElement * fakesink = gst_element_factory_make("fakesink", NULL);
  info.GetReturnValue().Set(est);
}
