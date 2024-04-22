
int blake2b_increment_counter(blake2b_state *S,uint64_t inc)

{
  uint uVar1;
  uint in_r2;
  int iVar2;
  byte bVar3;
  uint in_r3;
  uint uVar4;
  bool bVar5;
  uint64_t inc_local;
  blake2b_state *S_local;
  
  uVar1 = *(uint *)S->t;
  iVar2 = *(int *)((int)S->t + 4);
  *(uint *)S->t = in_r2 + uVar1;
  *(uint *)((int)S->t + 4) = in_r3 + iVar2 + (uint)CARRY4(in_r2,uVar1);
  uVar1 = *(uint *)(S->t + 1);
  uVar4 = *(uint *)((int)S->t + 4);
  bVar5 = in_r3 <= uVar4;
  if (uVar4 == in_r3) {
    bVar5 = in_r2 <= *(uint *)S->t;
  }
  if (!bVar5) {
    in_r2 = 1;
  }
  bVar3 = (byte)in_r2;
  if (bVar5) {
    bVar3 = 0;
  }
  *(uint *)(S->t + 1) = bVar3 + uVar1;
  *(uint *)((int)S->t + 0xc) = *(int *)((int)S->t + 0xc) + (uint)CARRY4((uint)bVar3,uVar1);
  return 0;
}

