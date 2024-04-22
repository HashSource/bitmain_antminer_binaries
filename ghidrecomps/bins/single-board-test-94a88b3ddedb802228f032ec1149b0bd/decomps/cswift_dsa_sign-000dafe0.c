
DSA_SIG * cswift_dsa_sign(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  BN_CTX *ctx;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  DSA_SIG *pDVar7;
  ulong *puVar8;
  code *pcVar9;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  size_t local_6c;
  ulong *local_68;
  char acStack_64 [16];
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
  iVar1 = DAT_000db280;
  if (ctx == (BN_CTX *)0x0) {
    return (DSA_SIG *)0x0;
  }
  iVar2 = (**(code **)(DAT_000db280 + 0xc))(&local_78);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar2;
    }
    pDVar7 = (DSA_SIG *)0x0;
    ERR_put_error(iVar2,0x65,0x6c,DAT_000db284,0x32d);
    goto LAB_000db15c;
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
    pDVar7 = (DSA_SIG *)0x0;
    ERR_put_error(iVar2,0x65,0x66,DAT_000db2b0,0x339);
    goto LAB_000db1f2;
  }
  iVar2 = *(int *)(*(int *)(param_3 + 0xc) + 4);
  if (pBVar3->dmax < iVar2) {
    pBVar4 = bn_expand2(pBVar3,iVar2);
    if (pBVar4 != (BIGNUM *)0x0) {
      iVar2 = *(int *)(*(int *)(param_3 + 0x10) + 4);
      if (a->dmax < iVar2) goto LAB_000db212;
      goto LAB_000db056;
    }
LAB_000db196:
    iVar2 = DAT_000db280;
    iVar5 = *(int *)(iVar1 + 4);
    if (iVar5 == 0) {
      iVar5 = ERR_get_next_error_library();
      *(int *)(iVar2 + 4) = iVar5;
    }
    pDVar7 = (DSA_SIG *)0x0;
    ERR_put_error(iVar5,0x65,0x67,DAT_000db284,0x341);
  }
  else {
    iVar2 = *(int *)(*(int *)(param_3 + 0x10) + 4);
    if (a->dmax < iVar2) {
LAB_000db212:
      pBVar4 = bn_expand2(a,iVar2);
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_000db196;
    }
LAB_000db056:
    iVar2 = *(int *)(*(int *)(param_3 + 0x14) + 4);
    if ((a_00->dmax < iVar2) && (pBVar4 = bn_expand2(a_00,iVar2), pBVar4 == (BIGNUM *)0x0))
    goto LAB_000db196;
    iVar2 = *(int *)(*(int *)(param_3 + 0x1c) + 4);
    if (a_01->dmax < iVar2) {
      pBVar4 = bn_expand2(a_01,iVar2);
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_000db196;
      pBVar4 = *(BIGNUM **)(param_3 + 0xc);
      iVar2 = pBVar4->top;
      if (a_02->dmax < iVar2) goto LAB_000db1cc;
    }
    else {
      pBVar4 = *(BIGNUM **)(param_3 + 0xc);
      iVar2 = pBVar4->top;
      if (a_02->dmax < iVar2) {
LAB_000db1cc:
        pBVar4 = bn_expand2(a_02,iVar2);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_000db196;
        pBVar4 = *(BIGNUM **)(param_3 + 0xc);
      }
    }
    local_54 = 3;
    local_50 = BN_bn2bin(pBVar4,(uchar *)pBVar3->d);
    iVar2 = DAT_000db280;
    local_4c = pBVar3->d;
    local_48 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x10),(uchar *)a->d);
    local_44 = a->d;
    local_40 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x14),(uchar *)a_00->d);
    local_3c = a_00->d;
    local_38 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x1c),(uchar *)a_01->d);
    local_34 = a_01->d;
    iVar5 = (**(code **)(iVar1 + 0x10))(local_78,&local_54);
    if (iVar5 == -0x2716) {
      iVar5 = *(int *)(iVar2 + 4);
      if (iVar5 == 0) {
        iVar5 = ERR_get_next_error_library();
        *(int *)(iVar2 + 4) = iVar5;
      }
      pDVar7 = (DSA_SIG *)0x0;
      ERR_put_error(iVar5,0x65,0x65,DAT_000db284,0x354);
    }
    else {
      if (iVar5 == 0) {
        local_74 = param_2;
        local_70 = param_1;
        iVar6 = BN_num_bits(*(BIGNUM **)(param_3 + 0xc));
        iVar5 = iVar6 + 7;
        if (iVar6 + 7 < 0) {
          iVar5 = iVar6 + 0xe;
        }
        local_6c = iVar5 >> 3;
        memset(a_02->d,0,local_6c);
        local_68 = a_02->d;
        iVar5 = (**(code **)(iVar2 + 0x14))(local_78,3,&local_74,1,&local_6c,1);
        if (iVar5 == 0) {
          pDVar7 = DSA_SIG_new();
          if (pDVar7 != (DSA_SIG *)0x0) {
            pBVar3 = BN_bin2bn((uchar *)a_02->d,0x14,(BIGNUM *)0x0);
            puVar8 = a_02->d;
            pDVar7->r = pBVar3;
            pBVar3 = BN_bin2bn((uchar *)(puVar8 + 5),0x14,(BIGNUM *)0x0);
            pcVar9 = *(code **)(iVar1 + 0x18);
            pDVar7->s = pBVar3;
            (*pcVar9)(local_78);
            goto LAB_000db15c;
          }
          goto LAB_000db1f2;
        }
        iVar6 = *(int *)(iVar2 + 4);
        if (iVar6 == 0) {
          iVar6 = ERR_get_next_error_library();
          *(int *)(iVar2 + 4) = iVar6;
        }
        iVar2 = 0x36a;
      }
      else {
        iVar6 = *(int *)(iVar2 + 4);
        if (iVar6 == 0) {
          iVar6 = ERR_get_next_error_library();
          *(int *)(iVar2 + 4) = iVar6;
        }
        iVar2 = 0x359;
      }
      ERR_put_error(iVar6,0x65,0x6b,DAT_000db284,iVar2);
      pDVar7 = (DSA_SIG *)0x0;
      sprintf(acStack_64,DAT_000db288,iVar5);
      ERR_add_error_data(2,DAT_000db28c,acStack_64);
    }
  }
LAB_000db1f2:
  (**(code **)(iVar1 + 0x18))(local_78);
LAB_000db15c:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return pDVar7;
}

