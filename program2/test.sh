#!/usr/bin/env bash

# Note: this file is not a part of the bazel build system because bazel places executions in a
# jailed cache. Instead, we simply run the bazel commands ourselves while using bashunit.

gitroot=$(git rev-parse --show-toplevel)
cd $gitroot
source thirdparty/shell/unittest.bash

bazel_run="bazel run --experimental_ui_limit_console_output=1"

function test_least_greatest_no_input() {
  echo -99 | $bazel_run program2:least_greatest > $TEST_log
  expect_log "You didn't enter any numbers"
}

function test_least_greatest_single_input() {
  echo 1 -99 | $bazel_run program2:least_greatest > $TEST_log
  expect_log "The largest number was 1"
  expect_log "The smallest number was 1"
}

function test_least_greatest_multiple() {
  echo 1 2 3 4 5 6 7 8 9 -99 | $bazel_run program2:least_greatest > $TEST_log
  expect_log "The largest number was 9"
  expect_log "The smallest number was 1"
}

function test_random_number_guessing() {
  input=$(mktemp -u)
  output=$(mktemp -u)
  mkfifo $input
  mkfifo $output

  tail -f $input | $bazel_run program2:random_number_guessing > $output &

  low=0
  high=1000
  guesses=0

  while [[ $low -le $high ]]; do
    mid=$(( (low + high) / 2 ))
    echo $mid > $input
    guesses=$(( guesses + 1 ))

    read result
    echo $result > $TEST_log

    if [[ $result == *"too high"* ]]; then
      high=$(( mid - 1 ))
    elif [[ $result == *"too low"* ]]; then
      low=$(( mid + 1 ))
    elif [[ $result == *"correct answer"* ]]; then
      expect_log "You got the correct answer in $guesses attempts!"
      break
    fi
  done < $output
}

function test_payroll_negative_hours() {
  echo -1 -1 -1 0 15 0 15 0 15 0 15 0 15 0 15 0 15 | $bazel_run program2:payroll > $TEST_log
  expect_log "Hours worked cannot be negative. Try again."
}

function test_payroll_payrate_too_low() {
  echo 0 14 14 14 15 0 15 0 15 0 15 0 15 0 15 0 15 | $bazel_run program2:payroll > $TEST_log
  expect_log "Pay rate cannot be lower than \$15.00 per hour. Try again."
}

function test_payroll_full_calculation() {
  echo 10 16 15 17 20 18 25 19 30 20 35 21 40 22 | $bazel_run program2:payroll > $TEST_log
  expect_log "Employee 5658845: \$160"
  expect_log "Employee 4520125: \$255"
  expect_log "Employee 7895122: \$360"
  expect_log "Employee 8777541: \$475"
  expect_log "Employee 8451277: \$600"
  expect_log "Employee 1302850: \$735"
  expect_log "Employee 7580489: \$880"
}

function main() {
  TEST_verbose=false
  set -e
  bazel test program2:tests
  run_suite "Test suite for program 2"
}

main "$@"
