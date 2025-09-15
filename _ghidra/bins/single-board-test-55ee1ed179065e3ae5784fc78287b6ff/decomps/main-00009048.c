
int main(void)

{
  char local_4c [64];
  int local_c;
  
  memset(local_4c,0,0x40);
  local_c = cgpu_init();
  if ((-1 < local_c) && (local_c = configMiner(), -1 < local_c)) {
    display_arguments();
    puts("press key to test!");
    do {
      while (local_c = read_key(local_4c), Conf._108_4_ == 1) {
        if ((0 < local_c) && (local_4c[0] == '\x01')) {
          if (Conf._116_4_ == 0x6ba) {
            singleAsicTest_BM1722();
          }
          else if (Conf._116_4_ == 0x6bd) {
            singleAsicTest_BM1725();
          }
          else {
            printf("Single ASIC test: Can\'t find ASIC type!!! AsicType = %d\n",Conf._116_4_);
          }
        }
      }
      if (((0 < local_c) && (local_4c[0] == '\x01')) ||
         ((pattern_test_time < gHowManyVoltageLevel && (pattern_test_time != 0)))) {
        if (gHashBoard_BBD12601 == '\0') {
          if (gHashBoard_BBD25601 == '\0') {
            printf("%s: Please config HashBoard name in Config.ini\n",&__FUNCTION___7462);
          }
          else {
            singleBoardTest_BBD25601();
          }
        }
        else {
          singleBoardTest_BBD12601();
        }
      }
      if (gHowManyVoltageLevel <= pattern_test_time) {
        pattern_test_time = 0;
      }
    } while( true );
  }
  return local_c;
}

