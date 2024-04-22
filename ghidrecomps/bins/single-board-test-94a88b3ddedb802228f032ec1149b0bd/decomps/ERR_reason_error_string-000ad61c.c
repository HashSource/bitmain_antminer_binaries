
char * ERR_reason_error_string(ulong e)

{
  int iVar1;
  int iVar2;
  uint local_20 [3];
  
  iVar1 = DAT_000ad68c;
  iVar2 = *(int *)(DAT_000ad68c + 0x2f4);
  if (iVar2 == 0) {
    CRYPTO_lock(9,1,DAT_000ad690,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad694;
    }
    CRYPTO_lock(10,1,DAT_000ad690,0x12a);
    iVar2 = *(int *)(iVar1 + 0x2f4);
  }
  iVar1 = DAT_000ad68c;
  local_20[0] = e & 0xff000fff;
  iVar2 = (**(code **)(iVar2 + 8))(local_20);
  if ((iVar2 == 0) &&
     (local_20[0] = e & 0xfff, iVar2 = (**(code **)(*(int *)(iVar1 + 0x2f4) + 8))(local_20),
     iVar2 == 0)) {
    return (char *)0x0;
  }
  return *(char **)(iVar2 + 4);
}

