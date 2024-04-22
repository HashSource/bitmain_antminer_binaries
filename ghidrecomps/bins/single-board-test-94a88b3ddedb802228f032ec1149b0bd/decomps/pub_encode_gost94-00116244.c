
int pub_encode_gost94(X509_PUBKEY *param_1,EVP_PKEY *param_2)

{
  void *pvVar1;
  int iVar2;
  ASN1_OBJECT *aobj;
  int iVar3;
  uchar *to;
  ASN1_OCTET_STRING *str;
  uchar *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  uchar *puVar7;
  int iVar8;
  void *local_34;
  uchar *local_2c [2];
  
  local_2c[0] = (uchar *)0x0;
  pvVar1 = EVP_PKEY_get0(param_2);
  iVar2 = EVP_PKEY_base_id(param_2);
  aobj = OBJ_nid2obj(iVar2);
  if (param_2->save_parameters == 0) {
    iVar2 = -1;
    local_34 = (void *)0x0;
  }
  else {
    iVar2 = 0x10;
    local_34 = (void *)encode_gost_algor_params(param_2);
  }
  iVar3 = BN_num_bits(*(BIGNUM **)((int)pvVar1 + 0x18));
  iVar8 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar8 = iVar3 + 7;
  }
  iVar8 = iVar8 >> 3;
  to = (uchar *)CRYPTO_malloc(iVar8,DAT_0011630c,0x288);
  BN_bn2bin(*(BIGNUM **)((int)pvVar1 + 0x18),to);
  str = ASN1_OCTET_STRING_new();
  ASN1_STRING_set(str,(void *)0x0,iVar8);
  puVar4 = ASN1_STRING_data(str);
  if (0 < iVar8) {
    puVar7 = to + iVar8;
    puVar5 = puVar4;
    do {
      puVar7 = puVar7 + -1;
      puVar6 = puVar5 + 1;
      *puVar5 = *puVar7;
      puVar5 = puVar6;
    } while (puVar6 != puVar4 + iVar8);
  }
  CRYPTO_free(to);
  iVar8 = i2d_ASN1_OCTET_STRING(str,local_2c);
  ASN1_BIT_STRING_free(str);
  if (iVar8 < 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = X509_PUBKEY_set0_param(param_1,aobj,iVar2,local_34,local_2c[0],iVar8);
  }
  return iVar2;
}

