
/* WARNING: Unknown calling convention */

pool * select_balanced(pool *cp)

{
  _Bool _Var1;
  pool *ret;
  pool **pppVar2;
  pool **pppVar3;
  pool *pool_00;
  pool *pool;
  int iVar5;
  int iVar6;
  int lowest;
  pool **pppVar4;
  
  iVar6 = cp->shares;
  iVar5 = *DAT_0001e448;
  if (0 < iVar5) {
    pppVar2 = (pool **)*DAT_0001e44c;
    pppVar3 = pppVar2;
    do {
      pppVar4 = pppVar3 + 1;
      pool_00 = *pppVar3;
      _Var1 = pool_unusable(pool_00);
      if ((!_Var1) && (pool_00->shares < iVar6)) {
        iVar6 = pool_00->shares;
        cp = pool_00;
      }
      pppVar3 = pppVar4;
    } while (pppVar4 != pppVar2 + iVar5);
    iVar6 = cp->shares;
  }
  cp->shares = iVar6 + 1;
  return cp;
}

