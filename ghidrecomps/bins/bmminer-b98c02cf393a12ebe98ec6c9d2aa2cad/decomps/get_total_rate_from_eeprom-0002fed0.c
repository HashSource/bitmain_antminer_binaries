
int get_total_rate_from_eeprom(void)

{
  FILE *__stream;
  int *piVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar1 = (int *)(dev + 4);
  puVar2 = chain_pic_buf;
  do {
    piVar1 = piVar1 + 1;
    puVar3 = puVar2 + 0x80;
    if (*piVar1 == 1) {
      iVar4 = iVar4 + *(int *)(puVar2 + 0x56);
    }
    puVar2 = puVar3;
  } while (puVar3 != nonce_mutex);
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: totalrate = %d\n","driver-btm-c5.c",0xeb9,
              "get_total_rate_from_eeprom",iVar4);
    }
    fclose(__stream);
    return iVar4;
  }
  return iVar4;
}

