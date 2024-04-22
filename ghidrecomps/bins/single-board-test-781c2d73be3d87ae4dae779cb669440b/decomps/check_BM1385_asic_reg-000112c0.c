
/* WARNING: Unknown calling convention */

void check_BM1385_asic_reg(uchar which_chain,uchar chip_addr,uchar reg,_Bool mode)

{
  uint *puVar1;
  uchar uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  reg_buf *prVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uchar reg_buf [5];
  
  uVar4 = (uint)which_chain;
  reg_buf[4] = '\0';
  reg_buf[0] = '\0';
  reg_buf[1] = '\0';
  reg_buf[2] = '\0';
  reg_buf[3] = '\0';
  clear_register_value_buf();
  printf("%s: check chain J%d \n",DAT_000114e4,uVar4 + 1);
  read_BM1385_asic_register(which_chain,'\0',reg,mode);
  if (reg == '\0') {
    *(undefined *)(DAT_000114e8 + uVar4 + 0x30c) = 0;
  }
  iVar8 = 0;
  do {
    while( true ) {
      usleep(300000);
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      uVar10 = reg_value_buf->reg_value_num;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      if (uVar10 != 0) break;
      iVar8 = iVar8 + 1;
      usleep(100000);
      printf("%s: no asic address register come back for %d time.\n",DAT_000114e4,iVar8);
      if (iVar8 == 3) {
        if (reg == '\0') {
          if (cgpu.max_asic_num_in_one_chain < cgpu.chain_asic_num[uVar4]) {
            cgpu.max_asic_num_in_one_chain = (uint)cgpu.chain_asic_num[uVar4];
          }
          printf("%s: chain J%d has %d ASIC\n",DAT_000114e4,uVar4 + 1);
        }
        clear_register_value_buf();
        return;
      }
    }
    uVar9 = 0;
    do {
      while( true ) {
        pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
        prVar7 = reg_value_buf;
        if (reg_value_buf->reg_buffer[reg_value_buf->p_rd].chain_number == uVar4) break;
        puVar1 = &reg_value_buf->reg_value_num;
        uVar5 = reg_value_buf->p_rd + 1;
        bVar11 = uVar5 == 0x200;
        reg_value_buf->p_rd = uVar5;
        uVar6 = *puVar1 - 1;
        prVar7->reg_value_num = uVar6;
        if (bVar11) {
          uVar5 = 0;
          uVar6 = uVar5;
        }
        if (bVar11) {
          prVar7->p_rd = uVar6;
        }
        printf("%s: the return data is from chain%d, but it should be from chain%d\n",DAT_000114e4,
               (uint)prVar7->reg_buffer[uVar5].chain_number,uVar4);
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
LAB_00011386:
        uVar9 = uVar9 + 1;
        if (uVar10 == uVar9) goto LAB_0001142c;
      }
      reg_buf[4] = '\0';
      uVar6 = reg_value_buf->reg_buffer[reg_value_buf->p_rd].reg_value;
      reg_buf[3] = (char)uVar6;
      reg_buf[2] = (char)(uVar6 >> 8);
      reg_buf[1] = (char)(uVar6 >> 0x10);
      reg_buf[0] = (uchar)(uVar6 >> 0x18);
      uVar2 = CRC5(reg_buf,'#');
      prVar7 = reg_value_buf;
      uVar6 = reg_value_buf->p_rd;
      if (reg_value_buf->reg_buffer[uVar6].crc == uVar2) {
        if (reg == '\0') {
          cgpu.chain_asic_num[uVar4] = cgpu.chain_asic_num[uVar4] + '\x01';
          uVar6 = prVar7->p_rd;
        }
        else if (reg == '\f') {
          printf("%s: the asic freq is 0x%08x\n",DAT_000114e4,
                 reg_value_buf->reg_buffer[uVar6].reg_value);
          uVar6 = reg_value_buf->p_rd;
          prVar7 = reg_value_buf;
        }
        uVar6 = uVar6 + 1;
        bVar11 = uVar6 == 0x200;
        prVar7->p_rd = uVar6;
        if (bVar11) {
          uVar6 = 0;
        }
        if (bVar11) {
          prVar7->p_rd = uVar6;
        }
        prVar7->reg_value_num = prVar7->reg_value_num - 1;
        pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
        goto LAB_00011386;
      }
      uVar5 = reg_value_buf->reg_value_num;
      reg_value_buf->p_rd = uVar6 + 1;
      if (uVar6 + 1 == 0x200) {
        prVar7->p_rd = 0;
      }
      uVar9 = uVar9 + 1;
      prVar7->reg_value_num = uVar5 - 1;
      bVar3 = CRC5(reg_buf,'#');
      printf("%s: crc is 0x%x, but it should be 0x%x\n",DAT_000114e4,(uint)bVar3,
             (uint)reg_value_buf->reg_buffer[reg_value_buf->p_rd].crc);
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
    } while (uVar10 != uVar9);
LAB_0001142c:
    iVar8 = 0;
  } while( true );
}

