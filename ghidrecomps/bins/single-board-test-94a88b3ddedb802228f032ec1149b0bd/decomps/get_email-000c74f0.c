
_STACK * get_email(X509_NAME *param_1,_STACK *param_2)

{
  X509_NAME_ENTRY *ne;
  ASN1_STRING *pAVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  uchar *data;
  void *data_00;
  int iVar5;
  _STACK *st;
  
  st = (_STACK *)0x0;
  iVar5 = -1;
  do {
    do {
      iVar5 = X509_NAME_get_index_by_NID(param_1,0x30,iVar5);
      if (iVar5 < 0) {
        iVar5 = 0;
        goto LAB_000c756c;
      }
      ne = X509_NAME_get_entry(param_1,iVar5);
      pAVar1 = X509_NAME_ENTRY_get_data(ne);
    } while (((pAVar1->type != 0x16) || (data = pAVar1->data, data == (uchar *)0x0)) ||
            (pAVar1->length == 0));
    if (st == (_STACK *)0x0) {
      st = sk_new(DAT_000c75e4);
      if (st == (_STACK *)0x0) {
        return (_STACK *)0x0;
      }
      data = pAVar1->data;
    }
    iVar2 = sk_find(st,data);
  } while ((iVar2 != -1) ||
          ((pcVar3 = BUF_strdup((char *)pAVar1->data), pcVar3 != (char *)0x0 &&
           (iVar2 = sk_push(st,pcVar3), iVar2 != 0))));
LAB_000c7554:
  sk_pop_free(st,DAT_000c75e0);
  return (_STACK *)0x0;
LAB_000c756c:
  iVar2 = sk_num(param_2);
  if (iVar2 <= iVar5) {
    return st;
  }
  piVar4 = (int *)sk_value(param_2,iVar5);
  if ((((*piVar4 == 1) && (piVar4 = (int *)piVar4[1], piVar4[1] == 0x16)) &&
      (data_00 = (void *)piVar4[2], data_00 != (void *)0x0)) && (*piVar4 != 0)) {
    if (st == (_STACK *)0x0) {
      st = sk_new(DAT_000c75e4);
      if (st == (_STACK *)0x0) {
        return (_STACK *)0x0;
      }
      data_00 = (void *)piVar4[2];
    }
    iVar2 = sk_find(st,data_00);
    if ((iVar2 == -1) &&
       ((pcVar3 = BUF_strdup((char *)piVar4[2]), pcVar3 == (char *)0x0 ||
        (iVar2 = sk_push(st,pcVar3), iVar2 == 0)))) goto LAB_000c7554;
  }
  iVar5 = iVar5 + 1;
  goto LAB_000c756c;
}

