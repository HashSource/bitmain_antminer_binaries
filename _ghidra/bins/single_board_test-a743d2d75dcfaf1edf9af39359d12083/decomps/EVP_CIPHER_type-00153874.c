
int EVP_CIPHER_type(EVP_CIPHER *ctx)

{
  ASN1_OBJECT *a;
  int n;
  
  n = ctx->nid;
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
  if (a == (ASN1_OBJECT *)0x0) {
    n = 0;
  }
  else if (a->data == (uchar *)0x0) {
    n = 0;
  }
  ASN1_OBJECT_free(a);
  return n;
}

