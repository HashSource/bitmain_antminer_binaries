
int EVP_CIPHER_type(EVP_CIPHER *ctx)

{
  int n;
  ASN1_OBJECT *a;
  int iVar1;
  
  n = EVP_CIPHER_nid(ctx);
  if (n == 0x1ad) {
    return 0x1ad;
  }
  if (n < 0x1ae) {
    if (n == 0x61) {
      return 5;
    }
    if (n < 0x62) {
      if (n == 0x1e) {
        return 0x1e;
      }
      if (n < 0x1f) {
        if (n == 5) {
          return 5;
        }
      }
      else {
        if (n == 0x25) {
          return 0x25;
        }
        if (n == 0x3d) {
          return 0x1e;
        }
      }
    }
    else {
      if (n == 0xa6) {
        return 0x25;
      }
      if (n < 0xa7) {
        if (n == 0x62) {
          return 0x25;
        }
      }
      else {
        if (n == 0x1a5) {
          return 0x1a5;
        }
        if (n == 0x1a9) {
          return 0x1a9;
        }
      }
    }
  }
  else {
    if (n == 0x28e) {
      return 0x1a9;
    }
    if (n < 0x28f) {
      if (n == 0x28b) {
        return 0x1a9;
      }
      if (n < 0x28c) {
        if (n == 0x28a) {
          return 0x1a5;
        }
      }
      else {
        if (n == 0x28c) {
          return 0x1ad;
        }
        if (n == 0x28d) {
          return 0x1a5;
        }
      }
    }
    else {
      if (n < 0x292) {
        if (n < 0x290) {
          return 0x1ad;
        }
        return 0x1e;
      }
      if (n < 0x294) {
        return 0x1e;
      }
    }
  }
  a = OBJ_nid2obj(n);
  iVar1 = OBJ_get0_data();
  if (iVar1 == 0) {
    n = 0;
  }
  ASN1_OBJECT_free(a);
  return n;
}

