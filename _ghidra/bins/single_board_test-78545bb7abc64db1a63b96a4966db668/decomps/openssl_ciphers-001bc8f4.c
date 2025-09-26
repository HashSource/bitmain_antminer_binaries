
int openssl_ciphers(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  EVP_CIPHER *pEVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == (undefined4 *)0x0) {
    iVar4 = pos_23934;
    if (init_23935 == 0) {
      pEVar2 = (EVP_CIPHER *)test_r4_cipher();
      if (pEVar2 != (EVP_CIPHER *)0x0) {
        iVar4 = pos_23934 * 4;
        pos_23934 = pos_23934 + 1;
        iVar3 = EVP_CIPHER_nid(pEVar2);
        *(int *)(cipher_nids_23933 + iVar4) = iVar3;
      }
      pEVar2 = (EVP_CIPHER *)test_r4_40_cipher();
      if (pEVar2 != (EVP_CIPHER *)0x0) {
        iVar4 = pos_23934 * 4;
        pos_23934 = pos_23934 + 1;
        iVar3 = EVP_CIPHER_nid(pEVar2);
        *(int *)(cipher_nids_23933 + iVar4) = iVar3;
      }
      iVar4 = pos_23934;
      init_23935 = 1;
      *(undefined4 *)(cipher_nids_23933 + pos_23934 * 4) = 0;
    }
    *param_3 = cipher_nids_23933;
  }
  else if (param_4 == 5) {
    iVar4 = 1;
    uVar1 = test_r4_cipher();
    *param_2 = uVar1;
  }
  else if (param_4 == 0x61) {
    iVar4 = 1;
    uVar1 = test_r4_40_cipher();
    *param_2 = uVar1;
  }
  else {
    iVar4 = 0;
    *param_2 = 0;
  }
  return iVar4;
}

