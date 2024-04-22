
ASN1_TEMPLATE * asn1_do_adb(ASN1_VALUE **pval,ASN1_TEMPLATE *tt,int nullerr)

{
  ASN1_OBJECT *o;
  int iVar1;
  int *piVar2;
  void *pvVar3;
  ASN1_ITEM_EXP *pAVar4;
  
  if ((tt->flags & 0x300) != 0) {
    pAVar4 = tt->item;
    if (*pval + pAVar4->utype == (ASN1_VALUE *)0x0) {
      tt = (ASN1_TEMPLATE *)pAVar4->sname;
    }
    else {
      o = *(ASN1_OBJECT **)(*pval + pAVar4->utype);
      if ((int)(tt->flags << 0x17) < 0) {
        iVar1 = OBJ_obj2nid(o);
      }
      else {
        iVar1 = ASN1_INTEGER_get((ASN1_INTEGER *)o);
      }
      piVar2 = (int *)pAVar4->tcount;
      if (0 < (int)pAVar4->funcs) {
        if (*piVar2 != iVar1) {
          pvVar3 = (void *)0x0;
          do {
            pvVar3 = (void *)((int)pvVar3 + 1);
            piVar2 = piVar2 + 6;
            if (pvVar3 == pAVar4->funcs) goto LAB_000bbabe;
          } while (*piVar2 != iVar1);
        }
        return (ASN1_TEMPLATE *)(piVar2 + 1);
      }
LAB_000bbabe:
      tt = (ASN1_TEMPLATE *)pAVar4->size;
    }
    if ((tt == (ASN1_TEMPLATE *)0x0) && (tt = (ASN1_TEMPLATE *)nullerr, nullerr != 0)) {
      ERR_put_error(0xd,0x6e,0xa4,DAT_000bbaf4,0x111);
      tt = (ASN1_TEMPLATE *)0x0;
    }
  }
  return tt;
}

