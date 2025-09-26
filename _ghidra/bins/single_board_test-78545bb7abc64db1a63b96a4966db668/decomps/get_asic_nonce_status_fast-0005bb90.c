
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void get_asic_nonce_status_fast(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char time_stamp [48];
  char tmp1 [256];
  uint32_t statistics_core_num;
  _Bool temp;
  pattern_work_new *work;
  pattern_work_new *works;
  uint32_t which_pattern;
  uint32_t result;
  uint32_t asic_num_per_voltage_domain;
  uint32_t voltage_domain;
  uint32_t pattern_num;
  uint32_t core_num;
  uint32_t asic_num;
  uint32_t how_many_core_not_receive_all_nonce_per_asic;
  uint32_t voltage_domain_received_nonce_number;
  uint32_t how_many_asic_not_receive_all_nonce;
  uint32_t which_voltage_domain;
  uint32_t which_core;
  uint32_t which_asic;
  uint32_t j;
  uint32_t i;
  
  uVar1 = (g_rt.config)->asics;
  uVar2 = (g_rt.config)->asic_small_cores;
  iVar3 = (g_rt.config)->patter_num;
  uVar4 = (g_rt.config)->domains;
  uVar5 = (g_rt.config)->asics_in_domain;
  j = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : \n------------------------------------------------------------------------------------------------------\n\n"
         ,"get_asic_nonce_status_fast");
  memcpy(tmp1,
         "\n------------------------------------------------------------------------------------------------------\n"
         ,0x69);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Hashboard require nonce number:                %d\n","get_asic_nonce_status_fast",
         uVar1 * uVar2 * iVar3);
  snprintf(tmp1,0x100,"Hashboard require nonce number:                %d",uVar1 * uVar2 * iVar3);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : every voltage domain require nonce number:     %d\n","get_asic_nonce_status_fast",
         uVar5 * uVar2 * iVar3);
  snprintf(tmp1,0x100,"every voltage domain require nonce number:     %d",uVar5 * uVar2 * iVar3);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : every ASIC require nonce number:               %d\n","get_asic_nonce_status_fast",
         uVar2 * iVar3);
  snprintf(tmp1,0x100,"every ASIC require nonce number:               %d",uVar2 * iVar3);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : every CORE require nonce number:               %d\n","get_asic_nonce_status_fast",
         iVar3);
  snprintf(tmp1,0x100,"every CORE require nonce number:               %d",iVar3);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : \n------------------------------------------------------------------------------------------------------\n\n"
         ,"get_asic_nonce_status_fast");
  memcpy(tmp1,
         "\n------------------------------------------------------------------------------------------------------\n"
         ,0x69);
  log_to_file(tmp1,time_stamp);
  for (which_voltage_domain = 0; which_voltage_domain < uVar4;
      which_voltage_domain = which_voltage_domain + 1) {
    for (which_asic = 0; which_asic < uVar5; which_asic = which_asic + 1) {
      g_rt.asic_stats.every_asic_nonce_rate[uVar5 * which_voltage_domain + which_asic] =
           (double)g_rt.asic_stats.every_asic_got_nonce_num
                   [which_asic + uVar5 * which_voltage_domain] /
           (double)(longlong)((g_rt.config)->patter_num * (g_rt.config)->asic_small_cores);
      if ((uint)g_rt.asic_stats.every_asic_got_nonce_num[which_asic + uVar5 * which_voltage_domain]
          < uVar2 * iVar3) {
        for (which_core = 0; which_core < uVar2; which_core = which_core + 1) {
        }
        if ((int)(uint)g_rt.asic_stats.every_asic_got_nonce_num
                       [which_asic + uVar5 * which_voltage_domain] <
            (((g_rt.config)->standard).asic_nonce_rate *
            (g_rt.config)->patter_num * (g_rt.config)->asic_small_cores) / 10000) {
          g_rt.asic_stats.bad_asic_list[uVar5 * which_voltage_domain + which_asic] = true;
        }
      }
    }
  }
  display_PCBA_result(g_rt.asic_stats.every_asic_got_nonce_num,(uint8_t)uVar4,(uint8_t)uVar5,false);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : \n------------------------------------------------------------------------------------------------------\n\n"
         ,"get_asic_nonce_status_fast");
  memcpy(tmp1,
         "\n------------------------------------------------------------------------------------------------------\n"
         ,0x69);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ------------------------------------------------------------------------------------------------------\n\n"
         ,"get_asic_nonce_status_fast");
  memcpy(tmp1,
         "------------------------------------------------------------------------------------------------------\n"
         ,0x68);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : bad asic list:\n","get_asic_nonce_status_fast");
  builtin_strncpy(tmp1,"bad asic lis",0xc);
  tmp1[0xc] = 't';
  tmp1[0xd] = ':';
  tmp1[0xe] = '\0';
  log_to_file(tmp1,time_stamp);
  for (i = 0; i < uVar1; i = i + 1) {
    if (g_rt.asic_stats.bad_asic_list[i] != false) {
      if (j % 5 == 0) {
        putchar(10);
        get_asic_nonce_status_fast::lexical_block_29::tmp1_9[0] = '\n';
        get_asic_nonce_status_fast::lexical_block_29::tmp1_9[1] = '\0';
        log_to_filex(get_asic_nonce_status_fast::lexical_block_29::tmp1_9,tmp1);
      }
      printf("asic[%03d]      ",i);
      snprintf(get_asic_nonce_status_fast::lexical_block_30::tmp1_10,0x100,"asic[%03d]      ",i);
      log_to_filex(get_asic_nonce_status_fast::lexical_block_30::tmp1_10,tmp1);
      add_bad_asic_ids(i);
      j = j + 1;
    }
  }
  putchar(10);
  get_asic_nonce_status_fast::lexical_block_31::tmp1_11[0] = '\n';
  get_asic_nonce_status_fast::lexical_block_31::tmp1_11[1] = '\0';
  log_to_filex(get_asic_nonce_status_fast::lexical_block_31::tmp1_11,tmp1);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : ------------------------------------------------------------------------------------------------------\n\n"
         ,"get_asic_nonce_status_fast");
  memcpy(tmp1,
         "------------------------------------------------------------------------------------------------------\n"
         ,0x68);
  log_to_file(tmp1,time_stamp);
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : valid nonce number = %d,      lost nonce number = %d\n","get_asic_nonce_status_fast",
         g_rt.asic_stats.valid_nonce_num,iVar3 * uVar2 * uVar1 - g_rt.asic_stats.valid_nonce_num);
  snprintf(tmp1,0x100,"valid nonce number = %d,      lost nonce number = %d",
           g_rt.asic_stats.valid_nonce_num,iVar3 * uVar2 * uVar1 - g_rt.asic_stats.valid_nonce_num);
  log_to_file(tmp1,time_stamp);
  return;
}

