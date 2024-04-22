
int asn1_ex_i2c(ASN1_VALUE **pval,uchar *cont,int *putype,ASN1_ITEM *it)

{
  int iVar1;
  uchar *__src;
  uchar **ppuVar2;
  int *piVar3;
  uchar *__n;
  ASN1_BIT_STRING *pAVar4;
  code *pcVar5;
  uchar *local_24;
  uchar local_20 [12];
  
  local_24 = cont;
  if ((it->funcs != (void *)0x0) &&
     (pcVar5 = *(code **)((int)it->funcs + 0x18), pcVar5 != (code *)0x0)) {
    iVar1 = (*pcVar5)();
    return iVar1;
  }
  if (it->itype == '\0') {
    iVar1 = it->utype;
    if (iVar1 != 1) {
      piVar3 = (int *)*pval;
      if (piVar3 == (int *)0x0) {
        return -1;
      }
LAB_000b984a:
      if (iVar1 == -4) {
        pval = (ASN1_VALUE **)(piVar3 + 1);
        iVar1 = *piVar3;
        *putype = iVar1;
        goto joined_r0x000b98a4;
      }
    }
    iVar1 = *putype;
  }
  else {
    piVar3 = (int *)*pval;
    if (piVar3 == (int *)0x0) {
      return -1;
    }
    if (it->itype != '\x05') {
      iVar1 = it->utype;
      goto LAB_000b984a;
    }
    iVar1 = piVar3[1];
    *putype = iVar1;
  }
joined_r0x000b98a4:
  if (iVar1 == 5) {
    __src = (uchar *)0x0;
    __n = __src;
LAB_000b9870:
    if (cont == (uchar *)0x0) {
      return (int)__n;
    }
    if (__n == (uchar *)0x0) {
      return 0;
    }
LAB_000b987c:
    memcpy(cont,__src,(size_t)__n);
  }
  else {
    if (iVar1 < 6) {
      if (iVar1 != 2) {
        if (iVar1 == 3) {
          ppuVar2 = (uchar **)cont;
          if (cont != (uchar *)0x0) {
            ppuVar2 = &local_24;
          }
          iVar1 = i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*pval,ppuVar2);
          return iVar1;
        }
        if (iVar1 != 1) goto LAB_000b9862;
        pAVar4 = (ASN1_BIT_STRING *)*pval;
        if (pAVar4 == (ASN1_BIT_STRING *)0xffffffff) {
          return -1;
        }
        if (it->utype != -4) {
          if (pAVar4 == (ASN1_BIT_STRING *)0x0) {
            if (it->size == 0) {
              return -1;
            }
          }
          else if (0 < it->size) {
            return -1;
          }
        }
        local_20[0] = (uchar)pAVar4;
        if (cont == (uchar *)0x0) {
          return 1;
        }
        __n = (uchar *)0x1;
        __src = local_20;
        goto LAB_000b987c;
      }
    }
    else if (iVar1 != 10) {
      if (iVar1 < 0xb) {
        if (iVar1 == 6) {
          __src = (uchar *)((ASN1_BIT_STRING *)*pval)[1].length;
          __n = (uchar *)((ASN1_BIT_STRING *)*pval)->flags;
          goto LAB_000b9870;
        }
      }
      else if ((iVar1 == 0x102) || (iVar1 == 0x10a)) goto LAB_000b98ea;
LAB_000b9862:
      pAVar4 = (ASN1_BIT_STRING *)*pval;
      if ((it->size == 0x800) && (pAVar4->flags << 0x1b < 0)) {
        if (cont != (uchar *)0x0) {
          pAVar4->data = cont;
          pAVar4->length = 0;
          return -2;
        }
        return -2;
      }
      __src = pAVar4->data;
      __n = (uchar *)pAVar4->length;
      goto LAB_000b9870;
    }
LAB_000b98ea:
    ppuVar2 = (uchar **)cont;
    if (cont != (uchar *)0x0) {
      ppuVar2 = &local_24;
    }
    __n = (uchar *)i2c_ASN1_INTEGER((ASN1_INTEGER *)*pval,ppuVar2);
  }
  return (int)__n;
}

