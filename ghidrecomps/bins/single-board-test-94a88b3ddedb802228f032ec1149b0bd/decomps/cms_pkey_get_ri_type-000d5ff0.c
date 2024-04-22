
undefined4 cms_pkey_get_ri_type(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uStack_c;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uStack_c = 0;
  }
  else {
    pcVar2 = *(code **)(*(int *)(param_1 + 0xc) + 0x58);
    if (pcVar2 == (code *)0x0) {
      uStack_c = 0;
    }
    else {
      iVar1 = (*pcVar2)(param_1,8,0,&uStack_c);
      if (iVar1 < 1) {
        uStack_c = 0;
      }
    }
  }
  return uStack_c;
}

