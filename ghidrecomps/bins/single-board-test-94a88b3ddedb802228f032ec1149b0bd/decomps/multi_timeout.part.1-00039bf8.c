
void multi_timeout_part_1(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_20;
  int local_1c;
  
  curlx_tvnow(&local_20);
  iVar1 = local_1c;
  iVar3 = local_20;
  iVar2 = Curl_splay(*DAT_00039c50,DAT_00039c50[1],*(undefined4 *)(param_1 + 0x44));
  iVar4 = *(int *)(iVar2 + 0xc);
  *(int *)(param_1 + 0x44) = iVar2;
  if ((iVar4 < iVar3) || ((iVar4 <= iVar3 && (*(int *)(iVar2 + 0x10) <= iVar1)))) {
    *param_2 = 0;
  }
  else {
    iVar3 = curlx_tvdiff(*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10),local_20,
                         local_1c);
    if (iVar3 == 0) {
      *param_2 = 1;
    }
    else {
      *param_2 = iVar3;
    }
  }
  return;
}

