
/* WARNING: Unknown calling convention */

void set_dhash_acc_control(uint value)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  char tmp42 [2048];
  
  pcVar3 = DAT_0002e8bc;
  iVar2 = DAT_0002e8a0;
  cVar1 = *DAT_0002e8bc;
  *(uint *)(*(int *)(DAT_0002e8a0 + 0x8d4) + 0x100) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e8a4 != '\0' || (*DAT_0002e8a8 != '\0')) || (6 < *DAT_0002e8b8)))) {
    snprintf(tmp42,0x800,DAT_0002e8ac,DAT_0002e8b0,value);
    _applog(7,tmp42,false);
  }
  iVar5 = 10;
  do {
    uVar4 = get_dhash_acc_control();
    if ((value | 0x80) == (uVar4 | 0x80)) {
      return;
    }
    *(uint *)(*(int *)(iVar2 + 0x8d4) + 0x100) = value;
    cgsleep_ms(2);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((*pcVar3 != '\0') &&
     (((*DAT_0002e8a4 != '\0' || (*DAT_0002e8a8 != '\0')) || (6 < *DAT_0002e8b8)))) {
    snprintf(tmp42,0x800,DAT_0002e8b4,DAT_0002e8b0);
    _applog(7,tmp42,false);
  }
  return;
}

