
undefined4 cms_RecipientInfo_pwri_crypt(int param_1,int param_2,int param_3)

{
  int iVar1;
  X509_ALGOR *a;
  char *name;
  EVP_CIPHER *cipher;
  EVP_CIPHER_CTX *ctx;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int extraout_r1;
  uchar *in;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uchar *out;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  bool bVar12;
  bool bVar13;
  int aiStack_2c [2];
  
  iVar10 = *(int *)(param_2 + 4);
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  if (*(int *)(iVar10 + 0x10) == 0) {
    ERR_put_error(0x2e,0xa7,0xb2,"crypto/cms/cms_pwri.c",0x125);
    return 0;
  }
  puVar7 = *(undefined4 **)(iVar10 + 8);
  if ((puVar7 == (undefined4 *)0x0) || (iVar1 = OBJ_obj2nid((ASN1_OBJECT *)*puVar7), iVar1 != 0x37d)
     ) {
    ERR_put_error(0x2e,0xa7,0xb3,"crypto/cms/cms_pwri.c",300);
    return 0;
  }
  a = (X509_ALGOR *)ASN1_TYPE_unpack_sequence(X509_ALGOR_it,puVar7[1]);
  if (a == (X509_ALGOR *)0x0) {
    ERR_put_error(0x2e,0xa7,0xb0,"crypto/cms/cms_pwri.c",0x135);
    return 0;
  }
  iVar1 = OBJ_obj2nid(a->algorithm);
  name = OBJ_nid2sn(iVar1);
  cipher = EVP_get_cipherbyname(name);
  if (cipher == (EVP_CIPHER *)0x0) {
    ERR_put_error(0x2e,0xa7,0x94,"crypto/cms/cms_pwri.c",0x13c);
    return 0;
  }
  ctx = EVP_CIPHER_CTX_new();
  if (ctx == (EVP_CIPHER_CTX *)0x0) {
    ERR_put_error(0x2e,0xa7,0x41,"crypto/cms/cms_pwri.c",0x142);
    return 0;
  }
  out = (uchar *)0x0;
  iVar1 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,param_3);
  if (iVar1 == 0) {
LAB_001919f4:
    out = (uchar *)0x0;
  }
  else {
    EVP_CIPHER_CTX_set_padding(ctx,0);
    iVar1 = EVP_CIPHER_asn1_to_param(ctx,a->parameter);
    if (iVar1 < 1) {
      ERR_put_error(0x2e,0xa7,0x66,"crypto/cms/cms_pwri.c",0x14b);
    }
    else {
      iVar1 = EVP_PBE_CipherInit((ASN1_OBJECT *)**(undefined4 **)(iVar10 + 4),
                                 *(char **)(iVar10 + 0x10),*(int *)(iVar10 + 0x14),
                                 (ASN1_TYPE *)(*(undefined4 **)(iVar10 + 4))[1],ctx,param_3);
      if (iVar1 < 0) {
        ERR_put_error(0x2e,0xa7,6,"crypto/cms/cms_pwri.c",0x156);
      }
      else if (param_3 == 0) {
        out = (uchar *)CRYPTO_malloc(**(int **)(iVar10 + 0xc),"crypto/cms/cms_pwri.c",0x16b);
        if (out == (uchar *)0x0) {
          ERR_put_error(0x2e,0xa7,0x41,"crypto/cms/cms_pwri.c",0x16e);
        }
        else {
          in = (uchar *)(*(uint **)(iVar10 + 0xc))[2];
          uVar3 = **(uint **)(iVar10 + 0xc);
          iVar10 = EVP_CIPHER_CTX_block_size(ctx);
          if (((uint)(iVar10 * 2) <= uVar3) && (__aeabi_uidivmod(uVar3,iVar10), extraout_r1 == 0)) {
            pbVar11 = (byte *)CRYPTO_malloc(uVar3,"crypto/cms/cms_pwri.c",0xbf);
            if (pbVar11 == (byte *)0x0) {
              ERR_put_error(0x2e,0xb4,0x41,"crypto/cms/cms_pwri.c",0xc0);
            }
            else {
              iVar2 = uVar3 + iVar10 * -2;
              iVar1 = EVP_DecryptUpdate(ctx,pbVar11 + iVar2,aiStack_2c,in + iVar2,iVar10 * 2);
              if (iVar1 != 0) {
                iVar1 = EVP_DecryptUpdate(ctx,pbVar11,aiStack_2c,pbVar11 + iVar2 + iVar10,iVar10);
                if (((((iVar1 != 0) &&
                      (iVar10 = EVP_DecryptUpdate(ctx,pbVar11,aiStack_2c,in,iVar2 + iVar10),
                      iVar10 != 0)) &&
                     (iVar10 = EVP_DecryptInit_ex(ctx,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                                                  (uchar *)0x0), iVar10 != 0)) &&
                    ((iVar10 = EVP_DecryptUpdate(ctx,pbVar11,aiStack_2c,pbVar11,uVar3), iVar10 != 0
                     && ((byte)((pbVar11[6] ^ pbVar11[3]) &
                               (pbVar11[2] ^ pbVar11[5]) & (pbVar11[4] ^ pbVar11[1])) == 0xff)))) &&
                   (uVar9 = (uint)*pbVar11, uVar9 - 4 <= uVar3)) {
                  memcpy(out,pbVar11 + 4,uVar9);
                  CRYPTO_clear_free(pbVar11,uVar3,"crypto/cms/cms_pwri.c",0xe2);
                  CRYPTO_clear_free(*(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0x14),
                                    "crypto/cms/cms_pwri.c",0x178);
                  *(uchar **)(iVar6 + 0x10) = out;
                  *(uint *)(iVar6 + 0x14) = uVar9;
                  goto LAB_00191b4a;
                }
              }
              CRYPTO_clear_free(pbVar11,uVar3,"crypto/cms/cms_pwri.c",0xe2);
            }
          }
          ERR_put_error(0x2e,0xa7,0xb4,"crypto/cms/cms_pwri.c",0x174);
        }
      }
      else {
        uVar9 = *(uint *)(iVar6 + 0x14);
        iVar1 = EVP_CIPHER_CTX_block_size(ctx);
        iVar2 = __aeabi_uidiv(uVar9 + 3 + iVar1,iVar1);
        uVar3 = iVar1 * iVar2;
        bVar13 = uVar3 <= (uint)(iVar1 * 2);
        bVar12 = iVar1 * 2 - uVar3 == 0;
        if (!bVar13 || bVar12) {
          bVar13 = 0xfe < uVar9;
          bVar12 = uVar9 == 0xff;
        }
        if ((bVar13 && !bVar12) ||
           (out = (uchar *)CRYPTO_malloc(uVar3,"crypto/cms/cms_pwri.c",0x161), out == (uchar *)0x0))
        goto LAB_001919f4;
        uVar3 = *(uint *)(iVar6 + 0x14);
        pbVar11 = *(byte **)(iVar6 + 0x10);
        iVar6 = EVP_CIPHER_CTX_block_size(ctx);
        iVar1 = __aeabi_uidiv(uVar3 + 3 + iVar6,iVar6);
        uVar9 = iVar6 * iVar1;
        bVar13 = uVar9 <= (uint)(iVar6 * 2);
        bVar12 = iVar6 * 2 - uVar9 == 0;
        if (!bVar13 || bVar12) {
          bVar13 = 0xfe < uVar3;
          bVar12 = uVar3 == 0xff;
        }
        if (!bVar13 || bVar12) {
          *out = (uchar)uVar3;
          out[1] = ~*pbVar11;
          out[2] = ~pbVar11[1];
          out[3] = ~pbVar11[2];
          memcpy(out + 4,pbVar11,uVar3);
          uVar4 = uVar3 + 4;
          if ((uVar9 < uVar4 || uVar9 - uVar4 == 0) ||
             (iVar6 = RAND_bytes(out + uVar4,(uVar9 - uVar3) + -4), 0 < iVar6)) {
            iVar6 = EVP_EncryptUpdate(ctx,out,aiStack_2c,out,uVar9);
            if ((iVar6 != 0) &&
               (iVar6 = EVP_EncryptUpdate(ctx,out,aiStack_2c,out,uVar9), iVar6 != 0)) {
              puVar5 = *(uint **)(iVar10 + 0xc);
              puVar5[2] = (uint)out;
              *puVar5 = uVar9;
LAB_00191b4a:
              uVar8 = 1;
              EVP_CIPHER_CTX_free(ctx);
              goto LAB_00191a0c;
            }
          }
        }
      }
    }
  }
  uVar8 = 0;
  EVP_CIPHER_CTX_free(ctx);
  CRYPTO_free(out);
LAB_00191a0c:
  X509_ALGOR_free(a);
  return uVar8;
}

