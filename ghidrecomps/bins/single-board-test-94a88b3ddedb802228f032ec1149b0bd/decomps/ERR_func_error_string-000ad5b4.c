
char * ERR_func_error_string(ulong e)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  uint local_18 [3];
  
  iVar1 = DAT_000ad610;
  iVar3 = *(int *)(DAT_000ad610 + 0x2f4);
  if (iVar3 == 0) {
    CRYPTO_lock(9,1,DAT_000ad614,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad618;
    }
    CRYPTO_lock(10,1,DAT_000ad614,0x12a);
    iVar3 = *(int *)(iVar1 + 0x2f4);
  }
  local_18[0] = e & 0xfffff000;
  pcVar2 = (char *)(**(code **)(iVar3 + 8))(local_18);
  if (pcVar2 != (char *)0x0) {
    pcVar2 = *(char **)(pcVar2 + 4);
  }
  return pcVar2;
}

