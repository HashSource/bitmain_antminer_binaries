
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void get_asic_nonce_status_super(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char tmp42 [256];
  uint32_t which_pattern;
  uint32_t which_core;
  uint32_t result;
  uint32_t asic_num_per_voltage_domain;
  uint32_t voltage_domain;
  uint32_t pattern_num;
  uint32_t core_num;
  uint32_t asic_num;
  uint32_t total_ntick_nonce;
  uint32_t voltage_domain_received_nonce_number;
  uint32_t how_many_asic_not_receive_all_nonce;
  uint32_t which_voltage_domain;
  uint32_t which_asic;
  uint32_t j;
  uint32_t i;
  
  uVar1 = (g_rt.config)->asics;
  iVar2 = (g_rt.config)->asic_small_cores;
  iVar3 = (g_rt.config)->patter_num;
  uVar4 = (g_rt.config)->domains;
  uVar5 = (g_rt.config)->asics_in_domain;
  j = 0;
  total_ntick_nonce = 0;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  snprintf(tmp42,0x100,"Hashboard require nonce number:                %d\n",uVar1 * iVar2 * iVar3);
  puts(tmp42);
  snprintf(tmp42,0x100,"every voltage domain require nonce number:     %d\n",uVar5 * iVar2 * iVar3);
  puts(tmp42);
  snprintf(tmp42,0x100,"every ASIC require nonce number:               %d\n",iVar2 * iVar3);
  puts(tmp42);
  snprintf(tmp42,0x100,"every CORE require nonce number:               %d\n",iVar3);
  puts(tmp42);
  puts(
      "------------------------------------------------------------------------------------------------------\n"
      );
  puts("super pattern");
  for (which_voltage_domain = 0; which_voltage_domain < uVar4;
      which_voltage_domain = which_voltage_domain + 1) {
    voltage_domain_received_nonce_number = 0;
    for (which_asic = 0; which_asic < uVar5; which_asic = which_asic + 1) {
      voltage_domain_received_nonce_number =
           voltage_domain_received_nonce_number +
           g_rt.asic_stats.every_asic_reg_ntick_nonce_num[which_asic + uVar5 * which_voltage_domain]
      ;
      if ((uint)g_rt.asic_stats.every_asic_reg_ntick_nonce_num
                [which_asic + uVar5 * which_voltage_domain] < (uint)(iVar2 * iVar3)) {
        if ((int)(uint)g_rt.asic_stats.every_asic_reg_ntick_nonce_num
                       [which_asic + uVar5 * which_voltage_domain] <
            (((g_rt.config)->standard).asic_nonce_rate *
            (g_rt.config)->patter_num * (g_rt.config)->asic_small_cores) / 10000) {
          g_rt.asic_stats.bad_asic_list[uVar5 * which_voltage_domain + which_asic] = true;
        }
      }
    }
    total_ntick_nonce = voltage_domain_received_nonce_number + total_ntick_nonce;
  }
  display_PCBA_result(g_rt.asic_stats.every_asic_reg_ntick_nonce_num,(uint8_t)uVar4,(uint8_t)uVar5,
                      false);
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  g_rt.asic_stats.valid_nonce_num = total_ntick_nonce;
  g_rt.stats.nonce_num_chain = total_ntick_nonce;
  builtin_strncpy(tmp42,"bad asic lis",0xc);
  tmp42[0xc] = 't';
  tmp42[0xd] = ':';
  tmp42[0xe] = '\0';
  puts(tmp42);
  for (i = 0; i < uVar1; i = i + 1) {
    if (g_rt.asic_stats.bad_asic_list[i] != false) {
      if (j % 5 == 0) {
        putchar(10);
      }
      printf("asic[%03d]      ",i);
      add_bad_asic_ids(i);
      j = j + 1;
    }
  }
  puts("\n");
  puts(
      "------------------------------------------------------------------------------------------------------\n"
      );
  snprintf(tmp42,0x100,"valid nonce number = %d,      lost nonce number = %d",
           g_rt.asic_stats.valid_nonce_num,iVar3 * iVar2 * uVar1 - g_rt.asic_stats.valid_nonce_num);
  puts(tmp42);
  snprintf(tmp42,0x100,"nonce rate = %f",tmp42,
           (double)((float)g_rt.asic_stats.valid_nonce_num / (float)(iVar3 * iVar2 * uVar1)));
  puts(tmp42);
  return;
}

