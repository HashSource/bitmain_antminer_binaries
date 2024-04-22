
undefined4
Curl_pipeline_site_blacklisted(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((*(int *)(param_1 + 0x40) != 0) &&
     (piVar1 = (int *)Curl_multi_pipelining_site_bl(), piVar1 != (int *)0x0)) {
    for (puVar4 = (undefined4 *)*piVar1; puVar4 != (undefined4 *)0x0;
        puVar4 = (undefined4 *)puVar4[2]) {
      puVar5 = (undefined4 *)*puVar4;
      iVar2 = Curl_raw_equal(*puVar5,*(undefined4 *)(param_2 + 0x98));
      if ((iVar2 != 0) &&
         (uVar3 = (uint)*(ushort *)(puVar5 + 1), uVar3 == *(uint *)(param_2 + 0xb4))) {
        Curl_infof(param_1,DAT_0003c4c4,*(undefined4 *)(param_2 + 0x98),uVar3,param_4);
        return 1;
      }
    }
  }
  return 0;
}

