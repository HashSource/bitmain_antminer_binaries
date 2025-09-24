
int i2d_ECPrivateKey(EC_KEY *key,uchar **out)

{
  undefined4 *puVar1;
  int len;
  ASN1_BIT_STRING *pAVar2;
  int iVar3;
  uint uVar4;
  ASN1_STRING *str;
  void *local_20;
  void *local_1c;
  
  local_20 = (void *)0x0;
  local_1c = (void *)0x0;
  if ((key != (EC_KEY *)0x0) && (*(int *)(key + 0xc) != 0)) {
    if ((*(int *)(key + 0x18) << 0x1e < 0) || (*(int *)(key + 0x10) != 0)) {
      puVar1 = (undefined4 *)EC_PRIVATEKEY_new();
      if (puVar1 == (undefined4 *)0x0) {
        ERR_put_error(0x10,0xc0,0x41,"crypto/ec/ec_asn1.c",0x44d);
        len = 0;
      }
      else {
        *puVar1 = *(undefined4 *)(key + 8);
        len = EC_KEY_priv2buf(key,&local_20);
        if (len == 0) {
          ERR_put_error(0x10,0xc0,0x10,"crypto/ec/ec_asn1.c",0x456);
        }
        else {
          ASN1_STRING_set0((ASN1_STRING *)puVar1[1],local_20,len);
          uVar4 = *(uint *)(key + 0x18);
          local_20 = (void *)0x0;
          if (-1 < (int)(uVar4 << 0x1f)) {
            iVar3 = EC_GROUP_get_ecpkparameters(*(undefined4 *)(key + 0xc),puVar1[2]);
            puVar1[2] = iVar3;
            if (iVar3 == 0) {
              ERR_put_error(0x10,0xc0,0x10,"crypto/ec/ec_asn1.c",0x461);
              goto LAB_0011c3de;
            }
            uVar4 = *(uint *)(key + 0x18);
          }
          if ((uVar4 & 2) == 0) {
            pAVar2 = ASN1_BIT_STRING_new();
            puVar1[3] = pAVar2;
            if (pAVar2 == (ASN1_BIT_STRING *)0x0) {
              ERR_put_error(0x10,0xc0,0x41,"crypto/ec/ec_asn1.c",0x469);
              goto LAB_0011c3de;
            }
            iVar3 = EC_KEY_key2buf(key,*(undefined4 *)(key + 0x1c),&local_1c,0);
            if (iVar3 == 0) {
              ERR_put_error(0x10,0xc0,0x10,"crypto/ec/ec_asn1.c",0x470);
              goto LAB_0011c3de;
            }
            str = (ASN1_STRING *)puVar1[3];
            str->flags = str->flags & 0xfffffff0U | 8;
            ASN1_STRING_set0(str,local_1c,iVar3);
            local_1c = (void *)0x0;
          }
          iVar3 = i2d_EC_PRIVATEKEY(puVar1,out);
          if (iVar3 != 0) {
            CRYPTO_clear_free(local_20,len,"crypto/ec/ec_asn1.c",0x480);
            CRYPTO_free(local_1c);
            EC_PRIVATEKEY_free(puVar1);
            return iVar3;
          }
          ERR_put_error(0x10,0xc0,0x10,"crypto/ec/ec_asn1.c",0x47b);
        }
      }
      goto LAB_0011c3de;
    }
  }
  puVar1 = (undefined4 *)0x0;
  ERR_put_error(0x10,0xc0,0x43,"crypto/ec/ec_asn1.c",0x448);
  len = 0;
LAB_0011c3de:
  CRYPTO_clear_free(local_20,len,"crypto/ec/ec_asn1.c",0x480);
  CRYPTO_free(local_1c);
  EC_PRIVATEKEY_free(puVar1);
  return 0;
}

