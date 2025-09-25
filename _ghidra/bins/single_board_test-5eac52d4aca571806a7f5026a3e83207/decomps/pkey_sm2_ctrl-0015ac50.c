
undefined4 pkey_sm2_ctrl(int param_1,int param_2,size_t param_3,undefined4 *param_4)

{
  EC_GROUP *pEVar1;
  void *__dest;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x14);
  if (param_2 == 0x1001) {
    pEVar1 = EC_GROUP_new_by_curve_name(param_3);
    if (pEVar1 == (EC_GROUP *)0x0) {
      ERR_put_error(0x35,0x6d,0x6c,"crypto/sm2/sm2_pmeth.c",0xad);
      return 0;
    }
    EC_GROUP_free((EC_GROUP *)*puVar2);
    *puVar2 = pEVar1;
  }
  else {
    if (0x1001 < param_2) {
      if (param_2 == 0x100b) {
        if ((int)param_3 < 1) {
          CRYPTO_free((void *)puVar2[2]);
          puVar2[2] = 0;
        }
        else {
          __dest = CRYPTO_malloc(param_3,"crypto/sm2/sm2_pmeth.c",0xc6);
          if (__dest == (void *)0x0) {
            ERR_put_error(0x35,0x6d,0x41,"crypto/sm2/sm2_pmeth.c",200);
            return 0;
          }
          memcpy(__dest,param_4,param_3);
          CRYPTO_free((void *)puVar2[2]);
          puVar2[2] = __dest;
        }
        puVar2[3] = param_3;
        puVar2[4] = 1;
        return 1;
      }
      if (0x100b < param_2) {
        if (param_2 == 0x100c) {
          memcpy(param_4,(void *)puVar2[2],puVar2[3]);
          return 1;
        }
        if (param_2 != 0x100d) {
          return 0xfffffffe;
        }
        *param_4 = puVar2[3];
        return 1;
      }
      if (param_2 != 0x1002) {
        return 0xfffffffe;
      }
      if ((EC_GROUP *)*puVar2 != (EC_GROUP *)0x0) {
        EC_GROUP_set_asn1_flag((EC_GROUP *)*puVar2,param_3);
        return 1;
      }
      ERR_put_error(0x35,0x6d,0x6d,"crypto/sm2/sm2_pmeth.c",0xb6);
      return 0;
    }
    if (param_2 != 7) {
      if (param_2 == 0xd) {
        *param_4 = puVar2[1];
        return 1;
      }
      if (param_2 != 1) {
        return 0xfffffffe;
      }
      puVar2[1] = param_4;
      return 1;
    }
  }
  return 1;
}

