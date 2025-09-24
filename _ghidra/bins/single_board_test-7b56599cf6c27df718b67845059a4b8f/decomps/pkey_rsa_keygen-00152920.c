
int pkey_rsa_keygen(undefined4 *param_1,EVP_PKEY *param_2)

{
  RSA *r;
  int iVar1;
  BIGNUM *a;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = (undefined4 *)param_1[5];
  if (puVar4[1] == 0) {
    a = BN_new();
    puVar4[1] = a;
    if (a == (BIGNUM *)0x0) {
      return 0;
    }
    iVar5 = BN_set_word(a,0x10001);
    if (iVar5 == 0) {
      return 0;
    }
  }
  r = RSA_new();
  if (r == (RSA *)0x0) {
    return 0;
  }
  iVar5 = param_1[7];
  if (iVar5 != 0) {
    iVar5 = BN_GENCB_new();
    if (iVar5 == 0) goto LAB_001529d0;
    evp_pkey_set_cb_translate(iVar5,param_1);
  }
  iVar1 = RSA_generate_multi_prime_key(r,*puVar4,puVar4[2],puVar4[1],iVar5);
  BN_GENCB_free(iVar5);
  if (iVar1 < 1) {
    RSA_free(r);
    return iVar1;
  }
  iVar5 = *(int *)*param_1;
  if (iVar5 == 0x390) {
    iVar2 = param_1[5];
    iVar3 = *(int *)(iVar2 + 0x20);
    if ((*(int *)(iVar2 + 0x18) == 0) && (*(int *)(iVar2 + 0x1c) == 0)) {
      if (iVar3 == -2) goto LAB_00152976;
    }
    else if (iVar3 == -2) {
      iVar3 = 0;
    }
    iVar5 = rsa_pss_params_create(*(int *)(iVar2 + 0x18),*(int *)(iVar2 + 0x1c),iVar3);
    (r->ex_data).dummy = iVar5;
    if (iVar5 == 0) {
LAB_001529d0:
      RSA_free(r);
      return iVar5;
    }
    iVar5 = *(int *)*param_1;
  }
LAB_00152976:
  EVP_PKEY_assign(param_2,iVar5,r);
  return iVar1;
}

