
undefined4 dlfcn_unload(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  if (param_1 == 0) {
    ERR_put_error(0x25,0x67,0x43,DAT_00126ae0,0xd3);
    uVar2 = 0;
  }
  else {
    iVar1 = sk_num(*(_STACK **)(param_1 + 4));
    if (iVar1 < 1) {
      uVar2 = 1;
    }
    else {
      pvVar3 = sk_pop(*(_STACK **)(param_1 + 4));
      if (pvVar3 == (void *)0x0) {
        ERR_put_error(0x25,0x67,0x68,DAT_00126ae0,0xda);
        sk_push(*(_STACK **)(param_1 + 4),(void *)0x0);
        uVar2 = 0;
      }
      else {
        dlclose();
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}

