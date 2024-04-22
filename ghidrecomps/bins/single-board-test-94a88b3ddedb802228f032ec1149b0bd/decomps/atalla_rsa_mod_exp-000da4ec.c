
undefined4 atalla_rsa_mod_exp(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = DAT_000da54c;
  if (*(int *)(DAT_000da54c + 8) == 0) {
    iVar3 = *(int *)(DAT_000da54c + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar3;
    }
    ERR_put_error(iVar3,0x68,0x69,DAT_000da550,0x215);
    uVar2 = 0;
  }
  else if ((*(int *)(param_3 + 0x18) == 0) || (*(int *)(param_3 + 0x10) == 0)) {
    iVar3 = *(int *)(DAT_000da54c + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar3;
    }
    ERR_put_error(iVar3,0x68,0x68,DAT_000da550,0x21a);
    uVar2 = 0;
  }
  else {
    uVar2 = atalla_mod_exp(param_1,param_2,*(int *)(param_3 + 0x18),*(int *)(param_3 + 0x10),param_4
                          );
  }
  return uVar2;
}

