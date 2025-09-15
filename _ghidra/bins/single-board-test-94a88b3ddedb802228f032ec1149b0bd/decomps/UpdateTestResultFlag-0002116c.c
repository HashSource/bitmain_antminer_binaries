
void UpdateTestResultFlag(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int local_c;
  
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    uVar1 = get_TestRet_ByCore(param_1,local_c,param_2);
    *(undefined4 *)(last_result + (local_c + param_1 * 0x100) * 4) = uVar1;
  }
  return;
}

