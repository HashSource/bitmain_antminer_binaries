
void trans_cb(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = *(int *)(param_3 + 4);
  puVar1 = *(undefined4 **)(iVar2 + 0x20);
  pcVar3 = *(code **)(iVar2 + 0x1c);
  *puVar1 = param_1;
  puVar1[1] = param_2;
  (*pcVar3)(iVar2);
  return;
}

