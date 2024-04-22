
void print_qualifiers(BIO *param_1,_STACK *param_2,int param_3)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  char *buf;
  ASN1_INTEGER *aint;
  char **ppcVar4;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int local_30;
  
  local_30 = 0;
  while( true ) {
    iVar1 = sk_num(param_2);
    if (iVar1 <= local_30) break;
    ppAVar2 = (ASN1_OBJECT **)sk_value(param_2,local_30);
    iVar1 = OBJ_obj2nid(*ppAVar2);
    if (iVar1 == 0xa4) {
      BIO_printf(param_1,DAT_000c9ebc,param_3,DAT_000c9eb4,ppAVar2[1]->nid);
    }
    else if (iVar1 == 0xa5) {
      BIO_printf(param_1,DAT_000c9ec0,param_3,DAT_000c9eb4);
      pAVar5 = ppAVar2[1];
      iVar1 = param_3 + 2;
      piVar7 = (int *)pAVar5->sn;
      if (piVar7 != (int *)0x0) {
        iVar6 = 0;
        BIO_printf(param_1,DAT_000c9ec4,iVar1,DAT_000c9eb4,*(undefined4 *)(*piVar7 + 8));
        iVar3 = sk_num((_STACK *)piVar7[1]);
        uVar8 = DAT_000c9eb4;
        if (1 < iVar3) {
          uVar8 = DAT_000c9ed4;
        }
        BIO_printf(param_1,DAT_000c9ec8,iVar1,DAT_000c9eb4,uVar8);
        for (; iVar3 = sk_num((_STACK *)piVar7[1]), iVar6 < iVar3; iVar6 = iVar6 + 1) {
          aint = (ASN1_INTEGER *)sk_value((_STACK *)piVar7[1],iVar6);
          if (iVar6 != 0) {
            BIO_puts(param_1,DAT_000c9ecc);
          }
          buf = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,aint);
          BIO_puts(param_1,buf);
          CRYPTO_free(buf);
        }
        BIO_puts(param_1,DAT_000c9eb8);
      }
      ppcVar4 = pAVar5->ln;
      if (ppcVar4 != (char **)0x0) {
        BIO_printf(param_1,DAT_000c9ed0,iVar1,DAT_000c9eb4,ppcVar4[2]);
      }
    }
    else {
      BIO_printf(param_1,DAT_000c9eb0,param_3 + 2,DAT_000c9eb4);
      i2a_ASN1_OBJECT(param_1,*ppAVar2);
      BIO_puts(param_1,DAT_000c9eb8);
    }
    local_30 = local_30 + 1;
  }
  return;
}

