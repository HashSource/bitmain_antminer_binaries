
/* WARNING: Unknown calling convention */

void hash_board_test(void)

{
  do {
    usleep(10000);
    if (gHashBoard_V9 == false) {
      if ((gHashBoard_BHB91601P == false) && (gHashBoard_BHB91601S == false)) {
        if (gHashBoard_BHB91603S == false) {
          if (gHashBoard_BHB07601 == false) {
            printf("%s: Please config HashBoard name in Config.ini\n","hash_board_test");
            pattern_test_time = '\0';
            return;
          }
          singleBoardTest_BHB07601_BM1397();
        }
        else {
          singleBoardTest_BHB91603_BM1391();
        }
      }
      else {
        singleBoardTest_BHB91601_BM1391();
      }
    }
    else {
      singleBoardTest_V9_BM1385_45();
    }
    printf("%s: pattern_test_time %d, gHowManyVoltageLevel %d\n","hash_board_test",
           (uint)pattern_test_time,(uint)gHowManyVoltageLevel);
  } while ((pattern_test_time == '\0' || pattern_test_time <= gHowManyVoltageLevel) &&
           (pattern_test_time != '\0' && gHowManyVoltageLevel != pattern_test_time));
  pattern_test_time = '\0';
  return;
}

