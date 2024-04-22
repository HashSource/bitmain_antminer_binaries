
void build_SYS_str_reasons(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int __errnum;
  int iVar6;
  int iVar7;
  char *__dest;
  
  iVar2 = DAT_000ac7fc;
  CRYPTO_lock(5,1,DAT_000ac7f4,0x247);
  if (*(int *)(iVar2 + 4) == 0) {
    CRYPTO_lock(6,1,DAT_000ac7f4,0x249);
    return;
  }
  CRYPTO_lock(6,1,DAT_000ac7f4,0x24d);
  CRYPTO_lock(9,1,DAT_000ac7f4,0x24e);
  uVar3 = DAT_000ac800;
  iVar1 = DAT_000ac7f8;
  if (*(int *)(iVar2 + 4) != 0) {
    __errnum = 1;
    iVar7 = DAT_000ac7f8 + 0x400;
    do {
      iVar4 = __errnum + -1;
      iVar6 = iVar1 + iVar4 * 8;
      *(int *)(iVar1 + iVar4 * 8) = __errnum;
      pcVar5 = DAT_000ac7f4;
      if (*(int *)(iVar6 + 4) == 0) {
        __dest = (char *)(iVar7 + iVar4 * 0x20);
        pcVar5 = strerror(__errnum);
        if (pcVar5 == (char *)0x0) {
          pcVar5 = DAT_000ac7f4;
          if (*(int *)(iVar6 + 4) == 0) {
            *(undefined4 *)(iVar6 + 4) = uVar3;
            pcVar5 = DAT_000ac7f4;
          }
        }
        else {
          strncpy(__dest,pcVar5,0x20);
          __dest[0x1f] = '\0';
          *(char **)(iVar6 + 4) = __dest;
          pcVar5 = DAT_000ac7f4;
        }
      }
      __errnum = __errnum + 1;
      DAT_000ac7f4 = pcVar5;
    } while (__errnum != 0x80);
    *(undefined4 *)(iVar2 + 4) = 0;
    CRYPTO_lock(10,1,pcVar5,0x26c);
    return;
  }
  CRYPTO_lock(10,1,DAT_000ac7f4,0x250);
  return;
}

