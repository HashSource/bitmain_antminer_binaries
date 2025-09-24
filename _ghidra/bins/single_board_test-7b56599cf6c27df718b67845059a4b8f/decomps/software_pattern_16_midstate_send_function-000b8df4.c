
void * software_pattern_16_midstate_send_function(void *arg)

{
  uchar uVar1;
  _Bool _Var2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  work_new *pwVar8;
  uint32_t uVar9;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  work_format work_buf;
  int received_nonce_num;
  int received_nonce_num_1;
  work_new *works;
  uint32_t send_counter;
  uint32_t position;
  uint32_t count;
  uint32_t *work_ptr;
  uint32_t pattern_num;
  uint32_t small_core_in_big_core;
  uint32_t core_num;
  uint32_t asic_num;
  uint32_t j;
  uint32_t i;
  work_new *work;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  uVar4 = (Local_Config_Information->Hash_Board).Asic_Num;
  uVar5 = (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core *
          (Local_Config_Information->Hash_Board).Big_Core_Num;
  uVar6 = (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core;
  uVar7 = (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
  err_nonce_resp = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : asic_num:%d,core_num:%d,small_core_in_big_core:%d,pattern:%d.\n",
         "software_pattern_16_midstate_send_function",uVar4,uVar5,uVar6,uVar7);
  snprintf(tmp1,0x100,"asic_num:%d,core_num:%d,small_core_in_big_core:%d,pattern:%d.",uVar4,uVar5,
           uVar6,uVar7);
  log_to_file(tmp1,time_stamp);
  for (which_asic = 0; which_asic < uVar4; which_asic = which_asic + 1) {
    pwVar8 = pattern_info_new.works[which_asic];
    for (which_core = 0; which_core < uVar5; which_core = uVar6 + which_core) {
      for (which_pattern = 0; which_pattern < uVar7; which_pattern = which_pattern + 1) {
        while (uVar1 = is_work_fifo_ready(gChain), uVar1 == '\0') {
          usleep(100);
        }
        memset(&work_buf,0,0x214);
        work_buf.work_type = '\x01';
        work_buf.chain_id = (byte)gChain | 0x80;
        work_buf.reserved1[0] = '\0';
        work_buf.reserved1[1] = '\0';
        uVar3 = which_pattern << 7;
        work_buf.work_count =
             uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | which_pattern << 0x1f
        ;
        work = pwVar8 + which_pattern + uVar7 * which_core;
        for (i = 0; i < 0xc; i = i + 1) {
          work_buf.data[i] = '\0';
        }
        for (i = 0; i < uVar6; i = i + 1) {
          if ((which_core < 0x4f0) || (3 < i)) {
            work = pwVar8 + which_pattern + uVar7 * (i + which_core);
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
          else {
            for (j = 0; j < 0x20; j = j + 1) {
              if (j < 0x18) {
                work_buf.midstate[i][j] = '\0';
              }
              else {
                work_buf.midstate[i][j] = (char)i + *(char *)((int)(&work->pattern + -2) + j);
              }
            }
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
    uVar9 = gHistory_Result[gPattern_test_counter].valid_nonce_num;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : asic[%d],acc send nonce:%d,received:%d\n",
           "software_pattern_16_midstate_send_function",which_asic,gSend_Work_Num,uVar9);
    snprintf(tmp1,0x100,"asic[%d],acc send nonce:%d,received:%d",which_asic,gSend_Work_Num,uVar9);
    log_to_file(tmp1,time_stamp);
  }
  _Var2 = read_temp_from_asic_once(false);
  if (!_Var2) {
    err_exit("asic temp outof range");
  }
  _Var2 = read_chain_domain_voltage(false);
  if (!_Var2) {
    err_exit("asic vol outof range");
  }
  uVar6 = uVar4 * uVar7 * (Local_Config_Information->Hash_Board).Small_Core_Num;
  if (uVar6 < gSend_Work_Num || uVar6 - gSend_Work_Num == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Send test %d pattern done\n","software_pattern_16_midstate_send_function",
           gSend_Work_Num);
    snprintf(tmp1,0x100,"Send test %d pattern done",gSend_Work_Num);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Send work num : %d, less than %d\n","software_pattern_16_midstate_send_function",
           gSend_Work_Num,uVar4 * uVar5 * uVar7);
    snprintf(tmp1,0x100,"Send work num : %d, less than %d",gSend_Work_Num,uVar4 * uVar5 * uVar7);
    log_to_file(tmp1,time_stamp);
  }
  sleep(2);
  uVar9 = gHistory_Result[gPattern_test_counter].valid_nonce_num;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : asic[%d],acc send nonce:%d,received:%d\n",
         "software_pattern_16_midstate_send_function",which_asic,gSend_Work_Num,uVar9);
  snprintf(tmp1,0x100,"asic[%d],acc send nonce:%d,received:%d",which_asic,gSend_Work_Num,uVar9);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : err_nonce_resp:%d\n","software_pattern_16_midstate_send_function",err_nonce_resp);
  snprintf(tmp1,0x100,"err_nonce_resp:%d",err_nonce_resp);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Stop receive thread\n","software_pattern_16_midstate_send_function");
  builtin_strncpy(tmp1,"Stop receive thread",0x14);
  log_to_file(tmp1,time_stamp);
  gStart_receive = false;
  return (void *)0x0;
}

