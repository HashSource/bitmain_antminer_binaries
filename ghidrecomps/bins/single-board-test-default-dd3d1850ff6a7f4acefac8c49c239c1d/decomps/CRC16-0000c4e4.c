
undefined2 CRC16(byte *param_1,short param_2)

{
  byte bVar1;
  char cVar2;
  short local_16;
  byte *local_14;
  undefined2 local_a;
  short sVar3;
  
  local_a = 0xffff;
  local_16 = param_2;
  local_14 = param_1;
  while( true ) {
    sVar3 = local_16;
    if (local_16 == 0) {
      sVar3 = 0;
    }
    cVar2 = (char)sVar3;
    if (local_16 != 0) {
      cVar2 = '\x01';
    }
    local_16 = local_16 + -1;
    if (cVar2 == '\0') break;
    bVar1 = *local_14;
    local_14 = local_14 + 1;
    local_a = CONCAT11(chCRCLTalbe[(ushort)((byte)local_a ^ bVar1)],
                       local_a._1_1_ ^ (&chCRCHTalbe)[(ushort)((byte)local_a ^ bVar1)]);
  }
  return local_a;
}

