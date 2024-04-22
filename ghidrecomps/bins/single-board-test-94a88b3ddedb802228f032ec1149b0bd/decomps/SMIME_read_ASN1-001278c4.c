
ASN1_VALUE * SMIME_read_ASN1(BIO *bio,BIO **bcont,ASN1_ITEM *it)

{
  undefined4 uVar1;
  _STACK *p_Var2;
  int iVar3;
  void *pvVar4;
  BIO_METHOD *pBVar5;
  BIO *pBVar6;
  BIO *pBVar7;
  ASN1_VALUE *pAVar8;
  BIO *in;
  char *pcVar9;
  int line;
  _STACK *local_40;
  undefined4 local_3c [2];
  undefined4 local_34 [4];
  
  local_40 = (_STACK *)0x0;
  if (bcont != (BIO **)0x0) {
    *bcont = (BIO *)0x0;
  }
  p_Var2 = (_STACK *)mime_parse_hdr(bio);
  uVar1 = DAT_00127bdc;
  if (p_Var2 == (_STACK *)0x0) {
    ERR_put_error(0xd,0xd4,0xcf,DAT_00127bd0,0x1b2);
  }
  else {
    local_34[0] = DAT_00127bdc;
    iVar3 = sk_find(p_Var2,local_34);
    if (((iVar3 < 0) || (pvVar4 = sk_value(p_Var2,iVar3), pvVar4 == (void *)0x0)) ||
       (pcVar9 = *(char **)((int)pvVar4 + 4), pcVar9 == (char *)0x0)) {
      sk_pop_free(p_Var2,DAT_00127bc0);
      ERR_put_error(0xd,0xd4,0xd1,DAT_00127bd0,0x1b8);
    }
    else {
      iVar3 = strcmp(pcVar9,DAT_00127bb4);
      if (iVar3 == 0) {
        local_3c[0] = DAT_00127bc4;
        iVar3 = sk_find(*(_STACK **)((int)pvVar4 + 8),local_3c);
        if (((iVar3 < 0) ||
            (pvVar4 = sk_value(*(_STACK **)((int)pvVar4 + 8),iVar3), pvVar4 == (void *)0x0)) ||
           (*(int *)((int)pvVar4 + 4) == 0)) {
          sk_pop_free(p_Var2,DAT_00127bc0);
          ERR_put_error(0xd,0xd4,0xd3,DAT_00127bd0,0x1c3);
        }
        else {
          iVar3 = multi_split(bio,*(int *)((int)pvVar4 + 4),&local_40);
          sk_pop_free(p_Var2,DAT_00127bc0);
          if ((iVar3 == 0) || (iVar3 = sk_num(local_40), iVar3 != 2)) {
            iVar3 = 0xd2;
            line = 0x1c9;
          }
          else {
            pBVar6 = (BIO *)sk_value(local_40,1);
            p_Var2 = (_STACK *)mime_parse_hdr();
            if (p_Var2 == (_STACK *)0x0) {
              line = 0x1d2;
              iVar3 = 0xd0;
            }
            else {
              local_34[0] = uVar1;
              iVar3 = sk_find(p_Var2,local_34);
              if (((iVar3 < 0) || (pvVar4 = sk_value(p_Var2,iVar3), pvVar4 == (void *)0x0)) ||
                 (pcVar9 = *(char **)((int)pvVar4 + 4), pcVar9 == (char *)0x0)) {
                sk_pop_free(p_Var2,DAT_00127c58);
                ERR_put_error(0xd,0xd4,0xd4,DAT_00127c50,0x1db);
                return (ASN1_VALUE *)0x0;
              }
              iVar3 = strcmp(pcVar9,DAT_00127bc8);
              if ((iVar3 != 0) && (iVar3 = strcmp(pcVar9,DAT_00127bcc), iVar3 != 0)) {
                ERR_put_error(0xd,0xd4,0xd5,DAT_00127c50,0x1e1);
                ERR_add_error_data(2,DAT_00127c54,*(undefined4 *)((int)pvVar4 + 4));
                sk_pop_free(p_Var2,DAT_00127c58);
                sk_pop_free(local_40,DAT_00127c5c);
                return (ASN1_VALUE *)0x0;
              }
              sk_pop_free(p_Var2,DAT_00127bc0);
              pBVar5 = BIO_f_base64();
              pBVar7 = BIO_new(pBVar5);
              if (pBVar7 == (BIO *)0x0) {
                ERR_put_error(0xd,0xd1,0x41,DAT_00127c50,0xba);
              }
              else {
                in = BIO_push(pBVar7,pBVar6);
                pAVar8 = (ASN1_VALUE *)ASN1_item_d2i_bio(it,in,(void *)0x0);
                if (pAVar8 != (ASN1_VALUE *)0x0) {
                  BIO_ctrl(in,0xb,0,(void *)0x0);
                  BIO_pop(in);
                  BIO_free(pBVar7);
                  if (bcont != (BIO **)0x0) {
                    pBVar7 = (BIO *)sk_value(local_40,0);
                    *bcont = pBVar7;
                    BIO_free(pBVar6);
                    sk_free(local_40);
                    return pAVar8;
                  }
                  sk_pop_free(local_40,DAT_00127bd4);
                  return pAVar8;
                }
                ERR_put_error(0xd,0xd1,0x6e,DAT_00127bd0,0xc0);
                BIO_ctrl(in,0xb,0,(void *)0x0);
                BIO_pop(in);
                BIO_free(pBVar7);
              }
              line = 0x1ea;
              iVar3 = 0xcc;
            }
          }
          ERR_put_error(0xd,0xd4,iVar3,DAT_00127bd0,line);
          sk_pop_free(local_40,DAT_00127bd4);
        }
      }
      else {
        iVar3 = strcmp(pcVar9,DAT_00127bb8);
        if ((iVar3 == 0) || (iVar3 = strcmp(pcVar9,DAT_00127bbc), iVar3 == 0)) {
          sk_pop_free(p_Var2,DAT_00127bc0);
          pBVar5 = BIO_f_base64();
          pBVar6 = BIO_new(pBVar5);
          if (pBVar6 == (BIO *)0x0) {
            ERR_put_error(0xd,0xd1,0x41,DAT_00127bd0,0xba);
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
            ERR_put_error(0xd,0xd1,0x6e,DAT_00127bd0,0xc0);
            BIO_ctrl(pBVar7,0xb,0,(void *)0x0);
            BIO_pop(pBVar7);
            BIO_free(pBVar6);
          }
          ERR_put_error(0xd,0xd4,0xcb,DAT_00127bd0,0x205);
        }
        else {
          ERR_put_error(0xd,0xd4,0xcd,DAT_00127bd0,0x1fc);
          ERR_add_error_data(2,DAT_00127bd8,*(undefined4 *)((int)pvVar4 + 4));
          sk_pop_free(p_Var2,DAT_00127bc0);
        }
      }
    }
  }
  return (ASN1_VALUE *)0x0;
}

