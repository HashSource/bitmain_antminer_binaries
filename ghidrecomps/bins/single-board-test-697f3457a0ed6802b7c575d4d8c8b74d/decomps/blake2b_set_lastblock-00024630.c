
int blake2b_set_lastblock(blake2b_state *S)

{
  blake2b_state *S_local;
  
  if (S->last_node != '\0') {
    blake2b_set_lastnode(S);
  }
  *(undefined4 *)S->f = 0xffffffff;
  *(undefined4 *)((int)S->f + 4) = 0xffffffff;
  return 0;
}

