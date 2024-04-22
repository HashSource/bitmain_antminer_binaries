
int CMAC_Init(CMAC_CTX *ctx,void *key,size_t keylen,EVP_CIPHER *cipher,ENGINE *impl)

{
  uchar *in;
  int iVar1;
  EVP_CIPHER *pEVar2;
  size_t sVar3;
  byte bVar4;
  CMAC_CTX *pCVar5;
  CMAC_CTX CVar6;
  CMAC_CTX *pCVar7;
  size_t sVar8;
  CMAC_CTX *out;
  
  if (cipher == (EVP_CIPHER *)0x0 && key == (void *)0x0) {
    if (impl != (ENGINE *)0x0 || keylen != 0) {
      return 1;
    }
    if ((*(int *)(ctx + 0x10c) != -1) &&
       (iVar1 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                   (uchar *)0x0,DAT_0011197c), iVar1 != 0)) {
      sVar3 = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
      memset(ctx + 0xcc,0,sVar3);
      *(undefined4 *)(ctx + 0x10c) = 0;
      return 1;
    }
  }
  else if ((cipher == (EVP_CIPHER *)0x0) ||
          (iVar1 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,cipher,impl,(uchar *)0x0,(uchar *)0x0),
          iVar1 != 0)) {
    if (key == (void *)0x0) {
      return 1;
    }
    pEVar2 = EVP_CIPHER_CTX_cipher((EVP_CIPHER_CTX *)ctx);
    if (((pEVar2 != (EVP_CIPHER *)0x0) &&
        (iVar1 = EVP_CIPHER_CTX_set_key_length((EVP_CIPHER_CTX *)ctx,keylen), in = DAT_0011197c,
        iVar1 != 0)) &&
       (iVar1 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                   (uchar *)key,DAT_0011197c), iVar1 != 0)) {
      out = ctx + 0xcc;
      sVar3 = EVP_CIPHER_CTX_block_size((EVP_CIPHER_CTX *)ctx);
      iVar1 = EVP_Cipher((EVP_CIPHER_CTX *)ctx,(uchar *)out,in,sVar3);
      if (iVar1 != 0) {
        pCVar5 = ctx + 0x8c;
        if (0 < (int)sVar3) {
          sVar8 = 0;
          pCVar7 = ctx + 0xcb;
          do {
            CVar6 = (CMAC_CTX)((char)pCVar7[1] << 1);
            pCVar5[sVar8] = CVar6;
            if ((int)sVar8 < (int)(sVar3 - 1)) {
              if ((char)pCVar7[2] < '\0') {
                CVar6 = (CMAC_CTX)((byte)CVar6 | 1);
              }
              if ((char)pCVar7[2] < '\0') {
                pCVar5[sVar8] = CVar6;
              }
            }
            sVar8 = sVar8 + 1;
            pCVar7 = pCVar7 + 1;
          } while (sVar8 != sVar3);
        }
        if ((char)ctx[0xcc] < '\0') {
          if (sVar3 != 0x10) {
            pCVar5 = (CMAC_CTX *)0x1b;
          }
          bVar4 = (byte)pCVar5;
          if (sVar3 == 0x10) {
            bVar4 = 0x87;
          }
          ctx[sVar3 + 0x8b] = (CMAC_CTX)((byte)ctx[sVar3 + 0x8b] ^ bVar4);
        }
        pCVar5 = ctx + 0xac;
        if (0 < (int)sVar3) {
          sVar8 = 0;
          pCVar7 = ctx + 0x8b;
          do {
            CVar6 = (CMAC_CTX)((char)pCVar7[1] << 1);
            pCVar5[sVar8] = CVar6;
            if ((int)sVar8 < (int)(sVar3 - 1)) {
              if ((char)pCVar7[2] < '\0') {
                CVar6 = (CMAC_CTX)((byte)CVar6 | 1);
              }
              if ((char)pCVar7[2] < '\0') {
                pCVar5[sVar8] = CVar6;
              }
            }
            sVar8 = sVar8 + 1;
            pCVar7 = pCVar7 + 1;
          } while (sVar8 != sVar3);
        }
        if ((char)ctx[0x8c] < '\0') {
          if (sVar3 != 0x10) {
            pCVar5 = (CMAC_CTX *)0x1b;
          }
          bVar4 = (byte)pCVar5;
          if (sVar3 == 0x10) {
            bVar4 = 0x87;
          }
          ctx[sVar3 + 0xab] = (CMAC_CTX)((byte)ctx[sVar3 + 0xab] ^ bVar4);
        }
        OPENSSL_cleanse(out,sVar3);
        iVar1 = EVP_EncryptInit_ex((EVP_CIPHER_CTX *)ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                                   (uchar *)0x0,in);
        if (iVar1 != 0) {
          memset(out,0,sVar3);
          *(undefined4 *)(ctx + 0x10c) = 0;
          return 1;
        }
      }
    }
  }
  return 0;
}

