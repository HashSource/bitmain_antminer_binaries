
undefined4 ssl_session_LHASH_COMP(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((*param_1 == *param_2) && (param_1[0x11] == param_2[0x11])) {
    uVar1 = (*(code *)PTR_memcmp_00194160)(param_1 + 0x12,param_2 + 0x12);
    return uVar1;
  }
  return 1;
}

