
work * __find_work_byid(work *que,uint id)

{
  uint id_local;
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
    if (work->id == id) break;
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

