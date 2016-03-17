#!/bin/sh
./bin/training/train --v 1 --cross_validation_folds 2 --logtostderr -num_threads 8 --input training_data
