
int SMIME_write_ASN1(BIO *bio,ASN1_VALUE *val,BIO *data,int flags,int ctype_nid,int econt_nid,
                    stack_st_X509_ALGOR *mdalgs,ASN1_ITEM *it)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  EVP_MD *pEVar6;
  int iVar7;
  int iVar8;
  BIO *out;
  BIO *pBVar9;
  BIO *pBVar10;
  BIO_METHOD *pBVar11;
  BIO *pBVar12;
  byte bVar13;
  byte bVar14;
  byte *pbVar15;
  byte *pbVar16;
  void *pvVar17;
  char *pcVar18;
  char *pcVar19;
  char *pcVar20;
  char cVar21;
  ASN1_VALUE *local_60;
  BIO *local_5c;
  BIO *local_58;
  undefined4 local_54;
  byte local_50 [32];
  byte local_30 [12];
  
  if ((flags & 0x400U) == 0) {
    pcVar20 = "application/pkcs7-";
  }
  else {
    pcVar20 = "application/x-pkcs7-";
  }
  if ((flags & 0x800U) == 0) {
    pcVar18 = "\n";
  }
  else {
    pcVar18 = "\r\n";
  }
  if ((flags << 0x19 < 0) && (data != (BIO *)0x0)) {
    iVar3 = RAND_pseudo_bytes(local_50,0x20);
    if (-1 < iVar3) {
      pbVar15 = local_50;
      do {
        bVar13 = *pbVar15 & 0xf;
        bVar14 = bVar13 + 0x37;
        if (bVar13 < 10) {
          bVar14 = bVar13 + 0x30;
        }
        pbVar16 = pbVar15 + 1;
        *pbVar15 = bVar14;
        pbVar15 = pbVar16;
      } while (pbVar16 != local_30);
      local_30[0] = 0;
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar18);
      bVar2 = false;
      BIO_printf(bio,"Content-Type: multipart/signed;");
      BIO_printf(bio," protocol=\"%ssignature\";",pcVar20);
      BIO_puts(bio," micalg=\"");
      bVar1 = false;
      for (iVar3 = 0; iVar8 = sk_num(&mdalgs->stack), iVar3 < iVar8; iVar3 = iVar3 + 1) {
        if (bVar1) {
          BIO_write(bio,",",1);
        }
        puVar4 = (undefined4 *)sk_value(&mdalgs->stack,iVar3);
        iVar8 = OBJ_obj2nid((ASN1_OBJECT *)*puVar4);
        pcVar5 = OBJ_nid2sn(iVar8);
        pEVar6 = EVP_get_digestbyname(pcVar5);
        if ((pEVar6 == (EVP_MD *)0x0) || (pEVar6->md_ctrl == (_func_1227 *)0x0)) {
LAB_00128060:
          if (iVar8 == 0x2a0) {
            BIO_puts(bio,"sha-256");
            bVar1 = true;
          }
          else if (iVar8 < 0x2a1) {
            if (iVar8 == 4) {
              BIO_puts(bio,"md5");
              bVar1 = true;
            }
            else if (iVar8 == 0x40) {
              BIO_puts(bio,"sha1");
              bVar1 = true;
            }
            else {
LAB_0012807a:
              bVar1 = false;
              if (!bVar2) {
                bVar1 = true;
                BIO_puts(bio,"unknown");
                bVar2 = bVar1;
              }
            }
          }
          else if (iVar8 == 0x2a2) {
            BIO_puts(bio,"sha-512");
            bVar1 = true;
          }
          else {
            if (0x2a1 < iVar8) {
              if (iVar8 != 0x329) goto LAB_0012807a;
              BIO_puts(bio,"gostr3411-94");
              break;
            }
            BIO_puts(bio,"sha-384");
            bVar1 = true;
          }
        }
        else {
          iVar7 = (*pEVar6->md_ctrl)((EVP_MD_CTX *)0x0,2,0,&local_60);
          if (iVar7 < 1) {
            if (iVar7 == -2) goto LAB_00128060;
            break;
          }
          BIO_puts(bio,(char *)local_60);
          bVar1 = true;
          CRYPTO_free(local_60);
        }
      }
      BIO_printf(bio,"\"; boundary=\"----%s\"%s%s",local_50,pcVar18,pcVar18);
      BIO_printf(bio,"This is an S/MIME signed message%s%s",pcVar18,pcVar18);
      BIO_printf(bio,"------%s%s",local_50,pcVar18);
      pvVar17 = it->funcs;
      local_60 = val;
      if ((flags & 0x8040U) != 0x40) {
        SMIME_crlf_copy(data,bio,flags);
LAB_0012823a:
        BIO_printf(bio,"%s------%s%s",pcVar18,local_50,pcVar18);
        BIO_printf(bio,"Content-Type: %ssignature;",pcVar20);
        BIO_printf(bio," name=\"smime.p7s\"%s",pcVar18);
        BIO_printf(bio,"Content-Transfer-Encoding: base64%s",pcVar18);
        BIO_printf(bio,"Content-Disposition: attachment;");
        BIO_printf(bio," filename=\"smime.p7s\"%s%s",pcVar18,pcVar18);
        pBVar11 = BIO_f_base64();
        pBVar10 = BIO_new(pBVar11);
        if (pBVar10 == (BIO *)0x0) {
          ERR_put_error(0xd,0xd2,0x41,"asn_mime.c",0x9b);
        }
        else {
          pBVar12 = BIO_push(pBVar10,bio);
          ASN1_item_i2d_bio(it,pBVar12,val);
          BIO_ctrl(pBVar12,0xb,0,(void *)0x0);
          BIO_pop(pBVar12);
          BIO_free(pBVar10);
        }
        BIO_printf(bio,"%s------%s--%s%s",pcVar18,local_50,pcVar18,pcVar18);
        return 1;
      }
      if ((pvVar17 == (void *)0x0) || (*(code **)((int)pvVar17 + 0x10) == (code *)0x0)) {
        ERR_put_error(0xd,0xd6,0xca,"asn_mime.c",0x17e);
      }
      else {
        local_58 = (BIO *)0x0;
        local_54 = 0;
        local_5c = bio;
        iVar3 = (**(code **)((int)pvVar17 + 0x10))(0xc,&local_60,it,&local_5c);
        if (0 < iVar3) {
          SMIME_crlf_copy(data,local_58,flags);
          iVar3 = (**(code **)((int)pvVar17 + 0x10))(0xd,&local_60,it,&local_5c);
          while (bio != local_58) {
            pBVar10 = BIO_pop(local_58);
            BIO_free(local_58);
            local_58 = pBVar10;
          }
          if (0 < iVar3) goto LAB_0012823a;
        }
      }
    }
    return 0;
  }
  if (ctype_nid == 0x17) {
    pcVar19 = "enveloped-data";
    pcVar5 = "smime.p7m";
  }
  else if (ctype_nid == 0x16) {
    cVar21 = 0xcb < (uint)econt_nid;
    if (econt_nid == 0xcc) {
      pcVar19 = "signed-receipt";
      pcVar5 = "smime.p7m";
    }
    else {
      pcVar5 = "smime.p7m";
      iVar3 = sk_num(&mdalgs->stack);
      pcVar19 = (char *)(iVar3 >> 0x20 & 0x183498);
      if (cVar21 == '\0') {
        pcVar19 = "signed-data";
      }
    }
  }
  else {
    if (ctype_nid != 0x312) {
      pcVar5 = "smime.p7m";
      BIO_printf(bio,"MIME-Version: 1.0%s",pcVar18);
      BIO_printf(bio,"Content-Disposition: attachment;");
      BIO_printf(bio," filename=\"%s\"%s",&DAT_0018348c,pcVar18);
      BIO_printf(bio,"Content-Type: %smime;",pcVar20);
      goto LAB_00127fc0;
    }
    pcVar19 = "compressed-data";
    pcVar5 = "smime.p7z";
  }
  BIO_printf(bio,"MIME-Version: 1.0%s",pcVar18);
  BIO_printf(bio,"Content-Disposition: attachment;");
  BIO_printf(bio," filename=\"%s\"%s",pcVar5,pcVar18);
  BIO_printf(bio,"Content-Type: %smime;",pcVar20);
  BIO_printf(bio," smime-type=%s;",pcVar19);
LAB_00127fc0:
  BIO_printf(bio," name=\"%s\"%s",pcVar5,pcVar18);
  BIO_printf(bio,"Content-Transfer-Encoding: base64%s%s",pcVar18,pcVar18);
  pBVar11 = BIO_f_base64();
  pBVar10 = BIO_new(pBVar11);
  if (pBVar10 == (BIO *)0x0) {
    ERR_put_error(0xd,0xd2,0x41,"asn_mime.c",0x9b);
    iVar3 = 0;
  }
  else {
    pBVar12 = BIO_push(pBVar10,bio);
    if (flags << 0x13 < 0) {
      out = BIO_new_NDEF(pBVar12,val,it);
      if (out == (BIO *)0x0) {
        ERR_put_error(0xd,0xd3,0x41,"asn_mime.c",0x7d);
        BIO_ctrl(pBVar12,0xb,0,(void *)0x0);
        BIO_pop(pBVar12);
        BIO_free(pBVar10);
        return 0;
      }
      SMIME_crlf_copy(data,out,flags);
      BIO_ctrl(out,0xb,0,(void *)0x0);
      do {
        pBVar9 = BIO_pop(out);
        BIO_free(out);
        out = pBVar9;
      } while (pBVar12 != pBVar9);
    }
    else {
      ASN1_item_i2d_bio(it,pBVar12,val);
    }
    BIO_ctrl(pBVar12,0xb,0,(void *)0x0);
    BIO_pop(pBVar12);
    BIO_free(pBVar10);
    BIO_printf(bio,"%s",pcVar18);
    iVar3 = 1;
  }
  return iVar3;
}

