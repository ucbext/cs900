#!/usr/bin/env bash

# This script is meant to copy solutions into the appropriate directories for each program. This
# script is not intended to be run by students but only the instructor. If you are a student, please
# ignore this script.

function log_error() {
    echo "error: $1"
    exit
}

function usage() {
    echo "$(basename $0) copies solutions into the appropriate directories for each program.

This script is meant to be used by the instructor. If you are a student, you may ignore this script
entirely.

    Required arguments:
        -p|--program          The program number to copy solutions for

    Optional arguments:
        -h|--help             Show this help
"
}

function main() {
    positional=()
    while [[ $# -gt 0 ]]; do
        key="$1"
        case $key in
            -p|--program)
                program="$2"
                shift; shift
                ;;
            -h|--help)
                usage
                exit
                ;;
            *)
                positional+=("$1")
                shift
                ;;
        esac
    done

    repo_path=$(dirname $(dirname $0))
    if [[ -z "$program" ]]; then
        log_error "no program number provided"
    fi

    files=()
    if [[ $program == "program1" ]]; then
        files+=("angle_calculator.cc")
        files+=("freezing_boiling_points.cc")
        files+=("mobile_service_provider.cc")
        files+=("monthly_payments.cc")
        files+=("stock_commission.cc")
    elif [[ $program == "program2" ]]; then
        files+=("is_prime.h")
        files+=("is_prime.cc")
        files+=("least_greatest.cc")
        files+=("lowest_score.h")
        files+=("lowest_score.cc")
        files+=("payroll.cc")
        files+=("random_number_guessing.cc")
    elif [[ $program == "program3" ]]; then
        files+=("ackermann.h")
        files+=("ackermann.cc")
        files+=("binary_search.h")
        files+=("binary_search.cc")
        files+=("lienar_search.h")
        files+=("lienar_search.cc")
        files+=("reverse.h")
        files+=("reverse.cc")
    elif [[ $program == "program4" ]]; then
        files+=("customer.h")
        files+=("customer.cc")
        files+=("password_verification.h")
        files+=("password_verification.cc")
        files+=("person.h")
        files+=("person.cc")
        files+=("preferred_customer.h")
        files+=("preferred_customer.cc")
        files+=("word_separator.h")
        files+=("word_separator.cc")
    elif [[ $program == "program5" ]]; then
        files+=("dynamic_array.h")
        files+=("dynamic_array.cc")
    else
        log_error "invalid program number"
    fi

    for file in "${files[@]}"; do
        directory=solutions/$program
        mkdir -p $directory
        cp $repo_path/$program/$file $directory
    done
}

main "$@"
