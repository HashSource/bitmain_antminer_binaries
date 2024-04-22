
uint i2c_status(byte param_1,undefined param_2)

{
  int iVar1;
  char cVar2;
  byte local_20;
  undefined local_1f;
  undefined local_1e;
  uint local_1c;
  undefined local_14;
  undefined local_13;
  undefined local_12;
  int local_c;
  
  local_c = 0;
  local_13 = 0;
  local_12 = 0x20;
  local_14 = param_2;
  midd_ioctl(*(undefined4 *)(g_chain + (uint)param_1 * 0x28),0,&local_14);
  usleep(200000);
  local_1e = 0x20;
  local_20 = param_1;
  local_1f = param_2;
  do {
    usleep(100000);
    iVar1 = read_reg_item(&local_20);
    if (0 < iVar1) {
      return local_1c & 0x80000000;
    }
    iVar1 = local_c;
    if (2 < local_c) {
      iVar1 = 0;
    }
    cVar2 = (char)iVar1;
    if (local_c < 3) {
      cVar2 = '\x01';
    }
    local_c = local_c + 1;
  } while (cVar2 != '\0');
  return 0xffffffff;
}

