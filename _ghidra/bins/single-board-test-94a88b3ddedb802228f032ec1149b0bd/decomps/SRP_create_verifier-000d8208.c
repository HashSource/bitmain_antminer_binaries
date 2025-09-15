
BIGNUM * SRP_create_verifier(int param_1,int param_2,int *param_3,undefined4 *param_4,int param_5,
                            undefined4 param_6)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *len;
  int iVar2;
  BIGNUM *ptr;
  undefined4 *puVar3;
  void *pvVar4;
  BIGNUM *local_13bc;
  BIGNUM *local_13b8;
  BIGNUM *local_13b4;
  uchar auStack_13b0 [2500];
  uchar auStack_9ec [2504];
  
  local_13b8 = (BIGNUM *)0x0;
  local_13b4 = (BIGNUM *)0x0;
  a_00 = (BIGNUM *)(uint)(param_1 == 0 || param_2 == 0);
  if (param_1 == 0 || param_2 == 0) {
    len = (BIGNUM *)0x0;
    a_00 = (BIGNUM *)0x0;
    a = (BIGNUM *)0x0;
  }
  else {
    len = a_00;
    a = a_00;
    if (param_3 != (int *)0x0 && param_4 != (undefined4 *)0x0) {
      if (param_5 != 0) {
        iVar1 = t_fromb64(auStack_13b0,param_5);
        if (iVar1 == 0) {
          a = (BIGNUM *)0x0;
        }
        else {
          a = BN_bin2bn(auStack_13b0,iVar1,(BIGNUM *)0x0);
          iVar1 = t_fromb64(auStack_13b0,param_6);
          if (iVar1 != 0) {
            local_13bc = (BIGNUM *)&DAT_00136778;
            a_00 = BN_bin2bn(auStack_13b0,iVar1,(BIGNUM *)0x0);
            goto LAB_000d8290;
          }
        }
        a_00 = (BIGNUM *)0x0;
        len = (BIGNUM *)0x0;
        goto LAB_000d831e;
      }
      puVar3 = (undefined4 *)SRP_get_default_gN(param_6);
      if (puVar3 == (undefined4 *)0x0) {
        return (BIGNUM *)0x0;
      }
      local_13bc = (BIGNUM *)*puVar3;
      a_00 = (BIGNUM *)puVar3[1];
      a = (BIGNUM *)puVar3[2];
LAB_000d8290:
      if (*param_3 == 0) {
        iVar1 = RAND_pseudo_bytes(auStack_9ec,0x14);
        if (-1 < iVar1) {
          local_13b8 = BN_bin2bn(auStack_9ec,0x14,(BIGNUM *)0x0);
          goto LAB_000d82b2;
        }
        len = (BIGNUM *)0x0;
      }
      else {
        len = (BIGNUM *)t_fromb64(auStack_9ec,*param_3);
        if (len != (BIGNUM *)0x0) {
          local_13b8 = BN_bin2bn(auStack_9ec,(int)len,(BIGNUM *)0x0);
LAB_000d82b2:
          len = (BIGNUM *)SRP_create_verifier_BN(param_1,param_2,&local_13b8,&local_13b4,a,a_00);
          if (len != (BIGNUM *)0x0) {
            BN_bn2bin(local_13b4,auStack_13b0);
            iVar2 = BN_num_bits(local_13b4);
            iVar1 = iVar2 + 7;
            if (iVar2 + 7 < 0) {
              iVar1 = iVar2 + 0xe;
            }
            ptr = (BIGNUM *)CRYPTO_malloc((iVar1 >> 3) << 1,"srp_vfy.c",0x237);
            len = ptr;
            if (ptr != (BIGNUM *)0x0) {
              iVar2 = BN_num_bits(local_13b4);
              iVar1 = iVar2 + 0xe;
              if (-1 < iVar2 + 7) {
                iVar1 = iVar2 + 7;
              }
              t_tob64(ptr,auStack_13b0,iVar1 >> 3);
              *param_4 = ptr;
              len = local_13bc;
              if (*param_3 == 0) {
                pvVar4 = CRYPTO_malloc(0x28,"srp_vfy.c",0x23f);
                if (pvVar4 == (void *)0x0) {
                  CRYPTO_free(ptr);
                  len = (BIGNUM *)0x0;
                }
                else {
                  t_tob64(pvVar4,auStack_9ec,0x14);
                  *param_3 = (int)pvVar4;
                }
              }
            }
          }
        }
      }
    }
  }
  if (param_5 == 0) {
    return len;
  }
LAB_000d831e:
  BN_free(a);
  BN_free(a_00);
  return len;
}

