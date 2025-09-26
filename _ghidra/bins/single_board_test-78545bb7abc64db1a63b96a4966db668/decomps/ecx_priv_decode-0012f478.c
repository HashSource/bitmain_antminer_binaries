
undefined4 ecx_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  ASN1_OCTET_STRING *x;
  uchar *puVar4;
  void *ptr;
  void *__dest;
  undefined4 *puVar5;
  size_t __n;
  undefined4 *puVar6;
  uchar *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uchar *__src;
  undefined4 uVar10;
  uchar *local_30;
  uchar *local_2c;
  X509_ALGOR *local_28;
  int local_24;
  
  iVar3 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&local_30,(int *)&local_2c,&local_28,param_2);
  if (iVar3 == 0) {
    return 0;
  }
  x = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_30,(long)local_2c);
  if (x == (ASN1_OCTET_STRING *)0x0) {
    iVar3 = *(int *)param_1->ameth;
    puVar4 = (uchar *)0x0;
    local_30 = puVar4;
    local_2c = puVar4;
    if (local_28 != (X509_ALGOR *)0x0) goto LAB_0012f4c8;
LAB_0012f50a:
    iVar3 = 0x41;
  }
  else {
    local_30 = (uchar *)ASN1_STRING_get0_data();
    puVar4 = (uchar *)ASN1_STRING_length(x);
    iVar3 = *(int *)param_1->ameth;
    __src = local_30;
    local_2c = puVar4;
    if (local_28 == (X509_ALGOR *)0x0) {
LAB_0012f4d8:
      if (__src != (uchar *)0x0) {
        if (iVar3 == 0x40a || iVar3 == 0x43f) {
          bVar1 = false;
          puVar7 = (uchar *)0x20;
        }
        else {
          bVar1 = true;
          if (iVar3 == 0x40b) {
            puVar7 = (uchar *)0x38;
          }
          else {
            puVar7 = (uchar *)0x39;
          }
        }
        if (puVar7 == puVar4) {
          ptr = (void *)CRYPTO_zalloc(0x40,"crypto/ec/ecx_meth.c",0x46);
          if (ptr == (void *)0x0) {
            ERR_put_error(0x10,0x10a,0x41,"crypto/ec/ecx_meth.c",0x48);
            uVar8 = 0;
            goto LAB_0012f520;
          }
          if (bVar1) {
            if (iVar3 == 0x40b) {
              puVar5 = (undefined4 *)CRYPTO_secure_malloc(0x38,"crypto/ec/ecx_meth.c",0x50);
              *(undefined4 **)((int)ptr + 0x3c) = puVar5;
              puVar2 = puVar5;
              puVar4 = __src;
              if (puVar5 != (undefined4 *)0x0) {
                do {
                  puVar7 = puVar4;
                  puVar6 = puVar2;
                  puVar4 = puVar7 + 0x10;
                  uVar10 = *(undefined4 *)(puVar7 + 4);
                  uVar9 = *(undefined4 *)(puVar7 + 8);
                  uVar8 = *(undefined4 *)(puVar7 + 0xc);
                  *puVar6 = *(undefined4 *)puVar7;
                  puVar6[1] = uVar10;
                  puVar6[2] = uVar9;
                  puVar6[3] = uVar8;
                  puVar2 = puVar6 + 4;
                } while (puVar4 != __src + 0x30);
                uVar8 = *(undefined4 *)(puVar7 + 0x14);
                puVar6[4] = *(undefined4 *)puVar4;
                puVar6[5] = uVar8;
                goto LAB_0012f630;
              }
            }
            else {
              __dest = (void *)CRYPTO_secure_malloc(0x39,"crypto/ec/ecx_meth.c",0x50);
              *(void **)((int)ptr + 0x3c) = __dest;
              if (__dest != (void *)0x0) {
                __n = 0x39;
                goto LAB_0012f568;
              }
            }
          }
          else {
            __dest = (void *)CRYPTO_secure_malloc(0x20,"crypto/ec/ecx_meth.c",0x50);
            *(void **)((int)ptr + 0x3c) = __dest;
            if (__dest != (void *)0x0) {
              __n = 0x20;
LAB_0012f568:
              puVar5 = (undefined4 *)memcpy(__dest,__src,__n);
              if (iVar3 == 0x40b) {
LAB_0012f630:
                X448_public_from_private(ptr,puVar5);
              }
              else if (iVar3 < 0x40c) {
                if (iVar3 == 0x40a) {
                  X25519_public_from_private(ptr,puVar5);
                }
              }
              else if (iVar3 == 0x43f) {
                ED25519_public_from_private(ptr,puVar5);
              }
              else if (iVar3 == 0x440) {
                ED448_public_from_private(ptr,puVar5);
              }
              uVar8 = 1;
              EVP_PKEY_assign(param_1,iVar3,ptr);
              goto LAB_0012f520;
            }
          }
          uVar8 = 0;
          ERR_put_error(0x10,0x10a,0x41,"crypto/ec/ecx_meth.c",0x52);
          CRYPTO_free(ptr);
          goto LAB_0012f520;
        }
      }
      goto LAB_0012f50a;
    }
LAB_0012f4c8:
    __src = local_30;
    local_2c = puVar4;
    X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_24,(void **)0x0,local_28);
    if (local_24 == -1) goto LAB_0012f4d8;
    iVar3 = 0x3b;
  }
  uVar8 = 0;
  ERR_put_error(0x10,0x10a,0x66,"crypto/ec/ecx_meth.c",iVar3);
LAB_0012f520:
  ASN1_STRING_clear_free(x);
  return uVar8;
}

