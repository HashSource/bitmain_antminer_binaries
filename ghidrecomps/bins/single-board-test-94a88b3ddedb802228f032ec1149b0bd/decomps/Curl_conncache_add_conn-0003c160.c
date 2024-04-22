
undefined4 Curl_conncache_add_conn(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  char *__s;
  size_t sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *param_2;
  puVar1 = (undefined4 *)
           Curl_conncache_find_bundle
                     (param_2,*(undefined4 *)(iVar5 + 0x580),param_3,param_4,param_4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)(**DAT_0003c240)(0xc);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0;
      *puVar1 = 0;
      iVar3 = Curl_llist_alloc(DAT_0003c244);
      puVar1[2] = iVar3;
      if (iVar3 != 0) {
        if (*(char *)((int)param_2 + 0x1ef) == '\0') {
          iVar3 = param_2[0x26];
        }
        else {
          iVar3 = param_2[0x2a];
        }
        __s = (char *)curl_maprintf(DAT_0003c248,iVar3,*(undefined2 *)(param_2 + 0x118));
        if (__s != (char *)0x0) {
          sVar2 = strlen(__s);
          iVar3 = Curl_hash_add(*(undefined4 *)(iVar5 + 0x580),__s,sVar2,puVar1);
          (**DAT_0003c24c)(__s);
          if (iVar3 != 0) {
            iVar3 = Curl_llist_insert_next(puVar1[2],*(undefined4 *)(puVar1[2] + 4),param_2);
            if (iVar3 == 0) {
              conncache_remove_bundle(*(undefined4 *)(iVar5 + 0x580),puVar1);
              return 0x1b;
            }
            goto LAB_0003c18c;
          }
        }
        bundle_destroy(puVar1);
        return 0x1b;
      }
      (**DAT_0003c24c)(puVar1);
    }
  }
  else {
    iVar5 = Curl_llist_insert_next(puVar1[2],*(undefined4 *)(puVar1[2] + 4),param_2);
    if (iVar5 != 0) {
LAB_0003c18c:
      iVar5 = puVar1[1];
      iVar4 = *(int *)(param_1 + 0x1c);
      iVar3 = *(int *)(param_1 + 0x18);
      param_2[0x11c] = (int)puVar1;
      puVar1[1] = iVar5 + 1;
      param_2[0x11] = iVar4;
      *(int *)(param_1 + 0x1c) = iVar4 + 1;
      *(int *)(param_1 + 0x18) = iVar3 + 1;
      return 0;
    }
  }
  return 0x1b;
}

