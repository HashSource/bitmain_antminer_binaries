
char * i2s_ASN1_ENUMERATED_TABLE(X509V3_EXT_METHOD *meth,ASN1_ENUMERATED *aint)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  
  lVar1 = ASN1_ENUMERATED_get(aint);
  piVar4 = (int *)meth->usr_data;
  pcVar3 = (char *)piVar4[1];
  if (pcVar3 != (char *)0x0) {
    iVar2 = *piVar4;
    while( true ) {
      if (iVar2 == lVar1) {
        pcVar3 = BUF_strdup(pcVar3);
        return pcVar3;
      }
      pcVar3 = (char *)piVar4[4];
      if (pcVar3 == (char *)0x0) break;
      piVar4 = piVar4 + 3;
      iVar2 = *piVar4;
    }
  }
  pcVar3 = i2s_ASN1_ENUMERATED(meth,aint);
  return pcVar3;
}

