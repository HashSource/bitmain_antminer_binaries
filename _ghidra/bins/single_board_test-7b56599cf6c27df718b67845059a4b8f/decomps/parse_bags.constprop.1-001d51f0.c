
undefined4 parse_bags_constprop_1(undefined4 param_1,char *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  PKCS12_SAFEBAG *bag;
  ASN1_STRING *in;
  int *piVar2;
  undefined4 uVar3;
  EVP_PKEY *pEVar4;
  PKCS8_PRIV_KEY_INFO *pPVar5;
  X509 *x;
  int iVar6;
  uchar *local_2c [2];
  
  iVar6 = 0;
  iVar1 = OPENSSL_sk_num(param_1);
  if (0 < iVar1) {
    do {
      bag = (PKCS12_SAFEBAG *)OPENSSL_sk_value(param_1,iVar6);
      in = (ASN1_STRING *)PKCS12_SAFEBAG_get0_attr(bag,0x9c);
      if (in != (ASN1_STRING *)0x0) {
        in = (ASN1_STRING *)in->type;
      }
      piVar2 = (int *)PKCS12_SAFEBAG_get0_attr(bag,0x9d);
      if (piVar2 != (int *)0x0) {
        piVar2 = (int *)piVar2[1];
      }
      uVar3 = PKCS12_SAFEBAG_get_nid(bag);
      switch(uVar3) {
      case 0x96:
        if ((param_3 != (int *)0x0) && (*param_3 == 0)) {
          pPVar5 = (PKCS8_PRIV_KEY_INFO *)PKCS12_SAFEBAG_get0_p8inf(bag);
          pEVar4 = EVP_PKCS82PKEY(pPVar5);
          *param_3 = (int)pEVar4;
          goto joined_r0x001d52a2;
        }
        break;
      case 0x97:
        if ((param_3 != (int *)0x0) && (*param_3 == 0)) {
          pPVar5 = PKCS12_decrypt_skey(bag,param_2,-1);
          if (pPVar5 == (PKCS8_PRIV_KEY_INFO *)0x0) {
            return 0;
          }
          pEVar4 = EVP_PKCS82PKEY(pPVar5);
          *param_3 = (int)pEVar4;
          PKCS8_PRIV_KEY_INFO_free(pPVar5);
          pEVar4 = (EVP_PKEY *)*param_3;
          goto joined_r0x001d52a2;
        }
        break;
      case 0x98:
        iVar1 = PKCS12_SAFEBAG_get_bag_nid(bag);
        if (iVar1 == 0x9e) {
          x = (X509 *)PKCS12_SAFEBAG_get1_cert(bag);
          if (x == (X509 *)0x0) {
            return 0;
          }
          if ((piVar2 != (int *)0x0) &&
             (iVar1 = X509_keyid_set1(x,(uchar *)piVar2[2],*piVar2), iVar1 == 0)) {
LAB_001d5320:
            X509_free(x);
            return 0;
          }
          if ((in != (ASN1_STRING *)0x0) && (iVar1 = ASN1_STRING_to_UTF8(local_2c,in), -1 < iVar1))
          {
            iVar1 = X509_alias_set1(x,local_2c[0],iVar1);
            CRYPTO_free(local_2c[0]);
            if (iVar1 == 0) goto LAB_001d5320;
          }
          iVar1 = OPENSSL_sk_push(param_4,x);
          if (iVar1 == 0) goto LAB_001d5320;
        }
        break;
      case 0x9b:
        uVar3 = PKCS12_SAFEBAG_get0_safes(bag);
        pEVar4 = (EVP_PKEY *)parse_bags_constprop_1(uVar3,param_2,param_3,param_4);
joined_r0x001d52a2:
        if (pEVar4 == (EVP_PKEY *)0x0) {
          return 0;
        }
      }
      iVar6 = iVar6 + 1;
      iVar1 = OPENSSL_sk_num(param_1);
    } while (iVar6 < iVar1);
  }
  return 1;
}

