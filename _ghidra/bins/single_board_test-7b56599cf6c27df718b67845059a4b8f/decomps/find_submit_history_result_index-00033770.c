
uint8_t find_submit_history_result_index(uint8_t *history_result_index)

{
  uint8_t uVar1;
  uint8_t *history_result_index_local;
  char time_stamp [48];
  char tmp1 [256];
  uint8_t i;
  
  if ((uint)gPattern_test_counter < gTest_loop - 1) {
    if (gHistory_Result[gPattern_test_counter].test_standard == '\0') {
      *history_result_index = gPattern_test_counter;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : find history result index: %d, and it is STRICT_STANDARD\n",
             "find_submit_history_result_index",(uint)*history_result_index);
      snprintf(tmp1,0x100,"find history result index: %d, and it is STRICT_STANDARD",
               (uint)*history_result_index);
      log_to_file(tmp1,time_stamp);
      uVar1 = '\0';
    }
    else {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : Not find history result index, and go on testing. gPattern_test_counter = %d\n",
             "find_submit_history_result_index",(uint)gPattern_test_counter);
      snprintf(tmp1,0x100,
               "Not find history result index, and go on testing. gPattern_test_counter = %d",
               (uint)gPattern_test_counter);
      log_to_file(tmp1,time_stamp);
      uVar1 = '\x02';
    }
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : We had do %d tests, and strict standard are not ok\n",
           "find_submit_history_result_index",gPattern_test_counter + 1);
    snprintf(tmp1,0x100,"We had do %d tests, and strict standard are not ok",
             gPattern_test_counter + 1);
    log_to_file(tmp1,time_stamp);
    for (i = '\0'; i < gTest_loop; i = i + '\x01') {
      if (gHistory_Result[i].test_standard == '\x01') {
        *history_result_index = i;
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s : find history result index: %d, and it is LOOSE_STANDARD\n",
               "find_submit_history_result_index",(uint)*history_result_index);
        snprintf(tmp1,0x100,"find history result index: %d, and it is LOOSE_STANDARD",
                 (uint)*history_result_index);
        log_to_file(tmp1,time_stamp);
        return '\0';
      }
    }
    *history_result_index = gPattern_test_counter;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : find history result index: %d, and this time pattern test fail\n",
           "find_submit_history_result_index",(uint)*history_result_index);
    snprintf(tmp1,0x100,"find history result index: %d, and this time pattern test fail",
             (uint)*history_result_index);
    log_to_file(tmp1,time_stamp);
    uVar1 = '\x01';
  }
  return uVar1;
}

