
ASN1_VALUE * SMIME_read_ASN1(BIO *bio,BIO **bcont,ASN1_ITEM *it)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  BIO_METHOD *pBVar5;
  BIO *pBVar6;
  BIO *pBVar7;
  ASN1_VALUE *pAVar8;
  BIO *in;
  char *pcVar9;
  undefined4 local_38;
  char *local_34;
  int local_30;
  int local_2c;
  
  local_38 = 0;
  if (bcont != (BIO **)0x0) {
    *bcont = (BIO *)0x0;
  }
  iVar1 = mime_parse_hdr(bio);
  if (iVar1 == 0) {
    ERR_put_error(0xd,0xd4,0xcf,"crypto/asn1/asn_mime.c",0x188);
    return (ASN1_VALUE *)0x0;
  }
  local_30 = 0;
  local_2c = 0;
  local_34 = "content-type";
  uVar2 = OPENSSL_sk_find(iVar1,&local_34);
  iVar3 = OPENSSL_sk_value(iVar1,uVar2);
  if ((iVar3 == 0) || (pcVar9 = *(char **)(iVar3 + 4), pcVar9 == (char *)0x0)) {
    OPENSSL_sk_pop_free(iVar1,0x1c5149);
    ERR_put_error(0xd,0xd4,0xd1,"crypto/asn1/asn_mime.c",399);
    return (ASN1_VALUE *)0x0;
  }
  iVar4 = strcmp(pcVar9,"multipart/signed");
  if (iVar4 != 0) {
    iVar4 = strcmp(pcVar9,"application/x-pkcs7-mime");
    if ((iVar4 != 0) && (iVar4 = strcmp(pcVar9,"application/pkcs7-mime"), iVar4 != 0)) {
      ERR_put_error(0xd,0xd4,0xcd,"crypto/asn1/asn_mime.c",0x1d5);
      ERR_add_error_data(2,"type: ",*(undefined4 *)(iVar3 + 4));
      OPENSSL_sk_pop_free(iVar1,0x1c5149);
      return (ASN1_VALUE *)0x0;
    }
    OPENSSL_sk_pop_free(iVar1,0x1c5149);
    pBVar5 = BIO_f_base64();
    pBVar6 = BIO_new(pBVar5);
    if (pBVar6 == (BIO *)0x0) {
      ERR_put_error(0xd,0xd1,0x41,"crypto/asn1/asn_mime.c",0x89);
    }
    else {
      pBVar7 = BIO_push(pBVar6,bio);
      pAVar8 = (ASN1_VALUE *)ASN1_item_d2i_bio(it,pBVar7,(void *)0x0);
      if (pAVar8 != (ASN1_VALUE *)0x0) {
        BIO_ctrl(pBVar7,0xb,0,(void *)0x0);
        BIO_pop(pBVar7);
        BIO_free(pBVar6);
        return pAVar8;
      }
      ERR_put_error(0xd,0xd1,0x6e,"crypto/asn1/asn_mime.c",0x8f);
      BIO_ctrl(pBVar7,0xb,0,(void *)0x0);
      BIO_pop(pBVar7);
      BIO_free(pBVar6);
    }
    ERR_put_error(0xd,0xd4,0xcb,"crypto/asn1/asn_mime.c",0x1de);
    return (ASN1_VALUE *)0x0;
  }
  local_34 = "boundary";
  local_30 = iVar4;
  uVar2 = OPENSSL_sk_find(*(undefined4 *)(iVar3 + 8),&local_34);
  iVar3 = OPENSSL_sk_value(*(undefined4 *)(iVar3 + 8),uVar2);
  if ((iVar3 == 0) || (*(int *)(iVar3 + 4) == 0)) {
    OPENSSL_sk_pop_free(iVar1,0x1c5149);
    ERR_put_error(0xd,0xd4,0xd3,"crypto/asn1/asn_mime.c",0x19a);
    return (ASN1_VALUE *)0x0;
  }
  iVar3 = multi_split(bio,*(int *)(iVar3 + 4),&local_38);
  OPENSSL_sk_pop_free(iVar1,0x1c5149);
  if ((iVar3 == 0) || (iVar1 = OPENSSL_sk_num(local_38), iVar1 != 2)) {
    iVar3 = 0x1a0;
    iVar1 = 0xd2;
  }
  else {
    pBVar6 = (BIO *)OPENSSL_sk_value(local_38,1);
    iVar1 = mime_parse_hdr();
    if (iVar1 == 0) {
      iVar3 = 0x1a9;
      iVar1 = 0xd0;
    }
    else {
      local_34 = "content-type";
      local_30 = iVar4;
      local_2c = iVar4;
      uVar2 = OPENSSL_sk_find(iVar1,&local_34);
      iVar3 = OPENSSL_sk_value(iVar1,uVar2);
      if ((iVar3 == 0) || (pcVar9 = *(char **)(iVar3 + 4), pcVar9 == (char *)0x0)) {
        OPENSSL_sk_pop_free(iVar1,0x1c5149);
        iVar1 = 0xd4;
        iVar3 = 0x1b3;
      }
      else {
        iVar4 = strcmp(pcVar9,"application/x-pkcs7-signature");
        if ((iVar4 != 0) && (iVar4 = strcmp(pcVar9,"application/pkcs7-signature"), iVar4 != 0)) {
          ERR_put_error(0xd,0xd4,0xd5,"crypto/asn1/asn_mime.c",0x1ba);
          ERR_add_error_data(2,"type: ",*(undefined4 *)(iVar3 + 4));
          OPENSSL_sk_pop_free(iVar1,0x1c5149);
          goto LAB_001c5c44;
        }
        OPENSSL_sk_pop_free(iVar1,0x1c5149);
        pBVar5 = BIO_f_base64();
        pBVar7 = BIO_new(pBVar5);
        if (pBVar7 == (BIO *)0x0) {
          ERR_put_error(0xd,0xd1,0x41,"crypto/asn1/asn_mime.c",0x89);
        }
        else {
          in = BIO_push(pBVar7,pBVar6);
          pAVar8 = (ASN1_VALUE *)ASN1_item_d2i_bio(it,in,(void *)0x0);
          if (pAVar8 != (ASN1_VALUE *)0x0) {
            BIO_ctrl(in,0xb,0,(void *)0x0);
            BIO_pop(in);
            BIO_free(pBVar7);
            if (bcont == (BIO **)0x0) {
              OPENSSL_sk_pop_free(local_38,0x10a2b5);
              return pAVar8;
            }
            pBVar7 = (BIO *)OPENSSL_sk_value(local_38,0);
            *bcont = pBVar7;
            BIO_free(pBVar6);
            OPENSSL_sk_free(local_38);
            return pAVar8;
          }
          ERR_put_error(0xd,0xd1,0x6e,"crypto/asn1/asn_mime.c",0x8f);
          BIO_ctrl(in,0xb,0,(void *)0x0);
          BIO_pop(in);
          BIO_free(pBVar7);
        }
        iVar3 = 0x1c3;
        iVar1 = 0xcc;
      }
    }
  }
  ERR_put_error(0xd,0xd4,iVar1,"crypto/asn1/asn_mime.c",iVar3);
LAB_001c5c44:
  OPENSSL_sk_pop_free(local_38,0x10a2b5);
  return (ASN1_VALUE *)0x0;
}

