
undefined4 x509_name_canon_part_0(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  X509_NAME_ENTRY *a;
  ASN1_OBJECT *pAVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  ASN1_STRING *in;
  byte *pbVar9;
  byte *pbVar10;
  undefined4 uVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  ASN1_STRING *dst;
  int local_48;
  int local_40;
  int local_3c;
  uchar *local_30;
  ASN1_VALUE *local_2c [2];
  
  iVar2 = OPENSSL_sk_new_null();
  if (iVar2 == 0) {
    ERR_put_error(0xb,0x9c,0x41,"crypto/x509/x_name.c",0x13d);
    uVar11 = 0;
    a = (X509_NAME_ENTRY *)0x0;
  }
  else {
    local_40 = -1;
    local_3c = 0;
    for (local_48 = 0; iVar3 = OPENSSL_sk_num(*param_1), local_48 < iVar3; local_48 = local_48 + 1)
    {
      puVar4 = (undefined4 *)OPENSSL_sk_value(*param_1,local_48);
      if (puVar4[2] != local_40) {
        local_3c = OPENSSL_sk_new_null();
        if (local_3c == 0) {
          uVar11 = 0;
          a = (X509_NAME_ENTRY *)0x0;
          goto LAB_0017724a;
        }
        iVar3 = OPENSSL_sk_push(iVar2,local_3c);
        if (iVar3 == 0) {
          OPENSSL_sk_free(local_3c);
          ERR_put_error(0xb,0x9c,0x41,"crypto/x509/x_name.c",0x148);
          uVar11 = 0;
          a = (X509_NAME_ENTRY *)0x0;
          goto LAB_0017724a;
        }
        local_40 = puVar4[2];
      }
      a = X509_NAME_ENTRY_new();
      if (a == (X509_NAME_ENTRY *)0x0) {
        ERR_put_error(0xb,0x9c,0x41,"crypto/x509/x_name.c",0x14f);
        uVar11 = 0;
        goto LAB_0017724a;
      }
      pAVar5 = OBJ_dup((ASN1_OBJECT *)*puVar4);
      a->object = pAVar5;
      if (pAVar5 == (ASN1_OBJECT *)0x0) {
        iVar3 = 0x154;
LAB_00177412:
        uVar11 = 0;
        ERR_put_error(0xb,0x9c,0x41,"crypto/x509/x_name.c",iVar3);
        goto LAB_0017724a;
      }
      in = (ASN1_STRING *)puVar4[1];
      dst = a->value;
      uVar6 = ASN1_tag2bit(in->type);
      if ((uVar6 & 0x2956) == 0) {
        iVar3 = ASN1_STRING_copy(dst,in);
        if (iVar3 == 0) {
LAB_00177248:
          uVar11 = 0;
          goto LAB_0017724a;
        }
      }
      else {
        dst->type = 0xc;
        iVar3 = ASN1_STRING_to_UTF8(&dst->data,in);
        dst->length = iVar3;
        if (iVar3 == -1) goto LAB_00177248;
        pbVar9 = dst->data;
        if (0 < iVar3) {
          do {
            iVar7 = ossl_ctype_check(*pbVar9,8);
            if (iVar7 == 0) {
              pbVar14 = pbVar9 + iVar3;
              goto LAB_001772cc;
            }
            iVar3 = iVar3 + -1;
            pbVar9 = pbVar9 + 1;
          } while (iVar3 != 0);
        }
        dst->length = 0;
      }
LAB_00177272:
      iVar3 = OPENSSL_sk_push(local_3c,a);
      if (iVar3 == 0) {
        iVar3 = 0x15a;
        goto LAB_00177412;
      }
    }
    iVar7 = 0;
    iVar3 = 0;
    do {
      iVar8 = OPENSSL_sk_num(iVar2);
      if (iVar8 <= iVar3) {
        param_1[4] = iVar7;
        local_30 = (uchar *)CRYPTO_malloc(iVar7,"crypto/x509/x_name.c",0x166);
        if (local_30 == (uchar *)0x0) {
          ERR_put_error(0xb,0x9c,0x41,"crypto/x509/x_name.c",0x168);
          uVar11 = 0;
          a = (X509_NAME_ENTRY *)0x0;
          goto LAB_0017724a;
        }
        param_1[3] = local_30;
        iVar3 = 0;
        goto LAB_001773d6;
      }
      local_2c[0] = (ASN1_VALUE *)OPENSSL_sk_value(iVar2,iVar3);
      iVar8 = ASN1_item_ex_i2d(local_2c,(uchar **)0x0,(ASN1_ITEM *)&X509_NAME_ENTRIES_it,-1,-1);
      iVar7 = iVar7 + iVar8;
      iVar3 = iVar3 + 1;
    } while (-1 < iVar8);
    uVar11 = 0;
    a = (X509_NAME_ENTRY *)0x0;
  }
  goto LAB_0017724a;
LAB_001772cc:
  pbVar14 = pbVar14 + -1;
  iVar7 = ossl_ctype_check(*pbVar14,8);
  if (iVar7 != 0) goto LAB_001772c8;
  pbVar14 = (byte *)0x0;
  pbVar13 = dst->data;
  do {
    pbVar12 = pbVar13 + 1;
    bVar1 = *pbVar9;
    if ((int)((uint)bVar1 << 0x18) < 0) {
      pbVar10 = pbVar9 + 1;
      pbVar14 = pbVar14 + 1;
      *pbVar13 = bVar1;
    }
    else {
      iVar7 = ossl_ctype_check(bVar1,8);
      if (iVar7 == 0) {
        pbVar10 = pbVar9 + 1;
        pbVar14 = pbVar14 + 1;
        bVar1 = ossl_tolower(*pbVar9);
        *pbVar13 = bVar1;
      }
      else {
        iVar7 = (int)pbVar14 - (int)pbVar9;
        *pbVar13 = 0x20;
        pbVar10 = pbVar9;
        do {
          pbVar10 = pbVar10 + 1;
          pbVar14 = pbVar10 + iVar7;
          iVar8 = ossl_ctype_check(*pbVar10,8);
        } while (iVar8 != 0);
      }
    }
    pbVar9 = pbVar10;
    pbVar13 = pbVar12;
  } while ((int)pbVar14 < iVar3);
  iVar7 = (int)pbVar12 - (int)dst->data;
LAB_0017726e:
  dst->length = iVar7;
  goto LAB_00177272;
LAB_001772c8:
  iVar3 = iVar3 + -1;
  iVar7 = 0;
  if (iVar3 == 0) goto LAB_0017726e;
  goto LAB_001772cc;
  while( true ) {
    local_2c[0] = (ASN1_VALUE *)OPENSSL_sk_value(iVar2,iVar3);
    iVar7 = ASN1_item_ex_i2d(local_2c,&local_30,(ASN1_ITEM *)&X509_NAME_ENTRIES_it,-1,-1);
    iVar3 = iVar3 + 1;
    if (iVar7 < 0) break;
LAB_001773d6:
    iVar7 = OPENSSL_sk_num(iVar2);
    if (iVar7 <= iVar3) break;
  }
  uVar11 = 1;
  a = (X509_NAME_ENTRY *)0x0;
LAB_0017724a:
  X509_NAME_ENTRY_free(a);
  OPENSSL_sk_pop_free(iVar2,0x177091);
  return uVar11;
}

