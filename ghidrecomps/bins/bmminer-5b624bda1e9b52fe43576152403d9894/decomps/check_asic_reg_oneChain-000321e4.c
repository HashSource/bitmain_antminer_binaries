
/* WARNING: Unknown calling convention */

_Bool check_asic_reg_oneChain(int chainIndex,uint reg)

{
  _Bool _Var1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  undefined1 display;
  undefined4 in_stack_fffff794;
  char (*buf) [32];
  int local_854;
  uint local_850;
  int iStack_84c;
  uint local_848;
  uchar reg_buf [5];
  uchar rate_buf [10];
  char tmp42 [2048];
  
  iVar5 = 0;
  reg_buf[0] = '\0';
  reg_buf[1] = '\0';
  reg_buf[2] = '\0';
  reg_buf[3] = '\0';
  reg_buf[4] = '\0';
  while( true ) {
    clear_register_value_buf();
    if (dev->chain_exist[chainIndex] != 1) {
      return true;
    }
    read_asic_register((uchar)chainIndex,'\x01','\0',(uchar)reg);
    display = (undefined1)in_stack_fffff794;
    if (reg == 0) {
      dev->chain_asic_num[chainIndex] = (uchar)reg;
    }
    if (2 < iVar5) break;
    local_854 = 0;
    local_850 = 0;
    iStack_84c = 0;
    local_848 = 0;
    while( true ) {
      cgsleep_ms(300);
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar4 = reg_value_buf.reg_value_num;
      if ((0x1fe < reg_value_buf.reg_value_num) || (0x1fe < reg_value_buf.p_rd)) break;
      if (reg_value_buf.reg_value_num == 0) {
        iVar5 = iVar5 + 1;
        cgsleep_ms(100);
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        display = (undefined1)in_stack_fffff794;
        if (iVar5 == 3) goto LAB_000324c8;
      }
      else {
        local_854 = local_854 + reg_value_buf.reg_value_num;
        if (600 < local_854) {
          pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
          return false;
        }
        uVar6 = 0;
        do {
          while (uVar3 = reg_value_buf.p_rd + 1,
                chainIndex != (uint)reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number) {
            reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
            reg_value_buf.p_rd = uVar3;
            if (0x1fe < uVar3) {
              reg_value_buf.p_rd = 0;
            }
LAB_000322c8:
            uVar6 = uVar6 + 1;
            if (uVar6 == uVar4) goto LAB_00032352;
          }
          reg_buf[3] = (uchar)reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
          reg_buf[2] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 8);
          reg_buf[1] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x10);
          uVar3 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
          reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
          uVar2 = uVar3 >> 0x18;
          reg_buf[0] = (uchar)(uVar3 >> 0x18);
          reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
          if (0x1fe < reg_value_buf.p_rd) {
            reg_value_buf.p_rd = 0;
          }
          if (reg != 0) {
            if (reg == 0xc) {
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"%s: the asic freq is 0x%x\n","check_asic_reg_oneChain",
                         reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value);
                _applog(7,tmp42,false);
              }
            }
            else if (reg == 8) {
              iVar5 = 0;
              while( true ) {
                sprintf((char *)(rate_buf + iVar5 * 2),"%02x",uVar2);
                if (iVar5 + 1 == 4) break;
                uVar2 = (uint)reg_buf[iVar5 + 1];
                iVar5 = iVar5 + 1;
              }
              if ((opt_debug != false) &&
                 (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
                snprintf(tmp42,0x800,"%s: hashrate is %s\n","check_asic_reg_oneChain",rate_buf);
                _applog(7,tmp42,false);
              }
              local_848 = local_848 + 1;
              uVar3 = strtol((char *)rate_buf,(char **)0x0,0x10);
              bVar7 = CARRY4(local_850,uVar3 * 0x1000000);
              local_850 = local_850 + uVar3 * 0x1000000;
              iStack_84c = iStack_84c + (((int)uVar3 >> 0x1f) << 0x18 | uVar3 >> 8) + (uint)bVar7;
            }
            goto LAB_000322c8;
          }
          uVar6 = uVar6 + 1;
          dev->chain_asic_num[chainIndex] = dev->chain_asic_num[chainIndex] + '\x01';
        } while (uVar6 != uVar4);
LAB_00032352:
        display = (undefined1)in_stack_fffff794;
        if ((reg == 0) && (dev->chain_asic_num[chainIndex] == '\x12')) {
          pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
          goto LAB_0003253c;
        }
        iVar5 = 0;
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      }
    }
    iVar5 = iVar5 + 1;
    pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
  }
  local_850 = 0;
  iStack_84c = 0;
  local_848 = 0;
LAB_000324c8:
  if (reg == 0) {
LAB_0003253c:
    uVar4 = (uint)dev->chain_asic_num[chainIndex];
    if (dev->max_asic_num_in_one_chain < uVar4) {
      dev->max_asic_num_in_one_chain = dev->chain_asic_num[chainIndex];
    }
  }
  else {
    uVar4 = (uint)dev->chain_asic_num[chainIndex];
  }
  if (uVar4 == local_848) {
    buf = displayed_rate + chainIndex;
    *(uint *)(rate + chainIndex) = local_850;
    *(int *)((int)rate + chainIndex * 8 + 4) = iStack_84c;
    suffix_string_c5(CONCAT44(iStack_84c,local_850),*buf,0x20,6,(_Bool)display);
    _Var1 = opt_debug;
    rate_error[chainIndex] = 0;
    if ((_Var1 != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: chain %d hashrate is %s\n","check_asic_reg_oneChain",chainIndex);
      display = SUB41(buf,0);
      _applog(7,tmp42,false);
    }
  }
  if (((local_848 == 0) || (status_error != false)) &&
     ((iVar5 = rate_error[chainIndex], rate_error[chainIndex] = iVar5 + 1, 3 < iVar5 + 1 ||
      (status_error != false)))) {
    *(undefined4 *)(rate + chainIndex) = 0;
    *(undefined4 *)((int)rate + chainIndex * 8 + 4) = 0;
    suffix_string_c5(0,displayed_rate[chainIndex],0x20,6,(_Bool)display);
  }
  clear_register_value_buf();
  return true;
}

