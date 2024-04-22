
/* WARNING: Unknown calling convention */
/* Local variable work:work *[r0:4] conflicts with parameter, skipped. */

work * __find_work_bymidstate
                 (work *que,char *midstate,size_t midstatelen,char *data,int offset,size_t datalen)

{
  work *pwVar1;
  int iVar2;
  work *tmp;
  work *pwVar3;
  
  if (que != (work *)0x0) {
    pwVar1 = (work *)(que->hh).next;
    while( true ) {
      pwVar3 = pwVar1;
      iVar2 = memcmp(que->midstate,midstate,midstatelen);
      if ((iVar2 == 0) && (iVar2 = memcmp(que->data + offset,data,datalen), iVar2 == 0)) {
        return que;
      }
      if (pwVar3 == (work *)0x0) break;
      pwVar1 = (work *)(pwVar3->hh).next;
      que = pwVar3;
    }
    que = (work *)0x0;
  }
  return que;
}

