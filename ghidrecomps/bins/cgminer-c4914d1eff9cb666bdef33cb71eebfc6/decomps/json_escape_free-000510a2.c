
/* WARNING: Unknown calling convention */

void json_escape_free(void)

{
  JE *pJVar1;
  JE *jenext;
  JE *jeptr;
  
  jeptr = jedata;
  jedata = (JE *)0x0;
  while (jeptr != (JE *)0x0) {
    pJVar1 = jeptr->next;
    free(jeptr->buf);
    free(jeptr);
    jeptr = pJVar1;
  }
  return;
}

