
int ubsec_mod_exp(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  BIGNUM *pBVar6;
  int iVar7;
  ulong *puVar8;
  ulong *puVar9;
  code *pcVar10;
  ulong *puVar11;
  int local_2c [2];
  
  iVar7 = DAT_000deefc;
  local_2c[0] = 0;
  if (*(int *)(DAT_000deefc + 8) == 0) {
    iVar5 = *(int *)(DAT_000deefc + 4);
    if (iVar5 == 0) {
      iVar5 = ERR_get_next_error_library();
      *(int *)(iVar7 + 4) = iVar5;
    }
    ERR_put_error(iVar5,0x6a,0x69,DAT_000def08,0x23d);
    iVar7 = 0;
  }
  else {
    local_2c[0] = BN_num_bits(param_4);
    if (*(int *)(DAT_000def00 + 0xcc) < local_2c[0]) {
      iVar5 = *(int *)(iVar7 + 4);
      if (iVar5 == 0) {
        iVar5 = ERR_get_next_error_library();
        *(int *)(iVar7 + 4) = iVar5;
      }
      ERR_put_error(iVar5,0x6a,0x6b,DAT_000def08,0x244);
    }
    else {
      if ((param_1->dmax < param_4->top) &&
         (pBVar6 = bn_expand2(param_1,param_4->top), pBVar6 == (BIGNUM *)0x0)) {
        iVar5 = *(int *)(iVar7 + 4);
        if (iVar5 == 0) {
          iVar5 = ERR_get_next_error_library();
          *(int *)(iVar7 + 4) = iVar5;
        }
        ERR_put_error(iVar5,0x6a,0x65,DAT_000def08,0x249);
        return 0;
      }
      iVar1 = (**(code **)(iVar7 + 0x14))(DAT_000def04);
      iVar5 = DAT_000deefc;
      if (iVar1 < 1) {
        iVar7 = *(int *)(DAT_000deefc + 4);
        if (iVar7 == 0) {
          iVar7 = ERR_get_next_error_library();
          *(int *)(iVar5 + 4) = iVar7;
        }
        ERR_put_error(iVar7,0x6a,0x6c,DAT_000def08,0x24f);
      }
      else {
        puVar8 = param_2->d;
        pcVar10 = *(code **)(DAT_000deefc + 0x24);
        iVar2 = BN_num_bits(param_2);
        puVar11 = param_4->d;
        iVar3 = BN_num_bits(param_4);
        puVar9 = param_3->d;
        iVar4 = BN_num_bits(param_3);
        iVar2 = (*pcVar10)(iVar1,puVar8,iVar2,puVar11,iVar3,puVar9,iVar4,param_1->d,local_2c);
        if (iVar2 == 0) {
          (**(code **)(iVar5 + 0x18))(iVar1);
          iVar5 = BN_num_bits(param_4);
          iVar7 = iVar5 + 0x3e;
          if (-1 < iVar5 + 0x1f) {
            iVar7 = iVar5 + 0x1f;
          }
          param_1->top = iVar7 >> 5;
          return 1;
        }
        iVar2 = *(int *)(iVar5 + 4);
        if (iVar2 == 0) {
          iVar2 = ERR_get_next_error_library();
          *(int *)(iVar5 + 4) = iVar2;
        }
        ERR_put_error(iVar2,0x6a,0x6a,DAT_000def08,599);
        (**(code **)(iVar7 + 0x18))(iVar1);
      }
    }
    iVar7 = BN_mod_exp(param_1,param_2,param_3,param_4,param_5);
  }
  return iVar7;
}

