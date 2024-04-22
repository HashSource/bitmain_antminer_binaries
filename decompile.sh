#!/usr/bin/env bash

ghidrecomp ./S9k/cgminer &>./S9k/decompile.log
ghidrecomp ./S9k/poweroff_hashboard &>./S9k/decompile.log

ghidrecomp ./S9SES9KTestJig/bmminer &>./S9SES9KTestJig/decompile.log
ghidrecomp ./S9SES9KTestJig/bitmain_axi.ko &>./S9SES9KTestJig/decompile.log
ghidrecomp ./S9SES9KTestJig/fpga_mem_driver.ko &>./S9SES9KTestJig/decompile.log
ghidrecomp ./S9SES9KTestJig/eeprom_test &>./S9SES9KTestJig/decompile.log

ghidrecomp ./S11/bmminer &>./S11/decompile.log
ghidrecomp ./S11/single-board-test &>./S11/decompile.log

ghidrecomp ./S17e/cgminer &>./S17e/decompile.log

ghidrecomp ./T9+/bmminer &>./T9+/decompile.log

ghidrecomp ./T17e/cgminer &>./T17e/decompile.log

ghidrecomp ./S17pro/single-board-test &>./S17pro/decompile.log

ghidrecomp ./S17/single-board-test &>./S17/decompile.log

ghidrecomp ./DR5/single-board-test &>./DR5/decompile.log
ghidrecomp ./DR5/test_demo &>./DR5/decompile.log

ghidrecomp ./Z9-mini/bm1740-test.exe &>./Z9-mini/decompile.log
ghidrecomp ./Z9-mini/single-board-test &>./Z9-mini/decompile.log
ghidrecomp ./Z9-mini/single-board-test-ok &>./Z9-mini/decompile.log
ghidrecomp ./Z9-mini/single-board-test-default &>./Z9-mini/decompile.log
ghidrecomp ./Z9-mini/test_demo &>./Z9-mini/decompile.log

ghidrecomp ./T17/cgminer &>./T17/decompile.log

ghidrecomp ./Z11/single-board-test &>./Z11/decompile.log
ghidrecomp ./Z11/z11-pcba &>./Z11/decompile.log

ghidrecomp ./Z15/single-board-test &>./Z15/decompile.log
