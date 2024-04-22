
/* WARNING: Unknown calling convention */

int get_work_nonce2(uint *buf)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char tmp42 [2048];
  
  iVar3 = *(int *)(DAT_0002e534 + 0x8d4);
  cVar1 = *DAT_0002e538;
  uVar2 = *(uint *)(iVar3 + 0x108);
  *buf = uVar2;
  uVar4 = *(uint *)(iVar3 + 0x10c);
  buf[1] = uVar4;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e53c != '\0' || (*DAT_0002e540 != '\0')) || (6 < *DAT_0002e544)))) {
    snprintf(tmp42,0x800,DAT_0002e548,DAT_0002e54c,uVar2,uVar4);
    _applog(7,tmp42,false);
  }
  return -1;
}

