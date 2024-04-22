
int list_empty(list_head *head)

{
  byte bVar1;
  list_head *plVar2;
  bool bVar3;
  list_head *head_local;
  
  plVar2 = head->next;
  bVar3 = head == plVar2;
  if (bVar3) {
    plVar2 = (list_head *)0x1;
  }
  bVar1 = (byte)plVar2;
  if (!bVar3) {
    bVar1 = 0;
  }
  return (uint)bVar1;
}

