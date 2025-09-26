
uint ossl_store_register_loader_int(int *param_1)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  byte *pbVar4;
  uint uVar5;
  
  pbVar4 = (byte *)*param_1;
  iVar2 = ossl_ctype_check(*pbVar4,3);
  if (iVar2 == 0) {
    if (*pbVar4 != 0) {
LAB_0016dc8e:
      ERR_put_error(0x2c,0x75,0x6a,"crypto/store/store_register.c",0xa5);
      ERR_add_error_data(2,"scheme=",*param_1);
      return 0;
    }
  }
  else if (*pbVar4 != 0) {
    iVar2 = ossl_ctype_check(*pbVar4,3);
    if (iVar2 == 0) goto LAB_0016dc70;
    do {
      do {
        do {
          pbVar4 = pbVar4 + 1;
          if (*pbVar4 == 0) goto LAB_0016dbfe;
          iVar2 = ossl_ctype_check(*pbVar4,3);
        } while (iVar2 != 0);
LAB_0016dc70:
        iVar2 = ossl_ctype_check(*pbVar4,4);
      } while (iVar2 != 0);
      bVar1 = *pbVar4;
      pcVar3 = strchr("+-.",(uint)bVar1);
    } while (pcVar3 != (char *)0x0);
    if (bVar1 != 0) goto LAB_0016dc8e;
  }
LAB_0016dbfe:
  if ((((param_1[2] != 0) && (param_1[6] != 0)) && (param_1[7] != 0)) &&
     ((param_1[8] != 0 && (param_1[9] != 0)))) {
    iVar2 = CRYPTO_THREAD_run_once(&registry_init,0x16db19);
    if ((iVar2 != 0) && (do_registry_init_ossl_ret_ != 0)) {
      CRYPTO_THREAD_write_lock(registry_lock);
      if ((loader_register != 0) ||
         (uVar5 = OPENSSL_LH_new(0x16db11,0x16db09), loader_register = uVar5, uVar5 != 0)) {
        uVar5 = 1;
        iVar2 = OPENSSL_LH_insert(loader_register,param_1);
        if (iVar2 == 0) {
          iVar2 = OPENSSL_LH_error(loader_register);
          uVar5 = (uint)(iVar2 == 0);
        }
      }
      CRYPTO_THREAD_unlock(registry_lock);
      return uVar5;
    }
    ERR_put_error(0x2c,0x75,0x41,"crypto/store/store_register.c",0xb4);
    return 0;
  }
  ERR_put_error(0x2c,0x75,0x74,"crypto/store/store_register.c",0xae);
  return 0;
}

