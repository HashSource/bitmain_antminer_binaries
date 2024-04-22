
undefined4 parse_bags_constprop_1(_STACK *param_1,char *param_2,EVP_PKEY **param_3,_STACK *param_4)

{
  int iVar1;
  PKCS12_SAFEBAG *bag;
  ASN1_STRING *in;
  ASN1_STRING *pAVar2;
  X509 *x;
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pEVar3;
  int iVar4;
  uchar *local_2c [2];
  
  iVar4 = 0;
  iVar1 = sk_num(param_1);
  if (0 < iVar1) {
    do {
      bag = (PKCS12_SAFEBAG *)sk_value(param_1,iVar4);
      in = (ASN1_STRING *)PKCS12_get_attr_gen(bag->attrib,0x9c);
      if (in != (ASN1_STRING *)0x0) {
        in = ((_union_263 *)&in->type)->asn1_string;
      }
      pAVar2 = (ASN1_STRING *)PKCS12_get_attr_gen(bag->attrib,0x9d);
      if (pAVar2 != (ASN1_STRING *)0x0) {
        pAVar2 = ((_union_263 *)&pAVar2->type)->asn1_string;
      }
      iVar1 = OBJ_obj2nid(bag->type);
      switch(iVar1) {
      case 0x96:
        if ((param_3 != (EVP_PKEY **)0x0) && (*param_3 == (EVP_PKEY *)0x0)) {
          pEVar3 = EVP_PKCS82PKEY((PKCS8_PRIV_KEY_INFO *)(bag->value).bag);
          *param_3 = pEVar3;
joined_r0x000d1acc:
          if (pEVar3 == (EVP_PKEY *)0x0) {
            return 0;
          }
        }
        break;
      case 0x97:
        if ((param_3 != (EVP_PKEY **)0x0) && (*param_3 == (EVP_PKEY *)0x0)) {
          p8 = PKCS12_decrypt_skey(bag,param_2,-1);
          if (p8 == (PKCS8_PRIV_KEY_INFO *)0x0) {
            return 0;
          }
          pEVar3 = EVP_PKCS82PKEY(p8);
          *param_3 = pEVar3;
          PKCS8_PRIV_KEY_INFO_free(p8);
          pEVar3 = *param_3;
          goto joined_r0x000d1acc;
        }
        break;
      case 0x98:
        iVar1 = OBJ_obj2nid(((bag->value).bag)->type);
        if (iVar1 == 0x9e) {
          x = PKCS12_certbag2x509(bag);
          if (x == (X509 *)0x0) {
            return 0;
          }
          if ((pAVar2 != (ASN1_STRING *)0x0) &&
             (iVar1 = X509_keyid_set1(x,pAVar2->data,pAVar2->length), iVar1 == 0)) {
LAB_000d1a96:
            X509_free(x);
            return 0;
          }
          if ((in != (ASN1_STRING *)0x0) && (iVar1 = ASN1_STRING_to_UTF8(local_2c,in), -1 < iVar1))
          {
            iVar1 = X509_alias_set1(x,local_2c[0],iVar1);
            CRYPTO_free(local_2c[0]);
            if (iVar1 == 0) goto LAB_000d1a96;
          }
          iVar1 = sk_push(param_4,x);
          if (iVar1 == 0) goto LAB_000d1a96;
        }
        break;
      case 0x9b:
        iVar1 = parse_bags_constprop_1((bag->value).bag,param_2,param_3,param_4);
        if (iVar1 == 0) {
          return 0;
        }
      }
      iVar4 = iVar4 + 1;
      iVar1 = sk_num(param_1);
    } while (iVar4 < iVar1);
  }
  return 1;
}

