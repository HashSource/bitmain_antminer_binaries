
undefined4 pkey_ecx_keygen(undefined4 *param_1,EVP_PKEY *param_2)

{
  void *ptr;
  byte *pbVar1;
  int iVar2;
  int type;
  
  type = *(int *)*param_1;
  ptr = (void *)CRYPTO_zalloc(0x40,"crypto/ec/ecx_meth.c",0x46);
  if (ptr == (void *)0x0) {
    ERR_put_error(0x10,0x10a,0x41,"crypto/ec/ecx_meth.c",0x48);
    return 0;
  }
  if (type == 0x40a || type == 0x43f) {
    pbVar1 = (byte *)CRYPTO_secure_malloc(0x20,"crypto/ec/ecx_meth.c",0x50);
    *(byte **)((int)ptr + 0x3c) = pbVar1;
    if (pbVar1 != (byte *)0x0) {
      iVar2 = RAND_priv_bytes(pbVar1,0x20);
joined_r0x0012564e:
      if (0 < iVar2) {
        if (type == 0x40a) {
          pbVar1[0x1f] = pbVar1[0x1f] & 0x7f | 0x40;
          *pbVar1 = *pbVar1 & 0xf8;
          X25519_public_from_private(ptr,pbVar1);
          goto LAB_00125618;
        }
        if (type != 0x40b) {
          if (type == 0x43f) {
            ED25519_public_from_private(ptr,pbVar1);
          }
          else if (type == 0x440) {
            ED448_public_from_private(ptr,pbVar1);
          }
          goto LAB_00125618;
        }
LAB_001256b0:
        *pbVar1 = *pbVar1 & 0xfc;
        pbVar1[0x37] = pbVar1[0x37] | 0x80;
        X448_public_from_private(ptr,pbVar1);
LAB_00125618:
        EVP_PKEY_assign(param_2,type,ptr);
        return 1;
      }
LAB_00125650:
      CRYPTO_secure_free(pbVar1,"crypto/ec/ecx_meth.c",0x57);
      *(undefined4 *)((int)ptr + 0x3c) = 0;
      goto LAB_00125660;
    }
  }
  else if (type == 0x40b) {
    pbVar1 = (byte *)CRYPTO_secure_malloc(0x38,"crypto/ec/ecx_meth.c",0x50);
    *(byte **)((int)ptr + 0x3c) = pbVar1;
    if (pbVar1 != (byte *)0x0) {
      iVar2 = RAND_priv_bytes(pbVar1,0x38);
      if (0 < iVar2) goto LAB_001256b0;
      goto LAB_00125650;
    }
  }
  else {
    pbVar1 = (byte *)CRYPTO_secure_malloc(0x39,"crypto/ec/ecx_meth.c",0x50);
    *(byte **)((int)ptr + 0x3c) = pbVar1;
    if (pbVar1 != (byte *)0x0) {
      iVar2 = RAND_priv_bytes(pbVar1,0x39);
      goto joined_r0x0012564e;
    }
  }
  ERR_put_error(0x10,0x10a,0x41,"crypto/ec/ecx_meth.c",0x52);
LAB_00125660:
  CRYPTO_free(ptr);
  return 0;
}

