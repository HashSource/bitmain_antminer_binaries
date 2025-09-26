
int asn1_ex_i2c(ASN1_VALUE **pval,uchar *cont,int *putype,ASN1_ITEM *it)

{
  int iVar1;
  undefined1 *__src;
  uchar **ppuVar2;
  ASN1_VALUE *pAVar3;
  undefined1 *__n;
  undefined4 *puVar4;
  code *pcVar5;
  uchar *local_24;
  undefined1 local_20 [12];
  
  local_24 = cont;
  if ((it->funcs != (void *)0x0) &&
     (pcVar5 = *(code **)((int)it->funcs + 0x18), pcVar5 != (code *)0x0)) {
    iVar1 = (*pcVar5)();
    return iVar1;
  }
  if (it->itype == '\0') {
    iVar1 = it->utype;
    if (iVar1 != 1) {
      pAVar3 = *pval;
      if (pAVar3 == (ASN1_VALUE *)0x0) {
        return -1;
      }
LAB_0015b28e:
      if (iVar1 == -4) {
        pval = (ASN1_VALUE **)(pAVar3 + 4);
        iVar1 = *(int *)pAVar3;
        *putype = iVar1;
        goto joined_r0x0015b2e8;
      }
    }
    iVar1 = *putype;
  }
  else {
    pAVar3 = *pval;
    if (pAVar3 == (ASN1_VALUE *)0x0) {
      return -1;
    }
    if (it->itype != '\x05') {
      iVar1 = it->utype;
      goto LAB_0015b28e;
    }
    iVar1 = *(int *)(pAVar3 + 4);
    *putype = iVar1;
  }
joined_r0x0015b2e8:
  if (iVar1 == 5) {
    __src = (undefined1 *)0x0;
    __n = __src;
LAB_0015b2b4:
    if (cont == (uchar *)0x0) {
      return (int)__n;
    }
    if (__n == (undefined1 *)0x0) {
      return 0;
    }
LAB_0015b2c0:
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
        if (iVar1 != 1) goto LAB_0015b2a6;
        iVar1 = (int)*pval;
        if (iVar1 == -1) {
          return -1;
        }
        if (it->utype != -4) {
          if (iVar1 == 0) {
            if (it->size == 0) {
              return -1;
            }
          }
          else if (0 < it->size) {
            return -1;
          }
        }
        local_20[0] = (undefined1)iVar1;
        if (cont == (uchar *)0x0) {
          return 1;
        }
        __n = (undefined1 *)0x1;
        __src = local_20;
        goto LAB_0015b2c0;
      }
    }
    else if (iVar1 != 10) {
      if (iVar1 < 0xb) {
        if (iVar1 == 6) {
          __src = *(undefined1 **)((int)*pval + 0x10);
          __n = *(undefined1 **)((int)*pval + 0xc);
          goto LAB_0015b2b4;
        }
      }
      else if ((iVar1 == 0x102) || (iVar1 == 0x10a)) goto LAB_0015b32e;
LAB_0015b2a6:
      puVar4 = (undefined4 *)*pval;
      if ((it->size == 0x800) && ((int)(puVar4[3] << 0x1b) < 0)) {
        if (cont != (uchar *)0x0) {
          puVar4[2] = cont;
          *puVar4 = 0;
          return -2;
        }
        return -2;
      }
      __src = (undefined1 *)puVar4[2];
      __n = (undefined1 *)*puVar4;
      goto LAB_0015b2b4;
    }
LAB_0015b32e:
    ppuVar2 = (uchar **)cont;
    if (cont != (uchar *)0x0) {
      ppuVar2 = &local_24;
    }
    __n = (undefined1 *)i2c_ASN1_INTEGER((ASN1_INTEGER *)*pval,ppuVar2);
  }
  return (int)__n;
}

