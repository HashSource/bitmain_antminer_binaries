
/* WARNING: Unknown calling convention */

int get_BC_command_buffer(uint *buf)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char tmp42 [2048];
  
  iVar4 = *(int *)(DAT_0002dc30 + 0x8d4);
  cVar1 = *DAT_0002dc34;
  uVar2 = *(uint *)(iVar4 + 0xc4);
  *buf = uVar2;
  uVar3 = *(uint *)(iVar4 + 200);
  buf[1] = uVar3;
  uVar5 = *(uint *)(iVar4 + 0xcc);
  buf[2] = uVar5;
  if ((cVar1 != '\0') &&
     (((*DAT_0002dc38 != '\0' || (*DAT_0002dc3c != '\0')) || (6 < *DAT_0002dc40)))) {
    snprintf(tmp42,0x800,DAT_0002dc44,DAT_0002dc48,uVar2,uVar3,uVar5);
    _applog(7,tmp42,false);
  }
  return uVar5;
}

