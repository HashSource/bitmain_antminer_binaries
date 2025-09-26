
void * software_pattern_16_midstate_send_function(void *arg)

{
  uchar uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  work_new *pwVar7;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [2048];
  work_format work_buf;
  work_new *works;
  uint32_t send_counter;
  uint32_t position;
  uint32_t *work_ptr;
  uint32_t pattern_num;
  uint32_t small_core_in_big_core;
  uint32_t core_num;
  uint32_t asic_num;
  uint32_t count;
  uint32_t received_nonce_num;
  uint32_t j;
  uint32_t i;
  work_new *work;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  uVar3 = (Local_Config_Information->Hash_Board).Asic_Num;
  uVar4 = (Local_Config_Information->Hash_Board).Small_Core_Num;
  uVar5 = (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core;
  uVar6 = (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
  count = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: asic_num:%d,core_num:%d,small_core_in_big_core:%d,pattern:%d.\n",
         "software_pattern_16_midstate_send_function",uVar3,uVar4,uVar5,uVar6);
  snprintf(tmp1,0x800,"asic_num:%d,core_num:%d,small_core_in_big_core:%d,pattern:%d.",uVar3,uVar4,
           uVar5,uVar6);
  log_to_file(tmp1,time_stamp);
  for (which_asic = 0; which_asic < uVar3; which_asic = which_asic + 1) {
    pwVar7 = pattern_info_new.works[which_asic];
    for (which_core = 0; which_core < uVar4; which_core = uVar5 + which_core) {
      for (which_pattern = 0; which_pattern < uVar6; which_pattern = which_pattern + 1) {
        while (uVar1 = is_work_fifo_ready(gChain), uVar1 == '\0') {
          usleep(100);
        }
        memset(&work_buf,0,0x214);
        work_buf.work_type = '\x01';
        work_buf.chain_id = (byte)gChain | 0x80;
        work_buf.reserved1[0] = '\0';
        work_buf.reserved1[1] = '\0';
        uVar2 = which_pattern << 7;
        work_buf.work_count =
             uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | which_pattern << 0x1f
        ;
        work = pwVar7 + which_pattern + uVar6 * which_core;
        for (i = 0; i < 0xc; i = i + 1) {
          work_buf.data[i] = '\0';
        }
        for (i = 0; i < uVar5; i = i + 1) {
          if (((which_core - 0x7f0 < 0x10) || (which_core - 0xf0 < 0x10)) && (0xc < i)) {
            for (j = 0; j < 0x20; j = j + 1) {
              if (j < 0x18) {
                work_buf.midstate[i][j] = '\0';
              }
              else {
                work_buf.midstate[i][j] = (char)i + *(char *)((int)(&work->pattern + -2) + j);
              }
            }
          }
          else {
            work = pwVar7 + which_pattern + uVar6 * (i + which_core);
            for (j = 0; j < 0x20; j = j + 1) {
              if (j < 0x18) {
                work_buf.midstate[i][j] = '\0';
              }
              else {
                work_buf.midstate[i][j] = *(uint8_t *)((int)(&work->pattern + -2) + j);
              }
            }
            gSend_Work_Num = gSend_Work_Num + 1;
          }
        }
        for (i = 0; i < 0x85; i = i + 1) {
          *(uint *)(work_buf.reserved1 + i * 4 + -2) =
               *(int *)(work_buf.reserved1 + i * 4 + -2) << 0x18 |
               *(uint *)(work_buf.reserved1 + i * 4 + -2) >> 0x18 |
               (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff0000) >> 8 |
               (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff00) << 8;
        }
        set_TW_write_command((uint32_t *)&work_buf,0x214);
      }
    }
  }
  uVar5 = uVar3 * uVar4 * uVar6;
  if (uVar5 < gSend_Work_Num || uVar5 - gSend_Work_Num == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Send test %d pattern done\n","software_pattern_16_midstate_send_function",
           gSend_Work_Num);
    snprintf(tmp1,0x800,"Send test %d pattern done",gSend_Work_Num);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Send work num : %d, less than %d\n","software_pattern_16_midstate_send_function",
           gSend_Work_Num,uVar3 * uVar4 * uVar6);
    snprintf(tmp1,0x800,"Send work num : %d, less than %d",gSend_Work_Num,uVar3 * uVar4 * uVar6);
    log_to_file(tmp1,time_stamp);
  }
  received_nonce_num = gHistory_Result[gPattern_test_counter].valid_nonce_num;
  while( true ) {
    while (gHistory_Result[gPattern_test_counter].valid_nonce_num != received_nonce_num) {
      count = 0;
      received_nonce_num = gHistory_Result[gPattern_test_counter].valid_nonce_num;
      usleep(200000);
    }
    count = count + 1;
    if (2 < count) break;
    usleep(200000);
  }
  usleep(10000000);
  gStart_receive = false;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Stop receive thread\n","software_pattern_16_midstate_send_function");
  builtin_strncpy(tmp1,"Stop receive thread",0x14);
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}

