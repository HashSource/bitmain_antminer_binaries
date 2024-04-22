
/* WARNING: Unknown calling convention */
/* Local variable work:work *[r0:4] conflicts with parameter, skipped. */

work * __find_work_byid(work *que,uint id)

{
  work *pwVar1;
  work *tmp;
  
  if (que != (work *)0x0) {
    pwVar1 = (work *)(que->hh).next;
    if (que->id == id) {
      return que;
    }
    do {
      que = pwVar1;
      if (que == (work *)0x0) {
        return (work *)0x0;
      }
      pwVar1 = (work *)(que->hh).next;
    } while (que->id != id);
  }
  return que;
}

