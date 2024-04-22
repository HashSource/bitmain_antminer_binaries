
undefined4
hwcrhk_mod_exp_isra_1(BIGNUM *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  ulong *puVar5;
  uint uVar6;
  undefined *local_448;
  undefined4 local_444;
  undefined4 local_440;
  int local_43c;
  undefined4 local_438;
  int local_434;
  undefined4 local_430;
  int local_42c;
  ulong *local_428;
  uint local_424;
  undefined auStack_420 [1024];
  
  iVar4 = DAT_000dc164;
  local_448 = auStack_420;
  local_444 = 0x400;
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
    local_430 = *param_4;
    local_438 = *param_3;
    local_42c = param_4[1] << 2;
    local_43c = param_2[1] << 2;
    local_434 = param_3[1] << 2;
    local_440 = *param_2;
    local_424 = param_1->dmax << 2;
    local_428 = param_1->d;
    iVar2 = (**(code **)(iVar4 + 0x28))
                      (*(undefined4 *)(iVar4 + 0x14),local_440,local_43c,local_438,local_434,
                       local_430,local_42c,&local_428,&local_448);
    uVar6 = local_424 >> 2;
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
      ERR_add_error_data(1,local_448);
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}

