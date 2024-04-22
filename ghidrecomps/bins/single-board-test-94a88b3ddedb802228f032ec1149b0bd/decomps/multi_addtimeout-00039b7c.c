
undefined4 multi_addtimeout(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  puVar2 = (undefined4 *)(**DAT_00039bf0)(8);
  if (puVar2 == (undefined4 *)0x0) {
    return 3;
  }
  uVar5 = param_2[1];
  *puVar2 = *param_2;
  puVar2[1] = uVar5;
  puVar3 = (undefined4 *)Curl_llist_count(param_1);
  if ((puVar3 != (undefined4 *)0x0) &&
     (puVar3 = (undefined4 *)*param_1, puVar3 != (undefined4 *)0x0)) {
    puVar1 = puVar3;
    puVar3 = (undefined4 *)0x0;
    do {
      puVar6 = puVar1;
      iVar4 = curlx_tvdiff(*(undefined4 *)*puVar6,((undefined4 *)*puVar6)[1],*puVar2,puVar2[1]);
      if (0 < iVar4) break;
      puVar1 = (undefined4 *)puVar6[2];
      puVar3 = puVar6;
    } while ((undefined4 *)puVar6[2] != (undefined4 *)0x0);
  }
  iVar4 = Curl_llist_insert_next(param_1,puVar3,puVar2);
  if (iVar4 == 0) {
    (**DAT_00039bf4)(puVar2);
    return 3;
  }
  return 0;
}

