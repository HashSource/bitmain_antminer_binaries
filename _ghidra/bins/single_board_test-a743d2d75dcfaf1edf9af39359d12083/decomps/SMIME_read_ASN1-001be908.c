
ASN1_VALUE * SMIME_read_ASN1(BIO *bio,BIO **bcont,ASN1_ITEM *it)

{
  _STACK *p_Var1;
  int iVar2;
  void *pvVar3;
  BIO_METHOD *pBVar4;
  BIO *pBVar5;
  BIO *pBVar6;
  ASN1_VALUE *pAVar7;
  BIO *in;
  char *pcVar8;
  int line;
  _STACK *local_40;
  char *local_3c [2];
  char *local_34 [4];
  
  local_40 = (_STACK *)0x0;
  if (bcont != (BIO **)0x0) {
    *bcont = (BIO *)0x0;
  }
  p_Var1 = (_STACK *)mime_parse_hdr(bio);
  if (p_Var1 == (_STACK *)0x0) {
    ERR_put_error(0xd,0xd4,0xcf,"asn_mime.c",0x1b2);
  }
  else {
    local_34[0] = "content-type";
    iVar2 = sk_find(p_Var1,local_34);
    if (((iVar2 < 0) || (pvVar3 = sk_value(p_Var1,iVar2), pvVar3 == (void *)0x0)) ||
       (pcVar8 = *(char **)((int)pvVar3 + 4), pcVar8 == (char *)0x0)) {
      sk_pop_free(p_Var1,(func *)0x1be1e1);
      ERR_put_error(0xd,0xd4,0xd1,"asn_mime.c",0x1b8);
    }
    else {
      iVar2 = strcmp(pcVar8,"multipart/signed");
      if (iVar2 == 0) {
        local_3c[0] = "boundary";
        iVar2 = sk_find(*(_STACK **)((int)pvVar3 + 8),local_3c);
        if (((iVar2 < 0) ||
            (pvVar3 = sk_value(*(_STACK **)((int)pvVar3 + 8),iVar2), pvVar3 == (void *)0x0)) ||
           (*(int *)((int)pvVar3 + 4) == 0)) {
          sk_pop_free(p_Var1,(func *)0x1be1e1);
          ERR_put_error(0xd,0xd4,0xd3,"asn_mime.c",0x1c3);
        }
        else {
          iVar2 = multi_split(bio,*(int *)((int)pvVar3 + 4),&local_40);
          sk_pop_free(p_Var1,(func *)0x1be1e1);
          if ((iVar2 == 0) || (iVar2 = sk_num(local_40), iVar2 != 2)) {
            iVar2 = 0xd2;
            line = 0x1c9;
          }
          else {
            pBVar5 = (BIO *)sk_value(local_40,1);
            p_Var1 = (_STACK *)mime_parse_hdr();
            if (p_Var1 == (_STACK *)0x0) {
              line = 0x1d2;
              iVar2 = 0xd0;
            }
            else {
              local_34[0] = "content-type";
              iVar2 = sk_find(p_Var1,local_34);
              if (((iVar2 < 0) || (pvVar3 = sk_value(p_Var1,iVar2), pvVar3 == (void *)0x0)) ||
                 (pcVar8 = *(char **)((int)pvVar3 + 4), pcVar8 == (char *)0x0)) {
                sk_pop_free(p_Var1,(func *)0x1be1e1);
                ERR_put_error(0xd,0xd4,0xd4,"asn_mime.c",0x1db);
                return (ASN1_VALUE *)0x0;
              }
              iVar2 = strcmp(pcVar8,"application/x-pkcs7-signature");
              if ((iVar2 != 0) && (iVar2 = strcmp(pcVar8,"application/pkcs7-signature"), iVar2 != 0)
                 ) {
                ERR_put_error(0xd,0xd4,0xd5,"asn_mime.c",0x1e1);
                ERR_add_error_data(2,"type: ",*(undefined4 *)((int)pvVar3 + 4));
                sk_pop_free(p_Var1,(func *)0x1be1e1);
                sk_pop_free(local_40,(func *)0x149bd5);
                return (ASN1_VALUE *)0x0;
              }
              sk_pop_free(p_Var1,(func *)0x1be1e1);
              pBVar4 = BIO_f_base64();
              pBVar6 = BIO_new(pBVar4);
              if (pBVar6 == (BIO *)0x0) {
                ERR_put_error(0xd,0xd1,0x41,"asn_mime.c",0xba);
              }
              else {
                in = BIO_push(pBVar6,pBVar5);
                pAVar7 = (ASN1_VALUE *)ASN1_item_d2i_bio(it,in,(void *)0x0);
                if (pAVar7 != (ASN1_VALUE *)0x0) {
                  BIO_ctrl(in,0xb,0,(void *)0x0);
                  BIO_pop(in);
                  BIO_free(pBVar6);
                  if (bcont != (BIO **)0x0) {
                    pBVar6 = (BIO *)sk_value(local_40,0);
                    *bcont = pBVar6;
                    BIO_free(pBVar5);
                    sk_free(local_40);
                    return pAVar7;
                  }
                  sk_pop_free(local_40,(func *)0x149bd5);
                  return pAVar7;
                }
                ERR_put_error(0xd,0xd1,0x6e,"asn_mime.c",0xc0);
                BIO_ctrl(in,0xb,0,(void *)0x0);
                BIO_pop(in);
                BIO_free(pBVar6);
              }
              line = 0x1ea;
              iVar2 = 0xcc;
            }
          }
          ERR_put_error(0xd,0xd4,iVar2,"asn_mime.c",line);
          sk_pop_free(local_40,(func *)0x149bd5);
        }
      }
      else {
        iVar2 = strcmp(pcVar8,"application/x-pkcs7-mime");
        if ((iVar2 == 0) || (iVar2 = strcmp(pcVar8,"application/pkcs7-mime"), iVar2 == 0)) {
          sk_pop_free(p_Var1,(func *)0x1be1e1);
          pBVar4 = BIO_f_base64();
          pBVar5 = BIO_new(pBVar4);
          if (pBVar5 == (BIO *)0x0) {
            ERR_put_error(0xd,0xd1,0x41,"asn_mime.c",0xba);
          }
          else {
            pBVar6 = BIO_push(pBVar5,bio);
            pAVar7 = (ASN1_VALUE *)ASN1_item_d2i_bio(it,pBVar6,(void *)0x0);
            if (pAVar7 != (ASN1_VALUE *)0x0) {
              BIO_ctrl(pBVar6,0xb,0,(void *)0x0);
              BIO_pop(pBVar6);
              BIO_free(pBVar5);
              return pAVar7;
            }
            ERR_put_error(0xd,0xd1,0x6e,"asn_mime.c",0xc0);
            BIO_ctrl(pBVar6,0xb,0,(void *)0x0);
            BIO_pop(pBVar6);
            BIO_free(pBVar5);
          }
          ERR_put_error(0xd,0xd4,0xcb,"asn_mime.c",0x205);
        }
        else {
          ERR_put_error(0xd,0xd4,0xcd,"asn_mime.c",0x1fc);
          ERR_add_error_data(2,"type: ",*(undefined4 *)((int)pvVar3 + 4));
          sk_pop_free(p_Var1,(func *)0x1be1e1);
        }
      }
    }
  }
  return (ASN1_VALUE *)0x0;
}

