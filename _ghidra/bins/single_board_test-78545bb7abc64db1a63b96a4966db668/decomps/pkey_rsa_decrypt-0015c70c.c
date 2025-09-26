
uint pkey_rsa_decrypt(int param_1,uchar *param_2,uint *param_3,uchar *param_4,int param_5)

{
  uint uVar1;
  int num;
  uchar *to;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14);
  if (*(int *)(iVar3 + 0x14) == 4) {
    to = *(uchar **)(iVar3 + 0x28);
    if (to == (uchar *)0x0) {
      num = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
      to = (uchar *)CRYPTO_malloc(num,"crypto/rsa/rsa_pmeth.c",0x6a);
      *(uchar **)(iVar3 + 0x28) = to;
      if (to == (uchar *)0x0) {
        ERR_put_error(4,0xa7,0x41,"crypto/rsa/rsa_pmeth.c",0x6b);
        return 0xffffffff;
      }
    }
    uVar1 = RSA_private_decrypt(param_5,param_4,to,*(RSA **)(*(int *)(param_1 + 8) + 0x18),3);
    if ((int)uVar1 < 1) {
      return uVar1;
    }
    uVar1 = RSA_padding_check_PKCS1_OAEP_mgf1
                      (param_2,uVar1,*(undefined4 *)(iVar3 + 0x28),uVar1,uVar1,
                       *(undefined4 *)(iVar3 + 0x2c),*(undefined4 *)(iVar3 + 0x30),
                       *(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 0x1c));
  }
  else {
    uVar1 = RSA_private_decrypt(param_5,param_4,param_2,*(RSA **)(*(int *)(param_1 + 8) + 0x18),
                                *(int *)(iVar3 + 0x14));
  }
  uVar2 = (int)uVar1 >> 0x1f;
  *param_3 = ~uVar2 & uVar1 | uVar2 & *param_3;
  return ~uVar2 & 1 | uVar2 & uVar1;
}

