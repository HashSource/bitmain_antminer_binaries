
int SMIME_write_ASN1(BIO *bio,ASN1_VALUE *val,BIO *data,int flags,int ctype_nid,int econt_nid,
                    stack_st_X509_ALGOR *mdalgs,ASN1_ITEM *it)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  char *pcVar7;
  EVP_MD *pEVar8;
  int iVar9;
  BIO_METHOD *pBVar10;
  BIO *pBVar11;
  byte bVar12;
  BIO *pBVar13;
  byte bVar14;
  char *pcVar15;
  int iVar16;
  void *pvVar17;
  char *pcVar18;
  char *pcVar19;
  ASN1_VALUE *local_5c;
  BIO *local_58;
  BIO *local_54;
  undefined4 local_50;
  byte local_4c [32];
  byte local_2c [8];
  
  if (flags << 0x15 < 0) {
    pcVar19 = "application/x-pkcs7-";
  }
  else {
    pcVar19 = "application/pkcs7-";
  }
  if (flags << 0x14 < 0) {
    pcVar15 = "\r\n";
  }
  else {
    pcVar15 = "\n";
  }
  pBVar13 = data;
  if (data != (BIO *)0x0) {
    pBVar13 = (BIO *)0x1;
  }
  if (((uint)pBVar13 & (uint)flags >> 6) != 0) {
    iVar3 = RAND_bytes(local_4c,0x20);
    if (iVar3 < 1) {
      return 0;
    }
    pbVar4 = local_4c;
    do {
      bVar14 = *pbVar4 & 0xf;
      bVar12 = bVar14 + 0x30;
      if (9 < bVar14) {
        bVar12 = bVar14 + 0x37;
      }
      pbVar5 = pbVar4 + 1;
      *pbVar4 = bVar12;
      pbVar4 = pbVar5;
    } while (pbVar5 != local_2c);
    local_2c[0] = 0;
    iVar16 = 0;
    BIO_printf(bio,"MIME-Version: 1.0%s",pcVar15);
    BIO_printf(bio,"Content-Type: multipart/signed;");
    BIO_printf(bio," protocol=\"%ssignature\";",pcVar19);
    bVar2 = false;
    bVar1 = false;
    BIO_puts(bio," micalg=\"");
    iVar3 = OPENSSL_sk_num(mdalgs);
    if (0 < iVar3) {
      do {
        if (bVar1) {
          BIO_write(bio,",",1);
        }
        puVar6 = (undefined4 *)OPENSSL_sk_value(mdalgs,iVar16);
        iVar3 = OBJ_obj2nid((ASN1_OBJECT *)*puVar6);
        pcVar7 = OBJ_nid2sn(iVar3);
        pEVar8 = EVP_get_digestbyname(pcVar7);
        if ((pEVar8 == (EVP_MD *)0x0) || ((code *)pEVar8->required_pkey_type[0] == (code *)0x0)) {
LAB_001d3ffc:
          if (iVar3 == 0x2a1) {
            BIO_puts(bio,"sha-384");
            bVar1 = true;
          }
          else if (iVar3 < 0x2a2) {
            if (iVar3 == 0x40) {
              bVar1 = true;
              BIO_puts(bio,"sha1");
            }
            else if (iVar3 == 0x2a0) {
              bVar1 = true;
              BIO_puts(bio,"sha-256");
            }
            else {
              if (iVar3 != 4) goto LAB_001d41e0;
              bVar1 = true;
              BIO_puts(bio,"md5");
            }
          }
          else {
            if (iVar3 == 0x329) {
              BIO_puts(bio,"gostr3411-94");
              break;
            }
            if (iVar3 < 0x32a) {
              if (iVar3 == 0x2a2) {
                bVar1 = true;
                BIO_puts(bio,"sha-512");
                goto LAB_001d3fe6;
              }
            }
            else {
              if (iVar3 == 0x3d6) {
                BIO_puts(bio,"gostr3411-2012-256");
                break;
              }
              if (iVar3 == 0x3d7) {
                BIO_puts(bio,"gostr3411-2012-512");
                break;
              }
            }
LAB_001d41e0:
            bVar1 = false;
            if (!bVar2) {
              bVar1 = true;
              bVar2 = true;
              BIO_puts(bio,"unknown");
            }
          }
        }
        else {
          iVar9 = (*(code *)pEVar8->required_pkey_type[0])(0,2,0,&local_58);
          if (iVar9 < 1) {
            if (iVar9 == -2) goto LAB_001d3ffc;
            break;
          }
          BIO_puts(bio,(char *)local_58);
          bVar1 = true;
          CRYPTO_free(local_58);
        }
LAB_001d3fe6:
        iVar16 = iVar16 + 1;
        iVar3 = OPENSSL_sk_num(mdalgs);
      } while (iVar16 < iVar3);
    }
    BIO_printf(bio,"\"; boundary=\"----%s\"%s%s",local_4c,pcVar15,pcVar15);
    BIO_printf(bio,"This is an S/MIME signed message%s%s",pcVar15,pcVar15);
    BIO_printf(bio,"------%s%s",local_4c,pcVar15);
    local_5c = val;
    if ((flags & 0x8040U) == 0x40) {
      pvVar17 = it->funcs;
      if ((pvVar17 == (void *)0x0) || (*(code **)((int)pvVar17 + 0x10) == (code *)0x0)) {
        ERR_put_error(0xd,0xd6,0xca,"crypto/asn1/asn_mime.c",0x154);
        return 0;
      }
      local_54 = (BIO *)0x0;
      local_50 = 0;
      local_58 = bio;
      iVar3 = (**(code **)((int)pvVar17 + 0x10))(0xc,&local_5c,it);
      if (iVar3 < 1) {
        return 0;
      }
      SMIME_crlf_copy(data,local_54,flags);
      iVar3 = (**(code **)((int)pvVar17 + 0x10))(0xd,&local_5c,it,&local_58);
      while (bio != local_54) {
        pBVar13 = BIO_pop(local_54);
        BIO_free(local_54);
        local_54 = pBVar13;
      }
      if (iVar3 < 1) {
        return 0;
      }
    }
    else {
      SMIME_crlf_copy(data,bio,flags);
    }
    BIO_printf(bio,"%s------%s%s",pcVar15,local_4c,pcVar15);
    BIO_printf(bio,"Content-Type: %ssignature;",pcVar19);
    BIO_printf(bio," name=\"smime.p7s\"%s",pcVar15);
    BIO_printf(bio,"Content-Transfer-Encoding: base64%s",pcVar15);
    BIO_printf(bio,"Content-Disposition: attachment;");
    BIO_printf(bio," filename=\"smime.p7s\"%s%s",pcVar15,pcVar15);
    pBVar10 = BIO_f_base64();
    pBVar13 = BIO_new(pBVar10);
    if (pBVar13 == (BIO *)0x0) {
      ERR_put_error(0xd,0xd2,0x41,"crypto/asn1/asn_mime.c",0x69);
    }
    else {
      pBVar11 = BIO_push(pBVar13,bio);
      i2d_ASN1_bio_stream(pBVar11,val,(BIO *)0x0,0,it);
      BIO_ctrl(pBVar11,0xb,0,(void *)0x0);
      BIO_pop(pBVar11);
      BIO_free(pBVar13);
    }
    BIO_printf(bio,"%s------%s--%s%s",pcVar15,local_4c,pcVar15,pcVar15);
    return 1;
  }
  if (ctype_nid == 0x17) {
    pcVar18 = "enveloped-data";
    pcVar7 = "smime.p7m";
  }
  else if (ctype_nid == 0x16) {
    if (econt_nid == 0xcc) {
      pcVar18 = "signed-receipt";
      pcVar7 = "smime.p7m";
    }
    else {
      iVar3 = OPENSSL_sk_num(mdalgs);
      if (iVar3 < 0) {
        pcVar18 = "certs-only";
        pcVar7 = "smime.p7m";
      }
      else {
        pcVar18 = "signed-data";
        pcVar7 = "smime.p7m";
      }
    }
  }
  else {
    if (ctype_nid != 0x312) {
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar15);
      pcVar7 = "smime.p7m";
      BIO_printf(bio,"Content-Disposition: attachment;");
      BIO_printf(bio," filename=\"%s\"%s","smime.p7m",pcVar15);
      BIO_printf(bio,"Content-Type: %smime;",pcVar19);
      goto LAB_001d413c;
    }
    pcVar18 = "compressed-data";
    pcVar7 = "smime.p7z";
  }
  BIO_printf(bio,"MIME-Version: 1.0%s",pcVar15);
  BIO_printf(bio,"Content-Disposition: attachment;");
  BIO_printf(bio," filename=\"%s\"%s",pcVar7,pcVar15);
  BIO_printf(bio,"Content-Type: %smime;",pcVar19);
  BIO_printf(bio," smime-type=%s;",pcVar18);
LAB_001d413c:
  BIO_printf(bio," name=\"%s\"%s",pcVar7,pcVar15);
  BIO_printf(bio,"Content-Transfer-Encoding: base64%s%s",pcVar15,pcVar15);
  pBVar10 = BIO_f_base64();
  pBVar13 = BIO_new(pBVar10);
  if (pBVar13 == (BIO *)0x0) {
    ERR_put_error(0xd,0xd2,0x41,"crypto/asn1/asn_mime.c",0x69);
    return 0;
  }
  pBVar11 = BIO_push(pBVar13,bio);
  iVar3 = i2d_ASN1_bio_stream(pBVar11,val,data,flags,it);
  BIO_ctrl(pBVar11,0xb,0,(void *)0x0);
  BIO_pop(pBVar11);
  BIO_free(pBVar13);
  if (iVar3 == 0) {
    return 0;
  }
  BIO_printf(bio,"%s",pcVar15);
  return 1;
}

