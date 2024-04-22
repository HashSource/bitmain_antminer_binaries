
int dlfcn_bind_var(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  _STACK *p_Var4;
  int iVar5;
  
  if (param_1 == 0 || param_2 == 0) {
    ERR_put_error(0x25,0x65,0x43,DAT_0012696c,0xeb);
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    iVar1 = sk_num(*(_STACK **)(param_1 + 4));
    if (iVar1 < 1) {
      ERR_put_error(0x25,0x65,0x69,DAT_0012696c,0xef);
    }
    else {
      p_Var4 = *(_STACK **)(param_1 + 4);
      iVar5 = sk_num(p_Var4);
      pvVar2 = sk_value(p_Var4,iVar5 + -1);
      if (pvVar2 == (void *)0x0) {
        ERR_put_error(0x25,0x65,0x68,DAT_0012696c,0xf4);
        iVar5 = 0;
      }
      else {
        iVar5 = dlsym(pvVar2,param_2);
        if (iVar5 == 0) {
          ERR_put_error(0x25,0x65,0x6a,DAT_0012696c,0xf9);
          uVar3 = dlerror();
          ERR_add_error_data(4,DAT_00126970,param_2,DAT_00126974,uVar3);
        }
      }
    }
  }
  return iVar5;
}

