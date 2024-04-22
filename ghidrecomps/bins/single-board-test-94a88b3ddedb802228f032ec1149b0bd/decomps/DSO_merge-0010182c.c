
char * DSO_merge(DSO *dso,char *filespec1,char *filespec2)

{
  char *pcVar1;
  DSO_MERGER_FUNC pDVar2;
  
  if (dso == (DSO *)0x0 || filespec1 == (char *)0x0) {
    ERR_put_error(0x25,0x84,0x43,DAT_00101874,0x175);
  }
  else if ((dso->flags & 1U) == 0) {
    if (dso->merger != (DSO_MERGER_FUNC)0x0) {
      pcVar1 = (*dso->merger)(dso,filespec1,filespec2);
      return pcVar1;
    }
    pDVar2 = dso->meth->dso_merger;
    if (pDVar2 != (DSO_MERGER_FUNC)0x0) {
      pcVar1 = (*pDVar2)(dso,filespec1,filespec2);
      return pcVar1;
    }
    return (char *)0x0;
  }
  return (char *)0x0;
}

