
undefined4 UI_dup_user_data(UI *param_1)

{
  void *user_data;
  undefined4 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)param_1 + 0x18);
  if ((pcVar2 == (code *)0x0) || (*(int *)(*(int *)param_1 + 0x1c) == 0)) {
    ERR_put_error(0x28,0x76,0x70,"crypto/ui/ui_lib.c",0x19b);
    uVar1 = 0xffffffff;
  }
  else {
    user_data = (void *)(*pcVar2)();
    if (user_data == (void *)0x0) {
      ERR_put_error(0x28,0x76,0x41,"crypto/ui/ui_lib.c",0x1a1);
      uVar1 = 0xffffffff;
    }
    else {
      UI_add_user_data(param_1,user_data);
      uVar1 = 0;
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 2;
    }
  }
  return uVar1;
}

