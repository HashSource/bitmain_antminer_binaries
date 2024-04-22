
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pqueue pqueue_new(void)

{
  pqueue p_Var1;
  
  p_Var1 = (pqueue)CRYPTO_malloc(8,DAT_000d6fc4,0x5d);
  if (p_Var1 != (pqueue)0x0) {
    *p_Var1 = (_pqueue)0x0;
    p_Var1[1] = (_pqueue)0x0;
    p_Var1[2] = (_pqueue)0x0;
    p_Var1[3] = (_pqueue)0x0;
    p_Var1[4] = (_pqueue)0x0;
    p_Var1[5] = (_pqueue)0x0;
    p_Var1[6] = (_pqueue)0x0;
    p_Var1[7] = (_pqueue)0x0;
  }
  return p_Var1;
}

