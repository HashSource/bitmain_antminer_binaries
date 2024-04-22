
int X509V3_NAME_from_section(X509_NAME *nm,stack_st_CONF_VALUE *dn_sk,ulong chtype)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  char *field;
  char cVar4;
  char *pcVar5;
  int iVar6;
  
  if (nm == (X509_NAME *)0x0) {
LAB_000c876c:
    iVar2 = 0;
  }
  else {
    iVar6 = 0;
    iVar2 = sk_num(&dn_sk->stack);
    if (0 < iVar2) {
      do {
        pvVar3 = sk_value(&dn_sk->stack,iVar6);
        field = *(char **)((int)pvVar3 + 4);
        cVar4 = *field;
        if (cVar4 == '\0') {
LAB_000c8736:
          iVar2 = 0;
        }
        else {
          pcVar5 = field;
          cVar1 = cVar4;
          if (cVar4 != ',' && cVar4 != ':') {
            do {
              if (cVar1 == '.') break;
              pcVar5 = pcVar5 + 1;
              cVar1 = *pcVar5;
              if (cVar1 == '\0') goto LAB_000c872a;
            } while (cVar1 != ':' && cVar1 != ',');
          }
          if (pcVar5[1] != '\0') {
            field = pcVar5 + 1;
            cVar4 = pcVar5[1];
          }
LAB_000c872a:
          if (cVar4 != '+') goto LAB_000c8736;
          field = field + 1;
          iVar2 = -1;
        }
        iVar2 = X509_NAME_add_entry_by_txt(nm,field,chtype,*(uchar **)((int)pvVar3 + 8),-1,-1,iVar2)
        ;
        if (iVar2 == 0) goto LAB_000c876c;
        iVar6 = iVar6 + 1;
        iVar2 = sk_num(&dn_sk->stack);
      } while (iVar6 < iVar2);
    }
    iVar2 = 1;
  }
  return iVar2;
}

