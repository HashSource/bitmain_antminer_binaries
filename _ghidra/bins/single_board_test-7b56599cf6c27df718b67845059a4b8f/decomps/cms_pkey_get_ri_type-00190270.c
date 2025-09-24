
undefined4 cms_pkey_get_ri_type(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0;
  }
  pcVar2 = *(code **)(*(int *)(param_1 + 0xc) + 0x5c);
  if (pcVar2 != (code *)0x0) {
    iVar1 = (*pcVar2)(param_1,8,0,&local_c);
    if (iVar1 < 1) {
      local_c = 0;
    }
    return local_c;
  }
  return 0;
}

