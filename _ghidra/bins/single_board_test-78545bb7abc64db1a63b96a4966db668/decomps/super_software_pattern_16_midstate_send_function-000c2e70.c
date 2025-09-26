
void * super_software_pattern_16_midstate_send_function(void *arg)

{
  bool bVar1;
  work *pwVar2;
  uchar uVar3;
  uint uVar4;
  uint32_t uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  void *arg_local;
  char time_stamp [48];
  char tmp1 [256];
  work_format work_buf;
  work *work;
  work *works;
  uint32_t *work_ptr;
  uint32_t pattern_num;
  uint32_t small_core_in_big_core;
  uint32_t big_core_num;
  uint32_t small_core_num;
  uint32_t asic_num;
  uint32_t j;
  uint32_t i;
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t which_asic;
  
  uVar5 = (Local_Config_Information->Hash_Board).Small_Core_Num;
  uVar6 = (Local_Config_Information->Hash_Board).Big_Core_Num;
  uVar7 = (Local_Config_Information->Hash_Board).Small_Core_Num_In_Big_Core;
  uVar8 = (Local_Config_Information->Test_Info).Test_Standard.Pattern_Number;
  bVar1 = false;
  while (pwVar2 = pattern_info.works[0], !bVar1) {
    for (which_pattern = 0; which_pattern < uVar8; which_pattern = which_pattern + 1) {
      for (which_core = 0; which_core < uVar6; which_core = which_core + 1) {
        while (uVar3 = is_work_fifo_ready(gChain), uVar3 == '\0') {
          usleep(100);
        }
        memset(&work_buf,0,0x214);
        work_buf.work_type = '\x01';
        work_buf.chain_id = (byte)gChain | 0x80;
        work_buf.reserved1[0] = '\0';
        work_buf.reserved1[1] = '\0';
        uVar4 = which_pattern << 7;
        work_buf.work_count =
             uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | which_pattern << 0x1f
        ;
        for (i = 0; i < 0xc; i = i + 1) {
          work_buf.data[i] = pwVar2[which_core].pattern.data[i];
        }
        for (i = 0; i < uVar7; i = i + 1) {
          for (j = 0; j < 0x20; j = j + 1) {
            work_buf.midstate[i][j] = pwVar2[which_core].pattern.midstate[j];
          }
          gSend_Work_Num = gSend_Work_Num + 1;
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
    bVar1 = true;
  }
  if (uVar5 * uVar8 < gSend_Work_Num || uVar5 * uVar8 - gSend_Work_Num == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Send test %d pattern done\n","super_software_pattern_16_midstate_send_function",
           gSend_Work_Num);
    snprintf(tmp1,0x100,"Send test %d pattern done",gSend_Work_Num);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : Send work num : %d, less than %d\n",
           "super_software_pattern_16_midstate_send_function",gSend_Work_Num,uVar5 * uVar8);
    snprintf(tmp1,0x100,"Send work num : %d, less than %d",gSend_Work_Num,uVar5 * uVar8);
    log_to_file(tmp1,time_stamp);
  }
  usleep(400000);
  return (void *)0x0;
}

