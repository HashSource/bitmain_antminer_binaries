
int blake2b_set_lastnode(blake2b_state *S)

{
  blake2b_state *S_local;
  
  *(undefined4 *)(S->f + 1) = 0xffffffff;
  *(undefined4 *)((int)S->f + 0xc) = 0xffffffff;
  return 0;
}

