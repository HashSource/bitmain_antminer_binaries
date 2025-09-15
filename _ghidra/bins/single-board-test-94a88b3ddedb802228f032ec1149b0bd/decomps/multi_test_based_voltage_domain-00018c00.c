
void multi_test_based_voltage_domain(void)

{
  bool bVar1;
  int iVar2;
  FILE *pFVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  bVar1 = true;
  g_is_low_power_hashrate_scan = 0;
  quickly_set_to_working_voltage();
  sleep(1);
  get_avg_voltage();
  single_board_test_based_voltage_domain();
  iVar2 = GetTotalRate();
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d: total ideal hash rate is: %d\n","board_frq_tuning.c",0x87e,iVar2);
    }
    fclose(pFVar3);
  }
  local_20 = 0;
  uStack_1c = 0;
  if (iVar2 < 0x4844) {
    local_20 = 0x33333333;
    uStack_1c = 0x4025b333;
  }
  else if (iVar2 < 0x4c2c) {
    local_20 = 0;
    uStack_1c = 0x40258000;
  }
  else if (iVar2 < 20000) {
    local_20 = 0xcccccccd;
    uStack_1c = 0x40254ccc;
  }
  else if (iVar2 < 0x5014) {
    local_20 = 0x9999999a;
    uStack_1c = 0x40251999;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (3 < log_level) {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d: hash low, using voltage %f to scan again...\n","board_frq_tuning.c",
                0x898,local_20,uStack_1c);
      }
      fclose(pFVar3);
    }
    set_fixed_voltage(local_20);
    set_iic_power_to_working_voltage();
    sleep(1);
    get_avg_voltage();
    single_board_test_based_voltage_domain();
    uVar4 = GetTotalRate();
    if (3 < log_level) {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d: total ideal hash rate is: %d\n","board_frq_tuning.c",0x8a5,uVar4);
      }
      fclose(pFVar3);
    }
  }
  iVar2 = is_S11();
  if (iVar2 != 0) {
    if (3 < log_level) {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d: scan for low power mode\n","board_frq_tuning.c",0x8af);
      }
      fclose(pFVar3);
    }
    set_fixed_voltage(0);
    set_iic_power_to_working_voltage();
    sleep(1);
    get_avg_voltage();
    g_is_low_power_hashrate_scan = 1;
    single_board_test_based_voltage_domain();
  }
  return;
}

