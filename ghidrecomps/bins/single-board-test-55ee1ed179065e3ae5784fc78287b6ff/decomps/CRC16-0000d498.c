
undefined2 CRC16(undefined *param_1,int param_2)

{
  undefined uVar1;
  char cVar2;
  int iVar3;
  int local_18;
  undefined *local_14;
  undefined2 local_a;
  
  local_a = 0xffff;
  local_18 = param_2;
  local_14 = param_1;
  while( true ) {
    iVar3 = local_18;
    if (local_18 == 0) {
      iVar3 = 0;
    }
    cVar2 = (char)iVar3;
    if (local_18 != 0) {
      cVar2 = '\x01';
    }
    local_18 = local_18 + -1;
    if (cVar2 == '\0') break;
    uVar1 = *local_14;
    local_14 = local_14 + 1;
    local_a = crc_itu_t_byte(local_a,uVar1);
  }
  return local_a;
}

