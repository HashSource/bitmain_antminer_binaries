
int main(void)

{
  char local_50 [64];
  ssize_t local_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  memset(local_50,0,0x40);
  local_10 = cgpu_init();
  if ((-1 < local_10) && (local_10 = configMiner(), -1 < local_10)) {
    run_status = 0;
    display_arguments();
    do {
      while( true ) {
        lseek(key_fd,0,0);
        local_10 = read(key_fd,local_50,0x40);
        if (Conf._108_4_ != 1) break;
        if ((0 < local_10) && (local_50[0] == '0')) {
          if (Conf._116_4_ == 0x569) {
            puts("\nBegin singleAsicTest_BM1385\n");
            singleAsicTest_BM1385();
          }
          else {
            printf("Single ASIC test: Can\'t find ASIC type!!! AsicType = %d\n",Conf._116_4_);
          }
        }
      }
      if (((0 < local_10) && (local_50[0] == '0')) ||
         ((pattern_test_time < gHowManyVoltageLevel && (pattern_test_time != 0)))) {
        usleep(10000);
        if (gHashBoard_V9 == '\0') {
          printf("%s: Please config HashBoard name in Config.ini\n",&__FUNCTION___7415);
        }
        else {
          singleBoardTest_V9_BM1385_45();
        }
      }
      if (gHowManyVoltageLevel <= pattern_test_time) {
        pattern_test_time = 0;
      }
    } while( true );
  }
  return local_10;
}

