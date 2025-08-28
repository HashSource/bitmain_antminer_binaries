
undefined4 Curl_pipeline_set_site_blacklist(int *param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  char *__s;
  undefined4 *puVar5;
  char *pcVar6;
  int iVar7;
  
  iVar7 = *param_2;
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = Curl_llist_alloc(0x3c309);
    if (iVar2 == 0) {
      return 3;
    }
    iVar3 = *param_1;
    while (iVar3 != 0) {
      __s = (char *)(*Curl_cstrdup)();
      if (__s == (char *)0x0) {
LAB_0003c57e:
        Curl_llist_destroy(iVar2,__s);
        return 3;
      }
      puVar5 = (undefined4 *)(*Curl_cmalloc)(8);
      if (puVar5 == (undefined4 *)0x0) {
        (*Curl_cfree)();
        Curl_llist_destroy(iVar2,0);
        return 3;
      }
      pcVar6 = strchr(__s,0x3a);
      if (pcVar6 == (char *)0x0) {
        *(undefined2 *)(puVar5 + 1) = 0x50;
      }
      else {
        *pcVar6 = '\0';
        lVar4 = strtol(pcVar6 + 1,(char **)0x0,10);
        *(short *)(puVar5 + 1) = (short)lVar4;
      }
      *puVar5 = __s;
      iVar3 = Curl_llist_insert_next(iVar2,*(undefined4 *)(iVar2 + 4),puVar5);
      if (iVar3 == 0) {
        (*Curl_cfree)(*puVar5);
        pcVar1 = Curl_cfree;
        *puVar5 = 0;
        (*pcVar1)(puVar5);
        __s = (char *)0x0;
        goto LAB_0003c57e;
      }
      param_1 = param_1 + 1;
      iVar3 = *param_1;
    }
  }
  if (iVar7 != 0) {
    Curl_llist_destroy(iVar7,0);
  }
  *param_2 = iVar2;
  return 0;
}

