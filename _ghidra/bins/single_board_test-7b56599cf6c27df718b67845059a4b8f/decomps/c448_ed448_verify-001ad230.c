
undefined4 c448_ed448_verify(int param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar3 = (byte *)(param_1 + 0x72);
  pbVar2 = &UNK_002358c9;
  while( true ) {
    pbVar3 = pbVar3 + -1;
    pbVar2 = pbVar2 + -1;
    if (*pbVar2 < *pbVar3) {
      return 0;
    }
    if (*pbVar3 < *pbVar2) break;
    if (pbVar2 == &order_12732) {
      return 0;
    }
  }
  uVar1 = c448_ed448_verify_part_0();
  return uVar1;
}

