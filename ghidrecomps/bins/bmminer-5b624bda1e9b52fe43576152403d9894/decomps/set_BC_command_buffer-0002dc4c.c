
/* WARNING: Unknown calling convention */

void set_BC_command_buffer(uint *value)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint buf [4];
  char tmp42 [2048];
  
  pcVar2 = DAT_0002dcc4;
  iVar3 = *(int *)(DAT_0002dcc0 + 0x8d4);
  buf[1] = 0;
  *(uint *)(iVar3 + 0xc4) = *value;
  cVar1 = *pcVar2;
  buf[2] = 0;
  *(uint *)(iVar3 + 200) = value[1];
  buf[3] = 0;
  buf[0] = 0;
  *(uint *)(iVar3 + 0xcc) = value[2];
  if ((cVar1 != '\0') &&
     (((*DAT_0002dcc8 != '\0' || (*DAT_0002dccc != '\0')) || (6 < *DAT_0002dcd0)))) {
    snprintf(tmp42,0x800,DAT_0002dcd4,DAT_0002dcd8,*value,value[1],value[2]);
    _applog(7,tmp42,false);
  }
  get_BC_command_buffer(buf);
  return;
}

