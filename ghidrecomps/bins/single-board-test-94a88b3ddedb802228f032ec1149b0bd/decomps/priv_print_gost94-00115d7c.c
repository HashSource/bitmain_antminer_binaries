
undefined4 priv_print_gost94(BIO *param_1,EVP_PKEY *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  EC_KEY *key;
  char *pcVar4;
  BIGNUM *pBVar5;
  BIGNUM *local_1c [2];
  
  iVar2 = BIO_indent(param_1,param_3,0x80);
  if (iVar2 == 0) {
    return 0;
  }
  BIO_printf(param_1,DAT_00115e7c);
  iVar2 = EVP_PKEY_base_id(param_2);
  if (iVar2 == 0x32b) {
    key = (EC_KEY *)EVP_PKEY_get0(param_2);
    if (key != (EC_KEY *)0x0) {
      pBVar5 = EC_KEY_get0_private_key(key);
      goto joined_r0x00115e76;
    }
  }
  else if ((iVar2 == 0x32c) && (pvVar3 = EVP_PKEY_get0(param_2), pvVar3 != (void *)0x0)) {
    pBVar5 = *(BIGNUM **)((int)pvVar3 + 0x1c);
joined_r0x00115e76:
    if (pBVar5 != (BIGNUM *)0x0) {
      BN_print(param_1,pBVar5);
      goto LAB_00115db8;
    }
  }
  BIO_printf(param_1,DAT_00115e80);
LAB_00115db8:
  BIO_printf(param_1,DAT_00115e84);
  pvVar3 = EVP_PKEY_get0(param_2);
  pBVar5 = *(BIGNUM **)((int)pvVar3 + 0x18);
  BIO_indent(param_1,param_3,0x80);
  BIO_printf(param_1,DAT_00115e88);
  BN_print(param_1,pBVar5);
  BIO_printf(param_1,DAT_00115e84);
  piVar1 = DAT_00115e8c;
  pvVar3 = EVP_PKEY_get0(param_2);
  local_1c[0] = BN_new();
  pcVar4 = (char *)piVar1[3];
  do {
    if (pcVar4 == (char *)0x0) {
      iVar2 = 0;
      BN_free(local_1c[0]);
LAB_00115e24:
      BIO_indent(param_1,param_3,0x80);
      pcVar4 = OBJ_nid2ln(iVar2);
      BIO_printf(param_1,DAT_00115e90,pcVar4);
      return 1;
    }
    BN_dec2bn(local_1c,pcVar4);
    iVar2 = BN_cmp(local_1c[0],*(BIGNUM **)((int)pvVar3 + 0x10));
    if (iVar2 == 0) {
      BN_free(local_1c[0]);
      iVar2 = *piVar1;
      goto LAB_00115e24;
    }
    pcVar4 = (char *)piVar1[7];
    HintPreloadData(piVar1 + 0x23);
    piVar1 = piVar1 + 4;
  } while( true );
}

