
/* WARNING: Unknown calling convention */

void read_clock_delay_control_single_core(void)

{
  core_cmd core;
  int i;
  
  core.core_id = 0;
  is_reading_core_reg = true;
  core.chain = '\0';
  core.chip_addr = '\0';
  core.mode = '\0';
  core.core_mode = '\0';
  core._12_4_ = 0;
  core._8_4_ = 0xff000000;
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      clear_register_value_buf();
      core.core_id = 0;
      core.chain = (uchar)i;
      set_core_cmd_BM1391(&core);
      check_asic_reg_without_read(0x40,'\0','\0',i,1);
    }
  }
  is_reading_core_reg = false;
  return;
}

