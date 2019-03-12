#!/usr/bin/env bash

#TODO:
#
# - Find a way to remove int16_t. Disabling it through the probability
#   configuration file (see safe_ops_size_prob on
#   svcomp_probabilities) results in a infinite loop.
#
# - Ensure that __VERIFIER_error is called inside blocks. For some
#   reason creating a "void" typed function resulted in _error never
#   being called, so I simply wrapped up in a proxy. The collateral
#   effect is that _error_proxy can be called from inside conditional
#   checks, which is not desirable. Might be worth injecting these as
#   a second step.

CSMITH=src/csmith

$CSMITH --no-argc --no-bitfields --no-checksum --no-comma-operators --no-embedded-assigns --no-unary-plus-operator --no-int8 --no-uint8 --no-float --no-math64 --no-packed-struct --no-volatiles --no-safe-math --no-compound-assignment --svcomp --probability-configuration svcomp_probabilities --ccomp --no-longlong --no-jumps
