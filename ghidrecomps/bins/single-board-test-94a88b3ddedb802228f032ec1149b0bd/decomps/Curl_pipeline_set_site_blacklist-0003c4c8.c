
undefined4 Curl_pipeline_set_site_blacklist(int *param_1,int *param_2)

{
  code **ppcVar1;
  code **ppcVar2;
  code **ppcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  char *__s;
  char **ppcVar7;
  char *pcVar8;
  int iVar9;
  code *pcVar10;
  
  iVar9 = *param_2;
  if (param_1 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = Curl_llist_alloc(DAT_0003c59c);
    ppcVar3 = DAT_0003c5a8;
    ppcVar2 = DAT_0003c5a4;
    if (iVar4 == 0) {
      return 3;
    }
    iVar5 = *param_1;
    while (iVar5 != 0) {
      __s = (char *)(**ppcVar2)();
      if (__s == (char *)0x0) {
LAB_0003c57e:
        Curl_llist_destroy(iVar4,__s);
        return 3;
      }
      ppcVar7 = (char **)(**ppcVar3)(8);
      if (ppcVar7 == (char **)0x0) {
        (**DAT_0003c5a0)();
        Curl_llist_destroy(iVar4,0);
        return 3;
      }
      pcVar8 = strchr(__s,0x3a);
      if (pcVar8 == (char *)0x0) {
        *(undefined2 *)(ppcVar7 + 1) = 0x50;
      }
      else {
        *pcVar8 = '\0';
        lVar6 = strtol(pcVar8 + 1,(char **)0x0,10);
        *(short *)(ppcVar7 + 1) = (short)lVar6;
      }
      *ppcVar7 = __s;
      iVar5 = Curl_llist_insert_next(iVar4,*(undefined4 *)(iVar4 + 4),ppcVar7);
      ppcVar1 = DAT_0003c5a0;
      if (iVar5 == 0) {
        (**DAT_0003c5a0)(*ppcVar7);
        pcVar10 = *ppcVar1;
        *ppcVar7 = (char *)0x0;
        (*pcVar10)(ppcVar7);
        __s = (char *)0x0;
        goto LAB_0003c57e;
      }
      param_1 = param_1 + 1;
      iVar5 = *param_1;
    }
  }
  if (iVar9 != 0) {
    Curl_llist_destroy(iVar9,0);
  }
  *param_2 = iVar4;
  return 0;
}

