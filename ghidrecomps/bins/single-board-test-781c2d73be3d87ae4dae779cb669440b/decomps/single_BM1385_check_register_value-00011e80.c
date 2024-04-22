
/* WARNING: Unknown calling convention */

int single_BM1385_check_register_value(uchar which_chain,uchar *register_data)

{
  byte bVar1;
  reg_buf *prVar2;
  uint uVar3;
  uint uVar4;
  
  prVar2 = reg_value_buf;
  uVar4 = reg_value_buf->reg_value_num;
  if (0x1fe < uVar4) {
    printf("%s: reg_value_buf buffer is full!\n",DAT_00011ee8);
    return -1;
  }
  uVar3 = reg_value_buf->p_wr;
  reg_value_buf->reg_buffer[uVar3].reg_value =
       (uint)register_data[3] | (uint)register_data[1] << 0x10 | (uint)*register_data << 0x18 |
       (uint)register_data[2] << 8;
  bVar1 = register_data[4];
  prVar2->reg_buffer[uVar3].chain_number = which_chain;
  prVar2->reg_buffer[uVar3].crc = bVar1 & 0x1f;
  prVar2->reg_value_num = uVar4 + 1;
  prVar2->p_wr = uVar3 + 1;
  if (0x1ff < uVar3 + 1) {
    prVar2->p_wr = 0;
    return 0;
  }
  return 0;
}

