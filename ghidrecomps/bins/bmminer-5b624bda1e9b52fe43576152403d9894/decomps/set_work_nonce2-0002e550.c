
/* WARNING: Unknown calling convention */

void set_work_nonce2(uint *value)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint buf [2];
  char tmp42 [2048];
  
  pcVar2 = DAT_0002e5b8;
  iVar3 = *(int *)(DAT_0002e5b4 + 0x8d4);
  buf[0] = 0;
  *(uint *)(iVar3 + 0x108) = *value;
  cVar1 = *pcVar2;
  buf[1] = 0;
  *(uint *)(iVar3 + 0x10c) = value[1];
  if ((cVar1 != '\0') &&
     (((*DAT_0002e5bc != '\0' || (*DAT_0002e5c0 != '\0')) || (6 < *DAT_0002e5c4)))) {
    snprintf(tmp42,0x800,DAT_0002e5c8,DAT_0002e5cc,*value,value[1]);
    _applog(7,tmp42,false);
  }
  get_work_nonce2(buf);
  return;
}

