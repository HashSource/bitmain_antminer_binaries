
void DES_set_odd_parity(DES_cblock *key)

{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  uchar uVar5;
  uchar uVar6;
  uchar uVar7;
  
  uVar1 = (&odd_parity)[(*key)[1]];
  uVar2 = (&odd_parity)[(*key)[2]];
  uVar3 = (&odd_parity)[(*key)[3]];
  uVar4 = (&odd_parity)[(*key)[4]];
  uVar5 = (&odd_parity)[(*key)[5]];
  uVar6 = (&odd_parity)[(*key)[6]];
  uVar7 = (&odd_parity)[(*key)[7]];
  (*key)[0] = (&odd_parity)[(*key)[0]];
  (*key)[1] = uVar1;
  (*key)[2] = uVar2;
  (*key)[3] = uVar3;
  (*key)[4] = uVar4;
  (*key)[5] = uVar5;
  (*key)[6] = uVar6;
  (*key)[7] = uVar7;
  return;
}

