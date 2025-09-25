
undefined4 tls13_update_key(int param_1,int param_2)

{
  EVP_MD *pEVar1;
  size_t __n;
  int iVar2;
  ulong uVar3;
  int iVar4;
  undefined4 uVar5;
  void *__dest;
  EVP_CIPHER *cipher;
  int local_c0;
  EVP_CIPHER_CTX *local_bc;
  int local_b4;
  int local_b0;
  int local_ac;
  undefined1 auStack_a8 [64];
  uchar auStack_68 [68];
  
  pEVar1 = (EVP_MD *)ssl_handshake_md();
  __n = EVP_MD_size(pEVar1);
  if (*(int *)(param_1 + 0x1c) == param_2) {
    __dest = (void *)(param_1 + 0x30c);
  }
  else {
    __dest = (void *)(param_1 + 0x2cc);
  }
  if (param_2 == 0) {
    local_c0 = param_1 + 0x3d0;
    local_bc = *(EVP_CIPHER_CTX **)(param_1 + 0x3cc);
    RECORD_LAYER_reset_read_sequence(param_1 + 0x650);
  }
  else {
    *(undefined4 *)(param_1 + 0x60) = 1;
    local_c0 = param_1 + 0x3f0;
    local_bc = *(EVP_CIPHER_CTX **)(param_1 + 0x3ec);
    RECORD_LAYER_reset_write_sequence(param_1 + 0x650);
  }
  pEVar1 = (EVP_MD *)ssl_handshake_md(param_1);
  cipher = *(EVP_CIPHER **)(*(int *)(param_1 + 0x7c) + 0x230);
  iVar2 = EVP_MD_size(pEVar1);
  if (iVar2 < 0) {
    ossl_statem_fatal(param_1,0x50,0x202,6,"ssl/tls13_enc.c",0x179);
  }
  else {
    iVar2 = tls13_hkdf_expand(param_1,pEVar1,__dest,"traffic upd",0xb,0,iVar2,auStack_a8,iVar2,1);
    if (iVar2 != 0) {
      iVar2 = EVP_CIPHER_key_length(cipher);
      uVar3 = EVP_CIPHER_flags(cipher);
      if ((uVar3 & 0xf0007) == 7) {
        iVar4 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
        if (((iVar4 == 0) && (iVar4 = *(int *)(*(int *)(param_1 + 0x474) + 0x1b8), iVar4 == 0)) &&
           ((*(int *)(param_1 + 0x478) == 0 ||
            (iVar4 = *(int *)(*(int *)(param_1 + 0x478) + 0x1b8), iVar4 == 0)))) {
          ossl_statem_fatal(param_1,0x50,0x202,6,"ssl/tls13_enc.c",0x194);
          goto LAB_000f9d20;
        }
        if ((*(uint *)(iVar4 + 0x18) & 0x30000) == 0) {
          local_ac = 0x10;
          local_b4 = 0xc;
          local_b0 = 0x10;
        }
        else {
          local_ac = 8;
          local_b4 = 0xc;
          local_b0 = 8;
        }
      }
      else {
        local_ac = 0;
        local_b4 = EVP_CIPHER_iv_length(cipher);
        local_b0 = 0;
      }
      iVar2 = tls13_derive_key(param_1,pEVar1,auStack_a8,auStack_68,iVar2);
      if ((iVar2 != 0) &&
         (iVar2 = tls13_derive_iv(param_1,pEVar1,auStack_a8,local_c0,local_b4), iVar2 != 0)) {
        iVar2 = EVP_CipherInit_ex(local_bc,cipher,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,param_2);
        if (((0 < iVar2) &&
            (iVar2 = EVP_CIPHER_CTX_ctrl(local_bc,9,local_b4,(void *)0x0), iVar2 != 0)) &&
           (((local_b0 == 0 ||
             (iVar2 = EVP_CIPHER_CTX_ctrl(local_bc,0x11,local_ac,(void *)0x0), iVar2 != 0)) &&
            (iVar2 = EVP_CipherInit_ex(local_bc,(EVP_CIPHER *)0x0,(ENGINE *)0x0,auStack_68,
                                       (uchar *)0x0,-1), 0 < iVar2)))) {
          uVar5 = 1;
          memcpy(__dest,auStack_a8,__n);
          *(undefined4 *)(param_1 + 0x60) = 0;
          goto LAB_000f9d2a;
        }
        ossl_statem_fatal(param_1,0x50,0x202,6,"ssl/tls13_enc.c",0x1ac);
      }
    }
  }
LAB_000f9d20:
  uVar5 = 0;
  OPENSSL_cleanse(auStack_68,0x40);
LAB_000f9d2a:
  OPENSSL_cleanse(auStack_a8,0x40);
  return uVar5;
}

