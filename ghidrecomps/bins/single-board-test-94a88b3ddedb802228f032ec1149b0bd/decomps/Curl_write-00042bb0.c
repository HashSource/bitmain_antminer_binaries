
/* WARNING: Removing unreachable block (ram,0x00042bee) */
/* WARNING: Removing unreachable block (ram,0x00042bf2) */

undefined4 Curl_write(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(param_1 + ((*(int *)(param_1 + 0x158) == param_2) + 0x5c) * 4))();
  *param_5 = iVar1;
  if (iVar1 < 0) {
    uVar2 = 0x37;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

