
int EVP_BytesToKey(EVP_CIPHER *type,EVP_MD *md,uchar *salt,uchar *data,int datal,int count,
                  uchar *key,uchar *iv)

{
  int iVar1;
  uchar *puVar2;
  size_t sVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  int local_90;
  uint local_84;
  EVP_MD_CTX EStack_80;
  uchar local_68 [68];
  
  sVar5 = type->key_len;
  iVar6 = type->iv_len;
  local_84 = 0;
  if (0x40 < (int)sVar5) {
    OpenSSLDie("evp_key.c",0x83,"nkey <= EVP_MAX_KEY_LENGTH");
  }
  if (0x10 < iVar6) {
    OpenSSLDie("evp_key.c",0x84,"niv <= EVP_MAX_IV_LENGTH");
  }
  if (data != (uchar *)0x0) {
    local_90 = 0;
    EVP_MD_CTX_init(&EStack_80);
    while (iVar1 = EVP_DigestInit_ex(&EStack_80,md,(ENGINE *)0x0), iVar1 != 0) {
      if (((((local_90 != 0) && (iVar1 = EVP_DigestUpdate(&EStack_80,local_68,local_84), iVar1 == 0)
            ) || (iVar1 = EVP_DigestUpdate(&EStack_80,data,datal), iVar1 == 0)) ||
          ((salt != (uchar *)0x0 && (iVar1 = EVP_DigestUpdate(&EStack_80,salt,8), iVar1 == 0)))) ||
         (iVar1 = EVP_DigestFinal_ex(&EStack_80,local_68,&local_84), iVar1 == 0)) goto LAB_0010429c;
      if (1 < (uint)count) {
        iVar4 = 1;
        do {
          iVar4 = iVar4 + 1;
          iVar1 = EVP_DigestInit_ex(&EStack_80,md,(ENGINE *)0x0);
          if (iVar1 == 0) goto LAB_0010429c;
          iVar1 = EVP_DigestUpdate(&EStack_80,local_68,local_84);
          if ((iVar1 == 0) ||
             (iVar1 = EVP_DigestFinal_ex(&EStack_80,local_68,&local_84), iVar1 == 0))
          goto LAB_0010429c;
        } while (count != iVar4);
      }
      sVar3 = sVar5;
      if (sVar5 != 0) {
        sVar3 = 0;
        puVar2 = key;
        do {
          key = puVar2;
          if (sVar3 == local_84) break;
          if (puVar2 != (uchar *)0x0) {
            key = puVar2 + 1;
            *puVar2 = local_68[sVar3];
          }
          sVar5 = sVar5 - 1;
          sVar3 = sVar3 + 1;
          puVar2 = key;
        } while (sVar5 != 0);
      }
      for (; (iVar6 != 0 && (sVar3 != local_84)); sVar3 = sVar3 + 1) {
        puVar2 = iv;
        if (iv != (uchar *)0x0) {
          puVar2 = iv + 1;
          *iv = local_68[sVar3];
        }
        iVar6 = iVar6 + -1;
        iv = puVar2;
      }
      local_90 = local_90 + 1;
      if (iVar6 == 0 && sVar5 == 0) {
        iVar1 = type->key_len;
LAB_0010429c:
        EVP_MD_CTX_cleanup(&EStack_80);
        OPENSSL_cleanse(local_68,0x40);
        return iVar1;
      }
    }
    sVar5 = 0;
  }
  return sVar5;
}

