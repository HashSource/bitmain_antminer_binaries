
int RAND_bytes(uchar *buf,int num)

{
  RAND_METHOD *pRVar1;
  int iVar2;
  
  pRVar1 = RAND_get_rand_method();
  if ((pRVar1 != (RAND_METHOD *)0x0) && (pRVar1->bytes != (_func_3913 *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00156398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*pRVar1->bytes)(buf,num);
    return iVar2;
  }
  ERR_put_error(0x24,100,0x65,"crypto/rand/rand_lib.c",0x3b2);
  return -1;
}

