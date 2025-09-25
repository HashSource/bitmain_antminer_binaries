
int RAND_pseudo_bytes(uchar *buf,int num)

{
  RAND_METHOD *pRVar1;
  int iVar2;
  
  pRVar1 = RAND_get_rand_method();
  if ((pRVar1 != (RAND_METHOD *)0x0) && (pRVar1->pseudorand != (_func_3916 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x001485e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*pRVar1->pseudorand)(buf,num);
    return iVar2;
  }
  ERR_put_error(0x24,0x7e,0x65,"crypto/rand/rand_lib.c",0x3bd);
  return -1;
}

