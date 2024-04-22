
undefined4 cms_RecipientInfo_pwri_crypt(int param_1,int param_2,int param_3)

{
  int iVar1;
  X509_ALGOR *a;
  char *name;
  EVP_CIPHER *cipher;
  int iVar2;
  uchar *out;
  uint uVar3;
  int extraout_r1;
  char **ppcVar4;
  uint *puVar5;
  undefined4 uVar6;
  int iVar7;
  ASN1_OBJECT **ppAVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  uchar *in;
  uchar *local_bc;
  int iStack_b8;
  EVP_CIPHER_CTX EStack_b4;
  
  iVar7 = *(int *)(param_2 + 4);
  iVar10 = *(int *)(*(int *)(param_1 + 4) + 0xc);
  local_bc = (uchar *)0x0;
  EVP_CIPHER_CTX_init(&EStack_b4);
  if (*(int *)(iVar7 + 0x10) == 0) {
    ERR_put_error(0x2e,0xa7,0xb2,DAT_000d68e8,0x14f);
    return 0;
  }
  ppAVar8 = *(ASN1_OBJECT ***)(iVar7 + 8);
  if ((ppAVar8 == (ASN1_OBJECT **)0x0) || (iVar1 = OBJ_obj2nid(*ppAVar8), iVar1 != 0x37d)) {
    ERR_put_error(0x2e,0xa7,0xb3,DAT_000d68e8,0x156);
    return 0;
  }
  if (ppAVar8[1]->sn != (char *)0x10) {
LAB_000d66c8:
    ERR_put_error(0x2e,0xa7,0xb0,DAT_000d68e8,0x161);
    return 0;
  }
  ppcVar4 = ppAVar8[1]->ln;
  local_bc = (uchar *)ppcVar4[2];
  a = d2i_X509_ALGOR((X509_ALGOR **)0x0,&local_bc,(long)*ppcVar4);
  if (a == (X509_ALGOR *)0x0) goto LAB_000d66c8;
  iVar1 = OBJ_obj2nid(a->algorithm);
  name = OBJ_nid2sn(iVar1);
  cipher = EVP_get_cipherbyname(name);
  if (cipher == (EVP_CIPHER *)0x0) {
    ERR_put_error(0x2e,0xa7,0x94,DAT_000d68e8,0x168);
    uVar6 = 0;
  }
  else {
    iVar1 = EVP_CipherInit_ex(&EStack_b4,cipher,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,param_3);
    if (iVar1 == 0) {
LAB_000d6720:
      uVar6 = 0;
    }
    else {
      EVP_CIPHER_CTX_set_padding(&EStack_b4,0);
      iVar1 = EVP_CIPHER_asn1_to_param(&EStack_b4,a->parameter);
      if (iVar1 < 0) {
        uVar6 = 0;
        ERR_put_error(0x2e,0xa7,0x66,DAT_000d68e8,0x172);
      }
      else {
        iVar1 = EVP_PBE_CipherInit(**(ASN1_OBJECT ***)(iVar7 + 4),*(char **)(iVar7 + 0x10),
                                   *(int *)(iVar7 + 0x14),
                                   (ASN1_TYPE *)(*(ASN1_OBJECT ***)(iVar7 + 4))[1],&EStack_b4,
                                   param_3);
        if (-1 < iVar1) {
          if (param_3 == 0) {
            out = (uchar *)CRYPTO_malloc(**(int **)(iVar7 + 0xc),DAT_000d68e8,0x192);
            if (out == (uchar *)0x0) {
              ERR_put_error(0x2e,0xa7,0x41,DAT_000d69d8,0x195);
              uVar6 = 0;
              goto LAB_000d6722;
            }
            uVar9 = **(uint **)(iVar7 + 0xc);
            in = (uchar *)(*(uint **)(iVar7 + 0xc))[2];
            iVar7 = EVP_CIPHER_CTX_block_size(&EStack_b4);
            if ((((uint)(iVar7 * 2) <= uVar9) && (__aeabi_uidivmod(uVar9,iVar7), extraout_r1 == 0))
               && (pbVar12 = (byte *)CRYPTO_malloc(uVar9,DAT_000d69d8,0xe9), pbVar12 != (byte *)0x0)
               ) {
              iVar1 = uVar9 + iVar7 * -2;
              EVP_DecryptUpdate(&EStack_b4,pbVar12 + iVar1,&iStack_b8,in + iVar1,iVar7 * 2);
              EVP_DecryptUpdate(&EStack_b4,pbVar12,&iStack_b8,pbVar12 + (uVar9 - iVar7),iVar7);
              EVP_DecryptUpdate(&EStack_b4,pbVar12,&iStack_b8,in,uVar9 - iVar7);
              EVP_DecryptInit_ex(&EStack_b4,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                                 (uchar *)0x0);
              EVP_DecryptUpdate(&EStack_b4,pbVar12,&iStack_b8,pbVar12,uVar9);
              if (((byte)((pbVar12[3] ^ pbVar12[6]) &
                         (pbVar12[1] ^ pbVar12[4]) & (pbVar12[5] ^ pbVar12[2])) == 0xff) &&
                 (uVar11 = (uint)*pbVar12, uVar11 - 4 <= uVar9)) {
                uVar6 = 1;
                memcpy(out,pbVar12 + 4,uVar11);
                OPENSSL_cleanse(pbVar12,uVar9);
                CRYPTO_free(pbVar12);
                *(uchar **)(iVar10 + 0x10) = out;
                *(uint *)(iVar10 + 0x14) = uVar11;
                goto LAB_000d6722;
              }
              OPENSSL_cleanse(pbVar12,uVar9);
              CRYPTO_free(pbVar12);
            }
            ERR_put_error(0x2e,0xa7,0xb4,DAT_000d68e8,0x19b);
          }
          else {
            uVar9 = *(uint *)(iVar10 + 0x14);
            iVar1 = EVP_CIPHER_CTX_block_size(&EStack_b4);
            iVar2 = __aeabi_uidiv(uVar9 + 3 + iVar1,iVar1);
            if ((((uint)(iVar1 * iVar2) < (uint)(iVar1 << 1)) || (0xff < uVar9)) ||
               (out = (uchar *)CRYPTO_malloc(iVar1 * iVar2,DAT_000d68e8,0x188), out == (uchar *)0x0)
               ) goto LAB_000d6720;
            uVar9 = *(uint *)(iVar10 + 0x14);
            pbVar12 = *(byte **)(iVar10 + 0x10);
            iVar10 = EVP_CIPHER_CTX_block_size(&EStack_b4);
            iVar1 = __aeabi_uidiv(uVar9 + 3 + iVar10,iVar10);
            uVar11 = iVar10 * iVar1;
            if (((uint)(iVar10 << 1) <= uVar11) && (uVar9 < 0x100)) {
              *out = (uchar)uVar9;
              out[1] = ~*pbVar12;
              out[2] = ~pbVar12[1];
              out[3] = ~pbVar12[2];
              memcpy(out + 4,pbVar12,uVar9);
              uVar3 = uVar9 + 4;
              if ((uVar11 < uVar3 || uVar11 - uVar3 == 0) ||
                 (iVar10 = RAND_pseudo_bytes(out + uVar3,(-4 - uVar9) + uVar11), -1 < iVar10)) {
                uVar6 = 1;
                EVP_EncryptUpdate(&EStack_b4,out,&iStack_b8,out,uVar11);
                EVP_EncryptUpdate(&EStack_b4,out,&iStack_b8,out,uVar11);
                puVar5 = *(uint **)(iVar7 + 0xc);
                puVar5[2] = (uint)out;
                *puVar5 = uVar11;
                goto LAB_000d6722;
              }
            }
          }
          uVar6 = 0;
          EVP_CIPHER_CTX_cleanup(&EStack_b4);
          CRYPTO_free(out);
          goto LAB_000d6728;
        }
        uVar6 = 0;
        ERR_put_error(0x2e,0xa7,6,DAT_000d68e8,0x17d);
      }
    }
  }
LAB_000d6722:
  EVP_CIPHER_CTX_cleanup(&EStack_b4);
LAB_000d6728:
  X509_ALGOR_free(a);
  return uVar6;
}

