
undefined4 sm2_ciphertext_size(EC_KEY *param_1,EVP_MD *param_2,int param_3,int *param_4)

{
  EC_GROUP *pEVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  int iVar2;
  int iVar3;
  uint length;
  int iVar4;
  uint uVar5;
  
  pEVar1 = EC_KEY_get0_group(param_1);
  a = BN_new();
  a_00 = BN_new();
  a_01 = BN_new();
  if ((a_01 == (BIGNUM *)0x0 || (a_00 == (BIGNUM *)0x0 || a == (BIGNUM *)0x0)) ||
     (iVar2 = EC_GROUP_get_curve(pEVar1,a,a_00,a_01,0), iVar2 == 0)) {
    BN_free(a);
    BN_free(a_00);
    BN_free(a_01);
    EVP_MD_size(param_2);
  }
  else {
    iVar3 = BN_num_bits(a);
    iVar2 = iVar3 + 0xe;
    if (-1 < iVar3 + 7) {
      iVar2 = iVar3 + 7;
    }
    BN_free(a);
    BN_free(a_00);
    BN_free(a_01);
    length = EVP_MD_size(param_2);
    uVar5 = length >> 0x1f;
    if (iVar2 >> 3 == 0) {
      uVar5 = 1;
    }
    if (uVar5 == 0) {
      iVar2 = ASN1_object_size(0,(iVar2 >> 3) + 1,2);
      iVar3 = ASN1_object_size(0,length,4);
      iVar4 = ASN1_object_size(0,param_3,4);
      iVar2 = ASN1_object_size(1,iVar3 + iVar2 * 2 + iVar4,0x10);
      *param_4 = iVar2;
      return 1;
    }
  }
  return 0;
}

