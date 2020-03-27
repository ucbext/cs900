#!/usr/bin/env bash

# Note: this file is not a part of the bazel build system because bazel places executions in a
# jailed cache. Instead, we simply run the bazel commands ourselves while using bashunit.

gitroot=$(git rev-parse --show-toplevel)
cd $gitroot
source thirdparty/shell/unittest.bash

bazel_run="bazel run --experimental_ui_limit_console_output=1"

function test_stock_commission() {
  $bazel_run program1:stock_commission > $TEST_log
  expect_log "Total paid for stock: \$26250"
  expect_log "Total commission: \$525"
  expect_log "Total paid: \$26775"
}

function test_angle_calculator_0() {
  echo 0 | $bazel_run program1:angle_calculator > $TEST_log
  expect_log "sin: 0"
  expect_log "cos: 1"
  expect_log "tan: 0"
}

function test_angle_calculator_90() {
  echo 90 | $bazel_run program1:angle_calculator > $TEST_log
  expect_log "sin: 0.893997"
  expect_log "cos: -0.448074"
  expect_log "tan: -1.9952"
}

function test_angle_calculator_negative() {
  echo -45 | $bazel_run program1:angle_calculator > $TEST_log
  expect_log "sin: -0.850904"
  expect_log "cos: 0.525322"
  expect_log "tan: -1.61978"
}

function test_monthly_payments() {
  echo 1 36 10000 | $bazel_run program1:monthly_payments > $TEST_log
  expect_log "Loan Amount: \$10000"
  expect_log "Monthly Interest Rate: 1%"
  expect_log "Number of Payments: 36"
  expect_log "Monthly Payment: \$332.14"
  expect_log "Amount Paid Back: \$11957"
  expect_log "Interest Paid: \$1957.16"
}

function test_freezing_boiling_points_ethyl_alcohol_freeze() {
  echo -172 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_not_log "Ethyl alcohol will freeze"

  echo -173 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Ethyl alcohol will freeze"

  echo -174 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Ethyl alcohol will freeze"
}

function test_freezing_boiling_points_ethyl_alcohol_boil() {
  echo 171 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_not_log "Ethyl alcohol will boil"

  echo 172 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Ethyl alcohol will boil"

  echo 173 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Ethyl alcohol will boil"
}

function test_freezing_boiling_points_mercury_freeze() {
  echo -37 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_not_log "Mercury will freeze"

  echo -38 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Mercury will freeze"

  echo -39 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Mercury will freeze"
}

function test_freezing_boiling_points_mercury_boil() {
  echo 675 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_not_log "Mercury will boil"

  echo 676 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Mercury will boil"

  echo 677 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Mercury will boil"
}

function test_freezing_boiling_points_oxygen_freeze() {
  echo -361 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_not_log "Oxygen will freeze"

  echo -362 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Oxygen will freeze"

  echo -363 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Oxygen will freeze"
}

function test_freezing_boiling_points_oxygen_boil() {
  echo -307 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_not_log "Oxygen will boil"

  echo -306 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Oxygen will boil"

  echo -305 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Oxygen will boil"
}

function test_freezing_boiling_points_waterfreeze() {
  echo 33 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_not_log "Water will freeze"

  echo 32 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Water will freeze"

  echo 31 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Water will freeze"
}

function test_freezing_boiling_points_water_boil() {
  echo 211 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_not_log "Water will boil"

  echo 212 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Water will boil"

  echo 213 | $bazel_run program1:freezing_boiling_points > $TEST_log
  expect_log "Water will boil"
}

function test_mobile_service_provider_incorrect_package() {
  echo D | $bazel_run program1:mobile_service_provider > $TEST_log
  expect_log "Please enter a valid package (A, B, C)."
}

function test_mobile_service_provider_package_a_no_extra_minutes() {
  for i in 449 450; do
    echo A $i | $bazel_run program1:mobile_service_provider > $TEST_log
    expect_log "Total bill: \$39.99"
    expect_not_log "If you purchase plan B, your savings would be: $"
    expect_not_log "If you purchase plan C, your savings would be: $"
  done
}

function test_mobile_service_provider_package_a_extra_minutes() {
  echo A 1000 | $bazel_run program1:mobile_service_provider > $TEST_log
  expect_log "Total bill: \$287.49"
  expect_log "If you purchase plan B, your savings would be: \$187.5"
  expect_log "If you purchase plan C, your savings would be: \$217.5"
}

function test_mobile_service_provider_package_b_no_extra_minutes() {
  for i in 899 900; do
    echo B $i | $bazel_run program1:mobile_service_provider > $TEST_log
    expect_log "Total bill: \$59.99"
    expect_not_log "If you purchase plan A, your savings would be: $"
    expect_not_log "If you purchase plan C, your savings would be: $"
  done
}

function test_mobile_service_provider_package_b_extra_minutes() {
  echo B 1000 | $bazel_run program1:mobile_service_provider > $TEST_log
  expect_log "Total bill: \$99.99"
  expect_not_log "If you purchase plan A, your savings would be: $"
  expect_log "If you purchase plan C, your savings would be: \$30"
}

function test_mobile_service_provider_package_c() {
  echo C 1000 | $bazel_run program1:mobile_service_provider > $TEST_log
  expect_log "Total bill: \$69.99"
  expect_not_log "If you purchase plan A, your savings would be: $"
  expect_not_log "If you purchase plan B, your savings would be: $"
}

function main() {
  TEST_verbose=false
  run_suite "Test suite for program 1"
}

main "$@"
