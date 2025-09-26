
undefined4 ssl2_enc_init(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  EVP_CIPHER_CTX *a;
  EVP_CIPHER_CTX *a_00;
  EVP_CIPHER *local_28;
  undefined4 local_24;
  
  iVar1 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_28,&local_24,0,0,0);
  if (iVar1 == 0) {
    ssl2_return_error(param_1,1);
    ERR_put_error(0x14,0x7c,0xce,"s2_enc.c",0x49);
    return 0;
  }
  ssl_replace_hash(param_1 + 0x84,local_24);
  ssl_replace_hash(param_1 + 0x90,local_24);
  a = *(EVP_CIPHER_CTX **)(param_1 + 0x80);
  if (a == (EVP_CIPHER_CTX *)0x0) {
    a = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s2_enc.c",0x50);
    *(EVP_CIPHER_CTX **)(param_1 + 0x80) = a;
    if (a != (EVP_CIPHER_CTX *)0x0) goto LAB_0011df74;
LAB_0011e084:
    ERR_put_error(0x14,0x7c,0x41,"s2_enc.c",0x76);
    uVar3 = 0;
  }
  else {
LAB_0011df74:
    EVP_CIPHER_CTX_init(a);
    a_00 = *(EVP_CIPHER_CTX **)(param_1 + 0x8c);
    if (a_00 == (EVP_CIPHER_CTX *)0x0) {
      a_00 = (EVP_CIPHER_CTX *)CRYPTO_malloc(0x8c,"s2_enc.c",0x5d);
      *(EVP_CIPHER_CTX **)(param_1 + 0x8c) = a_00;
      if (a_00 == (EVP_CIPHER_CTX *)0x0) goto LAB_0011e084;
    }
    EVP_CIPHER_CTX_init(a_00);
    iVar1 = local_28->key_len;
    *(int *)(*(int *)(param_1 + 0x54) + 0x9c) = iVar1 * 2;
    if (0x30 < (uint)(iVar1 * 2)) {
      OpenSSLDie("s2_enc.c",0x66,"s->s2->key_material_length <= sizeof s->s2->key_material");
    }
    iVar2 = ssl2_generate_key_material(param_1);
    if (iVar2 < 1) {
      uVar3 = 0;
    }
    else {
      if (8 < local_28->iv_len) {
        OpenSSLDie("s2_enc.c",0x6b,"c->iv_len <= (int)sizeof(s->session->key_arg)");
      }
      if (param_2 == 0) {
        iVar2 = 0xa0;
        EVP_EncryptInit_ex(a_00,local_28,(ENGINE *)0x0,(uchar *)(*(int *)(param_1 + 0x54) + 0xa0),
                           (uchar *)(*(int *)(param_1 + 0xc0) + 8));
        EVP_DecryptInit_ex(a,local_28,(ENGINE *)0x0,
                           (uchar *)(*(int *)(param_1 + 0x54) + iVar1 + 0xa0),
                           (uchar *)(*(int *)(param_1 + 0xc0) + 8));
        iVar4 = *(int *)(param_1 + 0x54);
        *(int *)(iVar4 + 0x5c) = iVar4 + iVar1 + 0xa0;
      }
      else {
        iVar2 = iVar1 + 0xa0;
        EVP_EncryptInit_ex(a_00,local_28,(ENGINE *)0x0,(uchar *)(*(int *)(param_1 + 0x54) + iVar2),
                           (uchar *)(*(int *)(param_1 + 0xc0) + 8));
        EVP_DecryptInit_ex(a,local_28,(ENGINE *)0x0,(uchar *)(*(int *)(param_1 + 0x54) + 0xa0),
                           (uchar *)(*(int *)(param_1 + 0xc0) + 8));
        iVar4 = *(int *)(param_1 + 0x54);
        *(int *)(iVar4 + 0x5c) = iVar4 + 0xa0;
      }
      uVar3 = 1;
      *(int *)(iVar4 + 0x60) = iVar4 + iVar2;
    }
  }
  return uVar3;
}

