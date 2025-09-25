
undefined4 asn1_generalizedtime_to_tm(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 4) != 0x18) {
    return 0;
  }
  uVar1 = asn1_time_to_tm();
  return uVar1;
}

