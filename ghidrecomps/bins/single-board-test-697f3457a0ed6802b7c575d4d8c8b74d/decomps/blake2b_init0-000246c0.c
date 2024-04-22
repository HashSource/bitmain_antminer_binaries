
int blake2b_init0(blake2b_state *S)

{
  undefined4 uVar1;
  blake2b_state *S_local;
  int i;
  
  memset(S,0,0x168);
  for (i = 0; i < 8; i = i + 1) {
    uVar1 = *(undefined4 *)((int)blake2b_IV + i * 8 + 4);
    *(undefined4 *)(S->h + i) = *(undefined4 *)(blake2b_IV + i);
    *(undefined4 *)((int)(S->h + i) + 4) = uVar1;
  }
  return 0;
}

