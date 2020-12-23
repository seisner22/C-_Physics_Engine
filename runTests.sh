#!/bin/bash
set -x
for t in build/*_test; do $t; done
