
/* WARNING: Restarted to delay deadcode elimination for space: stack */

BIGNUM * SRP_create_verifier(int param_1,int param_2,int *param_3,undefined4 *param_4,
                            BIGNUM *param_5,undefined4 param_6)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  undefined4 *puVar5;
  void *ptr;
  BIGNUM *pBVar6;
  BIGNUM *num;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  BIGNUM *local_13c8;
  BIGNUM *local_13c4;
  uchar *local_13c0;
  BIGNUM *pBStack_13b8;
  BIGNUM *local_13b4;
  uchar auStack_13b0 [2500];
  uchar auStack_9ec [2504];
  
  pBStack_13b8 = (BIGNUM *)0x0;
  local_13b4 = (BIGNUM *)0x0;
  if ((param_2 != 0 && param_1 != 0) && (param_4 != (undefined4 *)0x0 && param_3 != (int *)0x0)) {
    pBVar6 = (BIGNUM *)0x0;
    if (param_5 == (BIGNUM *)0x0) {
      puVar5 = (undefined4 *)SRP_get_default_gN(param_6);
      if (puVar5 != (undefined4 *)0x0) {
        pBVar2 = (BIGNUM *)puVar5[2];
        pBVar3 = (BIGNUM *)puVar5[1];
        pBVar7 = (BIGNUM *)*puVar5;
        local_13c4 = param_5;
        local_13c8 = param_5;
        goto LAB_0015f3e4;
      }
    }
    else {
      iVar1 = t_fromb64_constprop_5(auStack_13b0,param_5);
      if ((0 < iVar1) &&
         (pBVar2 = BN_bin2bn(auStack_13b0,iVar1,(BIGNUM *)0x0), pBVar2 != (BIGNUM *)0x0)) {
        iVar1 = t_fromb64_constprop_5(auStack_13b0,param_6);
        local_13c8 = pBVar2;
        if (iVar1 < 1) {
          local_13c4 = (BIGNUM *)0x0;
          num = pBVar6;
          pBVar8 = pBVar6;
          goto LAB_0015f4a2;
        }
        pBVar3 = BN_bin2bn(auStack_13b0,iVar1,(BIGNUM *)0x0);
        local_13c4 = pBVar3;
        if (pBVar3 == (BIGNUM *)0x0) {
          pBVar6 = (BIGNUM *)0x0;
          num = (BIGNUM *)0x0;
          pBVar8 = (BIGNUM *)0x0;
          goto LAB_0015f4a2;
        }
        pBVar7 = (BIGNUM *)&DAT_00219a8c;
LAB_0015f3e4:
        if (*param_3 == 0) {
          iVar1 = RAND_bytes(auStack_9ec,0x14);
          if (iVar1 < 1) {
            pBVar6 = (BIGNUM *)0x0;
            num = (BIGNUM *)0x0;
            pBVar8 = (BIGNUM *)0x0;
            goto LAB_0015f4a2;
          }
          pBVar6 = BN_bin2bn(auStack_9ec,0x14,(BIGNUM *)0x0);
LAB_0015f40c:
          local_13c0 = auStack_9ec;
          num = pBVar6;
          pBVar8 = pBVar6;
          pBStack_13b8 = pBVar6;
          if ((pBVar6 == (BIGNUM *)0x0) ||
             (pBVar6 = (BIGNUM *)
                       SRP_create_verifier_BN
                                 (param_1,param_2,&pBStack_13b8,&local_13b4,pBVar2,pBVar3),
             num = pBVar6, pBVar8 = pBVar6, pBVar6 == (BIGNUM *)0x0)) goto LAB_0015f4a2;
          iVar1 = BN_bn2bin(local_13b4,auStack_13b0);
          if (-1 < iVar1) {
            iVar4 = BN_num_bits(local_13b4);
            iVar1 = iVar4 + 0xe;
            if (-1 < iVar4 + 7) {
              iVar1 = iVar4 + 7;
            }
            num = (BIGNUM *)((iVar1 >> 3) << 1);
            pBVar6 = (BIGNUM *)CRYPTO_malloc((int)num,"crypto/srp/srp_vfy.c",0x27f);
            if (pBVar6 == (BIGNUM *)0x0) {
              pBVar8 = (BIGNUM *)0x0;
            }
            else {
              iVar4 = BN_num_bits(local_13b4);
              iVar1 = iVar4 + 0xe;
              if (-1 < iVar4 + 7) {
                iVar1 = iVar4 + 7;
              }
              iVar1 = t_tob64(pBVar6,auStack_13b0,iVar1 >> 3);
              if (iVar1 == 0) {
                pBVar8 = (BIGNUM *)0x0;
              }
              else {
                if (*param_3 == 0) {
                  ptr = CRYPTO_malloc(0x28,"crypto/srp/srp_vfy.c",0x287);
                  if (ptr == (void *)0x0) {
                    pBVar8 = (BIGNUM *)0x0;
                    goto LAB_0015f4a2;
                  }
                  iVar1 = t_tob64(ptr,local_13c0,0x14);
                  if (iVar1 == 0) {
                    CRYPTO_free(ptr);
                    pBVar8 = (BIGNUM *)0x0;
                    goto LAB_0015f4a2;
                  }
                  *param_3 = (int)ptr;
                }
                *param_4 = pBVar6;
                pBVar6 = (BIGNUM *)0x0;
                pBVar8 = pBVar7;
              }
            }
            goto LAB_0015f4a2;
          }
        }
        else {
          iVar1 = t_fromb64_constprop_5(auStack_9ec,*param_3);
          if (0 < iVar1) {
            pBVar6 = BN_bin2bn(auStack_9ec,iVar1,(BIGNUM *)0x0);
            goto LAB_0015f40c;
          }
        }
        pBVar6 = (BIGNUM *)0x0;
        num = (BIGNUM *)0x0;
        pBVar8 = (BIGNUM *)0x0;
        goto LAB_0015f4a2;
      }
    }
  }
  local_13c4 = (BIGNUM *)0x0;
  pBVar6 = (BIGNUM *)0x0;
  local_13c8 = (BIGNUM *)0x0;
  num = (BIGNUM *)0x0;
  pBVar8 = (BIGNUM *)0x0;
LAB_0015f4a2:
  BN_free(local_13c8);
  BN_free(local_13c4);
  CRYPTO_clear_free(pBVar6,num,"crypto/srp/srp_vfy.c",0x298);
  BN_clear_free(pBStack_13b8);
  BN_clear_free(local_13b4);
  return pBVar8;
}

