
ASN1_OBJECT * c2i_ASN1_OBJECT(ASN1_OBJECT **a,uchar **pp,long length)

{
  int in_r3;
  int iVar1;
  ASN1_OBJECT *ptr;
  uchar *__src;
  uchar *puVar2;
  uchar *puVar3;
  bool bVar4;
  bool bVar5;
  
  bVar4 = (int)pp < 0;
  bVar5 = pp == (uchar **)0x0;
  if (!bVar5) {
    bVar4 = length < 0;
  }
  if ((!bVar5 && length != 0) && !bVar4) {
    in_r3 = 0;
  }
  if ((((bVar5 || length == 0) || bVar4) || (__src = *pp, __src == (uchar *)0x0)) ||
     (puVar2 = __src + length, (char)puVar2[-1] < '\0')) {
    iVar1 = 0x11b;
LAB_000b5250:
    ERR_put_error(0xd,0xc4,0xd8,DAT_000b5398,iVar1);
LAB_000b525e:
    ptr = (ASN1_OBJECT *)0x0;
  }
  else {
    puVar3 = __src + -1;
    do {
      if ((puVar3[1] == 0x80) && ((in_r3 == 0 || (-1 < (char)*puVar3)))) {
        iVar1 = 0x122;
        goto LAB_000b5250;
      }
      in_r3 = in_r3 + 1;
      puVar3 = puVar3 + 1;
    } while (in_r3 < length);
    if (((a == (ASN1_OBJECT **)0x0) || (ptr = *a, ptr == (ASN1_OBJECT *)0x0)) ||
       (-1 < ptr->flags << 0x1f)) {
      ptr = (ASN1_OBJECT *)CRYPTO_malloc(0x18,DAT_000b5398,0x15a);
      if (ptr == (ASN1_OBJECT *)0x0) {
        ERR_put_error(0xd,0x7b,0x41,DAT_000b5398,0x15c);
        return (ASN1_OBJECT *)0x0;
      }
      ptr->data = (uchar *)0x0;
      ptr->sn = (char *)0x0;
      ptr->ln = (char **)0x0;
      ptr->length = 0;
      __src = *pp;
      ptr->nid = 0;
      ptr->flags = 1;
LAB_000b52fc:
      ptr->length = 0;
LAB_000b5292:
      puVar3 = (uchar *)CRYPTO_malloc(length,DAT_000b5398,0x13b);
      if (puVar3 == (uchar *)0x0) {
        ERR_put_error(0xd,0xc4,0x41,DAT_000b5398,0x150);
        if ((a == (ASN1_OBJECT **)0x0) || (*a != ptr)) {
          iVar1 = ptr->flags;
          if (iVar1 << 0x1d < 0) {
            if (ptr->sn != (char *)0x0) {
              CRYPTO_free(ptr->sn);
            }
            if (ptr->ln != (char **)0x0) {
              CRYPTO_free(ptr->ln);
            }
            iVar1 = ptr->flags;
            ptr->ln = (char **)0x0;
            ptr->sn = (char *)0x0;
          }
          if (iVar1 << 0x1c < 0) {
            if (ptr->data != (uchar *)0x0) {
              CRYPTO_free(ptr->data);
              iVar1 = ptr->flags;
            }
            ptr->data = (uchar *)0x0;
            ptr->length = 0;
          }
          if (iVar1 << 0x1f < 0) {
            CRYPTO_free(ptr);
            return (ASN1_OBJECT *)0x0;
          }
        }
        goto LAB_000b525e;
      }
      puVar2 = __src + length;
      ptr->flags = ptr->flags | 8;
      memcpy(puVar3,__src,length);
      ptr->data = puVar3;
      ptr->length = length;
      ptr->sn = (char *)0x0;
      ptr->ln = (char **)0x0;
      if (a != (ASN1_OBJECT **)0x0) goto LAB_000b52c6;
    }
    else {
      puVar3 = ptr->data;
      ptr->data = (uchar *)0x0;
      if (puVar3 == (uchar *)0x0) goto LAB_000b52fc;
      if (ptr->length < length) {
        ptr->length = 0;
        CRYPTO_free(puVar3);
        goto LAB_000b5292;
      }
      memcpy(puVar3,__src,length);
      ptr->data = puVar3;
      ptr->length = length;
      ptr->sn = (char *)0x0;
      ptr->ln = (char **)0x0;
LAB_000b52c6:
      *a = ptr;
    }
    *pp = puVar2;
  }
  return ptr;
}

