
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pqueue pqueue_new(void)

{
  pqueue p_Var1;
  
  p_Var1 = (pqueue)CRYPTO_zalloc(8,"ssl/pqueue.c",0x28);
  if (p_Var1 != (pqueue)0x0) {
    return p_Var1;
  }
  ERR_put_error(0x14,0x271,0x41,"ssl/pqueue.c",0x2b);
  return (pqueue)0x0;
}

