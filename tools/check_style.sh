#!/usr/bin/env sh

FILE_NAMES=$(find src -name \*.h -print -o -name \*.cpp -print  -o -name \*.cc -print)


check_style() {
        clang-format -style=file $1 | diff $1 -
}

fix_style() {
        clang-format -style=file -i $1
}

if [ "$1" = "--fix" ]
then
  for FILE_NAME in $FILE_NAMES; do fix_style $FILE_NAME; done
else
  for FILE_NAME in $FILE_NAMES; do check_style $FILE_NAME; done
fi

