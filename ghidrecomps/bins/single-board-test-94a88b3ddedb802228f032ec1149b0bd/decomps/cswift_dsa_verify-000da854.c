
int cswift_dsa_verify(undefined4 param_1,undefined4 param_2,BIGNUM **param_3,int param_4)

{
  int iVar1;
  BN_CTX *ctx;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar4;
  int iVar5;
  BIGNUM *pBVar6;
  ulong *puVar7;
  undefined4 local_84;
  int local_80;
  undefined4 local_7c;
  int *local_78;
  char acStack_74 [16];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  ulong *local_58;
  undefined4 local_54;
  int local_50;
  ulong *local_4c;
  int local_48;
  ulong *local_44;
  int local_40;
  ulong *local_3c;
  int local_38;
  ulong *local_34;
  
  ctx = BN_CTX_new();
  iVar1 = DAT_000dab04;
  if (ctx == (BN_CTX *)0x0) {
    return -1;
  }
  iVar2 = (**(code **)(DAT_000dab04 + 0xc))(&local_84);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar2;
    }
    iVar4 = -1;
    ERR_put_error(iVar2,0x66,0x6c,DAT_000dab08,0x393);
    goto LAB_000daa7e;
  }
  BN_CTX_start(ctx);
  pBVar3 = BN_CTX_get(ctx);
  a = BN_CTX_get(ctx);
  a_00 = BN_CTX_get(ctx);
  a_01 = BN_CTX_get(ctx);
  a_02 = BN_CTX_get(ctx);
  if (a_02 == (BIGNUM *)0x0) {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar2;
    }
    ERR_put_error(iVar2,0x66,0x66,DAT_000dab68,0x39f);
    iVar4 = -1;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_4 + 0xc) + 4);
    if (pBVar3->dmax < iVar2) {
      pBVar6 = bn_expand2(pBVar3,iVar2);
      if (pBVar6 != (BIGNUM *)0x0) {
        iVar2 = *(int *)(*(int *)(param_4 + 0x10) + 4);
        if (a->dmax < iVar2) goto LAB_000daaaa;
        goto LAB_000da8ca;
      }
    }
    else {
      iVar2 = *(int *)(*(int *)(param_4 + 0x10) + 4);
      if (a->dmax < iVar2) {
LAB_000daaaa:
        pBVar6 = bn_expand2(a,iVar2);
        if (pBVar6 == (BIGNUM *)0x0) goto LAB_000daa18;
      }
LAB_000da8ca:
      iVar2 = *(int *)(*(int *)(param_4 + 0x14) + 4);
      if ((iVar2 <= a_00->dmax) || (pBVar6 = bn_expand2(a_00,iVar2), pBVar6 != (BIGNUM *)0x0)) {
        iVar2 = *(int *)(*(int *)(param_4 + 0x18) + 4);
        if (a_01->dmax < iVar2) {
          pBVar6 = bn_expand2(a_01,iVar2);
          if (pBVar6 == (BIGNUM *)0x0) goto LAB_000daa18;
          iVar2 = a_02->dmax;
        }
        else {
          iVar2 = a_02->dmax;
        }
        if ((0x27 < iVar2) || (pBVar6 = bn_expand2(a_02,0x28), pBVar6 != (BIGNUM *)0x0)) {
          local_54 = 3;
          local_50 = BN_bn2bin(*(BIGNUM **)(param_4 + 0xc),(uchar *)pBVar3->d);
          iVar2 = DAT_000dab04;
          local_4c = pBVar3->d;
          local_48 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x10),(uchar *)a->d);
          local_44 = a->d;
          local_40 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x14),(uchar *)a_00->d);
          local_3c = a_00->d;
          local_38 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x18),(uchar *)a_01->d);
          local_34 = a_01->d;
          iVar4 = (**(code **)(iVar1 + 0x10))(local_84,&local_54);
          if (iVar4 == -0x2716) {
            iVar4 = *(int *)(iVar2 + 4);
            if (iVar4 == 0) {
              iVar4 = ERR_get_next_error_library();
              *(int *)(iVar2 + 4) = iVar4;
            }
            ERR_put_error(iVar4,0x66,0x65,DAT_000dab08,0x3ba);
            iVar4 = -1;
          }
          else if (iVar4 == 0) {
            puVar7 = a_02->d;
            local_5c = 0x28;
            local_64 = param_2;
            local_60 = param_1;
            local_58 = puVar7;
            memset(puVar7,0,0x28);
            pBVar3 = *param_3;
            iVar5 = BN_num_bits(pBVar3);
            iVar4 = iVar5 + 0xe;
            if (-1 < iVar5 + 7) {
              iVar4 = iVar5 + 7;
            }
            BN_bn2bin(pBVar3,(uchar *)((int)puVar7 + (0x14 - (iVar4 >> 3))));
            puVar7 = local_58;
            pBVar3 = param_3[1];
            iVar5 = BN_num_bits(pBVar3);
            iVar4 = iVar5 + 0xe;
            if (-1 < iVar5 + 7) {
              iVar4 = iVar5 + 7;
            }
            BN_bn2bin(pBVar3,(uchar *)((0x28 - (iVar4 >> 3)) + (int)puVar7));
            local_78 = &local_80;
            local_7c = 4;
            iVar4 = (**(code **)(iVar2 + 0x14))(local_84,4,&local_64,2,&local_7c,1);
            if (iVar4 == 0) {
              iVar4 = local_80;
              if (local_80 != 0) {
                iVar4 = 1;
              }
            }
            else {
              iVar5 = *(int *)(iVar2 + 4);
              if (iVar5 == 0) {
                iVar5 = ERR_get_next_error_library();
                *(int *)(iVar2 + 4) = iVar5;
              }
              ERR_put_error(iVar5,0x66,0x6b,DAT_000dab68,0x3d4);
              sprintf(acStack_74,DAT_000dab6c,iVar4);
              ERR_add_error_data(2,DAT_000dab70,acStack_74);
              iVar4 = -1;
            }
          }
          else {
            iVar5 = *(int *)(iVar2 + 4);
            if (iVar5 == 0) {
              iVar5 = ERR_get_next_error_library();
              *(int *)(iVar2 + 4) = iVar5;
            }
            ERR_put_error(iVar5,0x66,0x6b,DAT_000dab08,0x3bf);
            sprintf((char *)&local_64,DAT_000dab0c,iVar4);
            ERR_add_error_data(2,DAT_000dab10,&local_64);
            iVar4 = -1;
          }
          goto LAB_000daa78;
        }
      }
    }
LAB_000daa18:
    iVar2 = DAT_000dab04;
    iVar4 = *(int *)(iVar1 + 4);
    if (iVar4 == 0) {
      iVar4 = ERR_get_next_error_library();
      *(int *)(iVar2 + 4) = iVar4;
    }
    ERR_put_error(iVar4,0x66,0x67,DAT_000dab08,0x3a7);
    iVar4 = -1;
  }
LAB_000daa78:
  (**(code **)(iVar1 + 0x18))(local_84);
LAB_000daa7e:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar4;
}

