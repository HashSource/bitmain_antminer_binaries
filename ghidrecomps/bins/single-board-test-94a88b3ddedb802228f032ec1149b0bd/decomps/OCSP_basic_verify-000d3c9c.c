
int OCSP_basic_verify(OCSP_BASICRESP *bs,stack_st_X509 *certs,X509_STORE *st,ulong flags)

{
  int iVar1;
  int iVar2;
  _STACK *st_00;
  EVP_PKEY *pkey;
  OCSP_CERTID **ppOVar3;
  void *pvVar4;
  char *pcVar5;
  X509 *pXVar6;
  EVP_MD *pEVar7;
  _STACK *p_Var8;
  BUF_MEM *pBVar9;
  int iVar10;
  OCSP_CERTID *b;
  _STACK *p_Var11;
  OCSP_RESPID *pOVar12;
  OCSP_CERTID *local_b8;
  X509_STORE_CTX XStack_b0;
  
  pOVar12 = bs->tbsResponseData->responderId;
  if (pOVar12->type != 0) {
    if (((pOVar12->value).byName)->entries == (stack_st_X509_NAME_ENTRY *)0x14) {
      pBVar9 = ((pOVar12->value).byName)->bytes;
      iVar10 = 0;
      do {
        iVar1 = sk_num(&certs->stack);
        if (iVar1 <= iVar10) goto LAB_000d3d00;
        pXVar6 = (X509 *)sk_value(&certs->stack,iVar10);
        pEVar7 = EVP_sha1();
        X509_pubkey_digest(pXVar6,pEVar7,(uchar *)&XStack_b0,(uint *)0x0);
        iVar1 = memcmp(pBVar9,&XStack_b0,0x14);
        iVar10 = iVar10 + 1;
      } while (iVar1 != 0);
      goto LAB_000d3d3e;
    }
LAB_000d3d00:
    if ((flags & 2) == 0) {
      p_Var8 = &bs->certs->stack;
      if (pOVar12->type == 0) {
        pXVar6 = X509_find_by_subject((stack_st_X509 *)p_Var8,(pOVar12->value).byName);
      }
      else {
        if (((pOVar12->value).byName)->entries != (stack_st_X509_NAME_ENTRY *)0x14)
        goto LAB_000d3d08;
        pBVar9 = ((pOVar12->value).byName)->bytes;
        iVar10 = 0;
        do {
          iVar1 = sk_num(p_Var8);
          if (iVar1 <= iVar10) goto LAB_000d3d08;
          pXVar6 = (X509 *)sk_value(p_Var8,iVar10);
          pEVar7 = EVP_sha1();
          X509_pubkey_digest(pXVar6,pEVar7,(uchar *)&XStack_b0,(uint *)0x0);
          iVar1 = memcmp(pBVar9,&XStack_b0,0x14);
          iVar10 = iVar10 + 1;
        } while (iVar1 != 0);
      }
      iVar10 = 1;
      if (pXVar6 != (X509 *)0x0) goto LAB_000d3d4e;
    }
LAB_000d3d08:
    iVar10 = 0;
    p_Var8 = (_STACK *)0x0;
    ERR_put_error(0x27,0x69,0x76,DAT_000d3fb8,0x5c);
    goto LAB_000d3d1e;
  }
  pXVar6 = X509_find_by_subject(certs,(pOVar12->value).byName);
LAB_000d3d3e:
  if (pXVar6 == (X509 *)0x0) goto LAB_000d3d00;
  if ((int)(flags << 0x16) < 0) {
    flags = flags | 0x10;
    iVar10 = 2;
  }
  else {
    iVar10 = 2;
  }
LAB_000d3d4e:
  if (-1 < (int)(flags << 0x1d)) {
    pkey = X509_get_pubkey(pXVar6);
    if (pkey != (EVP_PKEY *)0x0) {
      iVar10 = ASN1_item_verify(DAT_000d3fc0,bs->signatureAlgorithm,bs->signature,
                                bs->tbsResponseData,pkey);
      EVP_PKEY_free(pkey);
      if (0 < iVar10) goto LAB_000d3d52;
    }
    p_Var8 = (_STACK *)0x0;
    ERR_put_error(0x27,0x69,0x75,DAT_000d3fb8,0x69);
    goto LAB_000d3d1e;
  }
LAB_000d3d52:
  if ((flags & 0x10) != 0) {
    p_Var8 = (_STACK *)0x0;
    goto LAB_000d3d1e;
  }
  p_Var8 = (_STACK *)0x0;
  if ((((flags & 8) == 0) && (p_Var8 = &bs->certs->stack, p_Var8 != (_STACK *)0x0)) &&
     (certs != (stack_st_X509 *)0x0)) {
    p_Var8 = sk_dup(p_Var8);
    iVar1 = 0;
    do {
      iVar2 = sk_num(&certs->stack);
      if (iVar2 <= iVar1) goto LAB_000d3d96;
      pvVar4 = sk_value(&certs->stack,iVar1);
      iVar2 = sk_push(p_Var8,pvVar4);
      iVar1 = iVar1 + 1;
    } while (iVar2 != 0);
    ERR_put_error(0x27,0x69,0x41,DAT_000d3fb8,0x75);
    goto LAB_000d3d1e;
  }
LAB_000d3d96:
  iVar10 = X509_STORE_CTX_init(&XStack_b0,st,pXVar6,(stack_st_X509 *)p_Var8);
  if (iVar10 == 0) {
    ERR_put_error(0x27,0x69,0xb,DAT_000d404c,0x7f);
    iVar10 = -1;
    goto LAB_000d3d1e;
  }
  X509_STORE_CTX_set_purpose(&XStack_b0,8);
  iVar10 = X509_verify_cert(&XStack_b0);
  st_00 = &X509_STORE_CTX_get1_chain(&XStack_b0)->stack;
  X509_STORE_CTX_cleanup(&XStack_b0);
  if (iVar10 < 1) {
    iVar1 = X509_STORE_CTX_get_error(&XStack_b0);
    ERR_put_error(0x27,0x69,0x65,DAT_000d3fb8,0x8a);
    pcVar5 = X509_verify_cert_error_string(iVar1);
    ERR_add_error_data(2,DAT_000d3fc4,pcVar5);
  }
  else if ((flags & 0x100) == 0) {
    p_Var11 = &bs->tbsResponseData->responses->stack;
    iVar10 = sk_num(st_00);
    if (iVar10 < 1) {
      ERR_put_error(0x27,0x6c,0x69,DAT_000d404c,0xed);
      iVar10 = -1;
    }
    else {
      iVar10 = sk_num(p_Var11);
      if (iVar10 < 1) {
        ERR_put_error(0x27,0x6b,0x6f,DAT_000d404c,0x11a);
        iVar10 = -1;
      }
      else {
        ppOVar3 = (OCSP_CERTID **)sk_value(p_Var11,0);
        local_b8 = *ppOVar3;
        if (iVar10 != 1) {
          iVar1 = 1;
          do {
            ppOVar3 = (OCSP_CERTID **)sk_value(p_Var11,iVar1);
            b = *ppOVar3;
            iVar1 = iVar1 + 1;
            iVar2 = OCSP_id_issuer_cmp(local_b8,b);
            if (iVar2 != 0) {
              iVar10 = OBJ_cmp(b->hashAlgorithm->algorithm,local_b8->hashAlgorithm->algorithm);
              if (iVar10 == 0) goto LAB_000d3eda;
              local_b8 = (OCSP_CERTID *)0x0;
              break;
            }
          } while (iVar1 != iVar10);
        }
        pXVar6 = (X509 *)sk_value(st_00,0);
        iVar10 = sk_num(st_00);
        if (iVar10 < 2) {
LAB_000d3ec8:
          iVar10 = ocsp_match_issuerid(pXVar6,local_b8,p_Var11);
          if (iVar10 == 0) {
LAB_000d3eda:
            if ((flags & 0x20) == 0) {
              iVar10 = sk_num(st_00);
              pXVar6 = (X509 *)sk_value(st_00,iVar10 + -1);
              iVar10 = X509_check_trust(pXVar6,0xb4,0);
              if (iVar10 == 1) goto LAB_000d3dd4;
              ERR_put_error(0x27,0x69,0x70,DAT_000d3fb8,0xa6);
              iVar10 = 0;
            }
            else {
              iVar10 = 0;
            }
          }
        }
        else {
          pvVar4 = sk_value(st_00,1);
          iVar10 = ocsp_match_issuerid(pvVar4,local_b8,p_Var11);
          if (-1 < iVar10) {
            if (iVar10 == 0) goto LAB_000d3ec8;
            X509_check_purpose(pXVar6,-1,0);
            if (((int)(pXVar6->ex_flags << 0x1d) < 0) && ((int)(pXVar6->ex_xkusage << 0x1a) < 0))
            goto LAB_000d3dd4;
            ERR_put_error(0x27,0x6a,0x67,DAT_000d404c,0x168);
            goto LAB_000d3eda;
          }
        }
      }
    }
  }
  else {
LAB_000d3dd4:
    iVar10 = 1;
  }
  if (st_00 != (_STACK *)0x0) {
    sk_pop_free(st_00,DAT_000d3fbc);
  }
LAB_000d3d1e:
  if ((bs->certs != (stack_st_X509 *)0x0) && (certs != (stack_st_X509 *)0x0)) {
    sk_free(p_Var8);
  }
  return iVar10;
}

