#!/bin/bash

PROG=Subset
ARG=
echo "1. Should error when no arguments are given: ${ARG}"
./${PROG} ${ARG}
echo ""
ARG='1 2 3'
echo "2. Should error when more arguments are given: ${ARG}"
./${PROG} ${ARG}
echo ""
ARG=1
echo "3. Should error when less arguments are given: ${ARG}"
./${PROG} ${ARG} 
echo ""
ARG='foo bar'
echo "4. Should error when alpha arguments are given: ${ARG}"
./${PROG} ${ARG} 
echo ""
ARG='1.234 120.123'
echo "5. Should error when non-integer arguments are given: ${ARG}"
./${PROG} ${ARG} 
echo ""
ARG='2 5'
echo "6. Should error when not Binomial Coefficients: ${ARG}"
./${PROG} ${ARG} 
echo ""
ARG='5 3'
echo "7. Works as intended: ${ARG}"
./${PROG} ${ARG} 
