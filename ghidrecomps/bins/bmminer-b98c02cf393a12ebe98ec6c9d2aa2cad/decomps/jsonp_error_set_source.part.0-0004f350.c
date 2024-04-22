
void jsonp_error_set_source_part_0(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined uVar2;
  size_t sVar3;
  int iVar4;
  
  sVar3 = strlen(param_2);
  uVar2 = DAT_00057d4a;
  if (sVar3 < 0x50) {
    iVar4 = sVar3 + 1;
    iVar1 = 0xc;
  }
  else {
    param_2 = param_2 + (sVar3 - 0x4c);
    iVar1 = 0xf;
    iVar4 = 0x4d;
    *(undefined2 *)(param_1 + 0xc) = DAT_00057d48;
    *(undefined *)(param_1 + 0xe) = uVar2;
  }
  (*(code *)PTR_strncpy_0007cfc4)(param_1 + iVar1,param_2,iVar4,param_4);
  return;
}

