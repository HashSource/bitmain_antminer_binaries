
undefined4 * OSSL_STORE_SEARCH_by_key_fingerprint(EVP_MD *param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  char acStack_48 [20];
  char acStack_34 [20];
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x18,"crypto/store/store_lib.c",0x20a);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x2c,0x88,0x41,"crypto/store/store_lib.c",0x20e);
  }
  else {
    if ((param_1 != (EVP_MD *)0x0) && (iVar2 = EVP_MD_size(param_1), iVar2 != param_3)) {
      iVar2 = EVP_MD_size(param_1);
      BIO_snprintf(acStack_48,0x14,"%d",iVar2);
      BIO_snprintf(acStack_34,0x14,"%zu",param_3);
      ERR_put_error(0x2c,0x88,0x79,"crypto/store/store_lib.c",0x218);
      iVar2 = EVP_MD_type(param_1);
      pcVar3 = OBJ_nid2sn(iVar2);
      ERR_add_error_data(5,pcVar3," size is ",acStack_48,", fingerprint size is ",acStack_34);
    }
    puVar1[3] = param_1;
    puVar1[4] = param_2;
    puVar1[5] = param_3;
    *puVar1 = 3;
  }
  return puVar1;
}

