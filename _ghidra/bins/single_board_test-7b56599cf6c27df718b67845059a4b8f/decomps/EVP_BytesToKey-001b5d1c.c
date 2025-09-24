
int EVP_BytesToKey(EVP_CIPHER *type,EVP_MD *md,uchar *salt,uchar *data,int datal,int count,
                  uchar *key,uchar *iv)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  EVP_MD_CTX *ctx;
  int iVar4;
  int iVar5;
  size_t sVar6;
  uchar *puVar7;
  size_t sVar8;
  int local_78;
  uint local_6c;
  uchar local_68 [68];
  
  local_6c = 0;
  sVar2 = EVP_CIPHER_key_length(type);
  iVar3 = EVP_CIPHER_iv_length(type);
  if (0x40 < (int)sVar2) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: nkey <= EVP_MAX_KEY_LENGTH","crypto/evp/evp_key.c",0x56);
  }
  if (0x10 < iVar3) {
                    /* WARNING: Subroutine does not return */
    OPENSSL_die("assertion failed: niv <= EVP_MAX_IV_LENGTH","crypto/evp/evp_key.c",0x57);
  }
  if (data != (uchar *)0x0) {
    ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
    if (ctx == (EVP_MD_CTX *)0x0) {
LAB_001b5ddc:
      sVar2 = 0;
    }
    else {
      local_78 = 0;
LAB_001b5d6c:
      do {
        iVar4 = EVP_DigestInit_ex(ctx,md,(ENGINE *)0x0);
        if (((iVar4 == 0) ||
            ((((local_78 != 0 && (iVar4 = EVP_DigestUpdate(ctx,local_68,local_6c), iVar4 == 0)) ||
              (iVar4 = EVP_DigestUpdate(ctx,data,datal), iVar4 == 0)) ||
             ((salt != (uchar *)0x0 && (iVar4 = EVP_DigestUpdate(ctx,salt,8), iVar4 == 0)))))) ||
           (iVar4 = EVP_DigestFinal_ex(ctx,local_68,&local_6c), iVar4 == 0)) goto LAB_001b5ddc;
        sVar8 = sVar2;
        if ((uint)count < 2) {
          sVar1 = sVar2;
          sVar6 = local_6c;
          if (sVar2 != 0) goto LAB_001b5e0c;
joined_r0x001b5ea4:
          sVar2 = sVar1;
          local_6c = sVar6;
          if ((iVar3 != 0) && (sVar2 != sVar6)) goto LAB_001b5e3e;
        }
        else {
          iVar4 = 1;
          do {
            iVar5 = EVP_DigestInit_ex(ctx,md,(ENGINE *)0x0);
            if (((iVar5 == 0) || (iVar5 = EVP_DigestUpdate(ctx,local_68,local_6c), iVar5 == 0)) ||
               (iVar5 = EVP_DigestFinal_ex(ctx,local_68,&local_6c), iVar5 == 0)) goto LAB_001b5ddc;
            iVar4 = iVar4 + 1;
          } while (iVar4 != count);
          if (sVar2 != 0) {
LAB_001b5e0c:
            sVar1 = local_6c;
            sVar6 = local_6c;
            if (local_6c != 0) {
              puVar7 = key;
              sVar2 = 0;
              do {
                key = puVar7;
                if (puVar7 != (uchar *)0x0) {
                  key = puVar7 + 1;
                  *puVar7 = local_68[sVar2];
                }
                sVar8 = sVar8 - 1;
                sVar2 = sVar2 + 1;
                if (sVar8 == 0) goto LAB_001b5e74;
                puVar7 = key;
              } while (sVar2 != local_6c);
            }
            goto joined_r0x001b5ea4;
          }
LAB_001b5e74:
          if (iVar3 == 0) break;
          if (local_6c == sVar2) {
            sVar2 = 0;
            local_78 = local_78 + 1;
            goto LAB_001b5d6c;
          }
          sVar8 = 0;
          sVar6 = local_6c;
LAB_001b5e3e:
          do {
            if (iv != (uchar *)0x0) {
              *iv = local_68[sVar2];
              iv = iv + 1;
            }
            iVar3 = iVar3 + -1;
            sVar2 = sVar2 + 1;
          } while ((iVar3 != 0) && (sVar2 != sVar6));
        }
        sVar2 = sVar8;
        local_78 = local_78 + 1;
      } while (iVar3 != 0 || sVar2 != 0);
      sVar2 = EVP_CIPHER_key_length(type);
    }
    EVP_MD_CTX_free(ctx);
    OPENSSL_cleanse(local_68,0x40);
  }
  return sVar2;
}

