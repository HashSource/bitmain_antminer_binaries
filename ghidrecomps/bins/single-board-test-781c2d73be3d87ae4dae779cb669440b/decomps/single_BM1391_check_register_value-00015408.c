
/* WARNING: Unknown calling convention */

int single_BM1391_check_register_value(uchar which_chain,uint *buf)

{
  reg_buf *prVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (0x1fe < reg_value_buf->reg_value_num) {
    printf("%s: reg_value_buf buffer is full!\n",DAT_000154bc);
    return 0;
  }
  uVar3 = *buf;
  uVar4 = buf[1];
  if (-1 < (int)(uVar3 << 0x19)) {
    if ((uVar3 & 0x20000000) == 0) {
      pthread_mutex_lock((pthread_mutex_t *)&reg_mutex);
      prVar1 = reg_value_buf;
      uVar2 = reg_value_buf->p_wr;
      reg_value_buf->reg_buffer[uVar2].reg_value = uVar4;
      prVar1->reg_buffer[uVar2].crc = (byte)((uVar3 << 3) >> 0x1b);
      prVar1->reg_buffer[uVar2].chip_address = (uchar)(uVar3 >> 0x10);
      prVar1->reg_buffer[uVar2].chain_number = (byte)uVar3 & 0xf;
      prVar1->reg_buffer[uVar2].reg_address = (uchar)(uVar3 >> 8);
      prVar1->p_wr = uVar2 + 1;
      if (0x1ff < uVar2 + 1) {
        prVar1->p_wr = 0;
      }
      prVar1->reg_value_num = prVar1->reg_value_num + 1;
      pthread_mutex_unlock((pthread_mutex_t *)&reg_mutex);
      return 0;
    }
    printf("%s: REG_TYPE error. data[0] = 0x%08x, reg_value = 0x%08x\n",DAT_000154bc,uVar3,uVar4);
    return -1;
  }
  printf("%s: reg crc error. data[0] = 0x%08x, reg_value = 0x%08x\n",DAT_000154bc,uVar3,uVar4);
  return -1;
}

