
ASN1_VALUE *
asn1_template_ex_i2d(ASN1_VALUE *param_1,uchar **param_2,uint *param_3,uint param_4,uint param_5)

{
  undefined4 *puVar1;
  int iVar2;
  ASN1_VALUE *length;
  int iVar3;
  ASN1_VALUE *pAVar4;
  int iVar5;
  void *ptr;
  uchar *ptr_00;
  size_t __nmemb;
  ASN1_VALUE *pAVar6;
  uint uVar7;
  ASN1_ITEM *it;
  uint aclass;
  bool bVar8;
  uint local_50;
  int local_4c;
  uint local_48;
  int local_44;
  uint local_40;
  ASN1_VALUE *local_38;
  ASN1_VALUE *local_34;
  ASN1_VALUE *local_30;
  uchar *local_2c [2];
  
  uVar7 = *param_3;
  bVar8 = (int)(uVar7 << 0x13) < 0;
  if (bVar8) {
    local_38 = param_1;
  }
  if (bVar8) {
    param_1 = (ASN1_VALUE *)&local_38;
  }
  if ((uVar7 & 0x18) == 0) {
    if (param_4 == 0xffffffff) {
      local_50 = 0;
    }
    else {
      local_50 = param_5 & 0xc0;
    }
  }
  else {
    if (param_4 != 0xffffffff) {
      return (ASN1_VALUE *)0xffffffff;
    }
    param_4 = param_3[1];
    local_50 = uVar7 & 0xc0;
  }
  aclass = param_5 & 0xffffff3f;
  if ((int)(uVar7 << 0x14) < 0) {
    if ((param_5 & 0x800) == 0) {
      local_4c = 1;
    }
    else {
      local_4c = 2;
    }
  }
  else {
    local_4c = 1;
  }
  if ((uVar7 & 6) == 0) {
    if (-1 < (int)(uVar7 << 0x1b)) {
      pAVar6 = (ASN1_VALUE *)
               ASN1_item_ex_i2d((ASN1_VALUE **)param_1,param_2,(ASN1_ITEM *)param_3[4],param_4,
                                local_50 | aclass);
      return pAVar6;
    }
    iVar5 = ASN1_item_ex_i2d((ASN1_VALUE **)param_1,(uchar **)0x0,(ASN1_ITEM *)param_3[4],-1,aclass)
    ;
    pAVar6 = (ASN1_VALUE *)0x0;
    if ((iVar5 != 0) &&
       (pAVar6 = (ASN1_VALUE *)ASN1_object_size(local_4c,iVar5,param_4),
       param_2 != (uchar **)0x0 && pAVar6 != (ASN1_VALUE *)0xffffffff)) {
      ASN1_put_object(param_2,local_4c,iVar5,param_4,local_50);
      ASN1_item_ex_i2d((ASN1_VALUE **)param_1,param_2,(ASN1_ITEM *)param_3[4],-1,aclass);
      if (local_4c == 2) {
        ASN1_put_eoc(param_2);
      }
    }
  }
  else {
    pAVar6 = *(ASN1_VALUE **)param_1;
    if (pAVar6 != (ASN1_VALUE *)0x0) {
      local_48 = param_4;
      if ((uVar7 & 2) == 0) {
        if ((param_4 == 0xffffffff) || ((uVar7 & 0x10) != 0)) {
          local_48 = 0x10;
          local_44 = 0;
          local_40 = 0;
        }
        else {
          local_40 = local_50;
          local_44 = 0;
        }
      }
      else {
        if ((uVar7 & 4) == 0) {
          local_44 = 1;
        }
        else {
          local_44 = 2;
        }
        if (param_4 == 0xffffffff) {
          local_40 = 0;
          local_48 = 0x11;
        }
        else {
          local_40 = local_50;
          if ((uVar7 & 0x10) != 0) {
            local_40 = 0;
            local_48 = 0x11;
          }
        }
      }
      iVar5 = 0;
      iVar3 = 0;
      do {
        iVar2 = OPENSSL_sk_num(pAVar6);
        if (iVar2 <= iVar5) {
          length = (ASN1_VALUE *)ASN1_object_size(local_4c,iVar3,local_48);
          if (length == (ASN1_VALUE *)0xffffffff) {
            return (ASN1_VALUE *)0xffffffff;
          }
          if ((uVar7 & 0x10) == 0) {
            pAVar4 = length;
            if (param_2 == (uchar **)0x0) {
              return length;
            }
          }
          else {
            pAVar4 = (ASN1_VALUE *)ASN1_object_size(local_4c,(int)length,param_4);
            if (pAVar4 == (ASN1_VALUE *)0xffffffff || param_2 == (uchar **)0x0) {
              return pAVar4;
            }
            ASN1_put_object(param_2,local_4c,(int)length,param_4,local_50);
          }
          ASN1_put_object(param_2,local_4c,iVar3,local_48,local_40);
          it = (ASN1_ITEM *)param_3[4];
          local_2c[0] = (uchar *)0x0;
          if ((local_44 == 0) || (iVar5 = OPENSSL_sk_num(pAVar6), iVar5 < 2)) {
            iVar5 = 0;
            while( true ) {
              iVar3 = OPENSSL_sk_num(pAVar6);
              if (iVar3 <= iVar5) break;
              local_30 = (ASN1_VALUE *)OPENSSL_sk_value(pAVar6,iVar5);
              ASN1_item_ex_i2d(&local_30,param_2,it,-1,aclass);
              iVar5 = iVar5 + 1;
            }
          }
          else {
            iVar5 = OPENSSL_sk_num(pAVar6);
            ptr = CRYPTO_malloc(iVar5 * 0xc,"crypto/asn1/tasn_enc.c",400);
            if (ptr != (void *)0x0) {
              ptr_00 = (uchar *)CRYPTO_malloc(iVar3,"crypto/asn1/tasn_enc.c",0x193);
              if (ptr_00 == (uchar *)0x0) {
                CRYPTO_free(ptr);
              }
              else {
                iVar5 = (int)ptr + 0x34;
                iVar3 = 0;
                local_2c[0] = ptr_00;
                while( true ) {
                  HintPreloadData(iVar5);
                  iVar2 = OPENSSL_sk_num(pAVar6);
                  if (iVar2 <= iVar3) break;
                  local_30 = (ASN1_VALUE *)OPENSSL_sk_value(pAVar6,iVar3);
                  *(uchar **)(iVar5 + -0x34) = local_2c[0];
                  iVar2 = ASN1_item_ex_i2d(&local_30,local_2c,it,-1,aclass);
                  *(int *)(iVar5 + -0x30) = iVar2;
                  *(ASN1_VALUE **)(iVar5 + -0x2c) = local_30;
                  iVar5 = iVar5 + 0xc;
                  iVar3 = iVar3 + 1;
                }
                __nmemb = OPENSSL_sk_num();
                qsort(ptr,__nmemb,0xc,(__compar_fn_t)0x104625);
                local_2c[0] = *param_2;
                iVar5 = (int)ptr + 0x4c;
                iVar3 = 0;
                while( true ) {
                  HintPreloadData(iVar5);
                  iVar2 = OPENSSL_sk_num(pAVar6);
                  if (iVar2 <= iVar3) break;
                  memcpy(local_2c[0],*(void **)(iVar5 + -0x4c),*(size_t *)(iVar5 + -0x48));
                  local_2c[0] = local_2c[0] + *(int *)(iVar5 + -0x48);
                  iVar5 = iVar5 + 0xc;
                  iVar3 = iVar3 + 1;
                }
                *param_2 = local_2c[0];
                if (local_44 == 2) {
                  iVar3 = (int)ptr + 0x5c;
                  iVar5 = 0;
                  while( true ) {
                    HintPreloadData(iVar3);
                    iVar2 = OPENSSL_sk_num(pAVar6);
                    if (iVar2 <= iVar5) break;
                    puVar1 = (undefined4 *)(iVar3 + -0x54);
                    iVar3 = iVar3 + 0xc;
                    OPENSSL_sk_set(pAVar6,iVar5,*puVar1);
                    iVar5 = iVar5 + 1;
                  }
                }
                CRYPTO_free(ptr);
                CRYPTO_free(ptr_00);
              }
            }
          }
          if (local_4c != 2) {
            return pAVar4;
          }
          ASN1_put_eoc(param_2);
          if ((uVar7 & 0x10) == 0) {
            return pAVar4;
          }
          ASN1_put_eoc(param_2);
          return pAVar4;
        }
        local_34 = (ASN1_VALUE *)OPENSSL_sk_value(pAVar6,iVar5);
        iVar2 = ASN1_item_ex_i2d(&local_34,(uchar **)0x0,(ASN1_ITEM *)param_3[4],-1,aclass);
        if (iVar2 == -1) {
          return (ASN1_VALUE *)0xffffffff;
        }
        bVar8 = iVar3 <= 0x7fffffff - iVar2;
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 + iVar2;
      } while (bVar8);
      return (ASN1_VALUE *)0xffffffff;
    }
  }
  return pAVar6;
}

