
/* WARNING: Unknown calling convention */

uint check_BM1391_asic_reg(uchar which_chain,uchar chip_addr,uchar reg,_Bool mode)

{
  uint *puVar1;
  uchar uVar2;
  uint uVar3;
  reg_buf *prVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  uint local_38;
  uchar reg_buf [7];
  
  uVar3 = (uint)which_chain;
  reg_buf[0] = '\0';
  reg_buf[1] = '\0';
  reg_buf[2] = '\0';
  reg_buf[3] = '\0';
  reg_buf[4] = '\0';
  reg_buf[5] = '\0';
  reg_buf[6] = '\0';
  clear_register_value_buf();
  BM1391_get_status(which_chain,chip_addr,reg,mode);
  if (reg == '\0') {
    *(undefined *)(DAT_00012e90 + uVar3 + 0x30c) = 0;
  }
  iVar7 = 0;
  local_38 = 0;
  do {
    while( true ) {
      usleep(30000);
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar9 = reg_value_buf->reg_value_num;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if (uVar9 != 0) break;
      iVar7 = iVar7 + 1;
      usleep(30000);
      if (iVar7 == 3) {
        if ((reg == '\0') && (cgpu.max_asic_num_in_one_chain < cgpu.chain_asic_num[uVar3])) {
          cgpu.max_asic_num_in_one_chain = (uint)cgpu.chain_asic_num[uVar3];
        }
        clear_register_value_buf();
        return local_38;
      }
    }
    uVar8 = 0;
    do {
      while( true ) {
        pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
        prVar4 = reg_value_buf;
        if (reg_value_buf->reg_buffer[reg_value_buf->p_rd].chain_number != uVar3) break;
        reg_buf[6] = '\0';
        uVar6 = reg_value_buf->p_rd;
        uVar5 = reg_value_buf->reg_buffer[uVar6].reg_value;
        reg_buf[4] = reg_value_buf->reg_buffer[uVar6].chip_address;
        reg_buf[5] = reg_value_buf->reg_buffer[uVar6].reg_address;
        reg_buf[3] = (uchar)uVar5;
        reg_buf[1] = (uchar)(uVar5 >> 0x10);
        reg_buf[0] = (uchar)(uVar5 >> 0x18);
        reg_buf[2] = (uchar)(uVar5 >> 8);
        uVar2 = CRC5(reg_buf,'3');
        prVar4 = reg_value_buf;
        uVar5 = reg_value_buf->p_rd;
        if (uVar2 == reg_value_buf->reg_buffer[uVar5].crc) {
          if (reg == '\0') {
            if ((reg_buf[0] == '\x13') && (reg_buf[1] == 0x91)) {
              cgpu.chain_asic_num[uVar3] = cgpu.chain_asic_num[uVar3] + '\x01';
              uVar5 = prVar4->p_rd;
            }
            else {
              printf("%s: error asic address : 0x%08x\n",DAT_00012e94,
                     reg_value_buf->reg_buffer[uVar5].reg_value);
              uVar5 = reg_value_buf->p_rd;
              prVar4 = reg_value_buf;
            }
          }
          local_38 = prVar4->reg_buffer[uVar5].reg_value;
          uVar5 = uVar5 + 1;
          prVar4->p_rd = uVar5;
          uVar6 = prVar4->reg_value_num - 1;
          prVar4->reg_value_num = uVar6;
          if (uVar5 == 0x200) {
            uVar6 = 0;
          }
          if (uVar5 == 0x200) {
            prVar4->p_rd = uVar6;
          }
        }
        else {
          printf("%s: crc is 0x%x, but it should be 0x%x\n",DAT_00012e94);
          prVar4 = reg_value_buf;
          puVar1 = &reg_value_buf->reg_value_num;
          uVar5 = reg_value_buf->p_rd + 1;
          reg_value_buf->p_rd = uVar5;
          prVar4->reg_value_num = *puVar1 - 1;
          if (uVar5 == 0x200) {
            prVar4->p_rd = 0;
          }
        }
        uVar8 = uVar8 + 1;
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        if (uVar9 == uVar8) goto LAB_00012dee;
      }
      puVar1 = &reg_value_buf->reg_value_num;
      uVar6 = reg_value_buf->p_rd + 1;
      bVar10 = uVar6 == 0x200;
      reg_value_buf->p_rd = uVar6;
      uVar8 = uVar8 + 1;
      uVar5 = *puVar1 - 1;
      prVar4->reg_value_num = uVar5;
      if (bVar10) {
        uVar6 = 0;
        uVar5 = uVar6;
      }
      if (bVar10) {
        prVar4->p_rd = uVar5;
      }
      printf("%s: the return data is from chain%d, but it should be from chain%d\n",DAT_00012e94,
             (uint)prVar4->reg_buffer[uVar6].chain_number,uVar3);
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
    } while (uVar9 != uVar8);
LAB_00012dee:
    iVar7 = 0;
  } while( true );
}

