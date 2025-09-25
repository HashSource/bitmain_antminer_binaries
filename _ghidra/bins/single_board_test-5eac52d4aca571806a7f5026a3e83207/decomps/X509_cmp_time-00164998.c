
int X509_cmp_time(ASN1_TIME *s,time_t *t)

{
  uchar *puVar1;
  int iVar2;
  ASN1_TIME *a;
  int iVar3;
  int local_18;
  int local_14;
  
  if (s->type == 0x17) {
    if (s->length != 0xd) {
      return 0;
    }
  }
  else {
    if (s->type != 0x18) {
      return 0;
    }
    if (s->length != 0xf) {
      return 0;
    }
  }
  iVar3 = 0;
  do {
    puVar1 = s->data + iVar3;
    iVar3 = iVar3 + 1;
    iVar2 = ascii_isdigit(*puVar1);
    if (iVar2 == 0) {
      return 0;
    }
  } while (iVar3 < s->length + -1);
  if (s->data[s->length + -1] != 'Z') {
    return 0;
  }
  a = X509_time_adj((ASN1_TIME *)0x0,0,t);
  if ((a == (ASN1_TIME *)0x0) || (iVar3 = ASN1_TIME_diff(&local_18,&local_14,s,a), iVar3 == 0)) {
    iVar3 = 0;
  }
  else if (local_18 < 0) {
    iVar3 = 1;
  }
  else if (local_14 < 0) {
    iVar3 = 1;
  }
  else {
    iVar3 = -1;
  }
  ASN1_TIME_free(a);
  return iVar3;
}

