#!/usr/bin/bash

# S21+
redress gomod \
    S21+/single_board_test >S21+/single_board_test.gomod.txt
redress info \
    S21+/single_board_test >S21+/single_board_test.info.txt
redress moduledata \
    S21+/single_board_test >S21+/single_board_test.moduledata.txt
redress packages \
    S21+/single_board_test >S21+/single_board_test.packages.txt
redress source \
    S21+/single_board_test >S21+/single_board_test.source.txt
redress types all \
    S21+/single_board_test >S21+/single_board_test.types.txt

# S21pro
redress gomod \
    S21pro/single_board_test >S21pro/single_board_test.gomod.txt
redress info \
    S21pro/single_board_test >S21pro/single_board_test.info.txt
redress moduledata \
    S21pro/single_board_test >S21pro/single_board_test.moduledata.txt
redress packages \
    S21pro/single_board_test >S21pro/single_board_test.packages.txt
redress source \
    S21pro/single_board_test >S21pro/single_board_test.source.txt
redress types all \
    S21pro/single_board_test >S21pro/single_board_test.types.txt
