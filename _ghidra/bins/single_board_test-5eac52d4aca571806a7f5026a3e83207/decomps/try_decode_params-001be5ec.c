
int try_decode_params(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,int *param_6)

{
  int iVar1;
  EVP_PKEY *pkey;
  int iVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  EVP_PKEY *pkey_00;
  EVP_PKEY *pEVar4;
  undefined4 local_2c [2];
  undefined4 local_24 [2];
  
  local_2c[0] = param_3;
  if (param_1 == (char *)0x0) {
LAB_001be634:
    pkey_00 = (EVP_PKEY *)0x0;
    pkey = (EVP_PKEY *)0x0;
    for (iVar1 = 0; iVar2 = EVP_PKEY_asn1_get_count(), iVar1 < iVar2; iVar1 = iVar1 + 1) {
      local_24[0] = local_2c[0];
      if ((pkey_00 == (EVP_PKEY *)0x0) && (pkey_00 = EVP_PKEY_new(), pkey_00 == (EVP_PKEY *)0x0)) {
        ERR_put_error(0x2c,0x79,6,"crypto/store/loader_file.c",0x24a);
        break;
      }
      pEVar3 = EVP_PKEY_asn1_get0(iVar1);
      pEVar4 = pkey;
      if ((((-1 < *(int *)(pEVar3 + 8) << 0x1f) &&
           (iVar2 = EVP_PKEY_set_type(pkey_00,*(int *)pEVar3), iVar2 != 0)) &&
          (pEVar3 = EVP_PKEY_get0_asn1(pkey_00), pEVar3 != (EVP_PKEY_ASN1_METHOD *)0x0)) &&
         ((*(code **)(pEVar3 + 0x3c) != (code *)0x0 &&
          (iVar2 = (**(code **)(pEVar3 + 0x3c))(pkey_00,local_24,param_4), iVar2 != 0)))) {
        pEVar4 = pkey_00;
        if (pkey != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(pkey_00);
          pEVar4 = pkey;
        }
        pkey_00 = (EVP_PKEY *)0x0;
        *param_6 = *param_6 + 1;
      }
      pkey = pEVar4;
    }
    EVP_PKEY_free(pkey_00);
    if (*param_6 != 1) goto LAB_001be626;
  }
  else {
    iVar1 = pem_check_suffix(param_1,"PARAMETERS");
    if (iVar1 == 0) {
      return 0;
    }
    *param_6 = 1;
    if (iVar1 < 1) goto LAB_001be634;
    pkey = EVP_PKEY_new();
    if (pkey == (EVP_PKEY *)0x0) {
      ERR_put_error(0x2c,0x79,6,"crypto/store/loader_file.c",0x238);
      return 0;
    }
    iVar1 = EVP_PKEY_set_type_str(pkey,param_1,iVar1);
    if (((iVar1 == 0) || (pEVar3 = EVP_PKEY_get0_asn1(pkey), pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0))
       || ((*(code **)(pEVar3 + 0x3c) == (code *)0x0 ||
           (iVar1 = (**(code **)(pEVar3 + 0x3c))(pkey,local_2c,param_4), iVar1 == 0))))
    goto LAB_001be626;
  }
  iVar1 = OSSL_STORE_INFO_new_PARAMS(pkey);
  if (iVar1 != 0) {
    return iVar1;
  }
LAB_001be626:
  EVP_PKEY_free(pkey);
  return 0;
}

