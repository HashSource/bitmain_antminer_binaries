
int makeup_work_pkg(uint8_t *str,uint8_t *work_str)

{
  ushort uVar1;
  uint8_t *work_str_local;
  uint8_t *str_local;
  uint16_t crc16;
  work_input *work;
  
  work_str[2] = work_str[2] & 0x1f | 0x20;
  *work_str = 'U';
  work_str[1] = 0xaa;
  uVar1 = CRC16_v1(work_str + 2,0x8e);
  *(ushort *)(work_str + 0x90) = uVar1 >> 8 | uVar1 << 8;
  memcpy(str,work_str,0x92);
  return 0x92;
}

