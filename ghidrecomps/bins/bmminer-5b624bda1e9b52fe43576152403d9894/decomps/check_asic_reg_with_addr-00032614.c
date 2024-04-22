
/* WARNING: Unknown calling convention */

uint check_asic_reg_with_addr(uint reg,uint chip_addr,uint chain,int check_num)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int i;
  uint uVar4;
  uint uVar5;
  reg_buf *prVar6;
  int local_82c;
  char tmp42 [2048];
  
  iVar1 = DAT_00032798;
  local_82c = 0;
  clear_register_value_buf();
  read_asic_register((uchar)chain,'\0',(uchar)chip_addr,(uchar)reg);
  pcVar3 = DAT_000327b0;
  pcVar2 = DAT_000327ac;
  cgsleep_ms(0x50);
  do {
    while( true ) {
      pthread_mutex_lock(DAT_0003279c);
      uVar4 = *(uint *)(iVar1 + 8);
      pthread_mutex_unlock(DAT_0003279c);
      if ((*pcVar2 != '\0') &&
         (((*pcVar3 != '\0' || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,DAT_000327a0,DAT_000327a4,uVar4);
        _applog(7,tmp42,false);
      }
      if (((uVar4 < 0x1ff) && (*(uint *)(iVar1 + 4) < 0x1ff)) && (uVar4 != 0)) break;
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
    pthread_mutex_lock(DAT_0003279c);
    do {
      chain = chain + 1;
      prVar6 = (reg_buf *)(iVar1 + (*(int *)(iVar1 + 4) + 1) * 8);
      uVar5 = prVar6->p_rd;
      if ((*pcVar2 != '\0') &&
         (((*pcVar3 != '\0' || (opt_log_output != false)) ||
          (prVar6 = (reg_buf *)&opt_log_level, 6 < opt_log_level)))) {
        snprintf(tmp42,0x800,DAT_000327a8,DAT_000327a4,chip_addr,reg,uVar5);
        prVar6 = (reg_buf *)0x32749;
        _applog(7,tmp42,false);
      }
      *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
      if (*(uint *)(iVar1 + 4) < 0x1ff) {
        prVar6 = &reg_value_buf;
      }
      if (*(uint *)(iVar1 + 4) < 0x1ff) {
        prVar6->p_rd = 0;
      }
      if (reg == 0x20) {
        if ((uVar5 & 0xc0000000) != 0) {
          uVar5 = 0;
        }
        pthread_mutex_unlock(DAT_0003279c);
        clear_register_value_buf();
        return uVar5;
      }
    } while (chain != uVar4);
    pthread_mutex_unlock(DAT_0003279c);
  } while( true );
}

