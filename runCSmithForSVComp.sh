#!/usr/bin/env bash

#TODO:
#
# - Ensure that __VERIFIER_error is called inside blocks. For some
#   reason creating a "void" typed function resulted in _error never
#   being called, so I simply wrapped up in a proxy. The collateral
#   effect is that _error_proxy can be called from inside conditional
#   checks, which is not desirable. Might be worth injecting these as
#   a second step.
#!/usr/bin/env bash
CSMITH=./csmith

if [[ $# == 0 ]]
then
	echo "Usage: runCSmithForSVComp.sh filename"
fi

#remove extension
FILENAME="${1%.*}"
TMP_FILE=$(mktemp)

$CSMITH --no-argc --no-bitfields --no-checksum --no-comma-operators \
		--no-embedded-assigns --no-unary-plus-operator --no-int8 \
		--no-uint8 --no-float --no-math64 --no-packed-struct --no-volatiles\
		--no-safe-math --no-compound-assignment --svcomp \
		--probability-configuration svcomp_probabilities --ccomp --no-longlong\
		--no-jumps --no-const-pointers --no-consts | \
	sed "s/csmith.h/csmith_svcomp.h/" | \
	sed "s/\^/+/gp" > "$TMP_FILE" #TODO figure out why csmith still generates XORs

#preprocess file
gcc -E -xc - < "$TMP_FILE" > "${FILENAME}.c"
sed "s/#include </TMP_TOKEN/g" < "$TMP_FILE" | gcc -E -xc -DRANDOM_INPUT - | sed "s/TMP_TOKEN/#include </g"  > "${FILENAME}_rnd.c"
	
rm "$TMP_FILE"
