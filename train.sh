#!/bin/sh
: <<'end_long_comment'
for i in 1 0.9 0.8 0.7 0.6 0.5 0.4 0.3 0.2 0.1 0.09 0.08 0.07 0.06 0.05 0.04 0.03 0.02 0.01
do
  for j in 0.01
  do
    for k in 2
    do
      ./bin/training/train -start_learning_rate $i -svm_margin $j -regularization_const $k --v 0 --cross_validation_folds 5 -num_threads 8 --input training_data
    done
  done
done


for i in 1
do
  for j in 0.01
  do
    for k in `seq 0.1 0.1 10`
    do
      ./bin/training/train -start_learning_rate $i -svm_margin $j -regularization_const $k --v 0 --cross_validation_folds 2 -num_threads 8 --input training_data
    done
  done
done


for i in 1
do
  for j in `seq 0.01 0.01 1.0`
  do
    for k in 0.2
    do
      ./bin/training/train -start_learning_rate $i -svm_margin $j -regularization_const $k --v 0 --cross_validation_folds 2 -num_threads 8 --input training_data
    done
  done
done

end_long_comment
for b in 0
do
  ./bin/training/train -graph_loopy_bp_passes $b -start_learning_rate 1 -svm_margin 0.3 -regularization_const 0.2 --v 0 --cross_validation_folds 2 -num_threads 8 --input training_data
done

