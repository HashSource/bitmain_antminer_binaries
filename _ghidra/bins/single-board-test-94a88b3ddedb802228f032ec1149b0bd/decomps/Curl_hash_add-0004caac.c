
undefined4 Curl_hash_add(int *param_1,void *param_2,size_t param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  void *__dest;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = *param_1;
  iVar1 = (*(code *)param_1[1])(param_2,param_3,param_1[4]);
  piVar5 = *(int **)(iVar4 + iVar1 * 4);
  piVar3 = (int *)*piVar5;
  do {
    if (piVar3 == (int *)0x0) {
LAB_0004caf6:
      puVar2 = (undefined4 *)(*Curl_cmalloc)(0xc);
      if (puVar2 != (undefined4 *)0x0) {
        __dest = (void *)(*Curl_cmalloc)(param_3);
        if (__dest != (void *)0x0) {
          memcpy(__dest,param_2,param_3);
          puVar2[1] = __dest;
          puVar2[2] = param_3;
          *puVar2 = param_4;
          iVar1 = Curl_llist_insert_next(piVar5,piVar5[1],puVar2);
          if (iVar1 == 0) {
            (*Curl_cfree)(puVar2[1]);
            (*Curl_cfree)(puVar2);
            param_4 = 0;
          }
          else {
            param_1[5] = param_1[5] + 1;
          }
          return param_4;
        }
        (*Curl_cfree)(puVar2);
      }
      return 0;
    }
    iVar1 = (*(code *)param_1[2])
                      (*(undefined4 *)(*piVar3 + 4),*(undefined4 *)(*piVar3 + 8),param_2,param_3);
    if (iVar1 != 0) {
      Curl_llist_remove(piVar5,piVar3,param_1);
      param_1[5] = param_1[5] + -1;
      goto LAB_0004caf6;
    }
    piVar3 = (int *)piVar3[2];
  } while( true );
}

