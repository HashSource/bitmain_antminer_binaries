
/* WARNING: Unknown calling convention */

void read_clock_delay_control(void)

{
  core_cmd core;
  int i;
  
  core.chain = '\0';
  core.chip_addr = '\0';
  core.mode = '\0';
  core.core_mode = '\x01';
  core.reg_data = 0xff;
  core.core_id = '\0';
  core.cmd_type = '\0';
  core.rw_falg = '\0';
  core.reserved = '\0';
  for (i = 0; i < 0x10; i = i + 1) {
    if ((dev->chain_exist[i] == 1) && (dev->chain_asic_num[i] != '\0')) {
      core.chain = (uchar)i;
      set_core_cmd_BM1393(&core);
      check_core_register = 0;
      check_asic_reg_with_addr(0x40,'\0',i,0xd0);
    }
  }
  return;
}

