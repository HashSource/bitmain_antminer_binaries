
int asn1_ex_c2i(ASN1_VALUE **pval,uchar *cont,int len,int utype,char *free_cont,ASN1_ITEM *it)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  ASN1_INTEGER *pAVar3;
  ASN1_TYPE *pAVar4;
  _union_263 _Var5;
  ASN1_TYPE *pAVar6;
  code *pcVar7;
  _union_263 *a;
  ASN1_STRING *str;
  byte *local_24 [2];
  
  local_24[0] = cont;
  if ((it->funcs != (void *)0x0) &&
     (pcVar7 = *(code **)((int)it->funcs + 0x14), pcVar7 != (code *)0x0)) {
    iVar1 = (*pcVar7)();
    return iVar1;
  }
  if (it->utype != -4) {
    pAVar6 = (ASN1_TYPE *)0x0;
    pAVar4 = pAVar6;
    a = (_union_263 *)pval;
    if (utype != 5) goto LAB_000baa2a;
LAB_000baab2:
    if (len != 0) {
      ERR_put_error(0xd,0xcc,0x90,DAT_000babf0,0x370);
      goto LAB_000baaea;
    }
    a->boolean = 1;
    goto LAB_000baabc;
  }
  pAVar6 = (ASN1_TYPE *)*pval;
  if (pAVar6 == (ASN1_TYPE *)0x0) {
    pAVar6 = ASN1_TYPE_new();
    if (pAVar6 == (ASN1_TYPE *)0x0) {
      ASN1_TYPE_free((ASN1_TYPE *)0x0);
      return 0;
    }
    *pval = (ASN1_VALUE *)pAVar6;
  }
  if (pAVar6->type != utype) {
    ASN1_TYPE_set(pAVar6,utype,(void *)0x0);
  }
  a = &pAVar6->value;
  pAVar4 = (ASN1_TYPE *)pval;
  if (utype == 5) goto LAB_000baab2;
LAB_000baa2a:
  if (utype < 6) {
    if (utype == 2) {
LAB_000bab2c:
      pAVar3 = c2i_ASN1_INTEGER(&a->integer,local_24,len);
      if (pAVar3 == (ASN1_INTEGER *)0x0) goto LAB_000baaea;
      a->asn1_string->type = a->asn1_string->type & 0x100U | utype;
LAB_000baabc:
      pAVar4 = pAVar6;
      if (pAVar6 != (ASN1_TYPE *)0x0) {
        pAVar4 = (ASN1_TYPE *)0x1;
      }
      if (utype != 5) {
        pAVar4 = (ASN1_TYPE *)0x0;
      }
      if (pAVar4 != (ASN1_TYPE *)0x0) {
        (pAVar6->value).ptr = (char *)0x0;
      }
    }
    else if (utype == 3) {
      pAVar2 = (ASN1_OBJECT *)c2i_ASN1_BIT_STRING(&a->bit_string,local_24,len);
joined_r0x000baa8a:
      if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_000baaea;
    }
    else {
      if (utype != 1) goto LAB_000baa38;
      if (len != 1) {
        ERR_put_error(0xd,0xcc,0x6a,DAT_000babf0,0x378);
        goto LAB_000baaea;
      }
      _Var5.boolean._1_3_ = 0;
      _Var5.boolean._0_1_ = *local_24[0];
      *a = _Var5;
    }
    pAVar6 = (ASN1_TYPE *)0x1;
  }
  else {
    if (utype == 10) goto LAB_000bab2c;
    if (utype < 0xb) {
      if (utype == 6) {
        pAVar2 = c2i_ASN1_OBJECT(&a->object,local_24,len);
        goto joined_r0x000baa8a;
      }
    }
    else if ((utype == 0x102) || (utype == 0x10a)) goto LAB_000bab2c;
LAB_000baa38:
    if (utype == 0x1e) {
      if ((len & 1U) == 0) {
LAB_000baa42:
        str = a->asn1_string;
        if (str == (ASN1_STRING *)0x0) {
          str = ASN1_STRING_type_new(utype);
          if (str == (ASN1_STRING *)0x0) {
            ERR_put_error(0xd,0xcc,0x41,DAT_000babf0,0x3b0);
            goto LAB_000baaea;
          }
          a->asn1_string = str;
        }
        else {
          str->type = utype;
        }
        if (*free_cont == '\0') {
          iVar1 = ASN1_STRING_set(str,local_24[0],len);
          if (iVar1 == 0) {
            ERR_put_error(0xd,0xcc,0x41,DAT_000babf0,0x3c1);
            ASN1_STRING_free(str);
            a->ptr = (char *)0x0;
            goto LAB_000baaea;
          }
        }
        else {
          if (str->data != (uchar *)0x0) {
            CRYPTO_free(str->data);
          }
          str->length = len;
          str->data = local_24[0];
          *free_cont = '\0';
        }
        goto LAB_000baabc;
      }
      ERR_put_error(0xd,0xcc,0xd6,DAT_000babf0,0x3a4);
    }
    else {
      if ((utype != 0x1c) || ((len & 3U) == 0)) goto LAB_000baa42;
      ERR_put_error(0xd,0xcc,0xd7,DAT_000babf0,0x3a9);
    }
LAB_000baaea:
    ASN1_TYPE_free(pAVar6);
    pAVar6 = pAVar4;
    if (pAVar4 != (ASN1_TYPE *)0x0) {
      pAVar6 = (ASN1_TYPE *)0x0;
      pAVar4->type = 0;
    }
  }
  return (int)pAVar6;
}

