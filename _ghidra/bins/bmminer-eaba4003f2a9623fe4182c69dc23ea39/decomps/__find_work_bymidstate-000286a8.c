
work * __find_work_bymidstate
                 (work *que,char *midstate,size_t midstatelen,char *data,int offset,size_t datalen)

{
  int iVar1;
  char *data_local;
  size_t midstatelen_local;
  char *midstate_local;
  work *que_local;
  work *ret;
  work *tmp;
  work *work;
  
  work = que;
  if (que == (work *)0x0) {
    tmp = (work *)0x0;
  }
  else {
    tmp = (work *)(que->hh).next;
  }
  while( true ) {
    if (work == (work *)0x0) {
      return (work *)0x0;
    }
    iVar1 = memcmp(work->midstate,midstate,midstatelen);
    if ((iVar1 == 0) && (iVar1 = memcmp(work->data + offset,data,datalen), iVar1 == 0)) break;
    work = tmp;
    if (tmp == (work *)0x0) {
      tmp = (work *)0x0;
    }
    else {
      tmp = (work *)(tmp->hh).next;
    }
  }
  return work;
}

