
int list_empty(list_head *head)

{
  byte bVar1;
  bool bVar2;
  list_head *head_local;
  
  bVar2 = head->next != head;
  if (bVar2) {
    head = (list_head *)0x0;
  }
  bVar1 = (byte)head;
  if (!bVar2) {
    bVar1 = 1;
  }
  return (uint)bVar1;
}

