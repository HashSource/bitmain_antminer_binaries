
void Curl_pgrsTime(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 extraout_s1;
  undefined4 extraout_s1_00;
  undefined4 extraout_s1_01;
  undefined4 extraout_s1_02;
  undefined4 extraout_s1_03;
  undefined4 extraout_s1_04;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  curlx_tvnow(&local_18);
  switch(param_2) {
  case 1:
    *(undefined4 *)(param_1 + 0x508) = local_18;
    *(undefined4 *)(param_1 + 0x50c) = uStack_14;
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x500) = local_18;
    *(undefined4 *)(param_1 + 0x504) = uStack_14;
    break;
  case 3:
    uVar1 = curlx_tvdiff_secs(local_18,uStack_14,*(undefined4 *)(param_1 + 0x500),
                              *(undefined4 *)(param_1 + 0x504));
    *(ulonglong *)(param_1 + 0x4c8) = CONCAT44(extraout_s1_00,uVar1);
    break;
  case 4:
    uVar1 = curlx_tvdiff_secs(local_18,uStack_14,*(undefined4 *)(param_1 + 0x500),
                              *(undefined4 *)(param_1 + 0x504));
    *(ulonglong *)(param_1 + 0x4d0) = CONCAT44(extraout_s1_01,uVar1);
    break;
  case 5:
    uVar1 = curlx_tvdiff_secs(local_18,uStack_14,*(undefined4 *)(param_1 + 0x500),
                              *(undefined4 *)(param_1 + 0x504));
    *(ulonglong *)(param_1 + 0x4d8) = CONCAT44(extraout_s1_02,uVar1);
    break;
  case 6:
    uVar1 = curlx_tvdiff_secs(local_18,uStack_14,*(undefined4 *)(param_1 + 0x500),
                              *(undefined4 *)(param_1 + 0x504));
    *(ulonglong *)(param_1 + 0x4e0) = CONCAT44(extraout_s1_03,uVar1);
    break;
  case 7:
    uVar1 = curlx_tvdiff_secs(local_18,uStack_14,*(undefined4 *)(param_1 + 0x500),
                              *(undefined4 *)(param_1 + 0x504));
    *(ulonglong *)(param_1 + 0x4e8) = CONCAT44(extraout_s1_04,uVar1);
    break;
  case 9:
    curlx_tvnow(&local_20);
    *(undefined4 *)(param_1 + 0x510) = local_20;
    *(undefined4 *)(param_1 + 0x514) = uStack_1c;
    break;
  case 10:
    uVar1 = curlx_tvdiff_secs(local_18,uStack_14,*(undefined4 *)(param_1 + 0x4f8),
                              *(undefined4 *)(param_1 + 0x4fc));
    *(ulonglong *)(param_1 + 0x4f0) = CONCAT44(extraout_s1,uVar1);
  }
  return;
}

