
int do_x509_check_constprop_4(X509 *param_1,char *param_2,size_t param_3,uint param_4)

{
  _STACK *a;
  int iVar1;
  int *piVar2;
  X509_NAME *name;
  X509_NAME_ENTRY *ne;
  ASN1_STRING *in;
  int iVar3;
  int iVar4;
  size_t *psVar5;
  uchar *local_24 [2];
  
  if (param_3 == 0) {
    param_3 = strlen(param_2);
  }
  a = (_STACK *)X509_get_ext_d2i(param_1,0x55,(int *)0x0,(int *)0x0);
  if (a == (_STACK *)0x0) {
    name = X509_get_subject_name(param_1);
    iVar4 = -1;
    do {
      do {
        iVar4 = X509_NAME_get_index_by_NID(name,0,iVar4);
        if (iVar4 < 0) {
          return 0;
        }
        ne = X509_NAME_get_entry(name,iVar4);
        in = X509_NAME_ENTRY_get_data(ne);
      } while ((in->data == (uchar *)0x0) || (in->length == 0));
      iVar1 = ASN1_STRING_to_UTF8(local_24,in);
      if (iVar1 < 0) {
        return -1;
      }
      iVar1 = equal_case(local_24[0],iVar1,param_2,param_3,param_4 & 0xffff7fff);
      CRYPTO_free(local_24[0]);
    } while (iVar1 == 0);
  }
  else {
    iVar4 = 0;
    do {
      do {
        iVar1 = sk_num(a);
        iVar3 = iVar4 + 1;
        if (iVar1 <= iVar4) {
          GENERAL_NAMES_free((GENERAL_NAMES *)a);
          return 0;
        }
        piVar2 = (int *)sk_value(a,iVar4);
        iVar4 = iVar3;
      } while (*piVar2 != 7);
      psVar5 = (size_t *)piVar2[1];
    } while (((((void *)psVar5[2] == (void *)0x0) || (*psVar5 == 0)) || (psVar5[1] != 4)) ||
            ((*psVar5 != param_3 || (iVar1 = memcmp((void *)psVar5[2],param_2,param_3), iVar1 != 0))
            ));
    iVar1 = 1;
    GENERAL_NAMES_free((GENERAL_NAMES *)a);
  }
  return iVar1;
}

