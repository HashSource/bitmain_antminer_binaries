
int param_print_gost01(BIO *param_1,EVP_PKEY *param_2,int param_3)

{
  EC_KEY *key;
  EC_GROUP *group;
  int n;
  int iVar1;
  char *pcVar2;
  
  key = (EC_KEY *)EVP_PKEY_get0(param_2);
  group = EC_KEY_get0_group(key);
  n = EC_GROUP_get_curve_name(group);
  iVar1 = BIO_indent(param_1,param_3,0x80);
  if (iVar1 != 0) {
    pcVar2 = OBJ_nid2ln(n);
    BIO_printf(param_1,DAT_001164d0,pcVar2);
    iVar1 = 1;
  }
  return iVar1;
}

