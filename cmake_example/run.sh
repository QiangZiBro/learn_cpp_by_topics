#!/usr/bin/env bash
rm -rf build
rm *.so
python3 setup.py develop
python3 test.py
