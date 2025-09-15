
void Curl_multi_closed(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_1c [2];
  
  iVar2 = *(int *)(*param_1 + 0x40);
  if (iVar2 != 0) {
    iVar1 = sh_getentry(iVar2 + 0x48);
    if (iVar1 != 0) {
      if (*(code **)(iVar2 + 0x1c) != (code *)0x0) {
        (**(code **)(iVar2 + 0x1c))
                  (*param_1,param_2,4,*(undefined4 *)(iVar2 + 0x20),*(undefined4 *)(iVar1 + 0xc));
      }
      local_1c[0] = param_2;
      Curl_hash_delete(iVar2 + 0x48,local_1c,4);
    }
  }
  return;
}

