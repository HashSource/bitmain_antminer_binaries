
void digestInit(blake2b_state *S,int n,int k)

{
  int iVar1;
  int iVar2;
  int k_local;
  int n_local;
  blake2b_state *S_local;
  blake2b_param P [1];
  
  memset(P,0,0x40);
  P[0].fanout = '\x01';
  P[0].depth = '\x01';
  iVar1 = __aeabi_idiv(0x200,n);
  iVar1 = n * iVar1;
  iVar2 = iVar1 + 7;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  P[0].digest_length = (uint8_t)(iVar2 >> 3);
  zcashPerson(P[0].personal,n,k);
  blake2b_init_param(S,P);
  return;
}

