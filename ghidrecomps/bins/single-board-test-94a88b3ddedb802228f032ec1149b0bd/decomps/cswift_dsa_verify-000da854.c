
int cswift_dsa_verify(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  BN_CTX *ctx;
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar3;
  BIGNUM *pBVar4;
  ulong *puVar5;
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
  if (ctx == (BN_CTX *)0x0) {
    return -1;
  }
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_84);
  if (iVar1 != 0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    iVar1 = -1;
    ERR_put_error(CSWIFT_lib_error_code,0x66,0x6c,"e_cswift.c",0x393);
    goto LAB_000daa7e;
  }
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  a = BN_CTX_get(ctx);
  a_00 = BN_CTX_get(ctx);
  a_01 = BN_CTX_get(ctx);
  a_02 = BN_CTX_get(ctx);
  if (a_02 == (BIGNUM *)0x0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x66,0x66,"e_cswift.c",0x39f);
    iVar1 = -1;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_4 + 0xc) + 4);
    if (pBVar2->dmax < iVar1) {
      pBVar4 = bn_expand2(pBVar2,iVar1);
      if (pBVar4 != (BIGNUM *)0x0) {
        iVar1 = *(int *)(*(int *)(param_4 + 0x10) + 4);
        if (a->dmax < iVar1) goto LAB_000daaaa;
        goto LAB_000da8ca;
      }
    }
    else {
      iVar1 = *(int *)(*(int *)(param_4 + 0x10) + 4);
      if (a->dmax < iVar1) {
LAB_000daaaa:
        pBVar4 = bn_expand2(a,iVar1);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_000daa18;
      }
LAB_000da8ca:
      iVar1 = *(int *)(*(int *)(param_4 + 0x14) + 4);
      if ((iVar1 <= a_00->dmax) || (pBVar4 = bn_expand2(a_00,iVar1), pBVar4 != (BIGNUM *)0x0)) {
        iVar1 = *(int *)(*(int *)(param_4 + 0x18) + 4);
        if (a_01->dmax < iVar1) {
          pBVar4 = bn_expand2(a_01,iVar1);
          if (pBVar4 == (BIGNUM *)0x0) goto LAB_000daa18;
          iVar1 = a_02->dmax;
        }
        else {
          iVar1 = a_02->dmax;
        }
        if ((0x27 < iVar1) || (pBVar4 = bn_expand2(a_02,0x28), pBVar4 != (BIGNUM *)0x0)) {
          local_54 = 3;
          local_50 = BN_bn2bin(*(BIGNUM **)(param_4 + 0xc),(uchar *)pBVar2->d);
          local_4c = pBVar2->d;
          local_48 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x10),(uchar *)a->d);
          local_44 = a->d;
          local_40 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x14),(uchar *)a_00->d);
          local_3c = a_00->d;
          local_38 = BN_bn2bin(*(BIGNUM **)(param_4 + 0x18),(uchar *)a_01->d);
          local_34 = a_01->d;
          iVar1 = (*p_CSwift_AttachKeyParam)(local_84,&local_54);
          if (iVar1 == -0x2716) {
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = ERR_get_next_error_library();
            }
            ERR_put_error(CSWIFT_lib_error_code,0x66,0x65,"e_cswift.c",0x3ba);
            iVar1 = -1;
          }
          else if (iVar1 == 0) {
            puVar5 = a_02->d;
            local_5c = 0x28;
            local_64 = param_2;
            local_60 = param_1;
            local_58 = puVar5;
            memset(puVar5,0,0x28);
            pBVar2 = (BIGNUM *)*param_3;
            iVar3 = BN_num_bits(pBVar2);
            iVar1 = iVar3 + 0xe;
            if (-1 < iVar3 + 7) {
              iVar1 = iVar3 + 7;
            }
            BN_bn2bin(pBVar2,(uchar *)((int)puVar5 + (0x14 - (iVar1 >> 3))));
            puVar5 = local_58;
            pBVar2 = (BIGNUM *)param_3[1];
            iVar3 = BN_num_bits(pBVar2);
            iVar1 = iVar3 + 0xe;
            if (-1 < iVar3 + 7) {
              iVar1 = iVar3 + 7;
            }
            BN_bn2bin(pBVar2,(uchar *)((0x28 - (iVar1 >> 3)) + (int)puVar5));
            local_78 = &local_80;
            local_7c = 4;
            iVar1 = (*p_CSwift_SimpleRequest)(local_84,4,&local_64,2,&local_7c,1);
            if (iVar1 == 0) {
              iVar1 = local_80;
              if (local_80 != 0) {
                iVar1 = 1;
              }
            }
            else {
              if (CSWIFT_lib_error_code == 0) {
                CSWIFT_lib_error_code = ERR_get_next_error_library();
              }
              ERR_put_error(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",0x3d4);
              sprintf(acStack_74,"%ld",iVar1);
              ERR_add_error_data(2,"CryptoSwift error number is ",acStack_74);
              iVar1 = -1;
            }
          }
          else {
            if (CSWIFT_lib_error_code == 0) {
              CSWIFT_lib_error_code = ERR_get_next_error_library();
            }
            ERR_put_error(CSWIFT_lib_error_code,0x66,0x6b,"e_cswift.c",0x3bf);
            sprintf((char *)&local_64,"%ld",iVar1);
            ERR_add_error_data(2,"CryptoSwift error number is ",&local_64);
            iVar1 = -1;
          }
          goto LAB_000daa78;
        }
      }
    }
LAB_000daa18:
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(CSWIFT_lib_error_code,0x66,0x67,"e_cswift.c",0x3a7);
    iVar1 = -1;
  }
LAB_000daa78:
  (*p_CSwift_ReleaseAccContext)(local_84);
LAB_000daa7e:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar1;
}

