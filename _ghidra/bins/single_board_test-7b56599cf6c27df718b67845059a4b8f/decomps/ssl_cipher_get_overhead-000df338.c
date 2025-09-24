
undefined4
ssl_cipher_get_overhead(int param_1,int *param_2,undefined4 *param_3,int *param_4,int *param_5)

{
  int iVar1;
  char *pcVar2;
  EVP_MD *md;
  int iVar3;
  EVP_CIPHER *cipher;
  ulong uVar4;
  int iVar5;
  undefined4 uVar6;
  
  if ((*(uint *)(param_1 + 0x18) & 0x30f000) == 0) {
    if ((*(uint *)(param_1 + 0x18) & 0xb0000) == 0) {
      if ((*(uint *)(param_1 + 0x1c) & 0x40) == 0) {
        iVar1 = SSL_CIPHER_get_digest_nid();
        pcVar2 = OBJ_nid2sn(iVar1);
        md = EVP_get_digestbyname(pcVar2);
        if (md != (EVP_MD *)0x0) {
          iVar3 = EVP_MD_size(md);
          if (*(int *)(param_1 + 0x18) == 0x20) {
            iVar1 = 0;
            iVar5 = 0;
            uVar6 = 0;
          }
          else {
            iVar1 = SSL_CIPHER_get_cipher_nid(param_1);
            pcVar2 = OBJ_nid2sn(iVar1);
            cipher = EVP_get_cipherbyname(pcVar2);
            if (cipher == (EVP_CIPHER *)0x0) {
              return 0;
            }
            uVar4 = EVP_CIPHER_flags(cipher);
            if ((uVar4 & 0xf0007) != 2) {
              return 0;
            }
            iVar5 = EVP_CIPHER_iv_length(cipher);
            iVar1 = EVP_CIPHER_block_size(cipher);
            uVar6 = 1;
          }
          goto LAB_000df360;
        }
      }
      return 0;
    }
    iVar5 = 0x10;
    iVar1 = 0;
    uVar6 = 0;
    iVar3 = 0;
  }
  else {
    iVar1 = 0;
    iVar5 = 0x18;
    uVar6 = 0;
    iVar3 = 0;
  }
LAB_000df360:
  *param_2 = iVar3;
  *param_3 = uVar6;
  *param_4 = iVar1;
  *param_5 = iVar5;
  return 1;
}

