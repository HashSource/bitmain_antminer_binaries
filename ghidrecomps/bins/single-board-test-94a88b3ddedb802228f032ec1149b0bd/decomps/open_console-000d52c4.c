
undefined4 open_console(void)

{
  int iVar1;
  char *__filename;
  char *__modes;
  FILE *pFVar2;
  int iVar3;
  int *piVar4;
  
  CRYPTO_lock(9,0x1f,DAT_000d533c,0x1de);
  __modes = DAT_000d534c;
  __filename = DAT_000d5348;
  iVar3 = DAT_000d5340;
  *(undefined4 *)(DAT_000d5344 + 0x110) = 1;
  pFVar2 = fopen(__filename,__modes);
  *(FILE **)(iVar3 + 4) = pFVar2;
  if (pFVar2 == (FILE *)0x0) {
    *(undefined4 *)(iVar3 + 4) = *DAT_000d5354;
  }
  pFVar2 = fopen(DAT_000d5348,DAT_000d5350);
  iVar1 = DAT_000d5340;
  *(FILE **)(iVar3 + 8) = pFVar2;
  if (pFVar2 == (FILE *)0x0) {
    *(undefined4 *)(iVar1 + 8) = *DAT_000d5358;
  }
  iVar1 = DAT_000d5344;
  iVar3 = fileno(*(FILE **)(iVar3 + 4));
  iVar3 = tcgetattr(iVar3,(termios *)(iVar1 + 0xd4));
  if (iVar3 != -1) {
    return 1;
  }
  piVar4 = __errno_location();
  if ((*piVar4 != 0x19) && (*piVar4 != 0x16)) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0x110) = 0;
  return 1;
}

