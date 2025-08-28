
/* WARNING: Unknown calling convention */

_Bool check_asic_reg(uint reg)

{
  char *__format;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  double dVar9;
  undefined1 in_stack_fffffe6c;
  int local_180;
  uint local_17c;
  int local_178;
  uint64_t *local_174;
  uint local_170;
  int iStack_16c;
  uchar reg_buf [5];
  uchar rate_buf [10];
  char displayed_rate_asic [32];
  char logstr [256];
  
  iVar4 = 0;
  reg_buf[0] = '\0';
  reg_buf[1] = '\0';
  reg_buf[2] = '\0';
  reg_buf[3] = '\0';
  reg_buf[4] = '\0';
LAB_00033078:
  local_178 = 0;
  uVar7 = 0;
  local_174 = rate;
  clear_register_value_buf();
  do {
    if (dev->chain_exist[uVar7] == 1) {
      read_asic_register((uchar)uVar7,'\x01','\0',(uchar)reg);
      if (reg == 0) {
        dev->chain_asic_num[uVar7] = (uchar)reg;
      }
      else if (reg == 8) {
        sprintf(logstr,"\nget RT hashrate from Chain[%d]: (asic index start from 1-%d)\n",uVar7,0x12
               );
        writeLogFile(logstr);
      }
      if (iVar4 < 3) {
        local_180 = 0;
        local_17c = 0;
        local_170 = 0;
        iStack_16c = 0;
        do {
          while( true ) {
            cgsleep_ms(300);
            pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
            uVar3 = reg_value_buf.reg_value_num;
            if ((0x1fe < reg_value_buf.reg_value_num) || (0x1fe < reg_value_buf.p_rd)) {
              iVar4 = iVar4 + 1;
              pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
              goto LAB_00033078;
            }
            if (reg_value_buf.reg_value_num == 0) break;
            local_180 = local_180 + reg_value_buf.reg_value_num;
            if (600 < local_180) {
              pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
              return false;
            }
            uVar5 = 0;
            do {
              while (uVar2 = reg_value_buf.p_rd + 1, uVar6 = local_17c,
                    reg_value_buf.reg_buffer[reg_value_buf.p_rd].chain_number != uVar7) {
                reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
                reg_value_buf.p_rd = uVar2;
                if (0x1fe < uVar2) {
                  reg_value_buf.p_rd = 0;
                }
LAB_0003316a:
                local_17c = uVar6;
                uVar5 = uVar5 + 1;
                if (uVar5 == uVar3) goto LAB_00033212;
              }
              reg_buf[3] = (uchar)reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
              reg_buf[2] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 8);
              reg_buf[1] = (uchar)(reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value >> 0x10);
              uVar2 = reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value;
              reg_value_buf.p_rd = reg_value_buf.p_rd + 1;
              uVar1 = uVar2 >> 0x18;
              reg_buf[0] = (uchar)(uVar2 >> 0x18);
              reg_value_buf.reg_value_num = reg_value_buf.reg_value_num - 1;
              if (0x1fe < reg_value_buf.p_rd) {
                reg_value_buf.p_rd = 0;
              }
              if (reg != 0) {
                if (reg == 0xc) {
                  __format = "chain[%d]: the asic freq is 0x%x\n";
                }
                else {
                  if (reg != 0x18) {
                    if ((reg == 8) && (uVar6 = local_17c + 1, (int)uVar6 < 0x13)) {
                      iVar4 = 0;
                      while( true ) {
                        sprintf((char *)(rate_buf + iVar4 * 2),"%02x",uVar1);
                        if (iVar4 + 1 == 4) break;
                        uVar1 = (uint)reg_buf[iVar4 + 1];
                        iVar4 = iVar4 + 1;
                      }
                      uVar2 = strtol((char *)rate_buf,(char **)0x0,0x10);
                      uVar1 = ((int)uVar2 >> 0x1f) << 0x18 | uVar2 >> 8;
                      uVar2 = uVar2 * 0x1000000;
                      bVar8 = CARRY4(local_170,uVar2);
                      local_170 = local_170 + uVar2;
                      iStack_16c = iStack_16c + uVar1 + bVar8;
                      suffix_string_c5(CONCAT44(uVar1,uVar2),displayed_rate_asic,0x20,6,
                                       (_Bool)in_stack_fffffe6c);
                      sprintf(logstr,"Asic[%02d]=%s ",uVar6,displayed_rate_asic);
                      writeLogFile(logstr);
                      dVar9 = strtod(displayed_rate_asic,(char **)0x0);
                      chain_asic_RT[uVar7][local_17c] = dVar9;
                      if (((uVar6 & 7) == 0) || (uVar6 == 0x12)) {
                        logstr[0] = '\n';
                        logstr[1] = '\0';
                        writeLogFile(logstr);
                      }
                    }
                    goto LAB_0003316a;
                  }
                  __format = "chain[%d]: the asic TICKET_MASK is 0x%x\n";
                }
                sprintf(logstr,__format,uVar7,reg_value_buf.reg_buffer[reg_value_buf.p_rd].reg_value
                       );
                writeInitLogFile(logstr);
                goto LAB_0003316a;
              }
              uVar5 = uVar5 + 1;
              dev->chain_asic_num[uVar7] = dev->chain_asic_num[uVar7] + '\x01';
            } while (uVar5 != uVar3);
LAB_00033212:
            if ((reg == 0) && (dev->chain_asic_num[uVar7] == '\x12')) {
              pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
              goto LAB_00033416;
            }
            iVar4 = 0;
            pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
          }
          iVar4 = iVar4 + 1;
          cgsleep_ms(100);
          pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        } while (iVar4 != 3);
      }
      else {
        local_170 = 0;
        iStack_16c = 0;
        local_17c = 0;
      }
      if (reg == 0) {
LAB_00033416:
        uVar3 = (uint)dev->chain_asic_num[uVar7];
        if (dev->max_asic_num_in_one_chain < uVar3) {
          dev->max_asic_num_in_one_chain = dev->chain_asic_num[uVar7];
        }
      }
      else {
        uVar3 = (uint)dev->chain_asic_num[uVar7];
      }
      if (uVar3 == local_17c) {
        *(uint *)local_174 = local_170;
        *(int *)((int)local_174 + 4) = iStack_16c;
        suffix_string_c5(CONCAT44(iStack_16c,local_170),displayed_rate[uVar7],0x20,6,
                         (_Bool)in_stack_fffffe6c);
        *(undefined4 *)((int)rate_error + local_178) = 0;
      }
      if (((local_17c == 0) || (status_error != false)) &&
         ((iVar4 = *(int *)((int)rate_error + local_178) + 1,
          *(int *)((int)rate_error + local_178) = iVar4, 3 < iVar4 || (status_error != false)))) {
        *(int *)local_174 = 0;
        *(int *)((int)local_174 + 4) = 0;
        suffix_string_c5(0,displayed_rate[uVar7],0x20,6,(_Bool)in_stack_fffffe6c);
      }
      iVar4 = 0;
      clear_register_value_buf();
    }
    uVar7 = uVar7 + 1;
    local_174 = local_174 + 1;
    local_178 = local_178 + 4;
    if (uVar7 == 0x10) {
      return true;
    }
  } while( true );
}

