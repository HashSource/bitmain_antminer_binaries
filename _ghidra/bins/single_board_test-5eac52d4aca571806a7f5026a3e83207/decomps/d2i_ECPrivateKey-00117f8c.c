
EC_KEY * d2i_ECPrivateKey(EC_KEY **key,uchar **in,long len)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  EC_POINT *pEVar4;
  EC_KEY *key_00;
  ASN1_STRING *x;
  uchar *local_24 [2];
  
  local_24[0] = *in;
  puVar1 = (undefined4 *)d2i_EC_PRIVATEKEY(0,local_24);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x10,0x92,0x10,"crypto/ec/ec_asn1.c",0x3f3);
    return (EC_KEY *)0x0;
  }
  if (((key == (EC_KEY **)0x0) || (key_00 = *key, key_00 == (EC_KEY *)0x0)) &&
     (key_00 = EC_KEY_new(), key_00 == (EC_KEY *)0x0)) {
    ERR_put_error(0x10,0x92,0x41,"crypto/ec/ec_asn1.c",0x3f9);
    goto LAB_00118066;
  }
  if (puVar1[2] == 0) {
    if (*(int *)(key_00 + 0xc) == 0) goto LAB_00118052;
  }
  else {
    EC_GROUP_free(*(EC_GROUP **)(key_00 + 0xc));
    iVar2 = EC_GROUP_new_from_ecpkparameters(puVar1[2]);
    *(int *)(key_00 + 0xc) = iVar2;
    if (iVar2 == 0) {
LAB_00118052:
      ERR_put_error(0x10,0x92,0x10,"crypto/ec/ec_asn1.c",0x408);
      goto LAB_00118066;
    }
    if (*(int *)puVar1[2] == 1) {
      *(undefined4 *)(iVar2 + 0x18) = 1;
    }
  }
  x = (ASN1_STRING *)puVar1[1];
  *(undefined4 *)(key_00 + 8) = *puVar1;
  if (x == (ASN1_STRING *)0x0) {
    ERR_put_error(0x10,0x92,0x7d,"crypto/ec/ec_asn1.c",0x414);
  }
  else {
    uVar3 = ASN1_STRING_get0_data(x);
    iVar2 = ASN1_STRING_length(x);
    iVar2 = EC_KEY_oct2priv(key_00,uVar3,iVar2);
    if (iVar2 != 0) {
      EC_POINT_clear_free(*(EC_POINT **)(key_00 + 0x10));
      pEVar4 = EC_POINT_new(*(EC_GROUP **)(key_00 + 0xc));
      *(EC_POINT **)(key_00 + 0x10) = pEVar4;
      if (pEVar4 == (EC_POINT *)0x0) {
        ERR_put_error(0x10,0x92,0x10,"crypto/ec/ec_asn1.c",0x41b);
      }
      else if (puVar1[3] == 0) {
        if ((*(code **)(**(int **)(key_00 + 0xc) + 0xb8) != (code *)0x0) &&
           (iVar2 = (**(code **)(**(int **)(key_00 + 0xc) + 0xb8))(key_00), iVar2 != 0)) {
          *(uint *)(key_00 + 0x18) = *(uint *)(key_00 + 0x18) | 2;
          goto LAB_00118034;
        }
      }
      else {
        uVar3 = ASN1_STRING_get0_data();
        iVar2 = ASN1_STRING_length((ASN1_STRING *)puVar1[3]);
        iVar2 = EC_KEY_oct2key(key_00,uVar3,iVar2,0);
        if (iVar2 != 0) {
LAB_00118034:
          if (key != (EC_KEY **)0x0) {
            *key = key_00;
          }
          EC_PRIVATEKEY_free(puVar1);
          *in = local_24[0];
          return key_00;
        }
        ERR_put_error(0x10,0x92,0x10,"crypto/ec/ec_asn1.c",0x426);
      }
    }
  }
LAB_00118066:
  if ((key == (EC_KEY **)0x0) || (key_00 != *key)) {
    EC_KEY_free(key_00);
  }
  EC_PRIVATEKEY_free(puVar1);
  return (EC_KEY *)0x0;
}

