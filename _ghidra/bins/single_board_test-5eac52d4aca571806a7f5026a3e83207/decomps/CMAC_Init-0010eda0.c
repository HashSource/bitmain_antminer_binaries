
int CMAC_Init(CMAC_CTX *ctx,void *key,size_t keylen,EVP_CIPHER *cipher,ENGINE *impl)

{
  CMAC_CTX CVar1;
  int iVar2;
  EVP_CIPHER *pEVar3;
  size_t sVar4;
  CMAC_CTX *pCVar5;
  CMAC_CTX *pCVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  CMAC_CTX *out;
  CMAC_CTX *pCVar10;
  
  if (key == (void *)0x0 && cipher == (EVP_CIPHER *)0x0) {
    if (impl != (ENGINE *)0x0 || keylen != 0) {
      return 1;
    }
    if ((*(int *)(ctx + 0x84) != -1) &&
       (iVar2 = EVP_EncryptInit_ex(*(EVP_CIPHER_CTX **)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                   (uchar *)0x0,""), iVar2 != 0)) {
      sVar4 = EVP_CIPHER_CTX_block_size(*(EVP_CIPHER_CTX **)ctx);
      memset(ctx + 0x44,0,sVar4);
      *(undefined4 *)(ctx + 0x84) = 0;
      return 1;
    }
  }
  else {
    if (cipher != (EVP_CIPHER *)0x0) {
      *(undefined4 *)(ctx + 0x84) = 0xffffffff;
      iVar2 = EVP_EncryptInit_ex(*(EVP_CIPHER_CTX **)ctx,cipher,impl,(uchar *)0x0,(uchar *)0x0);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if (key == (void *)0x0) {
      return 1;
    }
    *(undefined4 *)(ctx + 0x84) = 0xffffffff;
    pEVar3 = EVP_CIPHER_CTX_cipher(*(EVP_CIPHER_CTX **)ctx);
    if (((pEVar3 != (EVP_CIPHER *)0x0) &&
        (iVar2 = EVP_CIPHER_CTX_set_key_length(*(EVP_CIPHER_CTX **)ctx,keylen), iVar2 != 0)) &&
       (iVar2 = EVP_EncryptInit_ex(*(EVP_CIPHER_CTX **)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                   (uchar *)key,""), iVar2 != 0)) {
      out = ctx + 0x44;
      sVar4 = EVP_CIPHER_CTX_block_size(*(EVP_CIPHER_CTX **)ctx);
      iVar2 = EVP_Cipher(*(EVP_CIPHER_CTX **)ctx,(uchar *)out,"",sVar4);
      if (0 < iVar2) {
        CVar1 = ctx[0x44];
        uVar7 = (uint)(byte)CVar1;
        iVar2 = sVar4 - 1;
        if (iVar2 < 1) {
          iVar9 = 0;
        }
        else {
          pCVar10 = ctx + 3;
          pCVar6 = ctx + 0x45;
          do {
            iVar9 = uVar7 << 1;
            pCVar5 = pCVar6 + 1;
            uVar7 = (uint)(byte)*pCVar6;
            pCVar10 = pCVar10 + 1;
            *pCVar10 = (CMAC_CTX)((byte)iVar9 | (byte)*pCVar6 >> 7);
            pCVar6 = pCVar5;
            iVar9 = iVar2;
          } while (pCVar5 != out + sVar4);
        }
        if (sVar4 == 0x10) {
          bVar8 = 0x87;
        }
        else {
          bVar8 = 0x1b;
        }
        ctx[iVar9 + 4] =
             (CMAC_CTX)(bVar8 & (char)CVar1 >> 7 ^ (byte)(((int)(uVar7 << 0x19) >> 0x19) << 1));
        CVar1 = ctx[4];
        uVar7 = (uint)(byte)CVar1;
        if (iVar2 < 1) {
          iVar2 = 0;
        }
        else {
          pCVar10 = ctx + 0x23;
          pCVar6 = ctx + 5;
          do {
            iVar9 = uVar7 << 1;
            pCVar5 = pCVar6 + 1;
            uVar7 = (uint)(byte)*pCVar6;
            pCVar10 = pCVar10 + 1;
            *pCVar10 = (CMAC_CTX)((byte)iVar9 | (byte)*pCVar6 >> 7);
            pCVar6 = pCVar5;
          } while (ctx + sVar4 + 4 != pCVar5);
        }
        if (sVar4 == 0x10) {
          bVar8 = 0x87;
        }
        else {
          bVar8 = 0x1b;
        }
        ctx[iVar2 + 0x24] =
             (CMAC_CTX)((char)CVar1 >> 7 & bVar8 ^ (byte)(((int)(uVar7 << 0x19) >> 0x19) << 1));
        OPENSSL_cleanse(out,sVar4);
        iVar2 = EVP_EncryptInit_ex(*(EVP_CIPHER_CTX **)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                   (uchar *)0x0,"");
        if (iVar2 != 0) {
          memset(out,0,sVar4);
          *(undefined4 *)(ctx + 0x84) = 0;
          return 1;
        }
      }
    }
  }
  return 0;
}

