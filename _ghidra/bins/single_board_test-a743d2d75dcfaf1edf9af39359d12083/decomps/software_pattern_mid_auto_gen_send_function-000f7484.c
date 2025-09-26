
void * software_pattern_mid_auto_gen_send_function(void *arg)

{
  byte bVar1;
  uchar uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  work *pwVar7;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [2048];
  mid_auto_gen_work_format work_buf;
  work *work;
  work *works;
  uint32_t position;
  uint32_t j;
  uint32_t *work_ptr;
  uint32_t pattern_num;
  uint32_t core_num;
  uint32_t asic_num;
  uint32_t count;
  uint32_t received_nonce_num;
  uint32_t i;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  uVar4 = (Local_Config_Information->Hash_Board).Asic_Num;
  uVar5 = (Local_Config_Information->Hash_Board).Small_Core_Num;
  uVar6 = (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
  count = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s:  \n","software_pattern_mid_auto_gen_send_function");
  tmp1[0] = ' ';
  tmp1[1] = '\0';
  log_to_file(tmp1,time_stamp);
  for (which_asic = 0; which_asic < uVar4; which_asic = which_asic + 1) {
    pwVar7 = pattern_info.works[which_asic];
    for (which_core = 0; which_core < uVar5; which_core = which_core + 1) {
      for (which_pattern = 0; which_pattern < uVar6; which_pattern = which_pattern + 1) {
        while (uVar2 = is_work_fifo_ready(gChain), uVar2 == '\0') {
          usleep(100);
        }
        memset(&work_buf,0,0x54);
        work_buf.work_type = '\x01';
        bVar1 = (byte)gChain;
        work_buf.reserved1[0] = '\0';
        work_buf.reserved1[1] = '\0';
        uVar3 = which_pattern << 7;
        pwVar7[which_pattern + uVar6 * which_core].id = (uint16_t)uVar3;
        for (i = 0; i < 0xc; i = i + 1) {
          work_buf.data[i] = pwVar7[which_pattern + uVar6 * which_core].pattern.data[i];
        }
        for (i = 0; i < 0x40; i = i + 1) {
        }
        for (i = 0; i < 0x15; i = i + 1) {
          *(uint *)(work_buf.reserved1 + i * 4 + -2) =
               *(int *)(work_buf.reserved1 + i * 4 + -2) << 0x18 |
               *(uint *)(work_buf.reserved1 + i * 4 + -2) >> 0x18 |
               (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff0000) >> 8 |
               (*(uint *)(work_buf.reserved1 + i * 4 + -2) & 0xff00) << 8;
        }
        work_buf.chunk[0x3e] = '\0';
        work_buf.chain_id = bVar1 | 0x80;
        work_buf.work_count =
             which_pattern << 0x1f | uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8
        ;
        set_TW_write_command((uint32_t *)&work_buf,0x54);
        gSend_Work_Num = gSend_Work_Num + 1;
      }
    }
  }
  while (uVar3 = uVar4 * uVar5 * uVar6, gSend_Work_Num <= uVar3 && uVar3 - gSend_Work_Num != 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: Send work num : %d, less than %d\n","software_pattern_mid_auto_gen_send_function",
           gSend_Work_Num,uVar4 * uVar5 * uVar6);
    snprintf(tmp1,0x800,"Send work num : %d, less than %d",gSend_Work_Num,uVar4 * uVar5 * uVar6);
    log_to_file(tmp1,time_stamp);
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Send test %d pattern done\n","software_pattern_mid_auto_gen_send_function",
         gSend_Work_Num);
  snprintf(tmp1,0x800,"Send test %d pattern done",gSend_Work_Num);
  log_to_file(tmp1,time_stamp);
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
  gStart_receive = false;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Stop receive thread\n","software_pattern_mid_auto_gen_send_function");
  builtin_strncpy(tmp1,"Stop receive thread",0x14);
  log_to_file(tmp1,time_stamp);
  return (void *)0x0;
}

