
int dlfcn_bind_func(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  _STACK *p_Var4;
  int iVar5;
  
  if (param_1 == 0 || param_2 == 0) {
    ERR_put_error(0x25,100,0x43,"dso_dlfcn.c",0x109);
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    iVar1 = sk_num(*(_STACK **)(param_1 + 4));
    if (iVar1 < 1) {
      ERR_put_error(0x25,100,0x69,"dso_dlfcn.c",0x10d);
    }
    else {
      p_Var4 = *(_STACK **)(param_1 + 4);
      iVar5 = sk_num(p_Var4);
      pvVar2 = sk_value(p_Var4,iVar5 + -1);
      if (pvVar2 == (void *)0x0) {
        ERR_put_error(0x25,100,0x68,"dso_dlfcn.c",0x112);
        iVar5 = 0;
      }
      else {
        iVar5 = dlsym(pvVar2,param_2);
        if (iVar5 == 0) {
          ERR_put_error(0x25,100,0x6a,"dso_dlfcn.c",0x117);
          uVar3 = dlerror();
          ERR_add_error_data(4,"symname(",param_2,&DAT_0022f530,uVar3);
        }
      }
    }
  }
  return iVar5;
}

