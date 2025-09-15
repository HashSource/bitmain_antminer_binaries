
void jsonp_error_set_source_part_0(int param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  
  sVar2 = strlen(param_2);
  if (sVar2 < 0x50) {
    sVar2 = sVar2 + 1;
    iVar1 = 0xc;
  }
  else {
    param_2 = param_2 + (sVar2 - 0x4c);
    iVar1 = 0xf;
    sVar2 = 0x4d;
    *(undefined2 *)(param_1 + 0xc) = 0x2e2e;
    *(undefined1 *)(param_1 + 0xe) = 0x2e;
  }
  strncpy((char *)(param_1 + iVar1),param_2,sVar2);
  return;
}

