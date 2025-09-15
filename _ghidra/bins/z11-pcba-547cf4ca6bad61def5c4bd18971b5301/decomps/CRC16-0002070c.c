
undefined2 CRC16(byte *param_1,short param_2)

{
  short local_16;
  byte *local_14;
  undefined2 local_a;
  
  local_a = 0xffff;
  local_16 = param_2;
  local_14 = param_1;
  while (local_16 != 0) {
    local_a = CONCAT11(chCRCLTalbe[(ushort)((byte)local_a ^ *local_14)],
                       local_a._1_1_ ^ (&chCRCHTalbe)[(ushort)((byte)local_a ^ *local_14)]);
    local_16 = local_16 + -1;
    local_14 = local_14 + 1;
  }
  return local_a;
}

