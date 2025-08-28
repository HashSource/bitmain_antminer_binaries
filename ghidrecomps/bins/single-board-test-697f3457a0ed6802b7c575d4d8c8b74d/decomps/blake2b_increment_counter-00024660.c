
int blake2b_increment_counter(blake2b_state *S,uint64_t inc)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  bool bVar4;
  uint64_t inc_local;
  blake2b_state *S_local;
  
  inc_local._0_4_ = (uint)inc;
  inc_local._4_4_ = (uint)(inc >> 0x20);
  S->t[0] = inc + S->t[0];
  uVar1 = (uint)S->t[1];
  uVar3 = *(uint *)((int)S->t + 4);
  bVar4 = inc_local._4_4_ <= uVar3;
  if (uVar3 == inc_local._4_4_) {
    bVar4 = (uint)inc_local <= (uint)S->t[0];
  }
  if (!bVar4) {
    inc_local._0_4_ = 1;
  }
  bVar2 = (byte)(uint)inc_local;
  if (bVar4) {
    bVar2 = 0;
  }
  *(uint *)(S->t + 1) = bVar2 + uVar1;
  *(uint *)((int)S->t + 0xc) = *(int *)((int)S->t + 0xc) + (uint)CARRY4((uint)bVar2,uVar1);
  return 0;
}

