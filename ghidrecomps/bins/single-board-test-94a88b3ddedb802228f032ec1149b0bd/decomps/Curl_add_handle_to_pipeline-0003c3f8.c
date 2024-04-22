
undefined4
Curl_add_handle_to_pipeline(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  puVar3 = *(undefined4 **)(param_2 + 600);
  puVar5 = (undefined4 *)*puVar3;
  iVar1 = Curl_llist_insert_next(puVar3,puVar3[1],param_1,param_4,param_4);
  if (iVar1 == 0) {
    uVar4 = 0x1b;
  }
  else {
    uVar4 = 0;
  }
  if ((puVar3 == *(undefined4 **)(param_2 + 600)) && ((undefined4 *)*puVar3 != puVar5)) {
    uVar2 = *(undefined4 *)*puVar3;
    *(undefined *)(param_2 + 0x255) = 0;
    Curl_expire(uVar2,1);
    return uVar4;
  }
  return uVar4;
}

