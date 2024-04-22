
undefined4 singleBoardTest_V9_BM1740(void)

{
  if (inited == 0) {
    fl = fopen("/tmp/bm1740.log","w+");
    if (fl == (FILE *)0x0) {
      puts("open log file error");
      return 0;
    }
    bm1740_app_init();
  }
  bm1740_app_test_manual();
  return 1;
}

