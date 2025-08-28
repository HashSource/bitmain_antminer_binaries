
/* WARNING: Unknown calling convention */

uint check_asic_reg_with_addr(uint reg,uint chip_addr,uint chain,int check_num)

{
  uint uVar1;
  uint uVar2;
  reg_buf *prVar3;
  int local_82c;
  char tmp42 [2048];
  
  local_82c = 0;
  clear_register_value_buf();
  read_asic_register((uchar)chain,'\0',(uchar)chip_addr,(uchar)reg);
  cgsleep_ms(0x50);
  do {
    while( true ) {
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar1 = reg_value_buf.reg_value_num;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: reg_value_num %d","check_asic_reg_with_addr",uVar1);
        _applog(7,tmp42,false);
      }
      if (((uVar1 < 0x1ff) && (reg_value_buf.p_rd < 0x1ff)) && (uVar1 != 0)) break;
      clear_register_value_buf();
      local_82c = local_82c + 1;
      read_asic_register((uchar)chain,'\0',(uchar)chip_addr,(uchar)reg);
      cgsleep_ms(0x50);
      if (local_82c == 5) {
        clear_register_value_buf();
        return 0;
      }
    }
    chain = 0;
    pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
    do {
      chain = chain + 1;
      prVar3 = (reg_buf *)&reg_value_buf.reg_buffer[reg_value_buf.p_rd - 1].crc;
      uVar2 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) ||
          (prVar3 = (reg_buf *)&opt_log_level, 6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: chip %x reg %x reg_buff %x","check_asic_reg_with_addr",chip_addr,
                 reg,uVar2);
        prVar3 = (reg_buf *)0x32749;
        _applog(7,tmp42,false);
      }
      reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
      reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
      if (reg_value_buf.p_rd < 0x1ff) {
        prVar3 = &reg_value_buf;
      }
      if (reg_value_buf.p_rd < 0x1ff) {
        prVar3->p_rd = 0;
      }
      if (reg == 0x20) {
        if ((uVar2 & 0xc0000000) != 0) {
          uVar2 = 0;
        }
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        clear_register_value_buf();
        return uVar2;
      }
    } while (chain != uVar1);
    pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
  } while( true );
}

