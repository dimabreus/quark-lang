#!/bin/bash
set -e

echo "Building Quark program..."
fasm out.asm        out.o

echo "Build successful!"