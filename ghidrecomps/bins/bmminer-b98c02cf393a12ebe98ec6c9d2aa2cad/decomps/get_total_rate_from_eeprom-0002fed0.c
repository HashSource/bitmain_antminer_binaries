
int get_total_rate_from_eeprom(void)

{
  FILE *__stream;
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar1 = (int *)(dev + 4);
  iVar2 = DAT_0002ff54;
  do {
    piVar1 = piVar1 + 1;
    iVar3 = iVar2 + 0x80;
    if (*piVar1 == 1) {
      iVar4 = iVar4 + *(int *)(iVar2 + 0x56);
    }
    iVar2 = iVar3;
  } while (iVar3 != DAT_0002ff54 + 0x800);
  if (3 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: totalrate = %d\n","driver-btm-c5.c",0xeb9,DAT_0002ff58,iVar4);
    }
    fclose(__stream);
    return iVar4;
  }
  return iVar4;
}

