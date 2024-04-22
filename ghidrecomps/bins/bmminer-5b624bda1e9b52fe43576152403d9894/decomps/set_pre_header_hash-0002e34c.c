
/* WARNING: Unknown calling convention */

void set_pre_header_hash(uint *value)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char tmp42 [2048];
  
  pcVar2 = DAT_0002e3e8;
  iVar3 = *(int *)(DAT_0002e3e4 + 0x8d4);
  *(uint *)(iVar3 + 0x140) = *value;
  cVar1 = *pcVar2;
  *(uint *)(iVar3 + 0x144) = value[1];
  *(uint *)(iVar3 + 0x148) = value[2];
  *(uint *)(iVar3 + 0x14c) = value[3];
  *(uint *)(iVar3 + 0x150) = value[4];
  *(uint *)(iVar3 + 0x154) = value[5];
  *(uint *)(iVar3 + 0x158) = value[6];
  *(uint *)(iVar3 + 0x15c) = value[7];
  if ((cVar1 != '\0') &&
     (((*DAT_0002e3ec != '\0' || (*DAT_0002e3f0 != '\0')) || (6 < *DAT_0002e3f4)))) {
    snprintf(tmp42,0x800,DAT_0002e3f8,DAT_0002e3fc,*value,value[1],value[2],value[3],value[4],
             value[5],value[6],value[7]);
    _applog(7,tmp42,false);
  }
  return;
}

