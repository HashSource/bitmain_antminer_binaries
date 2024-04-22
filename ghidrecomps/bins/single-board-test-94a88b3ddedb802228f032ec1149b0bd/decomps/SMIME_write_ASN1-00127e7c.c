
int SMIME_write_ASN1(BIO *bio,ASN1_VALUE *val,BIO *data,int flags,int ctype_nid,int econt_nid,
                    stack_st_X509_ALGOR *mdalgs,ASN1_ITEM *it)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  ASN1_OBJECT **ppAVar5;
  char *name;
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
  undefined4 uVar18;
  undefined4 uVar19;
  uint uVar20;
  undefined4 uVar21;
  char cVar22;
  ASN1_VALUE *local_60;
  BIO *local_5c;
  BIO *local_58;
  undefined4 local_54;
  byte local_50 [32];
  byte local_30 [12];
  
  uVar18 = DAT_00128360;
  uVar3 = DAT_001280b8;
  uVar21 = DAT_00128098;
  if ((flags & 0x400U) != 0) {
    uVar21 = DAT_00128094;
  }
  uVar19 = DAT_0012809c;
  if ((flags & 0x800U) != 0) {
    uVar19 = DAT_001280a0;
  }
  if ((flags << 0x19 < 0) && (data != (BIO *)0x0)) {
    iVar4 = RAND_pseudo_bytes(local_50,0x20);
    if (-1 < iVar4) {
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
      BIO_printf(bio,DAT_001280a4,uVar19);
      bVar2 = false;
      BIO_printf(bio,DAT_001280a8);
      BIO_printf(bio,DAT_001280ac,uVar21);
      BIO_puts(bio,DAT_001280b0);
      bVar1 = false;
      for (iVar4 = 0; iVar8 = sk_num(&mdalgs->stack), iVar4 < iVar8; iVar4 = iVar4 + 1) {
        if (bVar1) {
          BIO_write(bio,DAT_001280b4,1);
        }
        ppAVar5 = (ASN1_OBJECT **)sk_value(&mdalgs->stack,iVar4);
        iVar8 = OBJ_obj2nid(*ppAVar5);
        name = OBJ_nid2sn(iVar8);
        pEVar6 = EVP_get_digestbyname(name);
        if ((pEVar6 == (EVP_MD *)0x0) || (pEVar6->md_ctrl == (_func_1227 *)0x0)) {
LAB_00128060:
          if (iVar8 == 0x2a0) {
            BIO_puts(bio,DAT_00128354);
            bVar1 = true;
          }
          else if (iVar8 < 0x2a1) {
            if (iVar8 == 4) {
              BIO_puts(bio,DAT_0012835c);
              bVar1 = true;
            }
            else if (iVar8 == 0x40) {
              BIO_puts(bio,DAT_00128358);
              bVar1 = true;
            }
            else {
LAB_0012807a:
              bVar1 = false;
              if (!bVar2) {
                bVar1 = true;
                BIO_puts(bio,DAT_001280d4);
                bVar2 = bVar1;
              }
            }
          }
          else if (iVar8 == 0x2a2) {
            BIO_puts(bio,DAT_00128350);
            bVar1 = true;
          }
          else {
            if (0x2a1 < iVar8) {
              if (iVar8 != 0x329) goto LAB_0012807a;
              BIO_puts(bio,DAT_0012833c);
              break;
            }
            BIO_puts(bio,DAT_0012834c);
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
      BIO_printf(bio,DAT_00128340,local_50,uVar19,uVar19);
      BIO_printf(bio,DAT_00128344,uVar19,uVar19);
      BIO_printf(bio,DAT_00128348,local_50,uVar19);
      pvVar17 = it->funcs;
      local_60 = val;
      if ((flags & 0x8040U) != 0x40) {
        SMIME_crlf_copy(data,bio,flags);
LAB_0012823a:
        BIO_printf(bio,DAT_00128380,uVar19,local_50,uVar19);
        BIO_printf(bio,DAT_00128384,uVar21);
        BIO_printf(bio,DAT_00128388,uVar19);
        BIO_printf(bio,DAT_0012838c,uVar19);
        BIO_printf(bio,DAT_00128368);
        BIO_printf(bio,DAT_00128390,uVar19,uVar19);
        pBVar11 = BIO_f_base64();
        pBVar10 = BIO_new(pBVar11);
        if (pBVar10 == (BIO *)0x0) {
          ERR_put_error(0xd,0xd2,0x41,DAT_0012839c,0x9b);
        }
        else {
          pBVar12 = BIO_push(pBVar10,bio);
          ASN1_item_i2d_bio(it,pBVar12,val);
          BIO_ctrl(pBVar12,0xb,0,(void *)0x0);
          BIO_pop(pBVar12);
          BIO_free(pBVar10);
        }
        BIO_printf(bio,DAT_00128394,uVar19,local_50,uVar19,uVar19);
        return 1;
      }
      if ((pvVar17 == (void *)0x0) || (*(code **)((int)pvVar17 + 0x10) == (code *)0x0)) {
        ERR_put_error(0xd,0xd6,0xca,DAT_0012839c,0x17e);
      }
      else {
        local_58 = (BIO *)0x0;
        local_54 = 0;
        local_5c = bio;
        iVar4 = (**(code **)((int)pvVar17 + 0x10))(0xc,&local_60,it,&local_5c);
        if (0 < iVar4) {
          SMIME_crlf_copy(data,local_58,flags);
          iVar4 = (**(code **)((int)pvVar17 + 0x10))(0xd,&local_60,it,&local_5c);
          while (bio != local_58) {
            pBVar10 = BIO_pop(local_58);
            BIO_free(local_58);
            local_58 = pBVar10;
          }
          if (0 < iVar4) goto LAB_0012823a;
        }
      }
    }
    return 0;
  }
  uVar20 = DAT_001283a0;
  if (ctype_nid != 0x17) {
    if (ctype_nid == 0x16) {
      cVar22 = 0xcb < (uint)econt_nid;
      uVar20 = DAT_001283a8;
      if (econt_nid != 0xcc) {
        iVar4 = sk_num(&mdalgs->stack);
        uVar20 = DAT_00128378 & iVar4 >> 0x20;
        if (cVar22 == '\0') {
          uVar20 = DAT_0012837c;
        }
      }
    }
    else {
      uVar18 = DAT_00128398;
      uVar20 = DAT_001283a4;
      if (ctype_nid != 0x312) {
        BIO_printf(bio,DAT_001280a4,uVar19);
        BIO_printf(bio,DAT_001280bc);
        BIO_printf(bio,DAT_001280c0,uVar3,uVar19);
        BIO_printf(bio,DAT_001280c4,uVar21);
        uVar18 = uVar3;
        goto LAB_00127fc0;
      }
    }
  }
  BIO_printf(bio,DAT_00128364,uVar19);
  BIO_printf(bio,DAT_00128368);
  BIO_printf(bio,DAT_0012836c,uVar18,uVar19);
  BIO_printf(bio,DAT_00128370,uVar21);
  BIO_printf(bio,DAT_00128374,uVar20);
LAB_00127fc0:
  BIO_printf(bio,DAT_001280c8,uVar18,uVar19);
  BIO_printf(bio,DAT_001280cc,uVar19,uVar19);
  pBVar11 = BIO_f_base64();
  pBVar10 = BIO_new(pBVar11);
  if (pBVar10 == (BIO *)0x0) {
    ERR_put_error(0xd,0xd2,0x41,DAT_0012839c,0x9b);
    iVar4 = 0;
  }
  else {
    pBVar12 = BIO_push(pBVar10,bio);
    if (flags << 0x13 < 0) {
      out = BIO_new_NDEF(pBVar12,val,it);
      if (out == (BIO *)0x0) {
        ERR_put_error(0xd,0xd3,0x41,DAT_0012839c,0x7d);
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
    BIO_printf(bio,DAT_001280d0,uVar19);
    iVar4 = 1;
  }
  return iVar4;
}

