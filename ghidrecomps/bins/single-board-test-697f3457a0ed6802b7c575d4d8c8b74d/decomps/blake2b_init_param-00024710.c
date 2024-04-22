
int blake2b_init_param(blake2b_state *S,blake2b_param *P)

{
  uint uVar1;
  uint64_t uVar2;
  blake2b_param *P_local;
  blake2b_state *S_local;
  uint8_t *p;
  size_t i;
  
  blake2b_init0(S);
  for (i = 0; i < 8; i = i + 1) {
    uVar2 = load64(P->reserved + i * 8 + -0x12);
    uVar1 = *(uint *)((int)(S->h + i) + 4);
    *(uint *)(S->h + i) = *(uint *)(S->h + i) ^ (uint)uVar2;
    *(uint *)((int)(S->h + i) + 4) = uVar1 ^ (uint)(uVar2 >> 0x20);
  }
  return 0;
}

