
undefined4
hwcrhk_mod_exp_mont(BIGNUM *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  ulong *puVar5;
  uint uVar6;
  undefined *puStack_448;
  undefined4 uStack_444;
  undefined4 uStack_440;
  int iStack_43c;
  undefined4 uStack_438;
  int iStack_434;
  undefined4 uStack_430;
  int iStack_42c;
  ulong *puStack_428;
  uint uStack_424;
  undefined auStack_420 [1024];
  
  iVar4 = DAT_000dc164;
  puStack_448 = auStack_420;
  uStack_444 = 0x400;
  if (*(int *)(DAT_000dc164 + 0x14) == 0) {
    iVar2 = *(int *)(DAT_000dc164 + 0x1c);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar4 + 0x1c) = iVar2;
    }
    ERR_put_error(iVar2,0x6b,0x6a,DAT_000dc168,0x396);
    uVar3 = 0;
  }
  else {
    bn_expand2(param_1,param_4[1]);
    uStack_430 = *param_4;
    uStack_438 = *param_3;
    iStack_42c = param_4[1] << 2;
    iStack_43c = param_2[1] << 2;
    iStack_434 = param_3[1] << 2;
    uStack_440 = *param_2;
    uStack_424 = param_1->dmax << 2;
    puStack_428 = param_1->d;
    iVar2 = (**(code **)(iVar4 + 0x28))
                      (*(undefined4 *)(iVar4 + 0x14),uStack_440,iStack_43c,uStack_438,iStack_434,
                       uStack_430,iStack_42c,&puStack_428,&puStack_448);
    uVar6 = uStack_424 >> 2;
    param_1->top = uVar6;
    if (uVar6 != 0) {
      puVar5 = param_1->d + (uVar6 - 1);
      do {
        if (*puVar5 != 0) break;
        uVar6 = uVar6 - 1;
        puVar5 = puVar5 + -1;
      } while (uVar6 != 0);
      param_1->top = uVar6;
    }
    iVar1 = DAT_000dc164;
    if (iVar2 < 0) {
      iVar4 = *(int *)(iVar4 + 0x1c);
      if (iVar2 == -2) {
        if (iVar4 == 0) {
          iVar4 = ERR_get_next_error_library();
          *(int *)(iVar1 + 0x1c) = iVar4;
        }
        ERR_put_error(iVar4,0x6b,0x70,DAT_000dc168,0x3ad);
      }
      else {
        if (iVar4 == 0) {
          iVar4 = ERR_get_next_error_library();
          *(int *)(iVar1 + 0x1c) = iVar4;
        }
        ERR_put_error(iVar4,0x6b,0x6f,DAT_000dc168,0x3af);
      }
      ERR_add_error_data(1,puStack_448);
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}

