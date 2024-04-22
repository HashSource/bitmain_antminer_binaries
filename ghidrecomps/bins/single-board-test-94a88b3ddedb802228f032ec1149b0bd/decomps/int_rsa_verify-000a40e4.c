
uint int_rsa_verify(int param_1,void *param_2,size_t param_3,undefined4 *param_4,int *param_5,
                   uchar *param_6,size_t param_7,RSA *param_8)

{
  uchar *ptr;
  size_t len;
  int iVar1;
  uchar *to;
  size_t __n;
  X509_SIG *a;
  undefined4 uVar2;
  size_t len_00;
  char *name;
  EVP_MD *md;
  undefined4 uVar3;
  undefined4 uVar4;
  X509_ALGOR *pXVar5;
  ASN1_OCTET_STRING *pAVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uchar *local_30;
  uchar *local_2c [2];
  
  len = RSA_size(param_8);
  if (len != param_7) {
    ERR_put_error(4,0x91,0x77,DAT_000a43c8,0xba);
    return 0;
  }
  uVar8 = (uint)(param_1 == 0x72);
  puVar7 = param_4;
  if (param_4 != (undefined4 *)0x0) {
    puVar7 = (undefined4 *)0x1;
  }
  if (((uint)puVar7 & uVar8) != 0) {
    iVar1 = RSA_public_decrypt(len,param_6,(uchar *)param_4,param_8,1);
    if (iVar1 < 1) {
      return (uint)(0 < iVar1);
    }
    *param_5 = iVar1;
    return (uint)(0 < iVar1);
  }
  to = (uchar *)CRYPTO_malloc(len,DAT_000a43c8,199);
  if (to == (uchar *)0x0) {
    ERR_put_error(4,0x91,0x41,DAT_000a43c8,0xc9);
    return 0;
  }
  uVar9 = uVar8;
  if (param_3 == 0x24) {
    uVar9 = 0;
  }
  if (uVar9 != 0) {
    ERR_put_error(4,0x91,0x83,DAT_000a43c8,0xcd);
    uVar8 = 0;
    goto LAB_000a41ee;
  }
  __n = RSA_public_decrypt(len,param_6,to,param_8,1);
  if (0 < (int)__n) {
    if (__n == 0x12 && param_1 == 0x5f) {
      if ((*to == '\x04') && (to[1] == '\x10')) {
        if (puVar7 == (undefined4 *)0x0) {
          iVar1 = memcmp(param_2,to + 2,0x10);
          uVar8 = 1;
          if (iVar1 != 0) {
            ERR_put_error(4,0x91,0x68,DAT_000a43c8,0xde);
            goto LAB_000a4188;
          }
        }
        else {
          uVar8 = 1;
          uVar2 = *(undefined4 *)(to + 6);
          uVar3 = *(undefined4 *)(to + 10);
          uVar4 = *(undefined4 *)(to + 0xe);
          *param_4 = *(undefined4 *)(to + 2);
          param_4[1] = uVar2;
          param_4[2] = uVar3;
          param_4[3] = uVar4;
          *param_5 = 0x10;
        }
      }
      else {
LAB_000a4188:
        uVar8 = 0;
      }
LAB_000a418a:
      local_30 = to;
      a = d2i_X509_SIG((X509_SIG **)0x0,&local_30,__n);
      if (a == (X509_SIG *)0x0) goto LAB_000a41ee;
      if (local_30 == to + __n) {
        local_2c[0] = (uchar *)0x0;
        len_00 = i2d_X509_SIG(a,local_2c);
        ptr = local_2c[0];
        if ((int)len_00 < 1) goto LAB_000a41a8;
        if (__n != len_00) {
          OPENSSL_cleanse(local_2c[0],len_00);
          CRYPTO_free(local_2c[0]);
          goto LAB_000a41a8;
        }
        iVar1 = memcmp(to,local_2c[0],__n);
        OPENSSL_cleanse(ptr,__n);
        CRYPTO_free(local_2c[0]);
        if (iVar1 != 0) goto LAB_000a41a8;
        pXVar5 = a->algor;
        if (pXVar5->parameter != (ASN1_TYPE *)0x0) {
          iVar1 = ASN1_TYPE_get(pXVar5->parameter);
          if (iVar1 == 5) {
            pXVar5 = a->algor;
            goto LAB_000a42ea;
          }
          iVar1 = 0xfc;
          goto LAB_000a41aa;
        }
LAB_000a42ea:
        iVar1 = OBJ_obj2nid(pXVar5->algorithm);
        if (iVar1 == param_1) {
          if (puVar7 == (undefined4 *)0x0) {
            if ((a->digest->length != param_3) ||
               (iVar1 = memcmp(param_2,a->digest->data,param_3), iVar1 != 0)) {
              iVar1 = 0x117;
              goto LAB_000a41aa;
            }
            uVar8 = 1;
          }
          else {
            name = OBJ_nid2sn(iVar1);
            md = EVP_get_digestbyname(name);
            if (md == (EVP_MD *)0x0) {
              pAVar6 = a->digest;
            }
            else {
              iVar1 = EVP_MD_size(md);
              pAVar6 = a->digest;
              if (iVar1 != pAVar6->length) {
                ERR_put_error(4,0x91,0x8f,DAT_000a43c8,0x10f);
                goto LAB_000a41c0;
              }
            }
            uVar8 = 1;
            memcpy(param_4,pAVar6->data,pAVar6->length);
            *param_5 = a->digest->length;
          }
        }
        else {
          ERR_put_error(4,0x91,100,DAT_000a43c8,0x108);
        }
      }
      else {
LAB_000a41a8:
        iVar1 = 0xf2;
LAB_000a41aa:
        ERR_put_error(4,0x91,0x68,DAT_000a43c8,iVar1);
      }
LAB_000a41c0:
      X509_SIG_free(a);
      goto LAB_000a41ee;
    }
    if (uVar8 == 0) goto LAB_000a418a;
    if (__n == 0x24) {
      uVar8 = 1;
      iVar1 = memcmp(to,param_2,0x24);
      if (iVar1 == 0) goto LAB_000a41ee;
    }
    ERR_put_error(4,0x91,0x68,DAT_000a43c8,0xe6);
  }
  uVar8 = 0;
LAB_000a41ee:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return uVar8;
}

