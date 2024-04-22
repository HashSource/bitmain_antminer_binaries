
undefined4 Curl_hash_add(int *param_1,void *param_2,size_t param_3,undefined4 param_4)

{
  code **ppcVar1;
  int iVar2;
  undefined4 *puVar3;
  void *__dest;
  int *piVar4;
  int iVar5;
  int **ppiVar6;
  
  iVar5 = *param_1;
  iVar2 = (*(code *)param_1[1])(param_2,param_3,param_1[4]);
  ppiVar6 = *(int ***)(iVar5 + iVar2 * 4);
  piVar4 = *ppiVar6;
  do {
    if (piVar4 == (int *)0x0) {
LAB_0004caf6:
      ppcVar1 = DAT_0004cb58;
      puVar3 = (undefined4 *)(**DAT_0004cb58)(0xc);
      if (puVar3 != (undefined4 *)0x0) {
        __dest = (void *)(**ppcVar1)(param_3);
        if (__dest != (void *)0x0) {
          memcpy(__dest,param_2,param_3);
          puVar3[1] = __dest;
          puVar3[2] = param_3;
          *puVar3 = param_4;
          iVar2 = Curl_llist_insert_next(ppiVar6,ppiVar6[1],puVar3);
          ppcVar1 = DAT_0004cb5c;
          if (iVar2 == 0) {
            (**DAT_0004cb5c)(puVar3[1]);
            (**ppcVar1)(puVar3);
            param_4 = 0;
          }
          else {
            param_1[5] = param_1[5] + 1;
          }
          return param_4;
        }
        (**DAT_0004cb5c)(puVar3);
      }
      return 0;
    }
    iVar2 = (*(code *)param_1[2])
                      (*(undefined4 *)(*piVar4 + 4),*(undefined4 *)(*piVar4 + 8),param_2,param_3);
    if (iVar2 != 0) {
      Curl_llist_remove(ppiVar6,piVar4,param_1);
      param_1[5] = param_1[5] + -1;
      goto LAB_0004caf6;
    }
    piVar4 = (int *)piVar4[2];
  } while( true );
}

