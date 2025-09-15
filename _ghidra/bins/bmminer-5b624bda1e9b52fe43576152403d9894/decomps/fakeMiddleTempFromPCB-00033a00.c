
/* WARNING: Unknown calling convention */

int fakeMiddleTempFromPCB(int local_temp)

{
  int iVar1;
  
  if (local_temp < 1) {
    return 0;
  }
  if (local_temp < 0x33) {
    return local_temp + 0x19;
  }
  if (local_temp < 0x3d) {
    iVar1 = local_temp + 0x1e;
  }
  else {
    iVar1 = local_temp + 0x23;
  }
  return iVar1;
}

